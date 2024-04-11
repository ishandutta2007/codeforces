//package round556;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		char[] s = ns(2*n);
		SegmentTree4TupleMaxSum st = new SegmentTree4TupleMaxSum(s);
		
//		tr(st.whole);
//		tr(st.pre);
//		tr(st.suf);
//		tr(st.inner);
		out.println(st.inner[1]);
		for(int i = 0;i < Q;i++){
			int x = ni()-1, y = ni()-1;
			for(int u : new int[]{x, y}){
				if(s[u] == '('){
					s[u] = ')';
				}else{
					s[u] = '(';
				}
				st.update(u, s[u]);
			}
//			tr(new String(s));
			out.println(st.inner[1]);
		}
	}
	
	// (a,b) + (c,d)
	// b >= c -> (a, b-c+d) d-c
	// b < c -> (a+c-b, d)
	// a+ba-b
	
	// )))))
	// )((((
	// (((((((
	// )
	
	// ))))))(((
	// ))))(
	
	// ))))))
	// )))))))
	
	public static class SegmentTree4TupleMaxSum {
		public int M, H, N;
		public Seg pre, suf, whole;
		public int[] inner; // max(a+b)
		public long I = Long.MIN_VALUE/2 + 30000;
		public int T = 30;
		
		public static class Seg
		{
			// max a+b
			// max a-b
			// max b-a
			AB[] abs;
			public Seg(int u, int n) {
				abs = new AB[u];
				for(int i = 0;i < u;i++){
					abs[i] = new AB(n);
				}
			}
			@Override
			public String toString() {
				return "Seg [" + (abs != null ? "abs=" + Arrays.toString(abs) : "") + "]";
			}
			
			
		}
		
		public static class AB
		{
			int[] a, b;
			public AB(int n)
			{
				a = new int[n];
				b = new int[n];
			}
			@Override
			public String toString() {
				return "AB [" + (a != null ? "a=" + Arrays.toString(a) + ", " : "")
						+ (b != null ? "b=" + Arrays.toString(b) : "") + "]";
			}
		}
		
		public SegmentTree4TupleMaxSum(char[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			pre = new Seg(3, M+T);
			suf = new Seg(3, M+T);
			whole = new Seg(1, M+T);
			inner = new int[M+T];
			// a:), b:(
			for(int i = 0;i < H;i++){
				if(i < N){
					inner[H+i] = 1;
					if(a[i] == '('){
						pre.abs[0].b[H+i] = 1;
						pre.abs[2].b[H+i] = 1;
						suf.abs[0].b[H+i] = 1;
						suf.abs[2].b[H+i] = 1;
						whole.abs[0].b[H+i] = 1;
					}else{
						pre.abs[0].a[H+i] = 1;
						pre.abs[1].a[H+i] = 1;
						suf.abs[0].a[H+i] = 1;
						suf.abs[1].a[H+i] = 1;
						whole.abs[0].a[H+i] = 1;
					}
				}
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		private void propagate(int i)
		{
			propNC(i, 2*i, 2*i+1);
		}
		
		// (a,b) + (c,d)
		// b >= c -> (a, b-c+d) d-c
		// b < c -> (a+c-b, d)
		int[] temp = new int[2];
		
		void go(int a, int b, int c, int d)
		{
			if(b >= c){
				temp[0] = a; temp[1] = b-c+d;
			}else{
				temp[0] = a+c-b; temp[1] = d;
			}
		}
		
		private void propNC(int p, int l, int r)
		{
			{
				for(int i = 0;i < 1;i++){
					whole.abs[i].a[p] = 0;
					whole.abs[i].b[p] = 0;
				}
				for(int i = 0;i < 1;i++){
					for(int j = 0;j < 1;j++){
						go(whole.abs[i].a[l], whole.abs[i].b[l], 
								whole.abs[j].a[r], whole.abs[j].b[r]);
						whole.abs[0].a[p] = temp[0];
						whole.abs[0].b[p] = temp[1];
					}
				}
			}
			{
				for(int i = 0;i < 3;i++){
					suf.abs[i].a[p] = suf.abs[i].a[r];
					suf.abs[i].b[p] = suf.abs[i].b[r];
				}
				for(int i = 0;i < 3;i++){
					for(int j = 0;j < 1;j++){
						go(suf.abs[i].a[l], suf.abs[i].b[l], 
								whole.abs[j].a[r], whole.abs[j].b[r]);
						if(temp[0] + temp[1] > suf.abs[0].a[p] + suf.abs[0].b[p]){
							suf.abs[0].a[p] = temp[0];
							suf.abs[0].b[p] = temp[1];
						}
						if(temp[0] - temp[1] > suf.abs[1].a[p] - suf.abs[1].b[p]){
							suf.abs[1].a[p] = temp[0];
							suf.abs[1].b[p] = temp[1];
						}
						if(temp[1] - temp[0] > suf.abs[2].b[p] - suf.abs[2].a[p]){
							suf.abs[2].a[p] = temp[0];
							suf.abs[2].b[p] = temp[1];
						}
					}
				}
			}
			{
				for(int i = 0;i < 3;i++){
					pre.abs[i].a[p] = pre.abs[i].a[l];
					pre.abs[i].b[p] = pre.abs[i].b[l];
				}
				for(int i = 0;i < 1;i++){
					for(int j = 0;j < 3;j++){
						go(whole.abs[i].a[l], whole.abs[i].b[l], 
								pre.abs[j].a[r], pre.abs[j].b[r]);
						if(temp[0] + temp[1] > pre.abs[0].a[p] + pre.abs[0].b[p]){
							pre.abs[0].a[p] = temp[0];
							pre.abs[0].b[p] = temp[1];
						}
						if(temp[0] - temp[1] > pre.abs[1].a[p] - pre.abs[1].b[p]){
							pre.abs[1].a[p] = temp[0];
							pre.abs[1].b[p] = temp[1];
						}
						if(temp[1] - temp[0] > pre.abs[2].b[p] - pre.abs[2].a[p]){
							pre.abs[2].a[p] = temp[0];
							pre.abs[2].b[p] = temp[1];
						}
					}
				}
			}
			
			inner[p] = Math.max(inner[l], inner[r]);
			{
				for(int i = 0;i < 3;i++){
					for(int j = 0;j < 3;j++){
						go(suf.abs[i].a[l], suf.abs[i].b[l], 
								pre.abs[j].a[r], pre.abs[j].b[r]);
						if(temp[0] + temp[1] > inner[p]){
							inner[p] = temp[0] + temp[1];
						}
					}
				}
			}
		}
		
		public void update(int pos, char v)
		{
			inner[H+pos] = 1;
			if(v == '('){
				pre.abs[0].a[H+pos] = 0;
				pre.abs[1].a[H+pos] = 0;
				suf.abs[0].a[H+pos] = 0;
				suf.abs[1].a[H+pos] = 0;
				whole.abs[0].a[H+pos] = 0;
				
				pre.abs[0].b[H+pos] = 1;
				pre.abs[2].b[H+pos] = 1;
				suf.abs[0].b[H+pos] = 1;
				suf.abs[2].b[H+pos] = 1;
				whole.abs[0].b[H+pos] = 1;
			}else{
				pre.abs[0].b[H+pos] = 0;
				pre.abs[2].b[H+pos] = 0;
				suf.abs[0].b[H+pos] = 0;
				suf.abs[2].b[H+pos] = 0;
				whole.abs[0].b[H+pos] = 0;
				
				pre.abs[0].a[H+pos] = 1;
				pre.abs[1].a[H+pos] = 1;
				suf.abs[0].a[H+pos] = 1;
				suf.abs[1].a[H+pos] = 1;
				whole.abs[0].a[H+pos] = 1;
			}
			for(int x = H+pos>>>1;x != 0;x>>>=1)propagate(x);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}