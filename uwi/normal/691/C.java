//package educational.round14;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String s = ns();
		s = rem0(s);
		int ind = s.indexOf('.');
		if(ind == -1){
			pint(s);
		}else{
			s = reml0(s);
			if(s.charAt(s.length()-1) == '.'){
				s = s.substring(0, s.length()-1);
				pint(s);
			}else{
				ind = s.indexOf('.');
				int nz = 0;
				for(int i = 0;i < s.length();i++){
					if(s.charAt(i) != '0' && s.charAt(i) != '.'){
						nz = i;
						break;
					}
				}
				int e = nz < ind ? ind-nz-1 : ind-nz;
				s = s.substring(0, ind) + s.substring(ind+1); // erase dot
				String t = reml0(rem0(s));
				if(e == 0){
					if(t.length() == 1){
						out.printf("%c\n", t.charAt(0));
					}else{
						out.printf("%c.%s\n", t.charAt(0), t.substring(1));
					}
				}else{
					if(t.length() == 1){
						out.printf("%cE%d\n", t.charAt(0), e);
					}else{
						out.printf("%c.%sE%d\n", t.charAt(0), t.substring(1), e);
					}
				}
			}
		}
	}
	
	void pint(String s)
	{
		if(s.length() == 1){
			out.println(s);
		}else{
			String t = reml0(s);
			if(t.length() == 1){
				out.printf("%cE%d\n", t.charAt(0), s.length()-1);
			}else{
				out.printf("%c.%sE%d\n", t.charAt(0), t.substring(1), s.length()-1);
			}
		}
	}
	
	String reml0(String s)
	{
		for(int i = s.length()-1;i >= 0;i--){
			if(s.charAt(i) != '0'){
				return s.substring(0, i+1);
			}
		}
		return "";
	}
	
	String rem0(String s)
	{
		for(int i = 0;i < s.length();i++){
			if(s.charAt(i) != '0'){
				return s.substring(i);
			}
		}
		return "";
	}
	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(10));
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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