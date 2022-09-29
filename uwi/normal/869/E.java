//package round439;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		long[][] f = new long[n+3][m+3];
		Random gen = new Random();
		int mod = BigInteger.probablePrime(30, gen).intValue();
		Map<Long, Long> map = new HashMap<>();
		for(int z = 0;z < Q;z++){
			int type = ni();
			int r1 = ni(), c1 = ni(), r2 = ni(), c2 = ni();
			if(type == 1){
				long code = 0;
				code = code * mod + r1;
				code = code * mod + c1;
				code = code * mod + r2;
				code = code * mod + c2;
				long val = gen.nextLong();
				map.put(code, val);
				addFenwick(f, r1, c1, val);
				addFenwick(f, r2+1, c1, val);
				addFenwick(f, r1, c2+1, val);
				addFenwick(f, r2+1, c2+1, val);
			}else if(type == 2){
				long code = 0;
				code = code * mod + r1;
				code = code * mod + c1;
				code = code * mod + r2;
				code = code * mod + c2;
				long val = map.get(code);
				addFenwick(f, r1, c1, val);
				addFenwick(f, r2+1, c1, val);
				addFenwick(f, r1, c2+1, val);
				addFenwick(f, r2+1, c2+1, val);
			}else{
				out.println(sumFenwick(f, r1, c1) == sumFenwick(f, r2, c2) ? "Yes" : "No");
			}
		}
	}
	
	public static long sumFenwick(long[][] ft, int r, int c)
	{
		long sum = 0;
		r++; c++;
		for(int rr = r;rr > 0;rr -= rr&-rr){
			for(int cc = c;cc > 0;cc -= cc&-cc){
				sum ^= ft[rr][cc];
			}
		}
		return sum;
	}
	
	public static void addFenwick(long[][] ft, int r, int c, long v)
	{
		if(v == 0)return;
		int R = ft.length;
		int C = ft[0].length;
		r++; c++;
		for(int rr = r;rr < R;rr += rr&-rr){
			for(int cc = c;cc < C;cc += cc&-cc){
				ft[rr][cc] ^= v;
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 2500, m = 2450, q = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(q + " ");
//		for (int i = 0; i < q; i++) {
//			sb.append(gen.nextInt(2)*2+1 + " ");
//			int v1 = gen.nextInt(n-1)+1;
//			int v2 = gen.nextInt(n-1)+1;
//			int v3 = gen.nextInt(m-1)+1;
//			int v4 = gen.nextInt(m-1)+1;
//			{
//				sb.append(Math.min(v1, v2) + 1 + " ");
//				sb.append(Math.min(v3, v4) + 1 + " ");
//				sb.append(Math.max(v1, v2) + 1 + " ");
//				sb.append(Math.max(v3, v4) + 1 + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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