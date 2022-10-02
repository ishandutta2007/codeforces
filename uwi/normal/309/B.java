//package croc2013.f;
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
		int n = ni(), r = ni(), c = ni();
		String[] w = new String[n];
		for(int i = 0;i < n;i++){
			w[i] = ns();
		}
		
		int[][] reach = new int[23][n];
		int[] len = new int[n+1];
		len[0] = 0;
		for(int i = 1;i <= n;i++){
			len[i] = len[i-1] + w[i-1].length() + 1;
		}
		int p = 1;
		for(int i = 0;i < n;i++){
			while(p <= n && len[p] - len[i] - 1 <= c)p++;
			reach[0][i] = p-1;
		}
		for(int i = 1;i <= 22;i++){
			for(int j = 0;j < n;j++){
				if(reach[i-1][j] == n){
					reach[i][j] = n;
				}else{
					reach[i][j] = reach[i-1][reach[i-1][j]];
				}
			}
		}
		int[] kreach = new int[n];
		for(int j = 0;j < n;j++){
			int to = j;
			for(int k = 0;k < 23 && to < n;k++){
				if(r<<31-k<0){
					to = reach[k][to];
				}
			}
			kreach[j] = to;
		}
		int max = 0;
		int maxi = -1;
		for(int i = 0;i < n;i++){
			if(kreach[i]-i > max){
				max = kreach[i]-i;
				maxi = i;
			}
		}
		
		if(maxi == -1)return;
		int cur = maxi;
		for(int i = 0;i < r;i++){
			if(cur == n || cur == reach[0][cur])break;
			for(int j = cur;j < reach[0][cur];j++){
				if(j > cur)out.print(" ");
				out.print(w[j]);
			}
			out.println();
			cur = reach[0][cur];
		}
	}
	
	void run() throws Exception
	{
//		int n = 1000000, r = 1000, c = 1000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(r + " ");
//		sb.append(c + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(100000) + " ");
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