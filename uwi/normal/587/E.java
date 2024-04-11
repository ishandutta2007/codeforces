//package round326;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		int S = (int)Math.sqrt(Q);
		int[][] qs = new int[Q][];
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1, K = ni();
				qs[z] = new int[]{t, l, r, K};
			}else{
				int l = ni()-1, r = ni()-1;
				qs[z] = new int[]{t, l, r};
			}
		}
		
		int[] map = new int[n+1];
		Arrays.fill(map, -1);
		for(int i = 0;i < Q;i+=S){
			int j = Math.min(Q, i+S);
			int[] xs = new int[2*(j-i)+2];
			int p = 0;
			for(int k = i;k < j;k++){
				xs[p++] = qs[k][1];
				xs[p++] = qs[k][2]+1;
			}
			xs[p++] = 0;
			xs[p++] = n;
			int[] imap = shrinkX(xs);
			int m = imap.length;
			for(int k = 0;k < m;k++){
				map[imap[k]] = k;
			}
			
			int[][] bas = new int[m][];
			int[] head = new int[m];
			for(int k = 0;k < m-1;k++){
				int[] basis = new int[32];
				for(int l = imap[k]+1;l < imap[k+1];l++)incbasis(a[l]^a[imap[k]], basis);
				head[k] = a[imap[k]];
				bas[k] = basis;
			}
			
			int[][][] st = new int[10][m-1][];
			st[0] = bas;
			for(int d = 1;d <= 9;d++){
				for(int e = 0;e+(1<<d) <= m-1;e++){
					st[d][e] = merge(st[d-1][e], st[d-1][e + (1<<d-1)]);
				}
			}
			
			for(int k = i;k < j;k++){
				int[] q = qs[k];
				if(q[0] == 1){
					int L = map[q[1]], R = map[q[2]+1];
					for(int t = L;t < R;t++){
						head[t] ^= q[3];
					}
				}else{
					int L = map[q[1]], R = map[q[2]+1];
					int h = 31-Integer.numberOfLeadingZeros(R-L);
					int[] lbas = merge(st[h][L], st[h][R-(1<<h)]);
					for(int t = L;t < R;t++){
						incbasis(head[t], lbas);
					}
//					int[] lbas = new int[32];
//					for(int t = L;t < R;t++){
//						incbasis(head[t], lbas);
//						for(int u = 0;u < 32;u++){
//							incbasis(bas[t][u], lbas);
//						}
//					}
					int rank = 0;
					for(int u : lbas)if(u != 0)rank++;
					out.println(1L<<rank);
				}
			}
			
			for(int k = 0;k < m;k++){
				map[imap[k]] = -1;
			}
			
			int[] imos = new int[n+1];
			for(int k = i;k < j;k++){
				int[] q = qs[k];
				if(q[0] == 1){
					imos[q[1]] ^= q[3];
					imos[q[2]+1] ^= q[3];
				}
			}
			for(int k = 0;k < n;k++){
				imos[k+1] ^= imos[k];
			}
			for(int k = 0;k < n;k++){
				a[k] ^= imos[k];
			}
		}
	}
	
	int[] merge(int[] b1, int[] b2)
	{
		int[] ret = Arrays.copyOf(b1, b1.length);
		for(int v : b2)incbasis(v, ret);
		return ret;
	}
	
	public static int[] incbasis(int x, int[] bas)
	{
		int h = 31-Integer.numberOfLeadingZeros(x);
		while(x != 0){
			if(bas[h] != 0){
				x ^= bas[h];
				h = 31-Integer.numberOfLeadingZeros(x);
			}else{
				bas[h] = x;
			}
		}
		return bas;
	}
	
	public static int[] basis(int[] a)
	{
		int[] bas = new int[32];
		for(int x : a){
			int h = 31-Integer.numberOfLeadingZeros(x);
			while(x != 0){
				if(bas[h] != 0){
					x ^= bas[h];
					h = 31-Integer.numberOfLeadingZeros(x);
				}else{
					bas[h] = x;
				}
			}
		}
		return bas;
	}
	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
	}
	
	void run() throws Exception
	{
//		int n = 200000, m = 40000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(1000000000) + " ");
//		}
//		sb.append("\n");
//		for(int i = 0;i < m;i++){
//			int t = gen.nextInt(2)+1;
//			sb.append(t + " ");
//			if(t == 1){
//				int v1 = gen.nextInt(n);
//				int v2 = gen.nextInt(n);
//				sb.append(Math.min(v1, v2) + 1 + " ");
//				sb.append(Math.max(v1, v2) + 1 + " ");
//				sb.append(gen.nextInt(1000000000) + " ");
//			}else{
//				int v1 = gen.nextInt(n);
//				int v2 = gen.nextInt(n);
//				sb.append(Math.min(v1, v2) + 1 + " ");
//				sb.append(Math.max(v1, v2) + 1 + " ");
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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