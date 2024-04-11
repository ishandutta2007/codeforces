//package round104;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "13 7 7477747774747 count count count count count switch 4 11 count";
//	String INPUT = "13 1 7474474447447 count";
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[] c = ns(n);
		SegmentTreeRXQ st = new SegmentTreeRXQ(c);
//		tbin(st.len44);
//		tbin(st.len47);
//		tbin(st.len74);
//		tbin(st.len77);
		for(int i = 0;i < m;i++){
			char[] com = ns(6);
			if(com[0] == 'c'){
				out.println(st.sum());
			}else{
				int l = ni(), r = ni();
				st.xorRange(l-1, r-1);
			}
		}
	}
	
	public static class SegmentTreeRXQ {
		public int M, H, N, B;
		public boolean[] st;
		public boolean[] plus;
		public int[] len44;
		public int[] len47;
		public int[] len74;
		public int[] len77;
		
		public SegmentTreeRXQ(char[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			st = new boolean[H];
			plus = new boolean[H];
			len44 = new int[M];
			len47 = new int[M];
			len74 = new int[M];
			len77 = new int[M];
			for(int i = 0;i < N;i++){
				st[i] = a[i] == '7';
				if(st[i]){
					len44[H+i] = 0;
					len47[H+i] = 0;
					len74[H+i] = 0;
					len77[H+i] = 1;
				}else{
					len44[H+i] = 1;
					len47[H+i] = 0;
					len74[H+i] = 0;
					len77[H+i] = 0;
				}
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			if(!plus[i]){
				len44[i] = len44[2*i] + len44[2*i+1];
				len77[i] = len77[2*i] + len77[2*i+1];
				{
					int max = 0;
					max = Math.max(max, len44[2*i] + len47[2*i+1]);
					max = Math.max(max, len44[2*i] + len77[2*i+1]);
					max = Math.max(max, len47[2*i] + len77[2*i+1]);
					len47[i] = max;
				}
				{
					int max = 0;
					max = Math.max(max, len74[2*i] + len44[2*i+1]);
					max = Math.max(max, len77[2*i] + len44[2*i+1]);
					max = Math.max(max, len77[2*i] + len74[2*i+1]);
					len74[i] = max;
				}
			}else{
				len77[i] = len44[2*i] + len44[2*i+1];
				len44[i] = len77[2*i] + len77[2*i+1];
				{
					int max = 0;
					max = Math.max(max, len44[2*i] + len47[2*i+1]);
					max = Math.max(max, len44[2*i] + len77[2*i+1]);
					max = Math.max(max, len47[2*i] + len77[2*i+1]);
					len74[i] = max;
				}
				{
					int max = 0;
					max = Math.max(max, len74[2*i] + len44[2*i+1]);
					max = Math.max(max, len77[2*i] + len44[2*i+1]);
					max = Math.max(max, len77[2*i] + len74[2*i+1]);
					len47[i] = max;
				}
			}
		}
		
		public void xorRange(int f, int t) { xorRange(f, t, B); }
		
		protected void xorRange(int f, int t, int b)
		{
			if(b == 0){
				st[f] = !st[f];
				if(st[f]){
					len44[H+f] = 0;
					len47[H+f] = 0;
					len74[H+f] = 0;
					len77[H+f] = 1;
				}else{
					len44[H+f] = 1;
					len47[H+f] = 0;
					len74[H+f] = 0;
					len77[H+f] = 0;
				}
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H|f)>>b] = !plus[(H|f)>>b];
				propagate((H|f)>>b);
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
		
		public int sum()
		{
			return Math.max(Math.max(len44[1], len47[1]), len77[1]);
		}
	}
	
	public void tbin(int[] x)
	{
		for(int f = 1, t = 2;t <= x.length;f *= 2, t *= 2){
			tr(Arrays.copyOfRange(x, f, t));
		}
		tr();
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 300000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextBoolean() ? 7 : 4);
//		}
//		sb.append(" ");
//		for(int i = 0;i < m;i++){
////			if(gen.nextBoolean()){
//				int a = gen.nextInt(n)+1;
//				int b = gen.nextInt(n)+1;
//				if(a > b){
//					int d = a; a = b; b = d;
//				}
//				sb.append("switch " + a + " " + b + " ");
////			}else{
////				sb.append("count ");
////			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
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