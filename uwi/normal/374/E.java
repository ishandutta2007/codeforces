//package round220;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] coa = new int[n][];
		int[][] cob = new int[m][];
		Set<Integer> ad = new HashSet<Integer>();
		for(int i = 0;i < n;i++){
			coa[i] = na(2);
			ad.add(coa[i][0]+coa[i][1]);
		}
		Set<Integer> bd = new HashSet<Integer>();
		for(int i = 0;i < m;i++){
			cob[i] = na(2);
			bd.add(cob[i][0]-cob[i][1]);
		}
		Arrays.sort(coa, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if((a[0]+a[1]) - (b[0]+b[1]) != 0)return (a[0]+a[1]) - (b[0]+b[1]);
				return a[0] - b[0];
			}
		});
		Arrays.sort(cob, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if((a[0]-a[1]) - (b[0]-b[1]) != 0)return (a[0]-a[1]) - (b[0]-b[1]);
				return a[0] - b[0];
			}
		});
		if(ad.size() < 2 || bd.size() < 2){
			out.println("Poor Sereja!");
			return;
		}
		
		int low = 0, high = 3000000;
		while(high - low > 1){
			int t = high+low>>>1;
			if(ok(coa, cob, t)){
				high = t;
			}else{
				low = t;
			}
		}
		out.println(high);
	}
	
	boolean ok(int[][] coa, int[][] cob, int t)
	{
		int n = coa.length, m = cob.length;
		int[][] as = new int[n][];
		{
			int p = 0;
			for(int i = 0;i < n;i++){
				if(i > 0 && coa[i-1][0]+coa[i-1][1] == coa[i][0]+coa[i][1] && coa[i-1][0]+t >= coa[i][0]-t){
					as[p-1][2] = coa[i][0]+t;
					as[p-1][3] = coa[i][1]-t;
				}else{
					as[p++] = new int[]{coa[i][0]-t, coa[i][1]+t, coa[i][0]+t, coa[i][1]-t};
				}
			}
			as = Arrays.copyOf(as, p);
		}
		int[][] bs = new int[m][];
		{
			int p = 0;
			for(int i = 0;i < m;i++){
				if(i > 0 && cob[i-1][0]-cob[i-1][1] == cob[i][0]-cob[i][1] && cob[i-1][0]+t >= cob[i][0]-t){
					bs[p-1][2] = cob[i][0]+t;
					bs[p-1][3] = cob[i][1]+t;
				}else{
					bs[p++] = new int[]{cob[i][0]-t, cob[i][1]-t, cob[i][0]+t, cob[i][1]+t};
				}
			}
			bs = Arrays.copyOf(bs, p);
		}
		n = as.length;
		m = bs.length;
		int[][] g = new int[n][];
//		long[][] ptns = new long[n][(m>>>6)+1];
		int[] row = new int[m];
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < m;j++){
				if(hasCommonPoint(as[i][0], as[i][1], as[i][2], as[i][3], bs[j][0], bs[j][1], bs[j][2], bs[j][3])){
//					if(Line2D.linesIntersect(as[i][0], as[i][1], as[i][2], as[i][3], bs[j][0], bs[j][1], bs[j][2], bs[j][3])){
//					ptns[i][j>>>6] |= 1L<<j;
					row[p++] = j;
				}
			}
			g[i] = Arrays.copyOf(row, p);
		}
		
		boolean[][] ved = new boolean[m][m];
		for(int i = 0;i < n;i++){
			for(int j : g[i]){
				for(int k : g[i]){
					if(j != k){
						if(ved[j][k])return true;
						ved[j][k] = true;
					}
				}
			}
		}
		return false;
	}
	
	public static boolean hasCommonPoint(long ax, long ay, long bx, long by, long cx, long cy, long dx, long dy)
	{
		long aa = bx - ax, cc = by - ay, bb = cx - dx, dd = cy - dy;
		long det = aa * dd - bb * cc;
//		if(det == 0){
//			return 
//					((cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0) ||
//					((dx-ax)*(by-ay)-(dy-ay)*(bx-ax)==0 && (dx-ax)*(dx-bx)+(dy-ay)*(dy-by) <= 0)
//					;
//		}
		long xx = cx - ax, yy = cy - ay;
		long tnum = dd*xx-bb*yy;
		long unum = -cc*xx+aa*yy;
		if(det < 0){
			det = -det;
			tnum = -tnum;
			unum = -unum;
		}
		return tnum >= 0 && tnum <= det && unum >= 0 && unum <= det;
	}
	
	void run() throws Exception
	{
//		int n = 2000, m = 2000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n+m;i++){
//			sb.append(gen.nextInt(2000000)-1000000 + " ");
//			sb.append(gen.nextInt(2000000)-1000000 + " ");
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