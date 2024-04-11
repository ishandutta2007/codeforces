//package round645;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	boolean sorted(long[] b)
	{
		int n = b.length;
		for(int i = 0;i < n-1;i++){
			if(b[i] > b[i+1])return false;
		}
		return true;
	}
	
	boolean valid(long[] b)
	{
		for(long v : b){
			if(v <= 0)return false;
		}
		return true;
	}
	
	void solve()
	{
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = nl();
		long[] ob = Arrays.copyOf(b, n);
		StringBuilder sb = new StringBuilder();
		int nf = 0;
		while(true){
			if(Arrays.equals(a, b)){
				out.println("SMALL");
				out.println(sb.length());
				out.println(sb.reverse());
				return;
			}
			if(Arrays.equals(rev(a), b)){
				out.println("SMALL");
				out.println(sb.length()+1);
				out.println("R" + sb.reverse());
				return;
			}
			if(!valid(b)){
				out.println("IMPOSSIBLE");
				return;
			}
			if(!sorted(b)){
				b = rev_(b);
				sb.append("R");
				if(!sorted(b)){
					out.println("IMPOSSIBLE");
					return;
				}
			}
			for(int i = n-2;i >= 0;i--){
				b[i+1] -= b[i];
			}
			sb.append("P");
			if(++nf > 200000){
				break;
			}
		}
		
		assert n <= 3;
		if(n == 1){
			out.println("IMPOSSIBLE");
		}else if(n == 2){
			b = ob;
			long ans = 0;
			Arrays.sort(a);
			while(true){
				if(!valid(b)){
					out.println("IMPOSSIBLE");
					return;
				}
				if(!sorted(b)){
					b = rev_(b);
				}
				if(a[0] == b[0] && a[1] <= b[1] && (b[1] - a[1]) % a[0] == 0){
					ans += (b[1]-a[1]) / a[0];
					out.println("BIG");
					out.println(ans);
					return;
				}
				long v = b[1] / b[0];
				b[1] -= v*b[0];
				ans += v;
			}
		}else{
			while(true){
				if(Arrays.equals(a, b)){
					out.println("BIG");
					out.println(nf);
					return;
				}
				if(Arrays.equals(rev(a), b)){
					out.println("BIG");
					out.println(nf);
					return;
				}
				if(!valid(b)){
					out.println("IMPOSSIBLE");
					return;
				}
				if(!sorted(b)){
					b = rev_(b);
					if(!sorted(b)){
						out.println("IMPOSSIBLE");
						return;
					}
				}
				for(int i = n-2;i >= 0;i--){
					b[i+1] -= b[i];
				}
				nf++;
			}
		}
	}
	
	public static long[] rev(long[] a){long[] b = new long[a.length];for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];return b;}

	public static long[] rev_(long[] a){for(int i = 0, j = a.length-1;i < j;i++,j--){long c = a[i]; a[i] = a[j]; a[j] = c;}return a;}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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