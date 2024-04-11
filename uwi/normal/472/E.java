//package round270;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] tor(int[][] a)
	{
		int[] t = new int[a.length];
		for(int i = 0;i < a.length;i++){
			t[i] = a[i][0];
		}
		return t;
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			b[i] = na(m);
		}
		int[] f = new int[901];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				f[a[i][j]]++;
				f[b[i][j]]--;
			}
		}
		for(int i = 0;i < 901;i++){
			if(f[i] != 0){
				out.println(-1);
				return;
			}
		}
		
		if(n == 1){
			if(Arrays.equals(a[0], b[0])){
				out.println(0);
				return;
			}
			
			for(int i = 0;i < m;i++){
				for(int j = i;j < m;j++){
					int[] t = Arrays.copyOf(a[0], m);
					int x = t[i];
					for(int k = i;k < j;k++){
						t[k] = t[k+1];
					}
					t[j] = x;
					if(Arrays.equals(t, b[0])){
						out.println(j-i);
						for(int k = i;k <= j;k++){
							out.println(1 + " " + (k+1));
						}
						return;
					}
				}
			}
			for(int i = 0;i < m;i++){
				for(int j = 0;j < i;j++){
					int[] t = Arrays.copyOf(a[0], m);
					int x = t[i];
					for(int k = i;k > j;k--){
						t[k] = t[k-1];
					}
					t[j] = x;
					if(Arrays.equals(t, b[0])){
						out.println(i-j);
						for(int k = i;k >= j;k--){
							out.println(1 + " " + (k+1));
						}
						return;
					}
				}
			}
			out.println(-1);
			return;
		}
		
		if(m == 1){
			int[] tob = tor(b);
			if(Arrays.equals(tor(a), tob)){
				out.println(0);
				return;
			}
			
			for(int i = 0;i < n;i++){
				for(int j = i;j < n;j++){
					int[] t = tor(a);
					int x = t[i];
					for(int k = i;k < j;k++){
						t[k] = t[k+1];
					}
					t[j] = x;
					if(Arrays.equals(t, tob)){
						out.println(j-i);
						for(int k = i;k <= j;k++){
							out.println((k+1) + " " + 1);
						}
						return;
					}
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < i;j++){
					int[] t = tor(a);
					int x = t[i];
					for(int k = i;k > j;k--){
						t[k] = t[k-1];
					}
					t[j] = x;
					if(Arrays.equals(t, tob)){
						out.println(i-j);
						for(int k = i;k >= j;k--){
							out.println((k+1) + " " + 1);
						}
						return;
					}
				}
			}
			out.println(-1);
			return;
		}
		
		int[][] pa = new int[n*m][];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				pa[i*m+j] = new int[]{a[i][j], i, j};
			}
		}
		int[][] pb = new int[n*m][];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				pb[i*m+j] = new int[]{b[i][j], i, j};
			}
		}
		Arrays.sort(pa, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		Arrays.sort(pb, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int hr = -1, hc = -1;
		int[][][] map = new int[n][m][];
		for(int i = 0;i < n*m;i++){
			map[pa[i][1]][pa[i][2]] = new int[]{pb[i][1], pb[i][2]};
			if(pb[i][1] == 0 && pb[i][2] == 0){
				hr = pa[i][1]; hc = pa[i][2];
			}
		}
		path = new int[1000000];
		pp = 0;
		path[pp++] = hr<<16|hc;
		solve(map);
		out.println(pp-1);
		for(int i = 0;i < pp;i++){
			out.println(((path[i]>>>16)+1) + " " + ((path[i]&65535)+1));
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j][0] == i && map[i][j][1] == j){
				}else{
					throw new RuntimeException();
				}
			}
		}
	}
	
	void solve(int[][][] map)
	{
		int n = map.length;
		int m = map[0].length;
		int[][][] imap = new int[n][m][];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				imap[map[i][j][0]][map[i][j][1]] = new int[]{i, j};
			}
		}
		boolean[][] wall = new boolean[n][m];
		
		for(int i = Math.max(n,m)-1;i >= 1;i--){
			if(i < n){
				for(int j = Math.min(i, m-1);j >= 0;j--){
					// (i,j)
					if(wall[i][j])continue;
					fill(i, j, map, imap, wall);
					wall[i][j] = true;
				}
			}
			
			if(i < m){
				for(int j = Math.min(n-1, i-1);j >= 0;j--){
					// (j,i)
					if(wall[j][i])continue;
					fill(j, i, map, imap, wall);
					wall[j][i] = true;
				}
			}
		}
	}
	
	int[] path;
	int pp;
	
	void fill(int gr, int gc, int[][][] map, int[][][] imap, boolean[][] wall)
	{
//		tr("go", gr, gc);
		int n = map.length;
		int m = map[0].length;
//		print(imap, wall, gr, gc);
		while(true){
			int hr = imap[0][0][0], hc = imap[0][0][1];
			int tr = imap[gr][gc][0], tc = imap[gr][gc][1];
			if(tr == gr && tc == gc)return;
			
			int dtr = Integer.signum(gr-tr), dtc = Integer.signum(gc-tc);
			int xdtr = -1, xdtc = -1;
			{
				int[][] DIR = {
						{2, 1, 0},
						{3, -99, 7},
						{4, 5, 6}
				};
				int basedir = DIR[dtr+1][dtc+1];
				int clo = 100;
				for(int k = -1;k <= 1;k++){
					for(int l = -1;l <= 1;l++){
						if(k == 0 && l == 0)continue;
						int ldir = DIR[k+1][l+1];
						int lclo = Math.min(Math.abs(ldir-basedir), Math.abs(ldir-basedir+8));
						lclo = Math.min(lclo, Math.abs(ldir-basedir-8));
						if(tr+k >= 0 && tr+k < n && tc+l >= 0 && tc+l < m && !wall[tr+k][tc+l]){
							if(lclo < clo){
								xdtr = k; xdtc = l;
								clo = lclo;
							}
						}
					}
				}
			}
			dtr = xdtr; dtc = xdtc;
			
			int thr = tr + dtr, thc = tc + dtc;
			if(wall[thr][thc]){
				throw new AssertionError(thr + " " + thc + " " + gr + " " + gc + " " + hr + " " + hc);
			}
			
			int nhr = -1, nhc = -1;
			if(hr == thr && hc == thc){
				nhr = tr; nhc = tc;
			}else{
				int dhr = Integer.signum(thr-hr), dhc = Integer.signum(thc-hc);
				int[][] DIR = {
						{2, 1, 0},
						{3, -99, 7},
						{4, 5, 6}
				};
				int basedir = DIR[dhr+1][dhc+1];
				int clo = 100;
				for(int k = -1;k <= 1;k++){
					for(int l = -1;l <= 1;l++){
						if(k == 0 && l == 0)continue;
						int ldir = DIR[k+1][l+1];
						int lclo = Math.min(Math.abs(ldir-basedir), Math.abs(ldir-basedir+8));
						lclo = Math.min(lclo, Math.abs(ldir-basedir-8));
						if(hr+k >= 0 && hr+k < n && hc+l >= 0 && hc+l < m && !wall[hr+k][hc+l] && !(tr == hr+k && tc == hc+l)){
							if(lclo < clo){
								nhr = hr + k; nhc = hc + l;
								clo = lclo;
							}
						}
					}
				}
			}
			if(nhr == -1)throw new AssertionError();
			int[] to = map[nhr][nhc];
			int[] dum = imap[to[0]][to[1]]; imap[to[0]][to[1]] = imap[0][0]; imap[0][0] = dum;
			map[nhr][nhc] = map[hr][hc]; map[hr][hc] = to;
			
			path[pp++] = nhr<<16|nhc;
			hr = nhr; hc = nhc;
			
//			print(imap, wall, gr, gc);
		}
	}
	
	void print(int[][][] imap, boolean[][] wall, int gr, int gc)
	{
		int n = imap.length, m = imap[0].length;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(wall[i][j]){
					out.print("#");
				}else if(i == imap[0][0][0] && j == imap[0][0][1]){
					out.print("o");
				}else if(i == imap[gr][gc][0] && j == imap[gr][gc][1]){
					out.print("t");
				}else if(i == gr && j == gc){
					out.print("g");
				}else{
					out.print(".");
				}
			}
			out.println();
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 30, m = 2;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		int[] a = new int[n*m];
//		for(int i = 0;i < n*m;i++)a[i] = i+1;
//		a = shuffle(a, gen);
//		for (int i = 0; i < n*m; i++) {
//			sb.append(a[i] + " ");
//		}
//		a = shuffle(a, gen);
//		for (int i = 0; i < n*m; i++) {
//			sb.append(a[i] + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
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