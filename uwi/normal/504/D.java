//package round285;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int D = 2000/64+1;
		long[][] bs = new long[2001][];
		long[][] bes = new long[2001][];
		outer:
		for(int T = ni(), e = 0;T >= 1;T--, e++){
			BigInteger b = new BigInteger(ns());
			long[] v = new long[D];
			for(int i = 0;i < 2000;i++){
				if(b.testBit(i)){
					v[i>>>6] |= 1L<<i;
				}
			}
			long[] has = new long[D];
			
			int h = 2000;
			while(h >= 0){
				while(h >= 0 && v[h>>>6]<<~h>=0)h--;
				if(h < 0)break;
				if(bs[h] == null){
					bs[h] = v;
					has[e>>>6] |= 1L<<e;
					bes[h] = has;
					out.println(0);
					continue outer;
				}
				for(int i = 0;i < D;i++){
					v[i] ^= bs[h][i];
					has[i] ^= bes[h][i];
				}
			}
			int ct = 0;
			for(int i = 0;i < D;i++){
				ct += Long.bitCount(has[i]);
			}
			out.print(ct);
			for(int i = 0;i < e;i++){
				if(has[i>>>6]<<~i<0){
					out.print(" " + i);
				}
			}
			out.println();
		}
	}
	
	void run() throws Exception
	{
//		int n = 600, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(2000 + " ");
//		for(int j = 0;j < 1000;j++){
////			for (int i = 0; i < n; i++) {
////				sb.append(gen.nextInt(10));
////			}
//			sb.append(BigInteger.valueOf(1).shiftLeft(j));
//			sb.append("\n");
//		}
//		for(int j = 0;j < 1000;j++){
////			for (int i = 0; i < n; i++) {
////				sb.append(gen.nextInt(10));
////			}
//			sb.append(BigInteger.valueOf(1).shiftLeft(1001).subtract(BigInteger.ONE));
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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