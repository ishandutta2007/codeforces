//package round400;
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
		int n = ni();
		long[] isp = isp(100005);
		out.println(n <= 2 ? 1 : 2);
		for(int i = 2;i <= n+1;i++){
			if(isp[i>>>6]<<~i<0){
				out.print(1 + " ");
			}else{
				out.print(2 + " ");
			}
		}
		out.println();
	}
	

	public static long[] isp(int n)
	{
		int[] tprimes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
		if(n <= 64){
			long ptn = 0;
			for(int p : tprimes)if(p <= n)ptn |= 1L<<p;
			return new long[]{ptn};
		}
		
		long[] isnp = new long[(n+1)/64+1];
		int sup = (n+1)/64+1;
		
		isnp[0] |= 1<<1;
		for(int tp : tprimes){
			long[] ptn = new long[tp];
			for(int i = 0;i < tp<<6;i+=tp)ptn[i>>>6] |= 1L<<i;
			for(int j = 0;j < sup;j += tp){
				for(int i = 0;i < tp && i+j < sup;i++){
					isnp[j+i] |= ptn[i];
				}
			}
		}
		
		final int[] magic = {0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36, 32,
	              60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};
		out:
		for(int i = 0;i < sup;i++){
			for(long j = ~isnp[i];j != 0;j &= j-1){
				int p = i<<6|magic[(int)((j&-j)*0x022fdd63cc95386dL>>>58)];
				if((long)p*p > n)break out;
				for(int q = p*p;q <= n;q += p)isnp[q>>6] |= 1L<<q;
			}
		}
		
		for(int i = 0;i < isnp.length;i++)isnp[i] = ~isnp[i];
		for(int tp : tprimes)isnp[0] |= 1L<<tp;
		isnp[isnp.length-1] &= (1L<<n+1)-1;
		
		return isnp;
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