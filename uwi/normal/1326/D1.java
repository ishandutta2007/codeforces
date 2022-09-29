//package round7;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		char[] s = ns().toCharArray();
		String rp = go(s);
		String rs = go(rev_(s));
		if(rp.length() >= rs.length()){
			out.println(rp);
//			out.println(rp.length());
		}else{
			out.println(rs);
//			out.println(rs.length());
		}
	}
	
	public static char[] rev_(char[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}

	
	
	
	String go(char[] s)
	{
		int n = s.length;
		int[] rads = palindrome(s);
		long[] es = new long[rads.length];
		for(int i = 0;i < rads.length;i++){
			es[i] = (long)(i-rads[i]+1)/2<<32|rads[i];
		}
		Arrays.sort(es);
		int[] res = new int[n];
		int p = 0;
		int cur = 0;
		// 2*i 2*i+es[p]-1 2*i+2*(es[p]-1)
		for(int i = 0;i < n;i++){
			cur -= 2;
			while(p < es.length && es[p]>>>32 == i){
				if(i+(int)es[p]-1 < n-i){
					cur = Math.max(cur, (int)es[p]);
				}
				p++;
			}
			res[i] = cur;
		}
		long ans = 0;
		int argi = -1;
		for(int i = 0, j = n-1;i < j;i++,j--){
			if(res[i] + i*2 > ans){
				ans = res[i] + i*2;
				argi = i;
			}
			if(s[i] != s[j])break;
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < ans - argi;i++){
			sb.append(s[i]);
		}
		for(int i = argi-1;i >= 0;i--){
			sb.append(s[i]);
		}
		return sb.toString();
	}
	
	public static int[] palindrome(char[] str)
	{
		int n = str.length;
		int[] r = new int[2*n];
		int k = 0;
		for(int i = 0, j = 0;i < 2*n;i += k, j = Math.max(j-k, 0)){
			// normally
			while(i-j >= 0 && i+j+1 < 2*n && str[(i-j)/2] == str[(i+j+1)/2])j++;
			r[i] = j;
			
			// skip based on the theorem
			for(k = 1;i-k >= 0 && r[i]-k >= 0 && r[i-k] != r[i]-k;k++){
				r[i+k] = Math.min(r[i-k], r[i]-k);
			}
		}
		return r;
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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