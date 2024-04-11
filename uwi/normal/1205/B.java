//package round580;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.function.LongPredicate;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		
		long[] fs = new long[3];
		for(int i = 0;i < n;i++){
			long x = a[i];
			for(int j = 0;j < 3;j++){
				long nx = x&fs[j];
				fs[j] |= x;
				x = nx;
			}
			if(fs[2] != 0){
				out.println(3);
				return;
			}
		}
		
//		{
//			long[] b = new long[a.length];
//			int p = 0;
//			for(int i = 0;i < a.length;i++){
//				if(a[i] != 0)b[p++] = a[i];
//			}
//			a = Arrays.copyOf(b, p);
//		}
		a = filter(a, (x) -> x != 0);
		int p = a.length;
		
		int[] from = new int[3600];
		int[] to = new int[3600];
		
		int q = 0;
		for(int i = 0;i < p;i++){
			for(int j = i+1;j < p;j++){
				if((a[i]&a[j]) != 0){
					from[q] = i; to[q] = j; q++;
				}
			}
		}
		
		from = Arrays.copyOf(from, q);
		to = Arrays.copyOf(to, q);
		
		int[] mcs = minCycleSizes(n, from, to);
		
		int min = 99999;
		for(int v : mcs){
			if(v != -1){
				min = Math.min(min, v);
			}
		}
		out.println(min == 99999 ? -1 : min);
	}
	
	static int[] minCycleSizes(int n, int[] from, int[] to)
	{
		int[][] g = packU(n, from, to);
		int m = from.length;
		int[] q = new int[n];
		
		int[] ret = new int[m];
		Arrays.fill(ret, -1);
		for(int i = 0;i < m;i++){
			int[] ds = new int[n];
			Arrays.fill(ds, n+999);
			ds[from[i]] = 0;
			int p = 0;
			q[p++] = from[i];
			for(int j = 0;j < p;j++){
				int cur = q[j];
				if(cur == to[i]){
					ret[i] = ds[cur] + 1;
					break;
				}
				for(int e : g[cur]){
					if(cur == from[i] && e == to[i])continue;
					if(ds[e] > ds[cur] + 1){
						ds[e] = ds[cur] + 1;
						q[p++] = e;
					}
				}
			}
		}
		return ret;
	}
	
	public static long[] filter(long[] a, LongPredicate pred)
	{
		long[] b = new long[a.length];
		int p = 0;
		for(int i = 0;i < a.length;i++){
			if(pred.test(a[i]))b[p++] = a[i];
		}
		return Arrays.copyOf(b, p);
	}
	
	public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	
	public static int[][] mul(int[][] A, int[][] B, int mod)
	{
		assert A[0].length == B.length;
		int m = A.length;
		int n = A[0].length;
		int o = B[0].length;
		int[][] C = new int[m][o];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < o;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * B[k][j];
					sum %= mod;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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