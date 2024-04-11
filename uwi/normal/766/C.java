//package round396;
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
		int n = ni();
		char[] s = ns(n);
		int[] lim = na(26);
		int[] reach = new int[n];
		// maxlen
		int maxlen = 0;
		for(int i = 0;i < n;i++){
			int len = Integer.MAX_VALUE;
			int j = i;
			for(;j < n;j++){
				len = Math.min(len, lim[s[j]-'a']);
				if(len < j-i+1){
					break;
				}
			}
			reach[i] = j;
			maxlen = Math.max(maxlen, j-i);
		}
		
		// minsp
		int minsp = 0;
		for(int cur = 0;cur < n;cur = reach[cur]){
			minsp++;
		}
		
		long[] dp = new long[n+5];
		addFenwick(dp, 0, 1);
		addFenwick(dp, 1, -1);
		for(int i = 0;i < n;i++){
			int r = reach[i];
			long val = sumFenwick(dp, i);
			addFenwick(dp, i+1, val);
			addFenwick(dp, r+1, -val);
		}
		out.println(sumFenwick(dp, n));
		out.println(maxlen);
		out.println(minsp);
	}
	
	public static final int mod = 1000000007;
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i){
			sum += ft[i];
			if(sum >= mod)sum -= mod;
		}
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		v %= mod;
		if(v < 0)v += mod;
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] += v;
			if(ft[i] >= mod)ft[i] -= mod;
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