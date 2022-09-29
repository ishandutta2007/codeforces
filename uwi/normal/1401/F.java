//package round665;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int ne = ni(), Q = ni();
		int n = 1<<ne;
		int[] a = na(n);
		boolean[] rev = new boolean[ne+1]; // rev of len 2^i
		boolean[] swap = new boolean[ne+1]; // swap of len 2^i and 2^i
		long[] ft = new long[n+5];
		for(int i = 0;i < n;i++)addFenwick(ft, i, a[i]);
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int x = ni()-1, K = ni();
				for(int d = 0;d <= ne;d++){
					if(rev[d]){
						x ^= (1<<d)-1;
					}
					if(swap[d]){
						x ^= 1<<d;
					}
				}
				long cha = K - a[x];
				a[x] = K;
				addFenwick(ft, x, cha);
			}else if(t == 2){
				rev[ni()] ^= true;
			}else if(t == 3){
				swap[ni()] ^= true;
			}else{
				int l = ni()-1, r = ni();
				long ans = 0;
				while(l != 0){
					int f = l&-l;
					if(l+f > r)break;
					int x = l, LV = Integer.numberOfTrailingZeros(f);
					for(int d = LV;d <= ne;d++){
						if(d > LV && rev[d])x ^= (1<<d)-(1<<LV);
						if(swap[d])x ^= 1<<d;
					}
					ans += sumFenwick(ft, x + (1<<LV)-1) - sumFenwick(ft, x-1);
					l += f;
				}
				
				while(l < r){
					int f = r&-r;
					int x = r^f, LV = Integer.numberOfTrailingZeros(f);
					for(int d = LV;d <= ne;d++){
						if(d > LV && rev[d])x ^= (1<<d)-(1<<LV);
						if(swap[d])x ^= 1<<d;
					}
					ans += sumFenwick(ft, x + (1<<LV)-1) - sumFenwick(ft, x-1);
					r -= f;
				}
				
				out.println(ans);
			}
		}
	}
	
	
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int l, int r, long v)
	{
		addFenwick(ft, l, v);
		addFenwick(ft, r, -v);
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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