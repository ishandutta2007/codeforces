//package round385;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] colors = new int[n];
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			colors[i] = nc();
			a[i] = ni();
			b[i] = ni();
		}
		int sa = Arrays.stream(a).sum();
		int sb = Arrays.stream(b).sum();
		
		long[][][] dp = new long[1<<16][][];
		dp[0] = new long[1][1];
		dp[0][0][0] = 1L<<0;
		for(int i = 1;i < 1<<n;i++){
			int bc = Integer.bitCount(i);
			int x = bc*(bc-1)/2;
			int m = (x+1>>>6)+1;
			dp[i] = new long[x+1][m];
			int red = 0, blue = 0;
			for(int j = 0;j < n;j++){
				if(i<<~j<0){
					if(colors[j] == 'R'){
						red++;
					}else{
						blue++;
					}
				}
			}
			for(int j = 0;j < n;j++){
				if(i<<~j<0){
					if(colors[j] == 'R'){
						red--;
					}else{
						blue--;
					}
					
					int rr = Math.min(a[j], red);
					int bb = Math.min(b[j], blue);
					int pi = i^1<<j;
					for(int k = 0;k < dp[pi].length;k++){
						or(dp[pi][k], 0, dp[pi].length, dp[i][k+rr], bb);
					}
					
					if(colors[j] == 'R'){
						red++;
					}else{
						blue++;
					}
				}
			}
		}
		
		int last = (1<<n)-1;
		long mincost = Long.MAX_VALUE;
		for(int i = 0;i < dp[last].length;i++){
			for(int j = 0;j < dp[last].length;j++){
				if(dp[last][i][j>>>6]<<~j<0){
					mincost = Math.min(mincost, Math.max(sa-i, sb-j) + n);
				}
			}
		}
		out.println(mincost);
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
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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