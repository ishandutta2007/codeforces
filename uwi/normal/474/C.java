//package round271;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T >= 1;T--){
			int[][] co = new int[4][];
			for(int i = 0;i < 4;i++){
				co[i] = na(4);
			}
			int min = 999;
			for(int a = 0;a < 4;a++){
				for(int b = 0;b < 4;b++){
					for(int c = 0;c < 4;c++){
						for(int d = 0;d < 4;d++){
							if(issq(co)){
								min = Math.min(min, a+b+c+d);
							}
							rot(co[3]);
						}
						rot(co[2]);
					}
					rot(co[1]);
				}
				rot(co[0]);
			}
			out.println(min == 999 ? -1 : min);
		}
	}
	
	boolean issq(int[][] co)
	{
		int[] ord = new int[3];
		for(int i = 0;i < 3;i++)ord[i] = i;
		do{
			if(isSq(
					co[ord[0]][0], co[ord[0]][1],
					co[ord[1]][0], co[ord[1]][1],
					co[ord[2]][0], co[ord[2]][1],
					co[3][0], co[3][1]
							)){
				return true;
			}
		}while(nextPermutation(ord));
		return false;
	}
	
	static boolean nextPermutation(int[] src) {
		int i;
		for (i = src.length - 2; i >= 0 && src[i] > src[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < src.length && src[i] < src[j]; j++)
			;
		int d = src[i];
		src[i] = src[j - 1];
		src[j - 1] = d;
		for (int p = i + 1, q = src.length - 1; p < q; p++, q--) {
			d = src[p];
			src[p] = src[q];
			src[q] = d;
		}
		return true;
	}
	
	public static boolean isSq(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
	{
		int vx = bx-ax;
		int vy = by-ay;
		return (!(dx == ax && dy == ay) && cx == ax + vy && cy == ay - vx && dx == bx + vy && dy == by - vx);
	}
	
	void rot(int[] c)
	{
		int x = c[0], y = c[1];
		int a = c[2], b = c[3];
		int nx = -(y-b)+a;
		int ny = (x-a)+b;
		c[0] = nx; c[1] = ny;
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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