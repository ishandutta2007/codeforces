//package sandbox;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
	}
	
	void solve()
	{
		Random gen = new Random();
		for(int T = ni();T > 0;T--){
			int n = ni();
			int[] a = na(n);
			shuffle(a, gen);
			Arrays.sort(a);
			a = uniq(a);
			n = a.length;
			long best = a[n-1];
			for(int i = n-2;i >= 0;i--){
				if(a[n-1] % a[i] != 0){
					best = a[n-1] + a[i];
					break;
				}
			}
			for(int i = 0;i < n && i < 10;i++){
				for(int j = i+1;j < n && j < 10;j++){
					for(int k = j+1;k < n && k < 10;k++){
						int ii = n-1-i, jj = n-1-j, kk = n-1-k;
						if(a[ii] % a[jj] != 0 && a[jj] % a[kk] != 0 && 
								a[ii] % a[kk] != 0){
							best = Math.max(best, a[ii] + a[jj] + a[kk]);
						}
					}
				}
			}
			int last = -1;
			for(int i = n-2;i >= 0;i--){
				if(a[n-1] % a[i] != 0){
					last = i;
					for(int j = i-1;j >= 0;j--){
						if(a[n-1] % a[j] != 0 && a[i] % a[j] != 0){
							best = Math.max(best, a[n-1] + a[i] + a[j]);
						}
					}
					break;
				}
			}
			for(int i = last-1;i >= 0;i--){
				if(a[last] % a[i] != 0){
					for(int j = i-1;j >= 0;j--){
						if(a[last] % a[j] != 0 && a[i] % a[j] != 0){
							best = Math.max(best, a[last] + a[i] + a[j]);
						}
					}
					break;
				}
			}
			
			out.println(best);
		}
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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