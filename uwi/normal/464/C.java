//package round265;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int Q = ni();
		char[][] ts = new char[Q][];
		for(int i = 0;i < Q;i++){
			char[] t = ns().toCharArray();
			ts[i] = t;
		}
		
		for(int i = 0;i < 10;i++){
			Arrays.fill(len[i], -1);
		}
		for(int i = 0;i < 10;i++){
			dfs(i, 0, ts);
		}
		
		long ret = 0;
		for(int i = 0;i < s.length;i++){
			int ld = s[i]-'0';
			ret = (ret * pow(10, len[ld][0], mod) + val[ld][0]) % mod;
		}
		out.println(ret);
	}
	
	void dfs(int dig, int pos, char[][] ts)
	{
		if(pos == ts.length){
			val[dig][pos] = dig;
			len[dig][pos] = 1;
			return;
		}
		if(len[dig][pos] != -1)return;
		if(ts[pos][0]-'0' != dig){
			dfs(dig, pos+1, ts);
			val[dig][pos] = val[dig][pos+1];
			len[dig][pos] = len[dig][pos+1];
		}else{
			long ret = 0;
			int rlen = 0;
			for(int i = 3;i < ts[pos].length;i++){
				int ld = ts[pos][i]-'0';
				dfs(ld, pos+1, ts);
				ret = (ret * pow(10, len[ld][pos+1], mod) + val[ld][pos+1]) % mod;
				rlen += len[ld][pos+1];
				if(rlen >= mod-1)rlen -= mod-1;
			}
			val[dig][pos] = ret;
			len[dig][pos] = rlen;
		}
	}
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
	}
	
	int mod = 1000000007;
	
	long[][] val = new long[10][100003];
	long[][] len = new long[10][100003];
	
	void run() throws Exception
	{
		int n = 50000, m = 99999;
		Random gen = new Random(1);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(gen.nextInt(10));
		}
		sb.append("\n");
		for(int i = 0;i < n;i++){
			sb.append(1);
			sb.append("->");
			for(int j = 0;j < 2;j++){
				sb.append(1);
			}
			sb.append("\n");
		}
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(10));
//			sb.append("->");
//			for(int j = 0;j < 300;j++){
//				sb.append(gen.nextInt(10));
//			}
//			sb.append("\n");
//		}
		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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