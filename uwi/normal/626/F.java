//package evc.elim;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		Arrays.sort(a);
		long[][] pre = new long[n/2+1][K+1];
		long[][] cur = new long[n/2+1][K+1];
		pre[0][0] = 1;
		int mod = 1000000007;
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j <= n/2;j++){
				Arrays.fill(cur[j], 0L);
			}
			if(i < n-1){
				for(int j = 1;j <= n/2;j++){
					for(int k = K;k-(a[i+1]-a[i])*j >= 0;k--){
						pre[j][k] = pre[j][k-(a[i+1]-a[i])*j];
					}
					for(int k = Math.min(K, (a[i+1]-a[i])*j-1);k >= 0;k--){
						pre[j][k] = 0;
					}
				}
			}
			for(int j = 0;j <= n/2;j++){
				// open
				if(j+1 <= n/2){
					for(int k = 0;k <= K;k++){
						cur[j+1][k] += pre[j][k];
						if(cur[j+1][k] >= mod)cur[j+1][k] -= mod;
					}
				}
				// close
				if(j-1 >= 0){
					for(int k = 0;k <= K;k++){
						cur[j-1][k] += pre[j][k] * j;
						cur[j-1][k] %= mod;
					}
				}
				// inner open&close
				for(int k = 0;k <= K;k++){
					cur[j][k] += pre[j][k] * (j+1);
					cur[j][k] %= mod;
				}
			}
			long[][] dum = pre; pre = cur; cur = dum;
		}
		long ret = 0;
		for(int i = 0;i <= K;i++){
			ret += pre[0][i];
		}
		out.println(ret%mod);
	}
	
	void run() throws Exception
	{
//		int n = 200, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(1000 + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(500)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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