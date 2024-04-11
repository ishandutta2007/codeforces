//package round208;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		int br = -1, bc = -1;
		out:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(a[i][j] == 1){
					br = i;
					bc = j;
					break out;
				}
			}
		}
		
		int one = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				one += a[i][j];
			}
		}
		if(one == 1){
			out.println(-1);
			return;
		}
		
		List<Integer> ok = new ArrayList<Integer>();
		outer:
		for(int K = 2;K <= Math.max(n, m);K++){
			int zr = br % K;
			int zc = bc % K;
			int nn = (n-zr+K-1)/K;
			int mm = (m-zc+K-1)/K;
			int[][] deg = new int[nn][mm];
			int all = 0;
			for(int i = zr;i < n;i+=K){
				for(int j = zc;j < m;j+=K){
					all += a[i][j];
				}
			}
			DJSet ds = new DJSet(nn*mm);
			for(int i = 0;i < nn;i++){
				for(int j = 0;j < mm-1;j++){
					if(a[i*K+zr][j*K+zc] == 1 && a[i*K+zr][(j+1)*K+zc] == 1){
						for(int u = j*K+zc+1;u < (j+1)*K+zc;u++){
							if(a[i*K+zr][u] != a[i*K+zr][j*K+zc+1]){
								continue outer;
							}
						}
						if(a[i*K+zr][j*K+zc+1] == 1){
							deg[i][j]++;
							deg[i][j+1]++;
							ds.union(i*mm+j, i*mm+j+1);
							all += K-1;
						}
					}
				}
			}
			for(int i = 0;i < nn-1;i++){
				for(int j = 0;j < mm;j++){
					if(a[i*K+zr][j*K+zc] == 1 && a[(i+1)*K+zr][j*K+zc] == 1){
						for(int u = i*K+zr+1;u < (i+1)*K+zr;u++){
							if(a[u][j*K+zc] != a[i*K+zr+1][j*K+zc]){
								continue outer;
							}
						}
						if(a[i*K+zr+1][j*K+zc] == 1){
							deg[i][j]++;
							deg[i+1][j]++;
							ds.union(i*mm+j, (i+1)*mm+j);
							all += K-1;
						}
					}
				}
			}
			if(all != one)continue outer;
			int clus = -1;
			int odd = 0;
			for(int i = 0;i < nn;i++){
				for(int j = 0;j < mm;j++){
					if(a[i*K+zr][j*K+zc] == 1){
						if(clus == -1){
							clus = ds.root(i*mm+j);
						}else{
							if(ds.root(i*mm+j) != clus)continue outer;
						}
						if(deg[i][j] % 2 == 1){
							odd++;
						}
					}
				}
			}
			if(odd <= 2){
				ok.add(K);
			}
		}
		if(ok.size() == 0){
			out.println(-1);
		}else{
			for(int v : ok){
				out.print(v + " ");
			}
			out.println();
		}
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public boolean union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;} return x == y;} public int count(){ int ct = 0; for(int u : upper)if(u < 0)ct++; return ct; }}
	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				sb.append(gen.nextInt(2) + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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