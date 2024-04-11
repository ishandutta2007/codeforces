//package educational.codefest19;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), W = ni();
		long base = 0;
		long[] ans = new long[W];
		for(int i = 0;i < n;i++){
			int L = ni();
			int[] a = na(L);
			if(L <= W/2){
				int max = 0;
				for(int v :a )max = Math.max(max, v);
				base += max;
				
				int pre = 0;
				for(int j = 0;j < L;j++){
					pre = Math.max(pre, a[j]);
					ans[j] += pre - max;
				}
				pre = 0;
				for(int j = 0;j < L;j++){
					pre = Math.max(pre, a[L-1-j]);
					ans[W-1-j] += pre - max;
				}
			}else{
				int[] ra = new int[L];
				for(int j = 0;j < L;j++)ra[j] = -a[j];
				SlideMinDeque smd = new SlideMinDeque(ra);
				for(int j = 0;j < W;j++){
					long max = j < W-L || j >= L ? 0 : Long.MIN_VALUE;
					if(j < L){
						smd.add();
					}
					ans[j] += Math.max(max, -smd.min());
					if(j >= W-L){
						smd.drop();
					}
				}
			}
		}
		for(int j = 0;j < W;j++){
			out.print(ans[j] + base + " ");
		}
		out.println();
	}
	
	public static class SlideMinDeque
	{
		public int[] dq;
		public int[] a;
		public int t = 0, h = 0;
		public int pt = 0, ph = 0;
		
		public SlideMinDeque(int[] a){ this.a = a; dq = new int[a.length]; }
		public int min(){ return t == h ? Integer.MAX_VALUE : a[dq[t]]; }
		public SlideMinDeque drop(){ pt++; while(t < h && dq[t] < pt)t++; return this; }
		public SlideMinDeque add(){ assert ph < a.length; while(t < h && a[dq[h-1]] >= a[ph])h--; if(pt <= ph)dq[h++] = ph; ph++; return this;}
		// pt <= ph strictly
//		public SlideMinDeque drop(){ assert pt < ph; pt++; while(t < h && dq[t] < pt)t++; return this; }
//		public SlideMinDeque add(){ assert ph < a.length; while(t < h && a[dq[h-1]] >= a[ph])h--; dq[h++] = ph++; return this;}
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
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
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