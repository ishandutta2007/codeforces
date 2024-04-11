//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class IndiaHacksFD {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		Arrays.sort(a);
		for(int K = 1;K <= 70;K++){
			boolean[][][] dp = new boolean[n+1][K+1][K*(K-1)/2+1];
			dp[0][0][0] = true;
			for(int i = 0;i < n;i++){
				for(int j = 1;j <= K;j++){
					for(int k = Math.max(a[i], j*(j-1)/2);k <= K*(K-1)/2;k++){
						dp[i+1][j][k] |= dp[i][j-1][k-a[i]];
						dp[i+1][j][k] |= dp[i+1][j-1][k-a[i]];
					}
				}
			}
			if(dp[n][K][K*(K-1)/2]){
				int[] f = new int[K];
				int p = 0;
				int ci = n, cj = K, ck = K*(K-1)/2;
				while(ci > 0){
					cj--; ck -= a[ci-1];
					f[p++] = a[ci-1];
					while(!dp[ci-1][cj][ck]){
						cj--; ck -= a[ci-1];
						f[p++] = a[ci-1];
					}
					ci--;
				}
				assert p == K;
				out.println(K);
				arrange(f);
				return;
			}
		}
		out.println("=(");
	}
	
	void arrange(int[] f)
	{
		int n = f.length;
		char[][] ret = new char[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(ret[i], '0');
		}
		int[][] fi = new int[n][];
		for(int i = 0;i < n;i++){
			fi[i] = new int[]{f[i], i};
		}
		for(int i = 0;i < n;i++){
			Arrays.sort(fi, i, n, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});

			for(int j = i+1;j < n;j++){
				if(fi[i][0] > 0){
					ret[fi[i][1]][fi[j][1]] = '1';
					fi[i][0]--;
				}else{
					ret[fi[j][1]][fi[i][1]] = '1';
					fi[j][0]--;
				}
			}
		}
		
		for(char[] row : ret){
//			int ct = 0;
//			for(char c : row)ct += c-'0';
//			tr(ct);
			out.println(new String(row));
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
	
	public static void main(String[] args) throws Exception { new IndiaHacksFD().run(); }
	
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