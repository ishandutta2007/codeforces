//package round325;
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
		int[][] vs = new int[n][];
		for(int i = 0;i < n;i++){
			vs[i] = na(3);
		}
		long[] s = new long[3];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				s[j] += vs[i][j];
			}
		}
		long o = 10000000*60;
		long t1 = s[1] - s[0];
		long t2 = s[2] - s[0];
		long tar = t1+o<<32|t2+o;
		int h = n/2;
		long[][] as = new long[(int)Math.pow(3, h)][];
		int p = 0;
		{
			int[] a = new int[h];
			do{
				long d1 = 0, d2 = 0, base = 0;
				for(int i = 0;i < h;i++){
					if(a[i] == 0){
						d1 -= vs[i][0];
						d2 -= vs[i][0];
						base += vs[i][0];
					}else if(a[i] == 1){
						d1 += vs[i][1];
					}else{
						d2 += vs[i][2];
					}
				}
				as[p] = new long[]{t1-d1+o<<32|t2-d2+o, p, base};
				p++;
			}while(inc(a, 3));
		}
		Arrays.sort(as, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return -Long.compare(a[2], b[2]);
			}
		});
		int pp = 0;
		for(int i = 0;i < p;i++){
			if(i == 0 || as[i][0] != as[i-1][0]){
				as[pp++] = as[i];
			}
		}
		p = pp;
		
		long[] av = new long[p];
		for(int i = 0;i < p;i++){
			av[i] = as[i][0];
		}
		
		{
			int bestrid = -1;
			int bestlid = -1;
			long bestbase = Long.MAX_VALUE;
			int[] a = new int[n-h];
			int xid = 0;
			do{
				long d1 = 0, d2 = 0, base = 0;
				for(int i = 0;i < n-h;i++){
					if(a[i] == 0){
						d1 -= vs[i+h][0];
						d2 -= vs[i+h][0];
						base += vs[i+h][0];
					}else if(a[i] == 1){
						d1 += vs[i+h][1];
					}else{
						d2 += vs[i+h][2];
					}
				}
				int ind = Arrays.binarySearch(av, d1+o<<32|d2+o);
				if(ind >= 0){
					if(base + as[ind][2] < bestbase){
						bestbase = base + as[ind][2];
						bestlid = (int)as[ind][1];
						bestrid = xid;
					}
				}
				xid++;
			}while(inc(a, 3));
			
			if(bestlid == -1){
				out.println("Impossible");
			}else{
				String[] T = {"MW", "LW", "LM"};
				String[] ret = new String[n];
				int bl = bestlid, br = bestrid;
				for(int i = h-1;i >= 0;i--){
					ret[i] = T[bestlid%3];
					bestlid /= 3;
				}
				for(int i = n-1;i >= h;i--){
					ret[i] = T[bestrid%3];
					bestrid /= 3;
				}
				for(int i = 0;i < n;i++){
					out.println(ret[i]);
				}
				
				long[] c = new long[3];
				for(int i = h-1;i >= 0;i--){
					if(bl%3 == 0){
						c[1] += vs[i][1];
						c[2] += vs[i][2];
					}else if(bl%3 == 1){
						c[0] += vs[i][0];
						c[2] += vs[i][2];
					}else{
						c[0] += vs[i][0];
						c[1] += vs[i][1];
					}
					bl /= 3;
				}
				for(int i = n-1;i >= h;i--){
					if(br%3 == 0){
						c[1] += vs[i][1];
						c[2] += vs[i][2];
					}else if(br%3 == 1){
						c[0] += vs[i][0];
						c[2] += vs[i][2];
					}else{
						c[0] += vs[i][0];
						c[1] += vs[i][1];
					}
					br /= 3;
				}
				assert c[0] == c[1] && c[1] == c[2];
			}
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
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