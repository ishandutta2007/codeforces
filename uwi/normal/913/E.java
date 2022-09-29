//package hello2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String[] cs = "!x&x, !(x|y|z), !x&!y&z, !x&!y, !x&!z&y, !x&!z, !(!y&!z|x|y&z), !(x|y&z), !x&y&z, !(!y&z|!z&y|x), !x&z, !(!z&y|x), !x&y, !(!y&z|x), !x&(y|z), !x, !y&!z&x, !y&!z, !(!x&!z|x&z|y), !(x&z|y), !(!x&!y|x&y|z), !(x&y|z), !(!x&!y|x&y|z)|!x&!y&z, !((x|y)&z|x&y), !x&y&z|!y&!z&x, !x&y&z|!y&!z, !x&z|!y&!z&x, !x&z|!y&!z, !x&y|!y&!z&x, !x&y|!y&!z, !x&(y|z)|!y&!z&x, !x|!y&!z, !y&x&z, !(!x&z|!z&x|y), !y&z, !(!z&x|y), !x&!z&y|!y&x&z, !x&!z|!y&x&z, !x&!z&y|!y&z, !x&!z|!y&z, !x&y&z|!y&x&z, !(!x&z|!z&x|y)|!x&y&z, !(x&y)&z, !(!z&x|y)|!x&z, !x&y|!y&x&z, !(!y&z|x)|!y&x&z, !x&y|!y&z, !x|!y&z, !y&x, !(!x&z|y), !y&(x|z), !y, !x&!z&y|!y&x, !x&!z|!y&x, !x&!z&y|!y&(x|z), !x&!z|!y, !x&y&z|!y&x, !(!x&z|y)|!x&y&z, !x&z|!y&x, !x&z|!y, !x&y|!y&x, !(!x&!y&z|x&y), !x&(y|z)|!y&x, !x|!y, !z&x&y, !(!x&y|!y&x|z), !x&!y&z|!z&x&y, !x&!y|!z&x&y, !z&y, !(!y&x|z), !x&!y&z|!z&y, !x&!y|!z&y, !x&y&z|!z&x&y, !(!x&y|!y&x|z)|!x&y&z, !x&z|!z&x&y, !(!z&y|x)|!z&x&y, !(x&z)&y, !(!y&x|z)|!x&y, !x&z|!z&y, !x|!z&y, !z&x, !(!x&y|z), !x&!y&z|!z&x, !x&!y|!z&x, !z&(x|y), !z, !x&!y&z|!z&(x|y), !x&!y|!z, !x&y&z|!z&x, !(!x&y|z)|!x&y&z, !x&z|!z&x, !(!x&!z&y|x&z), !x&y|!z&x, !x&y|!z, !x&(y|z)|!z&x, !x|!z, !y&x&z|!z&x&y, !(!x&y|!y&x|z)|!y&x&z, !y&z|!z&x&y, !(!z&x|y)|!z&x&y, !y&x&z|!z&y, !(!y&x|z)|!y&x&z, !y&z|!z&y, !(!y&!z&x|y&z), !x&y&z|!y&x&z|!z&x&y, !(!x&y|!y&x|z)|!x&y&z|!y&x&z, !(x&y)&z|!z&x&y, !(!z&x|y)|!x&z|!z&x&y, !(x&z)&y|!y&x&z, !(!y&x|z)|!x&y|!y&x&z, !(x&y)&z|!z&y, !x|!y&z|!z&y, !(y&z)&x, !(!x&y|z)|!y&x, !y&z|!z&x, !y|!z&x, !y&x|!z&y, !y&x|!z, !y&(x|z)|!z&y, !y|!z, !(y&z)&x|!x&y&z, !(!x&y|z)|!x&y&z|!y&x, !(x&y)&z|!z&x, !x&z|!y|!z&x, !(x&z)&y|!y&x, !x&y|!y&x|!z, !x&y|!y&z|!z&x, !(x&y&z), x&y&z, !(x|y|z)|x&y&z, !x&!y&z|x&y&z, !x&!y|x&y&z, !x&!z&y|x&y&z, !x&!z|x&y&z, !(!y&!z|x|y&z)|x&y&z, !(x|y&z)|x&y&z, y&z, !(x|y|z)|y&z, !x&z|y&z, !x&!y|y&z, !x&y|y&z, !x&!z|y&z, !x&(y|z)|y&z, !x|y&z, !y&!z&x|x&y&z, !y&!z|x&y&z, !(!x&!z|x&z|y)|x&y&z, !(x&z|y)|x&y&z, !(!x&!y|x&y|z)|x&y&z, !(x&y|z)|x&y&z, !(!x&!y|x&y|z)|!x&!y&z|x&y&z, !((x|y)&z|x&y)|x&y&z, !y&!z&x|y&z, !y&!z|y&z, !x&z|!y&!z&x|y&z, !(x&z|y)|y&z, !x&y|!y&!z&x|y&z, !(x&y|z)|y&z, !x&(y|z)|!y&!z&x|y&z, !x|!y&!z|y&z, x&z, !(x|y|z)|x&z, !y&z|x&z, !x&!y|x&z, !x&!z&y|x&z, !x&!z|x&z, !x&!z&y|!y&z|x&z, !(x|y&z)|x&z, (x|y)&z, !(x|y|z)|(x|y)&z, z, !x&!y|z, !x&y|x&z, !(!y&z|x)|x&z, !x&y|z, !x|z, !y&x|x&z, !y&!z|x&z, !y&(x|z)|x&z, !y|x&z, !x&!z&y|!y&x|x&z, !(x&y|z)|x&z, !x&!z&y|!y&(x|z)|x&z, !x&!z|!y|x&z, !y&x|y&z, !(!x&z|y)|y&z, !y&x|z, !y|z, !x&y|!y&x|x&z, !x&!z|!y&x|y&z, !x&y|!y&x|z, !x|!y|z, x&y, !(x|y|z)|x&y, !x&!y&z|x&y, !x&!y|x&y, !z&y|x&y, !x&!z|x&y, !x&!y&z|!z&y|x&y, !(x|y&z)|x&y, (x|z)&y, !(x|y|z)|(x|z)&y, !x&z|x&y, !(!z&y|x)|x&y, y, !x&!z|y, !x&z|y, !x|y, !z&x|x&y, !y&!z|x&y, !x&!y&z|!z&x|x&y, !(x&z|y)|x&y, !z&(x|y)|x&y, !z|x&y, !x&!y&z|!z&(x|y)|x&y, !x&!y|!z|x&y, !z&x|y&z, !(!x&y|z)|y&z, !x&z|!z&x|x&y, !x&!y|!z&x|y&z, !z&x|y, !z|y, !x&z|!z&x|y, !x|!z|y, (y|z)&x, !(x|y|z)|(y|z)&x, !y&z|x&y, !(!z&x|y)|x&y, !z&y|x&z, !(!y&x|z)|x&z, !y&z|!z&y|x&y, !x&!y|!z&y|x&z, (x|y)&z|x&y, !(x|y|z)|(x|y)&z|x&y, x&y|z, !x&!y|x&y|z, x&z|y, !x&!z|x&z|y, y|z, !x|y|z, x, !y&!z|x, !y&z|x, !y|x, !z&y|x, !z|x, !y&z|!z&y|x, !y|!z|x, x|y&z, !y&!z|x|y&z, x|z, !y|x|z, x|y, !z|x|y, x|y|z, !x|x".split(", ");
		
		for(int Q = ni();Q > 0;Q--){
			char[] s = ns().toCharArray();
			int x = 0;
			for(int i = 0;i < 8;i++){
				x = x | s[i]-'0'<<i;
			}
			out.println(cs[x]);
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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