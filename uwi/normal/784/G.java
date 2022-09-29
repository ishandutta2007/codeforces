//package af2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String s = ns();
		Parser3 p = new Parser3();
		try {
			long x = p.eval(s.toCharArray());
			for(char c : Long.toString(x).toCharArray()){
				for(int i = 0;i < c;i++){
					out.print("+");
				}
				out.println(".>");
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static class Parser3 {
		// exp = exp2 ([+-] exp2)*
		// exp2 = exp3 ([*] exp3)*
		// exp3 = exp4 | '(' exp ')'
		// exp4 = -*digit+{[\.]digit+}
		// digit = [0-9]
		char[] str;
		int pos;
		int n;
		
		public long eval(char[] str) throws Exception
		{
			this.str = str;
			pos = 0;
			n = this.str.length;
			long ret = exp();
			if(pos < n)throw new AssertionError(-1);
			return ret;
		}
		
		public long exp() throws Exception
		{
			long v = exp2();
			while(pos < n && (str[pos] == '+' || str[pos] == '-')){
				char op = str[pos];
				pos++;
				if(pos >= n)throw new AssertionError(pos);
				long w = exp2();
				if(op == '+'){
					v += w;
				}else{
					v -= w;
				}
			}
			return v;
		}
		
		public long exp2() throws Exception
		{
			long v = exp3();
			while(pos < n && (str[pos] == '*')){
//				char op = str[pos];
				pos++;
				if(pos >= n)throw new AssertionError(pos);
				long w = exp3();
				v *= w;
			}
			return v;
		}
		
		public long exp3() throws Exception
		{
			if(pos < n && str[pos] == '('){
				pos++;
				long v = exp();
				if(!(pos < n && str[pos] == ')'))throw new AssertionError(pos);
				pos++;
				return v;
			}else{
				return exp4();
			}
		}
		
		public long exp4() throws Exception
		{
			boolean minus = false;
			while(pos < n && str[pos] == '-'){
				minus = !minus;
				pos++;
			}
			boolean present = false;
			long v = 0;
			while(pos < n && str[pos] >= '0' && str[pos] <= '9'){
				v = v * 10 + digit();
				present = true;
			}
			if(!present)throw new AssertionError(pos);
			if(minus)v = -v;
			return v;
		}
		
		public long digit() throws Exception
		{
			if(pos == n)throw new AssertionError(pos);
			return str[pos++] - '0';
		}
		
		public static void main(String[] args) throws Exception {
			System.out.println(new Parser3().eval("50/(((98-9)/48))".toCharArray()));
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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