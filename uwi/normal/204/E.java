//package round129;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] s = new int[200002];
		int[] b = new int[n+1];
		b[0] = -1;
		int m = 0;
		for(int i = 0;i < n;i++){
			char[] x = ns().toCharArray();
			for(int j = 0;j < x.length;j++){
				s[j+m] = x[j];
			}
			m += x.length;
			s[m] = 12345+i;
			b[i+1] = m;
			m++;
		}
		if(K == 1){
			for(int i = 0;i < n;i++){
				if(i > 0)out.print(" ");
				out.print((long)(b[i+1]-b[i]-1)*(b[i+1]-b[i]+1-1)/2);
			}
			out.println();
			return;
		}
		
		s = Arrays.copyOf(s, m);
		int[] iclus = new int[m];
		for(int i = 0;i < n;i++){
			for(int j = b[i]+1;j < b[i+1];j++){
				iclus[j] = i;
			}
			iclus[b[i+1]] = -1;
		}
		Integer[] sa = doLarssonSadakane(s);
		int[] lcp = buildLCP(s, sa);
//		tr(sa);
		int[] clus = new int[m+1];
		for(int i = 1;i < sa.length;i++){
			clus[i] = iclus[sa[i]];
		}
//		tr(clus);
//		tr(lcp);
		int[][] q = new int[100002][2];
		int qp = 0;
		int[][] rs = new int[500000][];
		int rp = 0;
		for(int i = 1;i < lcp.length;i++){
//			lcp[i] = Math.min(lcp[i], b[clus[i]+1] - sa[i]);
//			if(i+1 < lcp.length)lcp[i+1] = Math.min(lcp[i+1], b[clus[i]+1] - sa[i]);
			int first = -1;
			while(qp > 0 && q[qp-1][0] > lcp[i]){
				// [q[qp-1][1]-1, i-1] * (q[qp-1][0]-max(q[qp-2][0],lcp[i]))
				int mul = q[qp-1][0] - (qp-2 >= 0 ? Math.max(q[qp-2][0], lcp[i]) : lcp[i]);
				rs[rp++] = new int[]{q[qp-1][1]-1, i-1, mul};
				
				first = q[qp-1][1];
				qp--;
			}
			
			if(qp == 0 || q[qp-1][0] != lcp[i]){
				q[qp][0] = lcp[i];
				q[qp][1] = first == -1 ? i : first;
				qp++;
			}
		}
		while(qp > 0){
			int i = lcp.length;
			int mul = q[qp-1][0] - (qp-2 >= 0 ? q[qp-2][0] : 0);
			if(mul > 0){
				rs[rp++] = new int[]{q[qp-1][1]-1, i-1, mul};
			}
			qp--;
		}
		rs = Arrays.copyOf(rs, rp);
		final int SQ = (int)Math.sqrt(lcp.length)+1;
		Arrays.sort(rs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] / SQ != b[0] / SQ){
					return a[0] / SQ - b[0] / SQ;
				}
				if(a[0] / SQ % 2 == 1){
					return -(a[1] - b[1]);
				}else{
					return a[1] - b[1];
				}
			}
		});
		
//		tr(clus);
//		tr("lcp", lcp);
//		tr(rs);
		int[] kind = new int[n];
		int nk = 0;
		int u = 1, v = 0;
		long[] imos = new long[lcp.length+1];
		for(int i = 0;i < rp;i++){
			while(v < rs[i][1]){
				v++;
				if(kind[clus[v]] == 0)nk++;
				kind[clus[v]]++;
			}
			while(u > rs[i][0]){
				u--;
				if(kind[clus[u]] == 0)nk++;
				kind[clus[u]]++;
			}
			while(u < rs[i][0]){
				if(kind[clus[u]] == 1)nk--;
				kind[clus[u]]--;
				u++;
			}
			while(v > rs[i][1]){
				if(kind[clus[v]] == 1)nk--;
				kind[clus[v]]--;
				v--;
			}
//			tr(kind);
			if(nk >= K){
				imos[rs[i][0]] += rs[i][2];
				imos[rs[i][1]+1] -= rs[i][2];
			}
		}
		
//		tr(imos);
		long[] ret = new long[n];
		long cum = 0;
		for(int i = 1;i < lcp.length;i++){
			cum += imos[i];
			if(clus[i] == -1)break;
			ret[clus[i]] += cum;
		}
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(ret[i]);
		}
		out.println();
	}
	
	public static Integer[] doLarssonSadakane(int[] str)
	{
		int n = str.length;
		final int[] g = new int[n+1];
		int[] b = new int[n+1];
		Integer[] v = new Integer[n+1];
		for(int i = 0;i < n+1;i++){
			v[i] = i;
			g[i] = i == n ? -1 : str[i];
		}
		b[0] = 0; b[n] = 0;
		
		Arrays.sort(v, new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				if(a == b)return -1;
				return g[a] - g[b];
			}
		});
		for(int h = 1;b[n] != n;h *= 2){
			final int u = h;
			Comparator<Integer> comp = new Comparator<Integer>(){
				public int compare(Integer a, Integer b){
					if(a == b)return -1;
					if(g[a] - g[b] != 0)return g[a] - g[b];
					return g[a+u] - g[b+u];
				}
			};
			Arrays.sort(v, comp);
			for(int i = 0;i < n;i++){
				b[i+1] = b[i] + (comp.compare(v[i], v[i+1]) < 0 ? 1 : 0);
			}
			for(int i = 0;i < n+1;i++)g[v[i]] = b[i];
		}
		return v;
	}
	
	public static int[] buildLCP(int[] str, Integer[] ls)
	{
		int n = str.length;
		int h = 0;
		int[] lcp = new int[n+1];
		int[] b = new int[n+1];
		for(int i = 0;i < n+1;i++)b[ls[i]] = i;
		for(int i = 0;i < n+1;i++){
			if(b[i] != 0){
				for(int j = ls[b[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; h++);
				lcp[b[i]] = h;
			}else{
				lcp[b[i]] = -1;
			}
			if(h > 0)h--;
		}
		return lcp;
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}