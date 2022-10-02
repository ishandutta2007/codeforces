//package round279;
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
		long a1 = ni(), b1 = ni();
		long a2 = ni(), b2 = ni();
		long s1 = a1 * b1;
		long s2 = a2 * b2;
		long s12 = 0, s13 = 0;
		long s22 = 0, s23 = 0;
		while(s1 % 2 == 0){
			s1 /= 2;
			s12++;
		}
		while(s1 % 3 == 0){
			s1 /= 3;
			s13++;
		}
		while(s2 % 2 == 0){
			s2 /= 2;
			s22++;
		}
		while(s2 % 3 == 0){
			s2 /= 3;
			s23++;
		}
		if(s1 != s2){
			out.println(-1);
		}else{
			long ret = 0;
			long g3 = Math.min(s13, s23);
			ret += s13+s23-g3*2;
			s12 += s13-g3;
			s22 += s23-g3;
			long g2 = Math.min(s12, s22);
			ret += s12+s22-g2*2;
			out.println(ret);
			
			for(int i = 0;i < s13-g3;i++){
				if(a1 % 3 == 0){
					a1 = a1 * 2 / 3;
				}else{
					b1 = b1 * 2 / 3;
				}
			}
			for(int i = 0;i < s12-g2;i++){
				if(a1 % 2 == 0){
					a1 = a1 / 2;
				}else{
					b1 = b1 / 2;
				}
			}
			out.println(a1 + " " + b1);
			for(int i = 0;i < s23-g3;i++){
				if(a2 % 3 == 0){
					a2 = a2 * 2 / 3;
				}else{
					b2 = b2 * 2 / 3;
				}
			}
			for(int i = 0;i < s22-g2;i++){
				if(a2 % 2 == 0){
					a2 = a2 / 2;
				}else{
					b2 = b2 / 2;
				}
			}
			out.println(a2 + " " + b2);
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