//package educational.round23;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[][] mcm = mcm(a);
		int[][] imcm = mcm(rev(a));
		rev(a);
		BigInteger MIN = BigInteger.ONE.shiftLeft(100);
		long ct = 0;
		for(int i = 1;i < n-1;i++){
			BigInteger CAN = 
			BigInteger.valueOf(a[i]).multiply(BigInteger.valueOf(mcm[0][i]))
			.multiply(BigInteger.valueOf(imcm[0][n-i-1]));
			int comp = CAN.compareTo(MIN);
			if(comp < 0){
				MIN = CAN;
				ct = (long)mcm[1][i] * imcm[1][n-i-1];
			}else if(comp == 0){
				ct += (long)mcm[1][i] * imcm[1][n-i-1];
			}
		}
		out.println(ct);
	}
	
	public static int[] rev(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}

	
	int[][] mcm(int[] a)
	{
		int n = a.length;
		int[] mins = new int[n+1];
		mins[0] = Integer.MAX_VALUE;
		int[] cmins = new int[n+1];
		for(int i = 0;i < n;i++){
			if(a[i] < mins[i]){
				mins[i+1] = a[i];
				cmins[i+1] = 1;
			}else if(a[i] == mins[i]){
				mins[i+1] = a[i];
				cmins[i+1] = cmins[i] + 1;
			}else{
				mins[i+1] = mins[i];
				cmins[i+1] = cmins[i];
			}
		}
		return new int[][]{mins, cmins};
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