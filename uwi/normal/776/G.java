//package round400;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] co = new int[16][65536];
		int[][] cocum = new int[16][65537];
		int[] f = new int[16];
		for(int max = 0;max <= 15;max++){
			for(int i = 0;i < 65536;i++){
				int lmax = max;
				lmax = Math.max(lmax, i&15);
				lmax = Math.max(lmax, i>>>4&15);
				lmax = Math.max(lmax, i>>>8&15);
				lmax = Math.max(lmax, i>>>12&15);
				if(i > (i^1<<lmax)){
					co[max][i] = 1;
					f[max]++;
				}
			}
			for(int i = 0;i < 65536;i++){
				cocum[max][i+1] = cocum[max][i] + co[max][i];
			}
		}
		for(int Q = ni();Q > 0;Q--){
			long s = Long.parseLong(ns(), 16);
			long t = Long.parseLong(ns(), 16);
			if(s>>>16 == t>>>16){
				int max = 0;
				for(long x = s>>>16;x > 0;x>>>=4){
					max = Math.max(max, (int)(x&15));
				}
				out.println(
						cocum[max][(int)(t&65535)+1]-
						cocum[max][(int)(s&65535)]
								);
			}else{
				long ret = 0;
				{
					int max = 0;
					for(long x = s>>>16;x > 0;x>>>=4){
						max = Math.max(max, (int)(x&15));
					}
					ret += cocum[max][65536]-cocum[max][(int)(s&65535)];
				}
				{
					int max = 0;
					for(long x = t>>>16;x > 0;x>>>=4){
						max = Math.max(max, (int)(x&15));
					}
					ret += cocum[max][(int)(t&65535)+1];
				}
				{
					long[] fr = count((t>>>16)-1);
					for(int i = 0;i < 16;i++){
						ret += f[i]*fr[i];
					}
				}
				{
					long[] fr = count((s>>>16));
					for(int i = 0;i < 16;i++){
						ret -= f[i]*fr[i];
					}
				}
				out.println(ret);
			}
		}
	}
	
	long[] count(long x)
	{
		char[] s = Long.toString(x, 16).toCharArray();
		int n = s.length;
		long[][] dp = new long[n+1][16];
		int edge = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= 15;j++){
				for(int k = 0;k <= 15;k++){
					dp[i+1][Math.max(j,k)] += dp[i][j];
				}
			}
			char d = s[i];
			int dv = 0;
			if(d >= '0' && d <= '9'){
				dv = d-'0';
			}else{
				dv = d-'a'+10;
			}
			for(int j = 0;j < dv;j++){
				dp[i+1][Math.max(edge, j)] += 1;
			}
			edge = Math.max(edge, dv);
		}
		dp[n][edge] += 1;
		
		return dp[n];
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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