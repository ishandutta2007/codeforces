//package round144;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "8  5 10 10 5 8 7 4 7  1 3 4 ";
//	String INPUT = "6  9 8 4 5 5 5  6  5 5 2 5 2 2 1 4 3 5 1 1";
	// q{, , , , , }
//	String INPUT = "10\r\n" + 
//			"1 2 2 1 100 99 99 100 100 100\r\n" + 
//			"6\r\n" + 
//			"1 4\r\n" + 
//			"1 2\r\n" + 
//			"3 4\r\n" + 
//			"1 5\r\n" + 
//			"9 10\r\n" + 
//			"10 10";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		long[] b = new long[n-1];
		long O = 1000000000;
		for(int i = 0;i < n-1;i++){
			b[i] = a[i+1] - a[i] + O;
		}
		
		long[] bx = new long[2*(n-1)+1];
		for(int i = 0;i < n-1;i++){
			bx[i] = b[i];
			bx[i+n-1+1] = -(b[i]-O)+O;
		}
		bx[n-1] = 0;
		
//		long[] c = new long[2*(n-1)+1];
//		for(int i = 0;i < 2*(n-1)+1;i++){
//			c[i] = bx[i] - O;
//		}
//		tr("c", c);
		
		Integer[] sax = doLarssonSadakane(bx); // +$+reverseSA
		// [0,n-1) n-1 [n,2n-1)
		int[] isax = new int[2*(n-1)+2];
		for(int i = 0;i < sax.length;i++){
			if(sax[i] >= 0)isax[sax[i]] = i;
		}
		int[] lcp = buildLCP(bx, sax);
//		tr(bx);
//		tr("isax", isax);
////		
//		tr("sax", sax);
//		tr("lcp", lcp);
		SegmentTreeRMQ st = new SegmentTreeRMQ(lcp);
		
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int from = ni()-1, to = ni()-1;
			qs[i] = new int[]{from, to, from-(to-from)-1, i, -1, -1};
			if(to - from > 0){
				int ind = isax[from+n];
				int len = to - from;
//				tr(from+n-1);
				int left = -1, right = -1;
				{
					int low = 0, high = ind;
					while(high - low > 1){
						int x = (high + low) / 2;
						int v = st.min(x+1, ind);
						if(v < len){
							low = x;
						}else{
							high = x;
						}
					}
					left = high;
				}
				{
					int low = ind, high = 2*(n-1)+2;
					while(high - low > 1){
						int x = (high + low) / 2;
						int v = st.min(ind+1, x);
//						tr(ind, x, v, len);
						if(v >= len){
							low = x;
						}else{
							high = x;
						}
					}
					right = low;
				}
				qs[i][4] = left;
				qs[i][5] = right;
			}
//			tr(qs[i]);
		}
		
		int[] ret = new int[Q];
		for(int i = 0;i < Q;i++){
			if(qs[i][1]-qs[i][0] == 0){
				ret[qs[i][3]] = n-1;
			}else{
				ret[qs[i][3]] = 0;
			}
		}
		
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		{
			int[] ft = new int[2*(n-1)+1+1+1];
			int p = 0;
			for(int i = 0;i < Q;i++){
				int[] q = qs[i];
				int len = q[1]-q[0];
				if(len != 0){
					while(p < (n-1)+1 && p <= q[2]){
						addFenwick(ft, isax[p], 1);
						p++;
					}
					ret[q[3]] += sumFenwick(ft, q[5]) - sumFenwick(ft, q[4]-1);
				}
			}
		}
		
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[1] - b[1]);
			}
		});
		
		{
			int[] ft = new int[2*(n-1)+1+1+1];
			int p = n-1;
			for(int i = 0;i < Q;i++){
				int[] q = qs[i];
				int len = q[1]-q[0];
				if(len != 0){
					while(p >= 0 && p >= q[1]+1){
						addFenwick(ft, isax[p], 1);
						p--;
					}
					ret[q[3]] += sumFenwick(ft, q[5]) - sumFenwick(ft, q[4]-1);
				}
			}
		}
		
		for(int i = 0;i < Q;i++){
			out.println(ret[i]);
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	public static class SegmentTreeRMQ {
		public int M, H, N, B;
		public int[] st;
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public int min(int f, int t){ return f > t ? Integer.MAX_VALUE : min(f, t, B);}
		
		public int min(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return st[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				return Math.min(min(f, w-1, b), min(w, t, b));
			}else{
				return min(f, t, b);
			}
		}
	}
	
	public static Integer[] doLarssonSadakane(long[] str)
	{
		int n = str.length;
		final long[] g = new long[n+1];
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
				return Long.signum(g[a] - g[b]);
			}
		});
		for(int h = 1;b[n] != n;h *= 2){
			final int u = h;
			Comparator<Integer> comp = new Comparator<Integer>(){
				public int compare(Integer a, Integer b){
					if(a == b)return -1;
					if(g[a] - g[b] != 0)return Long.signum(g[a] - g[b]);
					return Long.signum(g[a+u] - g[b+u]);
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
	
	static int[] ils;
	
	public static int[] buildLCP(long[] str, Integer[] ls)
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
		ils = b;
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