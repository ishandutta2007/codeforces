//package raif;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	void go()
	{
		int n = ni();
		char[] s = ns(n);
		int[] f = new int[3];
		for(int i = 0;i < n;i++){
			f["<->".indexOf(s[i])]++;
		}
		if(f[0] == 0 || f[2] == 0){
			out.println(n);
			return;
		}

		int[][] uc = uniqcount(s);
		int ans = 0;
		for(int i = 1;i < uc.length-1;i++){
			if(uc[i][0] == '-'){
				ans += uc[i][1] + 1;
			}
		}
		int v = uc[0][0] == '-' ? uc[0][1] : 0;
		if(uc[uc.length-1][0] == '-')v += uc[uc.length-1][1];
		if(v > 0)ans += v+1;
		out.println(ans);
	}

	public static int[][] uniqcount(char[] a)
	{
		int n = a.length;
		int p = 0;
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1])b[p++] = new int[]{a[i], 0};
			b[p-1][1]++;
		}
		return Arrays.copyOf(b, p);
	}


	public static class SplitResult
	{
		public boolean[] incycle;
		public int[] ord;
	}

	// @see splitsample
	public static SplitResult split(int[] f)
	{
		int n = f.length;
		boolean[] incycle = new boolean[n];
		Arrays.fill(incycle, true);
		int[] indeg = new int[n];
		for(int i = 0;i < n;i++)indeg[f[i]]++;
		int[] q = new int[n];
		int qp = 0;
		for(int i = 0;i < n;i++){
			if(indeg[i] == 0)q[qp++] = i;
		}
		for(int r = 0;r < qp;r++){
			int cur = q[r];
			indeg[cur] = -9999999;
			incycle[cur] = false;
			int e = f[cur];
			indeg[e]--;
			if(indeg[e] == 0)q[qp++] = e;
		}
		for(int i = 0;i < n;i++){
			if(indeg[i] == 1){
				q[qp++] = i;
			}
		}
		// reverse ord
		for(int i = 0, j = n-1;i < j;i++,j--){
			int d = q[i]; q[i] = q[j]; q[j] = d;
		}

		assert qp == n;
		SplitResult ret = new SplitResult();
		ret.incycle = incycle;
		ret.ord = q;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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