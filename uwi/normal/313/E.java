//package round186;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeSet;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] b = na(n);
		
		int[] ad = new int[m];
		for(int v : a)ad[v]++;
		int[] bd = new int[m];
		for(int v : b)bd[v]++;
		int[] fas = new int[m+2];
		int[] fbs = new int[m+2];
		
		for(int i = 0;i < m;i++){
			if(bd[i] > 0){
				addFenwick(fbs, i, 1);
			}
		}
		TreeSet<Long> q = new TreeSet<Long>();
		
		for(int i = 0;i < m;i++){
			if(ad[i] > 0){
				addFenwick(fas, i, 1);
				int ma = before(fbs, m-i);
				if(ma == -1)ma = before(fbs, m+1);
				q.add((long)(m-(i+ma)%m)<<40|(long)i<<20|ma);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		while(!q.isEmpty()){
			long cur = q.pollFirst();
			int c0 = (int)(cur>>>20&((1<<20)-1));
			int c1 = (int)(cur&((1<<20)-1));
			int c2 = m-(int)(cur>>>40);
			int minus = Math.min(ad[c0], bd[c1]);
//			tr(c0, c1, c2);
//			tr(restoreFenwick(fbs));
			for(int i = 0;i < minus;i++){
				sb.append(" " + c2);
			}
			
			ad[c0] -= minus;
			bd[c1] -= minus;
			if(minus > 0){
				if(ad[c0] == 0){
					addFenwick(fas, c0, -1);
				}
				if(bd[c1] == 0){
					addFenwick(fbs, c1, -1);
				}
			}
			if(ad[c0] > 0){
				int ma = before(fbs, m-c0);
				if(ma == -1)ma = before(fbs, m+1);
				q.add((long)(m-(c0+ma)%m)<<40|(long)c0<<20|ma);
			}else if(bd[c1] > 0){
				int ma = before(fas, m-c1);
				if(ma == -1)ma = before(fas, m+1);
				q.add((long)(m-(ma+c1)%m)<<40|(long)ma<<20|c1);
			}
		}
		out.println(sb.substring(1));
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(m) + " ");
//		}
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(m) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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