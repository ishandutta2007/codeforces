//package round502;
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
		long[][] coa = new long[n][];
		long[][] cob = new long[m][];
		for(int i = 0;i < n;i++){
			coa[i] = new long[]{ni(), ni()};
		}
		for(int i = 0;i < m;i++){
			cob[i] = new long[]{ni(), ni()};
		}
		long[][] ha = convexHull(coa);
		long[][] hb = convexHull(cob);
		out.println(equiv(ha, hb) ? "YES" : "NO");
	}
	
	boolean equiv(long[][] a, long[][] b)
	{
		if(a.length != b.length)return false;
		int n = a.length;
		long[] ads = new long[n];
		long[] bds = new long[n];
		for(int i = 0, j = 1;i < n;i++,j++){
			if(j == n)j = 0;
			ads[i] = d2(a[i], a[j]);
			bds[i] = d2(b[i], b[j]);
		}
		
		long[] c = new long[3*n];
		for(int i = 0;i < n;i++)c[i] = ads[i];
		for(int i = 0;i < n;i++)c[i+n] = bds[i];
		for(int i = 0;i < n;i++)c[i+2*n] = bds[i];
		int[] z = Z(c);
		
		outer:
		for(int i = n;i < 2*n;i++){
			if(z[i] >= n){
				for(int j = 0, k = i-n;j < n;j++,k++){
					if(k == n)k = 0;
					long va = d2(a[j], a[0]);
					long vb = d2(b[k], b[i-n]);
					if(va != vb)continue outer;
				}
				return true;
			}
		}
		return false;
	}
	
	public static long d2(long ax, long ay, long bx, long by) { return (bx-ax)*(bx-ax)+(by-ay)*(by-ay); }
	public static long d2(long[] a, long[] b) { return (b[0]-a[0])*(b[0]-a[0])+(b[1]-a[1])*(b[1]-a[1]); }

	
	public static int[] Z(long[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
	}

	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty){ return Long.signum((tx-ax)*(by-ay)-(bx-ax)*(ty-ay)); }
	public static int ccw(long[] a, long[] b, long[] t){ return Long.signum((t[0]-a[0])*(b[1]-a[1])-(b[0]-a[0])*(t[1]-a[1])); }
	public static int ccw(int[] a, int[] b, int[] t){ return Long.signum((long)(t[0]-a[0])*(b[1]-a[1])-(long)(b[0]-a[0])*(t[1]-a[1])); }

	
	public static long[][] convexHull(long[][] co)
	{
		int n = co.length;
		if(n <= 1)return co;
		Arrays.sort(co, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		int[] inds = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= 2 && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= inf && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int len = Math.max(p-1, 1);
		long[][] ret = new long[len][];
		for(int i = 0;i < len;i++)ret[i] = co[inds[i]];
		return ret;
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