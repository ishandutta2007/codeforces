//package round491;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long n = nl();
		int m = Long.toString(n).length();
		int[] f = new int[10];
		for(char c : Long.toString(n).toCharArray()){
			f[c-'0']++;
		}
		
		int M = 1;
		for(int i = 0;i < 10;i++){
			f[i]++;
			M *= f[i];
		}
		
		long[] dp = new long[M];
		dp[0] = 1;
		long ans = 0;
		for(int k = 1;k <= m;k++){
			long[] ndp = new long[M];
			
			int[] b = new int[10];
			int id = 0;
			do{
				for(int j = 0;j <= 9;j++){
					if(b[j] + 1 < f[j]){
						b[j]++;
						if(j >= 1){
							boolean ok = true;
							for(int t = 0;t < 10;t++){
								if(f[t] == 1 || b[t] >= 1){
								}else{
									ok = false;
								}
							}
							if(ok)ans += dp[id];
						}
						ndp[(int)encInc(b, f)] += dp[id];
						b[j]--;
					}
				}
				id++;
			}while(inc(b, f));
			dp = ndp;
		}
		out.println(ans);
	}

public static boolean inc(int[] b, int[] a)
{
	for(int i = b.length-1;i >= 0;i--){
		if(++b[i] < a[i])return true;
		b[i] = 0;
	}
	return false;
}

	
	public static long encInc(int[] a, int[] lim)
	{
		long code = 0;
		for(int i = 0;i < a.length;i++){
			code = code * lim[i] + a[i];
		}
		return code;
	}
	
	public static int[] decInc(long code, int[] lim)
	{
		int n = lim.length;
		int[] a = new int[n];
		for(int i = n-1;i >= 0;i--){
			a[i] = (int)(code % lim[i]);
			code /= lim[i];
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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