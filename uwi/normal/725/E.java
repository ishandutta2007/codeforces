//package canada2016;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni();
		int n = ni();
		int[] a = na(n);
		a = shuffle(a, new Random());
		Arrays.sort(a);
		int[][] ai = uniqcount(a);
		int u = ai.length;
		
		int[] prev = new int[m+1];
		Arrays.fill(prev, -1);
		int p = 0;
		for(int i = ai[0][0];i <= m;i++){
			if(p+1 < u && ai[p+1][0] == i)p++;
			prev[i] = p;
		}
		
		int rem = m;
		int min = Integer.MAX_VALUE / 2;
		for(int i = u-1;i >= 0;i--){
			for(int j = (i+1 < u ? ai[i+1][0] : m);j >= ai[i][0]+1;j--){
				for(int k = Math.min(min-1,rem)/j*j;k >= j;k-=j){
					if(!ok(rem-k, i, prev, ai)){
						min = k;
					}else{
						break;
					}
				}
			}
			for(int j = 0;j < ai[i][1];j++){
				if(rem-ai[i][0] >= 0){
					rem -= ai[i][0];
				}
			}
		}
		if(min > m){
			out.println("Greed is good");
		}else{
			out.println(min);
		}
	}
	
	boolean ok(int m, int f, int[] prev, int[][] ai)
	{
		while(f >= 0){
			int pre = prev[m];
			if(pre == -1)break;
			if(pre >= f)pre = f;
			
			int k = Math.min(ai[pre][1], m / ai[pre][0]);
			m -= k * ai[pre][0];
			f = pre-1;
		}
		return m == 0;
	}

	public static int[][] uniqcount(int[] a)
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
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E5().run(); }
	
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