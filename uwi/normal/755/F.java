//package eightvc.e;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
		int[] cs = splitIntoCycleSizes(f);
		Arrays.sort(cs);
		// min
		{
			int m = (n+1)>>>6;
			m++;
			long[] dp = new long[m];
			long[] temp = new long[m];
			dp[0] = 1L<<0;
			for(int i = 0;i < cs.length;){
				int j = i;
				while(j < cs.length && cs[j] == cs[i])j++;
				
				int k = j-i;
				for(int d = 1;d <= k;d*=2){
					k -= d;
					copy(dp, 0, (m<<6)-cs[i]*d, temp, 0);
					or(temp, 0, (m<<6)-cs[i]*d, dp, cs[i]*d);
				}
				if(k > 0){
					copy(dp, 0, (m<<6)-cs[i]*k, temp, 0);
					or(temp, 0, (m<<6)-cs[i]*k, dp, cs[i]*k);
				}
				
				i = j;
			}
			if(dp[K>>>6]<<~K<0){
				out.print(K + " ");
			}else{
				out.print(K + 1 + " ");
			}
		}
		// max
		{
			int L = K;
			int dead = 0;
			for(int i = 0;i < cs.length;i++){
				while(cs[i] >= 2 && L >= 1){
					cs[i] -= 2;
					L--;
					dead += 2;
				}
			}
			for(int i = 0;i < cs.length;i++){
				while(cs[i] >= 1 && L >= 1){
					cs[i]--;
					L--;
					dead++;
				}
			}
			
			out.println(dead);
		}
	}
	
	public static void copy(long[] from, int fl, int fr, long[] to, int tl)
	{
		if(!(fl >= 0 && fl < from.length<<6))return;
		if(!(fr >= 0 && fr <= from.length<<6))return;
		if(!(tl >= 0 && tl < to.length<<6))return;
		if(!(tl+(fr-fl) >= 0 && tl+(fr-fl) <= to.length<<6))return;
		if(fl > fr)return;
		
		int tr = tl+(fr-fl);
		for(int l1 = fl, l2 = Math.min(fr, (fl>>>6)+1<<6), r1 = tl, r2 = Math.min(tr, (tl>>>6)+1<<6);l1 < fr;){
			if(l2-l1 <= r2-r1){
				long f = from[l2-1>>>6]<<-l2>>>-l2+l1;
				to[l2-l1+r1-1>>>6] &= ~((1L<<r2-1)-(1L<<r1)|1L<<r2-1);
				to[l2-l1+r1-1>>>6] |= f<<r1;
				r1 += l2-l1;
				l1 = l2;
				l2 = Math.min(fr, (l1>>>6)+1<<6);
				if(r2 - r1 == 0){
					r2 = Math.min(tr, (r1>>>6)+1<<6);
				}
			}else{
				long f = from[r2-r1+l1-1>>>6]<<-(r2-r1+l1)>>>-(r2-r1+l1)+l1;
				to[r2-1>>>6] &= ~((1L<<r2-1)-(1L<<r1)|1L<<r2-1);
				to[r2-1>>>6] |= f<<r1;
				l1 += r2-r1;
				r1 = r2;
				r2 = Math.min(tr, (r1>>>6)+1<<6);
				if(l2 - l1 == 0){
					l2 = Math.min(fr, (l1>>>6)+1<<6);
				}
			}
		}
	}
	
	public static void or(long[] from, int fl, int fr, long[] to, int tl)
	{
		if(!(fl >= 0 && fl < from.length<<6))throw new RuntimeException();
		if(!(fr >= 0 && fr <= from.length<<6))throw new RuntimeException();
		if(!(tl >= 0 && tl < to.length<<6))throw new RuntimeException();
		if(!(tl+(fr-fl) >= 0 && tl+(fr-fl) <= to.length<<6))throw new RuntimeException();
		if(fl >= fr)return;
		
		int tr = tl+(fr-fl);
		for(int l1 = fl, l2 = Math.min(fr, (fl>>>6)+1<<6), r1 = tl, r2 = Math.min(tr, (tl>>>6)+1<<6);l1 < fr;){
			if(l2-l1 <= r2-r1){
				long f = from[l2-1>>>6]<<-l2>>>-l2+l1;
				to[l2-l1+r1-1>>>6] |= f<<r1;
				r1 += l2-l1;
				l1 = l2;
				l2 = Math.min(fr, (l1>>>6)+1<<6);
				if(r2 - r1 == 0){
					r2 = Math.min(tr, (r1>>>6)+1<<6);
				}
			}else{
				long f = from[r2-r1+l1-1>>>6]<<-(r2-r1+l1)>>>-(r2-r1+l1)+l1;
				to[r2-1>>>6] |= f<<r1;
				l1 += r2-r1;
				r1 = r2;
				r2 = Math.min(tr, (r1>>>6)+1<<6);
				if(l2 - l1 == 0){
					l2 = Math.min(fr, (l1>>>6)+1<<6);
				}
			}
		}
	}

	
	public static int[] splitIntoCycleSizes(int[] f)
	{
		int n = f.length;
		int[] szs = new int[n];
		boolean[] ved = new boolean[n];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int p = 0;
				for(int cur = i;!ved[cur];cur = f[cur], p++)ved[cur] = true;
				szs[q++] = p;
			}
		}
		return Arrays.copyOf(szs, q);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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