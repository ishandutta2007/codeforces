//package round107;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
//	String INPUT = "10 8 187\r\n" + 
//			"0 10 30 70 150 310 630 1270 2550 51100\r\n" + 
//			"13 87 65 0 100 44 67 3 4\r\n" + 
//			"1 10\r\n" + 
//			"2 9\r\n" + 
//			"3 8\r\n" + 
//			"1 5\r\n" + 
//			"6 10\r\n" + 
//			"2 7\r\n" + 
//			"4 10\r\n" + 
//			"4 5";
//	String INPUT = "3 3 10 0 10 100 100 0 1 2 2 3 1 3";
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), c = ni();
		int[] x = new int[n];
		int[] ins = new int[n-1];
		for(int i = 0;i < n;i++)x[i] = ni();
		for(int i = 0;i < n-1;i++)ins[i] = ni();
		double[] pro = new double[n-1];
		for(int i = 0;i < n-1;i++){
			pro[i] = (double)(x[i+1]-x[i])/2-(double)ins[i]/100*c;
		}
		double[] spro = new double[n];
		for(int i = 0;i < n-1;i++){
			spro[i+1] = spro[i] + pro[i];
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(spro);
		
		double ret = 0;
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			ret += st.min(f, t);
//			tr(i, st.min(f, t));
		}
		out.printf("%.9f\n", ret);
	}
	
	public static class SegmentTreeRMQ {
		public int M, H, N, B;
		public double[] stmax;
		public double[] stmin;
		public double[] stsub;
		
		public SegmentTreeRMQ(double[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			stmax = new double[M];
			stmin = new double[M];
			stsub = new double[M];
			for(int i = 0;i < N;i++){
				stmax[H+i] = a[i];
				stmin[H+i] = a[i];
				stsub[H+i] = 0;
			}
			Arrays.fill(stmax, H+N, M, Double.NEGATIVE_INFINITY);
			Arrays.fill(stmin, H+N, M, Double.POSITIVE_INFINITY);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			stmax[i] = Math.max(stmax[2*i], stmax[2*i+1]);
			stmin[i] = Math.min(stmin[2*i], stmin[2*i+1]);
			stsub[i] = Math.max(Math.max(stsub[2*i], stsub[2*i+1]), stmax[2*i+1]-stmin[2*i]);
		}
		
		public double min(int f, int t){ return min(f, t, B)[2];}
		
		public double[] min(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new double[]{stmax[(H|f)>>b], stmin[(H|f)>>b], stsub[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				double[] left = min(f, w-1, b);
				double[] right = min(w, t, b);
				return new double[]{
						Math.max(left[0], right[0]),
						Math.min(left[1], right[1]),
						Math.max(Math.max(left[2], right[2]), right[0]-left[1])
				};
			}else{
				return min(f, t, b);
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