//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class P219B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni();
		char[][] map = nm(n,m);
		int[][] cum = new int[n+1][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + map[i][j]-'0';
			}
		}
		int[][][][] o = new int[n][m][n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(int k = i;k < n;k++){
					for(int l = j;l < m;l++){
						o[i][j][k][l] = cum[k+1][l+1] - cum[i][l+1] - cum[k+1][j] + cum[i][j] == 0 ? 1 : 0;
					}
				}
			}
		}
		
		for(int j = 0;j < m;j++){
			for(int l = j;l < m;l++){
				for(int k = 0;k < n;k++){
					for(int i = n-2;i >= 0;i--){
						o[i][j][k][l] += o[i+1][j][k][l];
					}
				}
			}
		}
		for(int j = 0;j < m;j++){
			for(int l = j;l < m;l++){
				for(int i = 0;i < n;i++){
					for(int k = 1;k < n;k++){
						o[i][j][k][l] += o[i][j][k-1][l];
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int k = i;k < n;k++){
				for(int l = 0;l < m;l++){
					for(int j = m-2;j >= 0;j--){
						o[i][j][k][l] += o[i][j+1][k][l];
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int k = i;k < n;k++){
				for(int j = 0;j < m;j++){
					for(int l = 1;l < m;l++){
						o[i][j][k][l] += o[i][j][k][l-1];
					}
				}
			}
		}
		
		for(int i = 0;i < q;i++){
			out.println(o[ni()-1][ni()-1][ni()-1][ni()-1]);
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
	
	public static void main(String[] args) throws Exception { new P219B().run(); }
	
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