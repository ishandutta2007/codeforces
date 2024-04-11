//package round192;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1; to[i] = ni()-1;
		}
		
		int[][] g = packU(n, from, to);
		if(n < 6){
			int all = n*(n-1)/2;
			
			// (i,j)=(i,i+1+k)
			// n-1 ,.., n-1-i+1
			// (2n-2-i+1)/2*i+j-(i+1)
			int ng = 0;
			for(int i = 0;i < n;i++){
				for(int j : g[i]){
					if(i < j){
						ng |= 1<<(2*n-2-i+1)*i/2+j-(i+1);
					}
				}
			}
			outer:
			for(int i = 0;i < 1<<all;i++){
				if((i&ng)==0 && Integer.bitCount(i) == m){
					int[] deg = new int[n];
					{
						int r = 0, c = 1;
						for(int j = 0;j < all;j++){
							if(i<<31-j<0){
								deg[r]++;
								deg[c]++;
							}
							c++;
							if(c >= n){
								r++;
								c = r+1;
							}
						}
						for(int j = 0;j < n;j++){
							if(deg[j] > 2)continue outer;
						}
					}
					{
						int r = 0, c = 1;
						for(int j = 0;j < all;j++){
							if(i<<31-j<0){
								out.println((r+1) + " " + (c+1));
							}
							c++;
							if(c >= n){
								r++;
								c = r+1;
							}
						}
					}
					return;
				}
			}
			out.println(-1);
		}else{
			for(int[] v : g){
				Arrays.sort(v);
			}
			int[] path = new int[n];
			boolean[] used = new boolean[n];
			path[0] = 0;
			used[0] = true;
			int[] rem = new int[n-1];
			for(int i = 1;i < n;i++)rem[i-1] = i;
			outer:
			for(int i = 1;i < n;i++){
				for(int j = 0;j < n-i;j++){
					if(Arrays.binarySearch(g[path[i-1]], rem[j]) < 0){
						path[i] = rem[j];
						rem[j] = rem[n-i-1];
						continue outer;
					}
				}
				
				// on
				for(int j = 1;j < i;j++){
					if(
							Arrays.binarySearch(g[rem[0]], path[j]) < 0 && 
							Arrays.binarySearch(g[path[j-1]], path[i-1]) < 0
							){
						for(int k = j, l = i-1;k < l;k++,l--){
							int d = path[k]; path[k] = path[l]; path[l] = d;
						}
						path[i] = rem[0];
						rem[0] = rem[n-i-1];
						continue outer;
					}
				}
				
				throw new AssertionError();
			}
			
			for(int i = 0;i < n-1;i++){
				if(
						Arrays.binarySearch(g[path[n-1]], path[i]) < 0 &&
						Arrays.binarySearch(g[path[0]], path[i+1]) < 0
						){
					for(int k = i+1, l = n-1;k < l;k++,l--){
						int d = path[k]; path[k] = path[l]; path[l] = d;
					}
					break;
				}
			}
			if(m == n){
				for(int i = 0;i < n;i++){
					out.println((path[i]+1) + " " + (path[(i+1)%n]+1));
				}
			}else{
				for(int i = 0;i < m;i++){
					out.println((path[i]+1) + " " + (path[i+1]+1));
				}
			}
		}
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(100000)+1 + " ");
//			sb.append(gen.nextInt(100000)+1 + " ");
//		}
//		INPUT = sb.toString();
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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