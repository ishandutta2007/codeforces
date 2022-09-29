//package round647;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.function.ToLongFunction;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(2);
		}
		int O = 1000000000;
		Map<Long, List<int[]>> cog = groupBy(co, c -> {
			if(c[0] == 0 && c[1] == 0)return 0L;
			int g = gcd(Math.abs(c[0]), Math.abs(c[1]));
			return (long)c[0]/g+O<<32|c[1]/g+O;
		});
		
		List<Double> cont = new ArrayList<Double>();
		for(List<int[]> l : cog.values()){
			int m = l.size();
			double[] ds = new double[m];
			for(int i = 0;i < m;i++){
				int[] e = l.get(i);
				ds[i] = Math.sqrt((long)e[0]*e[0]+(long)e[1]*e[1]);
			}
			Arrays.sort(ds);
			int h = K-1;
			int t = 0;
			for(int i = 0;i < m && h >= 0;i++){
				cont.add(ds[m-1-i] * h);
				h -= 2;
				t++;
			}
			double cum = 0;
			for(int i = 0;t < m;i++){
				cont.add(-2*cum + ds[i] * h);
				cum += ds[i];
				t++;
			}
		}
		Collections.sort(cont);
		double ans = 0;
		for(int i = 0;i < K;i++){
			ans += cont.get(n-1-i);
		}
		out.printf("%.14f\n", ans);
	}
	
	<T> Map<Long, List<T>> groupBy(T[] a, ToLongFunction<T> f)
	{
		Map<Long, List<T>> map = new HashMap<>();
		for(T v : a){
			long key = f.applyAsLong(v);
			if(!map.containsKey(key))map.put(key, new ArrayList<>());
			map.get(key).add(v);
		}
		return map;
	}
//	
//	Map<Long, List<int[]>> groupBy(int[][] a, ToLongFunction<int[]> f)
//	{
//		Map<Long, List<int[]>> map = new HashMap<>();
//		for(int[] v : a){
//			long key = f.applyAsLong(v);
//			if(!map.containsKey(key))map.put(key, new ArrayList<>());
//			map.get(key).add(v);
//		}
//		return map;
//	}
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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