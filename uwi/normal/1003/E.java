//package round494;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), d = ni(), K = ni();
		if(d > n-1){
			out.println("NO");
			return;
		}
		if(K == 1){
			if(n == 2 && d == 1){
				out.println("YES");
				out.println(1 + " " + 2);
			}else{
				out.println("NO");
			}
		}else if(K == 2){
			if(d == n-1){
				out.println("YES");
				for(int i = 1;i <= n-1;i++){
					out.println(i + " " + (i+1));
				}
			}else{
				out.println("NO");
			}
		}else{
			long lim = 0;
			long round = 1;
			if(d % 2 == 0){
				// k*(k-1)
				lim += round;
				round *= K;
				if(round >= n)round = n;
				lim += round;
				if(lim >= n)lim = n;
				for(int i = 0;i < d/2-1;i++){
					round *= K-1;
					if(round >= n)round = n;
					lim += round;
					if(lim >= n)lim = n;
				}
				if(lim < n){
					out.println("NO");
					return;
				}
				
			}else{
				// k*(k-1)
				round *= 2;
				if(round >= n)round = n;
				lim += round;
				for(int i = 0;i < d/2;i++){
					round *= K-1;
					if(round >= n)round = n;
					lim += round;
					if(lim >= n)lim = n;
				}
				if(lim < n){
					out.println("NO");
					return;
				}
			}
			
			out.println("YES");
			int[] deg = new int[n];
			int[] dep = new int[n];
			for(int i = 0;i < d;i++){
				out.println((i+1) + " " + (i+2));
				deg[i]++;
				deg[i+1]++;
			}
			for(int i = 0;i < d+1;i++){
				dep[i] = Math.min(i, d-i);
			}
			int j = 0;
			for(int i = d+1;i < n;i++){
				while(!(deg[j] < K && dep[j] > 0)){
					j++;
				}
				out.println((j+1) + " " + (i+1));
				deg[j]++;
				deg[i]++;
				dep[i] = dep[j] - 1;
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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