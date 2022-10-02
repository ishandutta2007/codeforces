//package round239;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		int[][] b = new int[n*m][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				b[p++] = new int[]{a[i][j], i, j};
			}
		}
		
		int[][][] last = new int[n][m][];
		int[][] below = new int[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(below[i], -1);
		}
		{
			Arrays.sort(b, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					if(a[1] != b[1])return -(a[1] - b[1]);
					return a[2] - b[2];
				}
			});
			
			int[] ft = new int[m+1];
			int[] llast = new int[m];
			Arrays.fill(llast, -1);
			int lastv = -1;
			for(int i = 0;i < n*m;i++){
				if(lastv != b[i][0]){
					Arrays.fill(ft, 0);
					Arrays.fill(llast, -1);
				}
				int bef = before(ft, b[i][2]);
//				tr(b[i], lastv, restoreFenwick(ft), before(ft, b[i][2]));
				if(bef != -1){
					last[b[i][1]][b[i][2]] = new int[]{llast[bef], bef};
				}
				
				if(llast[b[i][2]] == -1){
					addFenwick(ft, b[i][2], 1);
				}else{
					below[b[i][1]][b[i][2]] = llast[b[i][2]];
				}
				llast[b[i][2]] = b[i][1];
				lastv = b[i][0];
			}
		}
//		tr(below);
		
		int[][][] first = new int[n][m][];
		{
			Arrays.sort(b, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					if(a[1] != b[1])return -(a[1] - b[1]);
					return -(a[2] - b[2]);
				}
			});
			
			int[] ft = new int[m+1];
			int[] lfirst = new int[m];
			Arrays.fill(lfirst, -1);
			int lastv = -1;
			for(int i = 0;i < n*m;i++){
				if(lastv != b[i][0]){
					Arrays.fill(ft, 0);
					Arrays.fill(lfirst, -1);
				}
				int aft = after(ft, b[i][2]);
				if(aft != -1){
					first[b[i][1]][b[i][2]] = new int[]{lfirst[aft], aft};
				}
				if(lfirst[b[i][2]] == -1)addFenwick(ft, b[i][2], 1);
				lfirst[b[i][2]] = b[i][1];
				lastv = b[i][0];
			}
		}
//		tr(first);
//		tr(last);
		
		Arrays.sort(b, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				if(a[2] != b[2])return a[2] - b[2];
				return a[1] - b[1];
			}
		});
		
		int[][] ib = new int[n][m];
		for(int i = 0;i < n*m;i++)ib[b[i][1]][b[i][2]] = i;
		
		int[] befs = new int[n*m];
		int[] afts = new int[n*m];
		Arrays.fill(befs, -1);
		Arrays.fill(afts, -1);
		
		int maxs = 0;
		for(int up = n-1;up >= 0;up--){
			for(int j = 0;j < m;j++){
				int ind = ib[up][j];
				if(last[up][j] != null){
					for(int x = ib[last[up][j][0]][last[up][j][1]];x != -1;x = befs[x]){
						afts[x] = ind;
					}
				}
				if(first[up][j] != null){
					for(int x = ib[first[up][j][0]][first[up][j][1]];x != -1;x = afts[x]){
						befs[x] = ind;
					}
				}
				if(below[up][j] != -1){
//					befs[ind] = ib[below[up][j]][j];
					afts[ib[below[up][j]][j]] = ind;
				}
			}
			
			int[] maxr = new int[m];
			Arrays.fill(maxr, m-1);
			for(int down = up;down < n;down++){
				for(int j = 0;j < m;j++){
					int ind = ib[down][j];
					int bef = befs[ind];
					int aft = afts[ind];
					if(bef != -1 && b[bef][0] == b[ind][0]){
						maxr[b[bef][2]] = Math.min(maxr[b[bef][2]], j-1);
					}
					if(aft != -1 && b[ind][0] == b[aft][0]){
						maxr[j] = Math.min(maxr[j], b[aft][2]-1);
					}
				}
				
				for(int j = m-2;j >= 0;j--){
					maxr[j] = Math.min(maxr[j], maxr[j+1]);
				}
				
				for(int j = 0;j < m;j++){
					maxs = Math.max(maxs, (maxr[j]-j+1)*(down-up+1));
				}
			}
		}
		out.println(maxs);
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	public static int after(int[] ft, int x)
	{
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if(f+1 >= ft.length-1)return -1;
		return f+1;
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
	
	public static void main(String[] args) throws Exception { new D4().run(); }
	
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