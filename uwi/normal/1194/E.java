//package educational.round68;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] hs = new int[n][];
		int[][] vs = new int[n][];
		int hp = 0, vp = 0;
		for(int i = 0;i < n;i++){
			int x1 = ni(), y1 = ni(), x2 = ni(), y2 = ni();
			if(y1 > y2){
				int d = y1; y1 = y2; y2 = d;
			}
			if(x1 > x2){
				int d = x1; x1 = x2; x2 = d;
			}
			if(x1 == x2){
				vs[vp++] = new int[]{x1, y1, y2, -1};
			}else{
				hs[hp++] = new int[]{y1, x1, x2};
			}
		}
		vs = Arrays.copyOf(vs, vp);
		hs = Arrays.copyOf(hs, hp);
		
		Arrays.sort(hs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		Arrays.sort(vs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		for(int i = 0;i < vp;i++)vs[i][3] = i;
		
		int[][] vsu = Arrays.copyOf(vs, vs.length);
		Arrays.sort(vsu, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		long ans = 0;
		for(int i = 0;i < hp;i++){
			int[] ft = new int[n+3];
			int p = vp-1;
			for(int j = hp-1;j >= i+1;j--){
				while(p >= 0 && vsu[p][2] >= hs[j][0]){
					if(vsu[p][1] <= hs[i][0]){
						addFenwick(ft, vsu[p][3], 1);
					}
					p--;
				}
				
				int L = lowerBound(vs, 0, Math.max(hs[i][1], hs[j][1]))-1;
				int R = lowerBound(vs, 0, Math.min(hs[i][2], hs[j][2])+1)-1;
				if(L < R){
					int u = sumFenwick(ft, R) - sumFenwick(ft, L);
					ans += (long)u * (u-1) / 2;
				}
			}
		}
		out.println(ans);
	}
	
	public static int lowerBound(int[][] a, int ind, int v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h][ind] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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