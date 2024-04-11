//package round324;
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
		int n = ni(), t = ni();
		char[] a = ns(n);
		char[] b = ns(n);
		int same = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == b[i])same++;
		}
		int diff = n-same;
		for(int i = 0;i <= diff;i += 2){
			int sc = i/2 + (diff-i);
			if(sc <= t && t <= sc + same){
				int sneed = t - sc;
				
				char[] ret = new char[n];
				Arrays.fill(ret, '.');
				int lrem = i/2, rrem = i/2;
				for(int j = 0;j < n;j++){
					if(a[j] != b[j]){
						if(lrem > 0 || rrem > 0){
							if(lrem >= rrem){
								lrem--;
								ret[j] = b[j];
							}else{
								rrem--;
								ret[j] = a[j];
							}
						}else{
							for(char c = 'a';c <= 'z';c++){
								if(a[j] != c && b[j] != c){
									ret[j] = c;
									break;
								}
							}
						}
					}
				}
				for(int j = 0;j < n;j++){
					if(a[j] == b[j]){
						if(sneed > 0){
							for(char c = 'a';c <= 'z';c++){
								if(a[j] != c && b[j] != c){
									ret[j] = c;
									break;
								}
							}
							sneed--;
						}else{
							ret[j] = a[j];
						}
					}
				}
				
//				int da = 0, db = 0;
//				for(int j = 0;j < n;j++){
//					if(a[j] != ret[j])da++;
//					if(b[j] != ret[j])db++;
//				}
//				tr(new String(ret));
//				assert da == t && db == t;
				
				out.println(new String(ret));
				return;
			}
		}
		out.println(-1);
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