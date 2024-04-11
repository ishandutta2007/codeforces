//package abbyy3;
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
		int n = ni(), m = ni();
		int[][] map = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				map[i][j] = ni();
			}
		}
		
		int[][] dp = new int[n][1<<m];
		for(int i = 0;i < n;i++){
			Arrays.fill(dp[i], -99999);
		}
		dp[0] = makeRow(map[0]);
		for(int i = 1;i < n;i++){
			int[] row = makeRow(map[i]);
			for(int j = 0;j < 1<<m;j++){
				for(int k = 0;k < 1<<m;k++){ // k->j
					int inv = (~k&(1<<m)-1);
					if((inv&j) == inv){
						int nex = row[j^inv] + dp[i-1][k];
						for(int l = 0;l < m;l++){
							if(inv<<31-l<0 && map[i-1][l] == map[i][l]){
								nex++;
							}
						}
						dp[i][j] = Math.max(dp[i][j], nex);
					}
				}
			}
		}
		out.println(n*m/2-dp[n-1][(1<<m)-1]);
	}
	
	int[] makeRow(int[] r)
	{
		int m = r.length;
		int[] row = new int[1<<m];
		Arrays.fill(row, -99999);
		row[0] = 0;
		for(int i = 0;i < 1<<m;i++){
			for(int j = 3, k = 0;j < 1<<m;j*=2, k++){
				if((i&j) == j){
					if(row[i^j] != -99999){
						row[i] = row[i^j] + (r[k] == r[k+1] ? 1 : 0);
					}
					break;
				}
			}
		}
		return row;
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