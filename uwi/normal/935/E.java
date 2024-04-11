//package round465;
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
	int pos, len;
	char[] s;
	int Z = 100;
	
	void solve()
	{
		s = ns().toCharArray();
		len = s.length; pos = 0;
		int P = ni(), M = ni();
		if(P <= Z){
			out.println(expr2()[0][P]);
		}else{
			out.println(exps2()[0][M]);
		}
	}
	
	int[][] expr()
	{
		int[][] a = expr2();
		assert s[pos] == '?';
		pos++;
		int[][] b = expr2();
		int[][] c = new int[2][Z+1];
		Arrays.fill(c[0], Integer.MIN_VALUE / 3);
		Arrays.fill(c[1], Integer.MAX_VALUE / 3);
		// plus 0:max, 1:min
		for(int i = 0;i <= Z;i++){
			for(int j = 0;i+j+1 <= Z;j++){
				c[0][i+j+1] = Math.max(c[0][i+j+1], a[0][i] + b[0][j]);
				c[1][i+j+1] = Math.min(c[1][i+j+1], a[1][i] + b[1][j]);
			}
		}
		// minus
		for(int i = 0;i <= Z;i++){
			for(int j = 0;i+j <= Z;j++){
				c[0][i+j] = Math.max(c[0][i+j], a[0][i] - b[1][j]);
				c[1][i+j] = Math.min(c[1][i+j], a[1][i] - b[0][j]);
			}
		}
		return c;
	}
	
	int[][] expr2()
	{
		if(s[pos] == '('){
			pos++;
			int[][] res = expr();
			pos++;
			return res;
		}else{
			assert s[pos] >= '0' && s[pos] <= '9';
			int[][] c = new int[2][Z+1];
			Arrays.fill(c[0], Integer.MIN_VALUE / 3);
			Arrays.fill(c[1], Integer.MAX_VALUE / 3);
			c[0][0] = s[pos]-'0';
			c[1][0] = s[pos]-'0';
			pos++;
			return c;
		}
	}
	
	int[][] exps()
	{
		int[][] a = exps2();
		assert s[pos] == '?';
		pos++;
		int[][] b = exps2();
		int[][] c = new int[2][Z+1];
		Arrays.fill(c[0], Integer.MIN_VALUE / 3);
		Arrays.fill(c[1], Integer.MAX_VALUE / 3);
		// plus 0:max, 1:min
		for(int i = 0;i <= Z;i++){
			for(int j = 0;i+j <= Z;j++){
				c[0][i+j] = Math.max(c[0][i+j], a[0][i] + b[0][j]);
				c[1][i+j] = Math.min(c[1][i+j], a[1][i] + b[1][j]);
			}
		}
		// minus
		for(int i = 0;i <= Z;i++){
			for(int j = 0;i+j+1 <= Z;j++){
				c[0][i+j+1] = Math.max(c[0][i+j+1], a[0][i] - b[1][j]);
				c[1][i+j+1] = Math.min(c[1][i+j+1], a[1][i] - b[0][j]);
			}
		}
		return c;
	}
	
	int[][] exps2()
	{
		if(s[pos] == '('){
			pos++;
			int[][] res = exps();
			pos++;
			return res;
		}else{
			assert s[pos] >= '0' && s[pos] <= '9';
			int[][] c = new int[2][Z+1];
			Arrays.fill(c[0], Integer.MIN_VALUE / 3);
			Arrays.fill(c[1], Integer.MAX_VALUE / 3);
			c[0][0] = s[pos]-'0';
			c[1][0] = s[pos]-'0';
			pos++;
			return c;
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