//package round101;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), L = ni();
		int[] x = new int[n];
		int[] d = new int[n];
		int[] t = new int[n];
		int[] p = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			d[i] = ni();
			t[i] = ni();
			p[i] = ni();
		}
		
		int[][] r = new int[n][4];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(x[i]-p[i] >= 0 && x[i]+d[i] <= L){
				r[q][0] = x[i]-p[i];
				r[q][1] = x[i]+d[i];
				r[q][2] = p[i]+t[i];
				r[q][3] = i;
				q++;
			}
//			if(x[i]+p[i] <= L && x[i]-d[i] >= 0){
//				r[q][0] = x[i]+p[i];
//				r[q][1] = x[i]-d[i];
//				r[q][2] = p[i]+t[i];
//				q++;
//			}
		}
		int[] z = new int[2*q+2];
		z[2*q] = 0;
		z[2*q+1] = L;
		for(int i = 0;i < q;i++){
			z[i] = r[i][0];
			z[q+i] = r[i][1];
		}
		
		int[] imap = shrinkX(z);
		
		int[] from = new int[q];
		int[] to = new int[q];
		int[] w = new int[q];
		int[] ind = new int[q];
		
		for(int i = 0;i < q;i++){
			from[i] = z[i];
			to[i] = z[q+i];
			w[i] = r[i][2];
			ind[i] = r[i][3];
		}
		
		int m = imap.length;
		int[][][] g = packWD(imap.length, from, to, w);
		int[][][] indg = packWD(imap.length, from, to, ind);
		
		final int[] td = new int[m];
		Arrays.fill(td, Integer.MAX_VALUE);
		int[] prev = new int[m];
		int[] prevd = new int[m];
		Arrays.fill(prev, -1);
		TreeSet<Integer> ts = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				if(td[a] - td[b] != 0)return td[a] - td[b];
				return a - b;
			}
		});
		ts.add(0);
		td[0] = 0;
		
		while(ts.size() > 0){
			int cur = ts.pollFirst();
			if(cur == imap.length-1)break;
			
			for(int i = 0;i < g[cur].length;i++){
				int next = g[cur][i][0];
				int nd = td[cur] + g[cur][i][1];
				if(nd < td[next]){
					ts.remove(next);
					td[next] = nd;
					prev[next] = cur;
					prevd[next] = indg[cur][i][1];
					ts.add(next);
				}
			}
			
			if(cur < imap.length-1){
				int nd = td[cur] + imap[cur+1]-imap[cur];
				if(nd < td[cur+1]){
					ts.remove(cur+1);
					td[cur+1] = nd;
					prev[cur+1] = cur;
					prevd[cur+1] = -1;
					ts.add(cur+1);
				}
			}
			if(cur >= 1){
				int nd = td[cur] - imap[cur-1]+imap[cur];
				if(nd < td[cur-1]){
					ts.remove(cur-1);
					td[cur-1] = nd;
					prev[cur-1] = cur;
					prevd[cur-1] = -1;
					ts.add(cur-1);
				}
			}
		}
		
		int ct = 0;
		for(int u = imap.length-1;u != -1;u = prev[u])ct++;
		int[] jmp = new int[ct];
		int jct = 0;
		for(int u = imap.length-1, f = ct - 1, a = -1;u != -1;a = prevd[u], u = prev[u], f--){
			jmp[f] = a;
			if(a != -1){
				jct++;
			}
		}
		out.println(td[imap.length-1]);
		out.println(jct);
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < ct;i++){
			if(jmp[i] != -1){
				sb.append(" " + (jmp[i]+1));
			}
		}
		if(sb.length() == 0){
			out.println();
		}else{
			out.println(sb.substring(1));
		}
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int)(b[0]>>32);
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0) {
				p++;
				ret[p] = (int)(b[i]>>32);
			}
			a[(int)b[i]] = p;
		}
		return Arrays.copyOf(ret, p+1);
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
		new D().run();
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