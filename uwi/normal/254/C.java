//package round155;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = ns(100001);
		char[] b = ns(100001);
		
		int[] ctb = new int[26];
		int[] cta = new int[26];
		for(char c : a){
			cta[c-'A']++;
		}
		for(char c : b){
			ctb[c-'A']++;
		}
		int u = 0;
		for(int i = 0;i < 26;i++){
			ctb[i] -= cta[i];
			if(ctb[i] > 0)u += ctb[i];
		}
		int n = a.length;
		
		char[] ret = new char[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ctb[a[i]-'A'] < 0){
				while(p < 26 && ctb[p] <= 0)p++;
				if(p < a[i]-'A' || cta[a[i]-'A'] <= -ctb[a[i]-'A']){
					ret[i] = (char)('A'+p);
					ctb[a[i]-'A']++;
					ctb[p]--;
				}else{
					ret[i] = a[i];
				}
			}else{
				ret[i] = a[i];
			}
			cta[a[i]-'A']--;
		}
		out.println(u);
		for(char c : ret){
			out.print(c);
		}
		out.println();
//		out.println(new String(ret));
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
	byte[] inbuf = new byte[1024];
	int lenbuf = 0, ptrbuf = 0;
	
	int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	double nd() { return Double.parseDouble(ns()); }
	char nc() { return (char)readByte(); }
	
	String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	int ni()
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
	
	long nl()
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
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}