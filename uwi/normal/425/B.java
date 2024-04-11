//package round243;
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
		int n = ni(), m = ni(), K = ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		
		if(n > m){
			int[][] na = new int[m][n];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					na[j][i] = a[i][j];
				}
			}
			int d = n; n = m; m = d;
			a = na;
		}
		
		if(m <= 20){
			int[] x = new int[n];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					x[i] |= a[i][j]<<j;
				}
			}
			
			int min = 9999;
			for(int i = 0;i < 1<<m;i++){
				int sum = 0;
				for(int j = 0;j < n;j++){
					int q = Integer.bitCount(i^x[j]);
					sum += Math.min(q, m-q);
				}
				min = Math.min(min, sum);
			}
			if(min <= K){
				out.println(min);
			}else{
				out.println(-1);
			}
		}else{
			for(int i = 0;i < n;i++){
				int diff = 0;
				for(int j = 0;j < m;j++){
					diff += a[i][j]^a[0][j];
				}
				if(diff > K){
					for(int j = 0;j < m;j++){
						a[i][j] ^= 1;
					}
				}
			}
			int ret = 0;
			for(int j = 0;j < m;j++){
				int ct = 0;
				for(int i = 0;i < n;i++){
					ct += a[i][j];
				}
				ret += Math.min(ct, n-ct);
			}
			if(ret <= K){
				out.println(ret);
			}else{
				out.println(-1);
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 20, m = 20;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(10 + " ");
//		for(int i = 0;i < n*m;i++){
//			sb.append(gen.nextInt(2) + " ");
//		}
//		INPUT = sb.toString();
		
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