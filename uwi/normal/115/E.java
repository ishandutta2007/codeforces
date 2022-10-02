//package round87;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "3 1\r\n" + 
			"10\r\n" + 
			"10\r\n" + 
			"10\r\n" + 
			"1 3 10";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] cost = new int[n];
		for(int i = 0;i < n;i++)cost[i] = ni();
		int[][] bene = new int[m][3];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 3;j++){
				bene[i][j] = ni();
			}
		}
		Arrays.sort(bene, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[1] - b[1];
			}
		});
		
		SegmentTreeRMQRange st = new SegmentTreeRMQRange(n);
		long[] dp = new long[n];
		long[] dpmax = new long[n+1];
		int p = 0;
		for(int i = 0;i < n;i++){
			st.addRange(i, i, dpmax[i]);
			st.addRange(0, i, -cost[i]);
			while(p < m && bene[p][1]-1 == i){
				st.addRange(0, bene[p][0]-1, bene[p][2]);
				p++;
			}
//			tr(p);
			dp[i] = st.max(0, i);
//			tr(i, dp[i]);
			dpmax[i+1] = Math.max(dpmax[i], dp[i]);
		}
		out.println(dpmax[n]);
	}
	
	public static class SegmentTreeRMQRange {
		public int M, H, N, B;
		public long[] st;
		public long[] plus;
		
		public SegmentTreeRMQRange(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new long[M];
			plus = new long[H];
		}
		
		public SegmentTreeRMQRange(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, Long.MIN_VALUE);
			for(int i = H-1;i >= 1;i--){
				st[i] = Math.max(st[i*2], st[i*2+1]);
			}
		}
		
		public void update(int pos, long x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1){
				st[i] = Math.max(st[2*i], st[2*i+1]) + plus[i];
			}
		}
		
		public void addRange(int f, int t, long v){ addRange(f, t, v, B); }
		
		public void addRange(int f, int t, long v, int b)
		{
			if(b == 0){
				update(f, st[H|f]+v);
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H|f)>>b] += v;
				for(int i = (H|f)>>b;i >= 1;i >>>= 1){
					st[i] = Math.max(st[2*i], st[2*i+1]) + plus[i];
				}
			}else{
				b--;
				if((f^t)<<31-b<0){
					int w = t>>b<<b;
					addRange(f, w-1, v, b);
					addRange(w, t, v, b);
				}else{
					addRange(f, t, v, b);
				}
			}
		}
		
		public long max(int f, int t) { return max(f, t, B); }
		
		public long max(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return st[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				return Math.max(max(f, w-1, b), max(w, t, b)) + plus[(H|f)>>b+1];
			}else{
				return max(f, t, b) + plus[(H|f)>>b+1];
			}
		}
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
	
	public String nline()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
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
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}