//package round201;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = ns(101);
		char[] b = ns(101);
		char[] v = ns(101);
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char d = a[i]; a[i] = a[j]; a[j] = d;
		}
		for(int i = 0, j = b.length-1;i < j;i++,j--){
			char d = b[i]; b[i] = b[j]; b[j] = d;
		}
		for(int i = 0, j = v.length-1;i < j;i++,j--){
			char d = v[i]; v[i] = v[j]; v[j] = d;
		}
		
		int[] kmp = kmpTable(v);
		
		int n = a.length, m = b.length, q = v.length;
		int[][][] dp = new int[n+1][m+1][q];
		int[][][] dpcum = new int[n+1][m+1][q];
		int[][][][] prev = new int[n+1][m+1][q][];
		int[][][][] prevcum = new int[n+1][m+1][q][];
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= m;j++){
				Arrays.fill(dp[i][j], -1);
				Arrays.fill(dpcum[i][j], -1);
			}
		}
		dp[0][0][0] = 0;
		for(int j = 0;j <= m;j++){
			dpcum[0][j][0] = 0;
		}
		for(int i = 0;i <= n;i++){
			dpcum[i][0][0] = 0;
		}
		int max = 0;
		int mi = -1, mj = -1, mk = -1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(a[i-1] == b[j-1]){
					for(int k = 0;k < q;k++){
						int c = dpcum[i-1][j-1][k];
						if(c == -1)continue;
						int p = k;
						while(p >= 0 && v[p] != a[i-1])p = kmp[p];
						if(++p < v.length){
//							tr(i, j, k, p, c+1);
							if(c+1 > dp[i][j][p]){
								dp[i][j][p] = c+1;
								prev[i][j][p] = prevcum[i-1][j-1][k];
							}
//							dp[i][j][p] = Math.max(dp[i][j][p], c + 1);
							if(dp[i][j][p] > max){
								max = dp[i][j][p];
								mi = i; mj = j; mk = p;
							}
//							max = Math.max(max, dp[i][j][p]);
						}
					}
				}
				for(int k = 0;k < q;k++){
					int lmax = dpcum[i-1][j][k];
					int[] u = prevcum[i-1][j][k];
					
					if(dpcum[i][j-1][k] > lmax){
						lmax = dpcum[i][j-1][k];
						u = prevcum[i][j-1][k];
					}
					
					if(dp[i][j][k] > lmax){
						lmax = dp[i][j][k];
						u = new int[]{i, j, k};
					}
					
					dpcum[i][j][k] = lmax;
					prevcum[i][j][k] = u;
//					dpcum[i][j][k] = Math.max(Math.max(dpcum[i-1][j][k], dpcum[i][j-1][k]), dp[i][j][k]);
				}
//				tr(i, j, dpcum[i][j], prevcum[i][j]);
			}
		}
		
		if(max == 0){
			out.println(0);
		}else{
			int[] u = new int[]{mi, mj, mk};
			while(u != null){
				out.print(a[u[0]-1]);
				u = prev[u[0]][u[1]][u[2]];
			}
			out.println();
		}
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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