//package round478;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class D2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 1 0\r\n" + 
//			"-1 1 2\r\n" + 
//			"0 0 1\r\n" + 
//			"1 -1 0";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long a = ni(), b = ni();
		Map<Long, List<long[]>> map = new HashMap<>();
		long[][] all = new long[n][];
		for(int i = 0;i < n;i++){
			long x = ni(), vx = ni(), vy = ni();
			all[i] = new long[]{vx, vy};
		}

		for(int i = 0;i < n;i++){
			long vx = all[i][0], vy = all[i][1];
			long z = -vy*1 + a*vx;
			if(!map.containsKey(z)){
				map.put(z, new ArrayList<>());
			}
			map.get(z).add(all[i]);
		}
		long ans = 0;
		for(long key : map.keySet()){
			ans += (long)map.get(key).size()*(map.get(key).size()-1)/2;
			List<long[]> my = map.get(key);
			Collections.sort(my, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[0], b[0]);
				}
			});

			int m = my.size();
			for(int i = 0;i < m;){
				int j = i;
				while(j < m && my.get(i)[0] == my.get(j)[0])j++;
				
				ans -= (long)(j-i)*(j-i-1)/2;
				i = j;
			}
		}
		out.println(ans*2);
	}
	
	public static int[] shrink(long[] a)
	{
		int n = a.length;
		long[] b = Arrays.copyOf(a, n);
		Arrays.sort(b);
//		b = radixSort(b);
		
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || b[i] != b[i-1])b[p++] = b[i];
		}
		
		int[] ret = new int[n];
		for(int i = 0;i < n;i++) {
			ret[i] = Arrays.binarySearch(b, 0, p, a[i]);
		}
		return ret;
	}

	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}

	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	
	public static long dot(long[] a, long[] b){ return a[0]*b[0]+a[1]*b[1]; }
	public static long cross(long[] a, long[] b){ return a[0]*b[1]-a[1]*b[0]; }

	
	
	public static Comparator<long[]> compArgi = new Comparator<long[]>(){
		public int compare(long[] a, long[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || ay == 0 && ax > 0 ? 0 : 1;
			int zb = by > 0 || by == 0 && bx > 0 ? 0 : 1;
			if(za != zb)return za - zb;
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		}
	};

	
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