//package round503;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 1620
		int n = ni();
		long S = nl();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++)co[i] = new long[] {ni(), ni()};
		Arrays.sort(co, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[1] != b[1])return Long.compare(a[1], b[1]);
				return Long.compare(a[0], b[0]);
			}
		});
		
		long[][] dco = new long[n*(n-1)/2][];
		int p = 0;
		for(int i = 0;i < n;i++) {
			for(int j = i+1;j < n;j++) {
				dco[p++] = new long[] {co[j][0]-co[i][0],co[j][1]-co[i][1], i, j};
			}
		}
		
		int[] ord = new int[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[i] = i;
		Arrays.sort(dco, compArgl);
		
		for(long[] e : dco) {
			int f = find(e, 2*S, co, ord);
			if(f != -1) {
				out.println("Yes");
				out.println(co[(int)e[2]][0] + " " + co[(int)e[2]][1]);
				out.println(co[(int)e[3]][0] + " " + co[(int)e[3]][1]);
				out.println(co[ord[f]][0] + " " + co[ord[f]][1]);
				return;
			}
			
			// exchange
			int s = (int)e[2], t = (int)e[3];
			{int d = ord[iord[s]]; ord[iord[s]] = ord[iord[t]]; ord[iord[t]] = d;}
			{int d = iord[s]; iord[s] = iord[t]; iord[t] = d; }
		}
		out.println("No");
	}
	
	int find(long[] e, long S, long[][] co, int[] ord)
	{
		int n = co.length;
		int low = 0, high = n;
//		for(int u = 0;u < n;u++) {
//			tr(u, S(e[0], e[1], co[ord[u]][0]-co[(int)e[2]][0], co[ord[u]][1]-co[(int)e[2]][1]));
//		}
		while(high - low > 1) {
			int h = high+low>>1;
			long v = S(e[0], e[1], co[ord[h]][0]-co[(int)e[2]][0], co[ord[h]][1]-co[(int)e[2]][1]);
			if(v == S)return h;
			if(v > S){
				high = h;
			}else {
				low = h;
			}
		}
		return -1;
	}
	
	static long S(long ax, long ay, long bx, long by)
	{
		return -ay*bx+ax*by;
	}
	
	public static Comparator<long[]> compArgl = new Comparator<long[]>(){
		public int compare(long[] a, long[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || ay == 0 && ax > 0 ? 0 : 1;
			int zb = by > 0 || by == 0 && bx > 0 ? 0 : 1;
			if(za != zb)return za - zb;
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		}
	};

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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