//package educational.round17;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] ras = new int[n][];
		for(int i = 0;i < n;i++){
			ras[i] = new int[]{ni(), ni(), ni()};
		}
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ras[i][0], ras[i][2], i};
		}
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] xs = new int[n];
		for(int i = 0;i < n;i++)xs[i] = co[i][0];
		
		for(int i = 0;i < n;i++)co[i][0] = i;
		StaticRangeTreeRSQ srt = new StaticRangeTreeRSQ(co, n);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[co[i][2]] = i;
		
		int[][] es = new int[2*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			es[p++] = new int[]{ras[i][0], i, 1};
			es[p++] = new int[]{ras[i][0]+ras[i][1]+1, i, -1};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[2] - b[2];
			}
		});
		long ret = 0;
		for(int[] e : es){
			if(e[2] == 1){
				int ind = Arrays.binarySearch(xs, e[0]-ras[e[1]][1]);
				if(ind < 0)ind = -ind-1;
				long v = srt.sum(ind, n, ras[e[1]][2]-m, ras[e[1]][2]+m+1);
				ret += v;
				srt.add(iord[e[1]], ras[e[1]][2], 1);
			}else{
				srt.add(iord[e[1]], ras[e[1]][2], -1);
			}
		}
		out.println(ret);
	}
	
	public static class StaticRangeTreeRSQ {
		public int M, H, N;
		public int[][] fts;
		public int[][] maps;
		public int[] count;
		public int I = Integer.MAX_VALUE;
		
		public StaticRangeTreeRSQ(int[][] co, int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
//			Arrays.sort(co, new Comparator<int[]>() { // x asc
//				public int compare(int[] a, int[] b) {
//					if(a[0] != b[0])return a[0] - b[0];
//					return a[1] - b[1];
//				}
//			});
			maps = new int[M][];
			fts = new int[M][];
			count = new int[M];
			for(int i = 0;i < co.length;i++){
				count[H+co[i][0]]++;
			}
			int off = 0;
			for(int i = 0;i < n;i++){
				maps[H+i] = new int[count[H+i]];
				for(int j = 0;j < count[H+i];j++,off++){
					maps[H+i][j] = co[off][1];
				}
				fts[H+i] = new int[count[H+i]+1];
			}
			
			for(int i = H-1;i >= 1;i--){
				if(maps[2*i+1] == null){
					maps[i] = maps[2*i];
					count[i] = count[2*i];
				}else{
					count[i] = count[2*i] + count[2*i+1];
					maps[i] = new int[count[i]];
					int l = 0;
					int j = 0, k = 0;
					while(j < count[2*i] && k < count[2*i+1]){
						if(maps[2*i][j] < maps[2*i+1][k]){
							maps[i][l++] = maps[2*i][j++];
						}else if(maps[2*i][j] > maps[2*i+1][k]){
							maps[i][l++] = maps[2*i+1][k++];
						}else{
							maps[i][l++] = maps[2*i][j++];
							k++;
						}
					}
					while(j < count[2*i])maps[i][l++] = maps[2*i][j++];
					while(k < count[2*i+1])maps[i][l++] = maps[2*i+1][k++];
					if(l != count[i]){ // uniq
						count[i] = l;
						maps[i] = Arrays.copyOf(maps[i], l);
					}
				}
				fts[i] = new int[count[i]+1];
			}
		}
		
		public void add(int x, int y, int v)
		{
			for(int pos = H+x;pos >= 1;pos>>>=1){
				int ind = Arrays.binarySearch(maps[pos], y);
				if(ind >= 0){
					addFenwick(fts[pos], ind, v);
				}else{
					throw new RuntimeException(String.format("access to non-existing point : (%d,%d):%d", x, y, v));
				}
			}
		}
		
		public long gsum;
		
		// [xl,xr)*[yl,yr)
		public long sum(int xl, int xr, int yl, int yr) { 
			gsum = 0;
			sum(xl, xr, yl, yr, 0, H, 1);
			return gsum;
		}
		
		public void sum(int xl, int xr, int yl, int yr, int cl, int cr, int cur)
		{
			if(xl <= cl && cr <= xr){
				int indl = Arrays.binarySearch(maps[cur], yl-1);
				int indr = Arrays.binarySearch(maps[cur], yr-1);
				if(indl < 0)indl = -indl - 2;
				if(indr < 0)indr = -indr - 2;
				gsum += sumFenwick(fts[cur], indr) - sumFenwick(fts[cur], indl);
			}else{
				int mid = cl+cr>>>1;
				if(cl < xr && xl < mid)sum(xl, xr, yl, yr, cl, mid, 2*cur);
				if(mid < xr && xl < cr)sum(xl, xr, yl, yr, mid, cr, 2*cur+1);
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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