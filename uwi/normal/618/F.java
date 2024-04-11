//package round341;
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
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		long sa = 0;
		for(int v : a)sa += v;
		long sb = 0;
		for(int v : a)sb += v;
		boolean rev = false;
		if(sa > sb){
			int[] c = a; a = b; b = c;
			rev = true;
		}
		long[] ca = new long[n+1];
		for(int i = 0;i < n;i++)ca[i+1] = ca[i] + a[i];
		long[] cb = new long[n+1];
		for(int i = 0;i < n;i++)cb[i+1] = cb[i] + b[i];
		
		int[] last = new int[n];
		int[] lastp = new int[n];
		Arrays.fill(last, -1);
		Arrays.fill(lastp, -1);
		int p = 0;
		for(int i = 0;i <= n;i++){
			while(p <= n && ca[i]-cb[p] >= 0)p++;
			int ind = (int)(ca[i]-cb[p-1]);
			if(last[ind] >= 0){
				if(!rev){
					out.println(i-last[ind]);
					for(int j = last[ind];j < i;j++){
						out.print(j+1 + " ");
					}
					out.println();
					out.println((p-1)-(lastp[ind]-1));
					for(int j = lastp[ind]-1;j < p-1;j++){
						out.print(j+1 + " ");
					}
					out.println();
				}else{
					out.println((p-1)-(lastp[ind]-1));
					for(int j = lastp[ind]-1;j < p-1;j++){
						out.print(j+1 + " ");
					}
					out.println();
					out.println(i-last[ind]);
					for(int j = last[ind];j < i;j++){
						out.print(j+1 + " ");
					}
					out.println();
				}
				return;
			}
			last[ind] = i;
			lastp[ind] = p;
		}
		throw new RuntimeException();
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