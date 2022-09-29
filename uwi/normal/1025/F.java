//package round505;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++)co[i] = na(2);
		
		long ans = 0;
		for(int i = 0;i < n;i++){
			int[][] rco = relativeCo(co, 0, n, i);
			ans += process(rco);
		}
		out.println(ans/2);
	}
	
	long process(int[][] co)
	{
		int n = co.length;
		Arrays.sort(co, compArgi);
//		mergesort(co, 0, n);
		
		int[] temp = new int[2];
		long ret = 0;
		int p = 0;
		while(p < n && (co[p][1] > 0 || co[p][1] == 0 && co[p][0] > 0))p++;
		for(int i = 0;i < n;i++){
			if(p == n)p = 0;
			int[] c = co[i];
			temp[0] = -c[0]; temp[1] = -c[1];
			while(p != i && ((long)c[0]*co[p][1]-(long)c[1]*co[p][0]) > 0){
				if(++p == n)p = 0;
			}
			int npos = p-i-1;
			if(npos < 0)npos += co.length;
			int nneg = n-1-npos;
			
			ret += (long)npos * (npos - 1) / 2 * nneg * (nneg - 1) / 2;
		}
		return ret;
	}
	
	private static int[][] stemp = new int[10000][];
	
	public static void mergesort(int[][] a, int s, int e)
	{
		if(e - s <= 1)return;
		int h = s+e>>1;
		mergesort(a, s, h);
		mergesort(a, h, e);
		int p = 0;
		int i= s, j = h;
		for(;i < h && j < e;)stemp[p++] = compArgi.compare(a[i], a[j]) < 0 ? a[i++] : a[j++];
//		for(;i < h && j < e;)stemp[p++] = compare(a[i], a[j]) < 0 ? a[i++] : a[j++];
		while(i < h)stemp[p++] = a[i++];
		while(j < e)stemp[p++] = a[j++];
		System.arraycopy(stemp, 0, a, s, e-s);
	}

	
	public static long compare(int[] a, int[] b)
	{
		long ax = a[0], ay = a[1];
		long bx = b[0], by = b[1];
		int za = ay > 0 || ay == 0 && ax > 0 ? 0 : 1;
		int zb = by > 0 || by == 0 && bx > 0 ? 0 : 1;
		if(za != zb)return za - zb;
		if(ay*bx-ax*by != 0)return (ay*bx-ax*by);
		return ((ax*ax+ay*ay)-(bx*bx+by*by));
	}
	
	public static Comparator<int[]> compArgi = new Comparator<int[]>(){
		public int compare(int[] a, int[] b)
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

	
	int[][] relativeCo(int[][] co, int l, int r, int o)
	{
		int n = l <= o && o < r ? r-l-1 : r-l;
		int[][] rco = new int[n][];
		int p = 0;
		for(int i = l;i < r;i++){
			if(i == o)continue;
			rco[p++] = new int[]{co[i][0] - co[o][0], co[i][1] - co[o][1]};
		}
		return rco;
	}
	
	void run() throws Exception
	{
//		int n = 2000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
//			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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