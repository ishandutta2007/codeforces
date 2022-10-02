//package round99;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] t = new int[n][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				t[i][j] = ni();
			}
		}
		int[][] mush = new int[m][2]; // pos mp
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 2;j++){
				mush[i][j] = ni();
			}
		}
		Arrays.sort(mush, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		
		int[][] r = new int[2*n][3]; // left right p
		int[][] ev = new int[4*n][2]; // pos ind
		for(int i = 0;i < n;i++){
			r[2*i][0] = t[i][0]-t[i][1];
			r[2*i][1] = t[i][0]-1;
			r[2*i][2] = t[i][2];
			r[2*i+1][0] = t[i][0]+1;
			r[2*i+1][1] = t[i][0]+t[i][1];
			r[2*i+1][2] = t[i][3];
		}
		for(int i = 0;i < 2*n;i++){
			ev[2*i][0] = r[i][0];
			ev[2*i][1] = i;
			ev[2*i+1][0] = r[i][1]+1;
			ev[2*i+1][1] = i;
		}
		
		Arrays.sort(ev, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		
		int p = 0;
		double E = 0;
		boolean[] flag = new boolean[2*n];
		SegmentTreeRSQ st = new SegmentTreeRSQ(2*n);
		for(int i = 0;i < m;i++){
			while(p < 4*n && ev[p][0] <= mush[i][0]){
				if(flag[ev[p][1]]){
					st.update(ev[p][1], 1.0);
					flag[ev[p][1]] = false;
				}else{
					st.update(ev[p][1], (double)(100-r[ev[p][1]][2]) / 100);
					flag[ev[p][1]] = true;
				}
				p++;
			}
//			tr(p, P, mush[i][1], mush[i][0]);
			E += st.sum(0, 2*n-1)*mush[i][1];
		}
		out.printf("%.8f\n", E);
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N, B;
		public double[] st;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			st = new double[M];
			for(int i = 0;i < N;i++){
				st[H+i] = 1.0;
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				st[i] = st[i*2] * st[i*2+1];
			}
		}
		
		public void update(int pos, double v)
		{
			st[H+pos] = v;
			for(int i = (H+pos)>>1;i >= 1;i >>>= 1){
				st[i] = st[2*i] * st[2*i+1];
			}
		}
		
		public double sum(int f, int t) { return sum(f, t, B); }
		
		protected double sum(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return st[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				return sum(f, w-1, b) * sum(w, t, b);
			}else{
				return sum(f, t, b);
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
		new C().run();
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