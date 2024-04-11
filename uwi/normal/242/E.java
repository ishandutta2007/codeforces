//package round149;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		
		SegmentTreeRXSQ[] st = new SegmentTreeRXSQ[20];
		int[] b = new int[n];
		for(int i = 0;i < 20;i++){
			for(int j = 0;j < n;j++){
				b[j] = a[j]>>>i&1;
			}
			st[i] = new SegmentTreeRXSQ(b);
		}
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1;
				long sum = 0;
				for(int j = 20-1;j >= 0;j--){
					sum = sum * 2 + st[j].sumRange(l, r);
				}
				out.println(sum);
			}else{
				int l = ni()-1, r = ni()-1, x = ni();
				for(int j = 20-1;j >= 0;j--){
					if(x<<31-j<0)st[j].xorRange(l, r);
				}
			}
		}
	}
	
	public static class SegmentTreeRXSQ {
		public int M, H, N, B;
		public boolean[] plus;
		public int[] ct;
		
		public SegmentTreeRXSQ(int n)
		{
			N = n;
			H = Integer.highestOneBit(Math.max(n,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			plus = new boolean[H];
			ct = new int[M];
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public SegmentTreeRXSQ(int[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			plus = new boolean[M];
			ct = new int[M];
			for(int i = 0;i < N;i++){
				ct[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			if(plus[i]){
				int q = H / Integer.highestOneBit(i);
				ct[i] = q - (ct[2*i] + ct[2*i+1]);
			}else{
				ct[i] = ct[2*i] + ct[2*i+1];
			}
		}
		
		public void xorRange(int f, int t) { xorRange(f, t, B); }
		
		protected void xorRange(int f, int t, int b)
		{
			if(b == 0){
				ct[H+f] = 1 - ct[H+f];
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H+f)>>>b] ^= true;
				propagate((H+f)>>b);
			}else{
				b--;
				if((f^t)<<31-b<0){
					int w = t>>b<<b;
					xorRange(f, w-1, b);
					xorRange(w, t, b);
				}else{
					xorRange(f, t, b);
				}
				propagate((H|f)>>b+1);
			}
		}
		
		public int sumRange(int f, int t) { return sumRange(f, t, B); }
		
		protected int sumRange(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return ct[(H+f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int A = sumRange(f, w-1, b);
				int B = sumRange(w, t, b);
				return plus[(H+f)>>b+1] ? (t-f+1)-(A+B) : A+B;
			}else{
				int A = sumRange(f, t, b);
				return plus[(H+f)>>b+1] ? (t-f+1)-A : A;
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
		new E3().run();
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