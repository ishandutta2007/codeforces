//package round320;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[] s = ns(n);
		long[] pre = new long[5]; // 0:yet, 1:abc-xabc, 2:xabc-abc, 3:abab-baba, 4:ended
		long[] cur = new long[5]; // 0:yet, 1:abc-xabc, 2:xabc-abc, 3:abab-baba, 4:ended
		pre[0] = 1;
		for(int i = 0;i < n;i++){
			Arrays.fill(cur, 0);
			for(int j = 0;j < m;j++){
				if(s[i] == j + 'a'){
					cur[4] += pre[4];
					cur[0] += pre[0];
				}else{
					if(i+1 < n && s[i+1] == j + 'a'){
						cur[3] += pre[0];
					}else if(i+1 == n){
						cur[4] += pre[0];
					}else{
						cur[1] += pre[0];
					}
				}
				if(i-1 >= 0 && j + 'a' == s[i-1]){
					cur[1] += pre[1];
				}
				if(i-1 >= 0 && j + 'a' != s[i-1] && s[i] == j + 'a'){
					cur[4] += pre[1];
				}
				if(i+1 < n && j + 'a' == s[i+1]){
					cur[2] += pre[2];
				}
				if(i+1 < n && j + 'a' != s[i+1]){
					cur[4] += pre[2];
				}
				if(i+1 == n){
					cur[4] += pre[2];
				}
				if(i+1 < n && i-1 >= 0 && j + 'a' == s[i-1] && j + 'a' == s[i+1]){
					cur[3] += pre[3];
				}
				if(i+1 < n && i-1 >= 0 && j + 'a' == s[i-1] && j + 'a' != s[i+1]){
					cur[1] += pre[3];
				}
				if(i+1 == n){
					cur[4] += pre[3];
				}
				if(i+1 < n && i-1 >= 0 && j + 'a' != s[i-1] && j + 'a' == s[i+1]){
					cur[2] += pre[3];
				}
				if(i+1 < n && i-1 >= 0 && j + 'a' != s[i-1] && j + 'a' != s[i+1]){
					cur[4] += pre[3];
				}
			}
			
			long[] dum = pre; pre = cur; cur = dum;
		}
		out.println(pre[4]+pre[3]+pre[2]+pre[1]);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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