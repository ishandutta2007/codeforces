//package round279;
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
		int n = ni();
		int S = 1000001, T = 1000002;
		int[][] co = new int[n][];
		int[] from = new int[n];
		int[] to = new int[n];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
			if(co[i][0] == 0)co[i][0] = S;
			if(co[i][1] == 0)co[i][1] = T;
			from[i] = co[i][0];
			to[i] = co[i][1];
		}
		int[][] g = packU(1000003, from, to);
		int[] ret = new int[n];
		if(n % 2 == 0){
			for(int i = 1, j = g[S][0], pre = S;i < n;i+=2){
				ret[i] = j;
				if(i+2 < n){
					int pj = j;
					if(g[j][0] == pre){
						j = g[j][1];
					}else{
						j = g[j][0];
					}
					pre = pj;
				}
			}
			for(int i = n-2, j = g[T][0], pre = T;i >= 0;i-=2){
				ret[i] = j;
				if(i-2 >= 0){
					int pj = j;
					if(g[j][0] == pre){
						j = g[j][1];
					}else{
						j = g[j][0];
					}
					pre = pj;
				}
			}
		}else{
			for(int i = 1, j = g[S][0], pre = S;i < n;i+=2){
				ret[i] = j;
				if(i+2 < n){
					int pj = j;
					if(g[j][0] == pre){
						j = g[j][1];
					}else{
						j = g[j][0];
					}
					pre = pj;
				}
			}
			int[] f = new int[2000000];
			for(int i = 0;i < n;i++){
				f[co[i][0]]++;
				f[co[i][1]]--;
			}
			for(int q = 0;q < S;q++){
				if(f[q] == 1){
					for(int i = 0, j = q, pre = -1;i < n;i+=2){
						ret[i] = j;
						if(i+2 < n){
							int pj = j;
							if(g[j][0] == pre){
								j = g[j][1];
							}else{
								j = g[j][0];
							}
							pre = pj;
						}
					}
					break;
				}
			}
		}
		for(int i = 0;i < n;i++){
			out.print(ret[i] + " ");
		}
		out.println();
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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