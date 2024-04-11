//package round317;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni(), b = ni(), c = ni();
		int L = ni();
		long ret = 0;
		for(int i = 0;i <= L;i++){
			int aa = a + i;
			int F = L-i;
			long large = mountain(Math.min(aa+b-1, c+F), Math.min(aa+b+F-1, c), F);
			
			large -= p1(c-1, aa+b-1, F);
			
			long small = 0;
			if(aa-b > 0 && aa-b-F <= 0){
				small += mountain(Math.min(aa-b, c+F), 0, aa-b);
				small += mountain(0, Math.min(-(aa-b-F), c), F-(aa-b));
				
				small -= p1(c-1, 0, aa-b);
				small -= p1(c-1, 0, F-(aa-b));
			}else if(aa-b > 0){
				small += mountain(Math.min(aa-b, c+F), Math.min(aa-b-F, c), F);
				small -= p1(c-1, aa-b-F, F);
			}else{
				small += mountain(Math.min(-(aa-b), c+F), Math.min(-(aa-b-F), c), F);
				small -= p1(c-1, -(aa-b), F);
			}
			
			ret += large - small;
		}
		out.println(ret);
	}
	
	long p1(long con, long left, long w)
	{
		if(left+w <= con){
			return (left+1)*(w+1)+w*(w+1)/2;
		}else if(left >= con){
			return (con+1)*(w+1);
		}else{
			long x = con-left;
			return (con+1)*(w+1)-x*(x+1)/2;
		}
	}
	
	// [0,w]
	long mountain(long left, long right, long w)
	{
		if(left + w == right){
			return (left+1)*(w+1)+w*(w+1)/2;
		}
		if(right + w == left){
			return (right+1)*(w+1)+w*(w+1)/2;
		}
		// left+x=right+w-x
		// x=(right+w-left)/2
		long xnum = right+w-left;
		long L = (xnum-1)/2;
		return (left+1) * (L+1) + L*(L+1)/2
				 + (right+1) * (w+1-(L+1)) + (w-L-1)*(w-L)/2;
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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