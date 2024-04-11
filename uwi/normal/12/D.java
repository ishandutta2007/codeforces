//package round12;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "3\r\n" + 
			"1 4 2\r\n" + 
			"4 3 2\r\n" + 
			"2 5 3";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][3];
		int[] y = new int[n];
		for(int j = 0;j < 3;j++){
			for(int i = 0;i < n;i++){
				co[i][j] = ni();
			}
		}
		
		for(int i = 0;i < n;i++){
			y[i] = co[i][1];
			co[i][2]++;
		}
		y = shrink(y);
		for(int i = 0;i < n;i++){
			co[i][1] = y[i];
		}
		
		Arrays.sort(co, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(a[0] != b[0])return -(a[0] - b[0]);
				if(a[1] != b[1])return -(a[1] - b[1]);
				return -(a[2] - b[2]);
			}
		});
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(n);
		
		int dead = 0;
		int start = 0;
		for(int i = 0;i < n;i++){
			if(st.max(co[i][1]+1, n-1) > co[i][2]){
				dead++;
			}
			
			if(i < n-1 && co[i][0] > co[i+1][0]){
				for(int j = start;j <= i;j++){
					int o = st.max(co[j][1], co[j][1]);
					st.update(co[j][1], Math.max(o, co[j][2]));
				}
				
				start = i+1;
			}
		}
		out.println(dead);
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	public static class SegmentTreeRMQ {
		public int M, H, N, B;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
		}
		
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
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.max(st[2*i], st[2*i+1]);
		}
		
		public int max(int f, int t){ return f > t ? 0 : max(f, t, B);}
		
		public int max(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return st[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				return Math.max(max(f, w-1, b), max(w, t, b));
			}else{
				return max(f, t, b);
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