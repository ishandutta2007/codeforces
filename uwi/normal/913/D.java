//package hello2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), T = ni();
		int[][] ps = new int[n][];
		for(int i = 0;i < n;i++){
			ps[i] = new int[]{ni(), ni(), -1, i};
		}
		Arrays.sort(ps, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		for(int i = 0;i < n;i++){
			ps[i][2] = i;
		}
		
		Arrays.sort(ps, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		
		int[] nums = new int[n+3];
		long[] sums = new long[n+3];
		int p = 0;
		int ans = 0;
		int when = -1;
		for(int gain = n;gain >= 0;gain--){
			while(p < n && ps[p][0] >= gain){
				addFenwick(nums, ps[p][2], 1);
				addFenwick(sums, ps[p][2], ps[p][1]);
				p++;
			}
			int low = -1, high = n;
			while(high - low > 1){
				int h = high+low>>1;
				int ln = sumFenwick(nums, h);
				long ls = sumFenwick(sums, h);
				if(ln <= gain && ls <= T){
					low = h;
				}else{
					high = h;
				}
			}
			int ln = sumFenwick(nums, low);
			if(ln >= ans){
				ans = ln;
				when = gain;
			}
		}
		Arrays.sort(ps, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		out.println(ans);
		List<Integer> ret = new ArrayList<>();
		int rem = ans;
		long rems = T;
		for(int i = 0;i < n;i++){
			if(rem > 0 && ps[i][0] >= when && rems > 0){
				ret.add(ps[i][3]+1);
				rem--;
				rems -= ps[i][1];
			}
		}
		out.println(ret.size());
		for(int v : ret){
			out.print(v + " ");
		}
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

	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int firstGEFenwick(int[] ft, int v)
	{
		int i = 0, n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0;b >>= 1){
			if((i|b) < n && ft[i|b] < v){
				i |= b;
				v -= ft[i];
			}
		}
		return i;
	}

	public static int firstGEFenwick(long[] ft, long v)
	{
		int i = 0, n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0;b >>= 1){
			if((i|b) < n && ft[i|b] < v){
				i |= b;
				v -= ft[i];
			}
		}
		return i;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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