//package round468;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(2);
		}
		long ans = 0;
		for(int pa = 0;pa < 2;pa++){
			int[][] rco = new int[n][];
			int p = 0;
			for(int i = 0;i < n;i++){
				if((co[i][0]+co[i][1]&1) == pa){
					rco[p++] = new int[]{co[i][0]-co[i][1], co[i][0]+co[i][1]};
				}
			}
			ans += count(Arrays.copyOf(rco, p), pa);
		}
		out.println(ans);
	}
	
	long count(int[][] co, int pa)
	{
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
//		tr(co);
		int[][] lefts = rev(sweep(co));
		co = rev(co);
		for(int[] c : co)c[0] = -c[0];
		int[][] rights = sweep(co);
		for(int[] c : rights){
			c[0] = -c[0];
			c[1] = -c[1];
			int d = c[0]; c[0] = c[1]; c[1] = d;
		}
//		tr(lefts);
//		tr(rights);
		int p = 0, q = 0;
		long ans = 0;
		while(p < lefts.length && q < rights.length){
			ans += S(lefts[p], rights[q], pa);
			if(lefts[p][1] <= rights[q][1]){
				p++;
			}else{
				q++;
			}
		}
		return ans;
	}
	
	// pa = 1 (0,1) -> (-1,1)
	// pa = 0 (0,2) -> (-2,2)
	long S(int[] a, int[] b, int pa)
	{
		long L = Math.max(a[0], b[0]);
		long R = Math.min(a[1], b[1]);
		long D = Math.max(a[2], b[2]);
		long U = Math.min(a[3], b[3]);
		if(pa == 0){
			L--; R--; D--; U--;
		}
		if(L <= R && D <= U){
			int B = 1000000000;
//			tr("hey", a, b, L, R, D, U, (long)((R+B)/2-(L+B-1)/2)*
//					((U+B)/2-(D+B-1)/2));
			return (long)((R+B)/2-(L+B-1)/2)*
					((U+B)/2-(D+B-1)/2);
		}
		return 0;
	}
	
	int[][] rev(int[][] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int[] d = a[i]; a[i] = a[j]; a[j] = d;
		}
		return a;
	}
	
	int[][] sweep(int[][] co)
	{
		int max = -9999999, min = 9999999;
		int n = co.length;
		int x = 9999999;
		int[][] rs = new int[n+1][];
		int p = 0;
		for(int i = n-1;i >= 0;i--){
			int[] e = co[i];
//			tr(e, max, min, e[0], x);
			if(max >= min && e[0] < x){
				rs[p++] = new int[]{e[0], x-1, min, max};
			}
			x = e[0];
			max = Math.max(max, e[1]-1);
			min = Math.min(min, e[1]+1);
		}
		if(max >= min){
			rs[p++] = new int[]{-9999999, x-1, min, max};
		}
		return Arrays.copyOf(rs, p);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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