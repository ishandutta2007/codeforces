//package round206;
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
		boolean[][][] dp = new boolean[43][7][7];
		dp[0][0][0] = true;
		for(int i = 0;i < 6;i++){
			for(int j = 42;j >= 0;j--){
				for(int k = 6;k >= 0;k--){
					for(int l = 6;l >= 0;l--){
						if(dp[j][k][l]){
							dp[j+4][k+1][l] = true;
							dp[j+7][k][l+1] = true;
						}
					}
				}
			}
		}
		int[][] repr = new int[43][];
		outer:
		for(int i = 0;i <= 42;i++){
			for(int j = 0;j <= 6;j++){
				for(int k = 0;k <= 6;k++){
					if(dp[i][j][k]){
						repr[i] = new int[]{j, k};
						continue outer;
					}
				}
			}
		}
		
		for(int T = ni();T >= 1;T--){
			long n = nl();
			int[][] lrepr = new int[5][];
			if(n < 1000000000000000000L){
				lrepr[0] = new int[0];
			}else{
				lrepr[1] = new int[0];
			}
			for(long d = 100000000000000000L;d >= 1;d /= 10){
				int[][] nlrepr = new int[5][];
				int di = (int)(n/d%10);
				for(int k = 0;k <= 4;k++){
					if(lrepr[k] != null){
						for(int l = 0;l <= 4;l++){
							int u = k*10+di-l;
							if(u >= 0 && u <= 42 && repr[u] != null && nlrepr[l] == null){
								nlrepr[l] = Arrays.copyOf(lrepr[k], lrepr[k].length+2);
								nlrepr[l][lrepr[k].length] = repr[u][0];
								nlrepr[l][lrepr[k].length+1] = repr[u][1];
							}
						}
					}
				}
				lrepr = nlrepr;
			}
			if(lrepr[0] != null){
				long[] a = new long[6];
				int o = 0;
				for(long d = 100000000000000000L;d >= 1;d /= 10, o+=2){
					int p = 0;
					for(int i = 0;i < lrepr[0][o];i++)a[p++] += 4*d;
					for(int i = 0;i < lrepr[0][o+1];i++)a[p++] += 7*d;
				}
				for(int i = 0;i < 6;i++){
					if(i > 0)out.print(" ");
					out.print(a[i]);
				}
				out.println();
			}else{
				out.println(-1);
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 5000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(Math.abs(gen.nextLong()%1000000000000000000L) + " ");
//		}
//		INPUT = sb.toString();
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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