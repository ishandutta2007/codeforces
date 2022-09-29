//package hello;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public void sortByArg(int[][] co)
	{
		int n = co.length;
		for(int i = 0, j = n-1;i < j;) {
			while(i < j && (co[i][1] > 0 || co[i][1] == 0 && co[i][0] > 0))i++;
			while(i < j && !(co[j][1] > 0 || co[j][1] == 0 && co[j][0] > 0))j--;
			int[] d = co[i]; co[i] = co[j]; co[j] = d;
		}
		int k = 0;
		for(;k < n && (co[k][1] > 0 || co[k][1] == 0 && co[k][0] > 0);k++);
		Arrays.sort(co, 0, k, (a, b) -> {
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		});
		Arrays.sort(co, k, n, (a, b) -> {
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		});
	}
	
	public static long cross(int[] a, int[] b){ return (long)a[0]*b[1]-(long)a[1]*b[0];	}
	
	public long countTrianglesContainingO(int[][] co)
	{
		int n = co.length;
//		Arrays.sort(co, compArgi);
		sortByArg(co);

		long ret = (long)n*(n-1)*(n-2)/6;
		for(int h = 0, t = 0, hm = 0, tm = 0;h < 2*n;h++, hm++) {
			if(hm == n)hm = 0;
			while(t < h && cross(co[hm], co[tm]) >= 0) {
				if(++tm == n)tm = 0;
				t++;
			}
			if(h >= n)ret -= (long)(h-t)*(h-t-1)/2;
		}
		return ret;
	}
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++) {
			co[i] = new int[] {ni(), ni()};
		}
		
		long ans = 0;
		for(int i = 0;i < n;i++) {
			int[][] dco = new int[n-1][];
			int p = 0;
			for(int j = 0;j < n;j++) {
				if(j == i)continue;
				dco[p++] = new int[] {co[j][0]-co[i][0], co[j][1] - co[i][1]};
			}
			ans += countTrianglesContainingO(dco);
		}
		out.println(ans * (n-4) / 2);
	}
	
	public static Comparator<int[]> compArgi = new Comparator<int[]>(){
		public int compare(int[] a, int[] b)
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
	
	public static void main(String[] args) throws Exception { new E4().run(); }
	
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