//package round279;
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
		int n = ni();
		char[][] s = new char[n][];
		for(int i = 0;i < n;i++){
			s[i] = ns().toCharArray();
		}
		int x = 0;
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = guess(x, s[i]);
			if(a[i] == -1){
				out.println("NO");
				return;
			}
			x = a[i];
		}
		out.println("YES");
		for(int i = 0;i < n;i++){
			out.println(a[i]);
		}
	}
	
	int guess(int x, char[] s)
	{
		String xs = Integer.toString(x);
		if(xs.length() > s.length)return -1;
		int n = s.length;
		char[] r = new char[n];
		Arrays.fill(r, '0');
		for(int i = xs.length()-1, j = n-1;i >= 0 && j >= 0;i--,j--){
			r[j] = xs.charAt(i);
		}
		for(int i = 0;i < n;i++){
			if(s[i] != '?'){
				if(r[i] > s[i]){
					return -1;
				}else if(r[i] < s[i]){
					for(int j = i;j < n;j++){
						if(s[j] == '?')s[j] = '0';
					}
					return Integer.parseInt(new String(s));
				}
			}else{
				// assume same
				boolean hasgr = false;
				if(!(i == 0 && r[i] == '0')){
					for(int j = i+1;j < n;j++){
						int v = s[j] == '?' ? '9' : s[j];
						if(r[j] < v){
							hasgr = true;
							break;
						}else if(r[j] > v){
							hasgr = false;
							break;
						}
					}
				}
				if(hasgr){
					s[i] = r[i];
				}else{
					if(r[i] == '9'){
						return -1;
					}
					s[i] = (char)(r[i]+1);
					for(int j = i+1;j < n;j++){
						if(s[j] == '?')s[j] = '0';
					}
					return Integer.parseInt(new String(s));
				}
			}
		}
		return -1;
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