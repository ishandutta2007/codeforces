//package tech2016.elim2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] cum;
	int n;
	
	void solve()
	{
		n = ni();
		cum = new int[n+1];
		for(int i = 0;i < n;i++)cum[i+1] = cum[i] + ni();
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 93;j++){
				for(int l = 0;l < 93;l++){
					Arrays.fill(cache[i][j][l], Integer.MAX_VALUE);
				}
			}
		}
		out.println(dfs(0, n, 1, 0));
	}
	
	int[][][][] cache = new int[2][93][93][4005];
	
	int dfs(int l, int r, int k, int turn)
	{
		if(l >= r)return 0;
		int lk = turn == 0 ? (n-r)-l : l-(n-r);
		int ll = turn == 0 ? l : r;
		int cval = cache[turn][k][lk][ll];
		if(cval != Integer.MAX_VALUE)return cval;
		
		if(turn == 0){
			int val = Integer.MIN_VALUE;
			if(l+k <= r){
				val = Math.max(val, dfs(l+k, r, k, turn^1) + cum[l+k] - cum[l]);
			}
			if(l+k+1 <= r){
				val = Math.max(val, dfs(l+k+1, r, k+1, turn^1) + cum[l+k+1] - cum[l]);
			}
			if(val == Integer.MIN_VALUE)val = 0;
			return cache[turn][k][lk][ll] = val;
		}else{
			int val = Integer.MAX_VALUE;
			if(l+k <= r){
				val = Math.min(val, dfs(l, r-k, k, turn^1) - cum[r] + cum[r-k]);
			}
			if(l+k+1 <= r){
				val = Math.min(val, dfs(l, r-k-1, k+1, turn^1) - cum[r] + cum[r-k-1]);
			}
			if(val == Integer.MAX_VALUE)val = 0;
			return cache[turn][k][lk][ll] = val;
		}
	}
	
	void run() throws Exception
	{
//		Random gen = new Random(1000000009L);
//		StringBuilder sb = new StringBuilder();
//		int n = 4000;
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(200000)-100000 + " ");
////		sb.append((char)(gen.nextInt(2)+'a') + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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