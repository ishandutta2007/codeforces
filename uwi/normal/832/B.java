//package round425;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int good = 0;
		for(char c : ns().toCharArray()){
			good |= 1<<c-'a';
		}
		char[] ptn = ns().toCharArray();
		int ast = -1;
		for(int i = 0;i < ptn.length;i++){
			if(ptn[i] == '*'){
				ast = i;
				break;
			}
		}
		if(ast == -1){
			outer:
			for(int Q = ni(); Q> 0;Q--){
				char[] s = ns().toCharArray();
				if(s.length != ptn.length){
					out.println("NO");
				}else{
					int n = s.length;
					for(int i = 0;i < n;i++){
						if(ptn[i] == '?'){
							if(good<<~(s[i]-'a')>=0){
								out.println("NO");
								continue outer;
							}
						}else{
							if(ptn[i] != s[i]){
								out.println("NO");
								continue outer;
							}
						}
					}
					out.println("YES");
				}
			}
		}else{
			outer:
			for(int Q = ni(); Q> 0;Q--){
				char[] s = ns().toCharArray();
				if(s.length < ptn.length-1){
					out.println("NO");
				}else{
					int n = s.length;
					for(int i = 0;i < n && ptn[i] != '*';i++){
						if(ptn[i] == '?'){
							if(good<<~(s[i]-'a')>=0){
								out.println("NO");
								continue outer;
							}
						}else{
							if(ptn[i] != s[i]){
								out.println("NO");
								continue outer;
							}
						}
					}
					for(int i = 0;i < n && ptn[ptn.length-1-i] != '*';i++){
						if(ptn[ptn.length-1-i] == '?'){
							if(good<<~(s[n-1-i]-'a')>=0){
								out.println("NO");
								continue outer;
							}
						}else{
							if(ptn[ptn.length-1-i] != s[n-1-i]){
								out.println("NO");
								continue outer;
							}
						}
					}
					for(int i = ast;i < n-(ptn.length-ast-1);i++){
						if(good<<~(s[i]-'a')<0){
							out.println("NO");
							continue outer;
						}
					}
					out.println("YES");
				}
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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