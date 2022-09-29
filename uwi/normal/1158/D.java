import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		char[] s = ns(n-2);
		int arg = 0;
		for(int i = 0;i < n;i++){
			if(co[i][1] < co[arg][1] || 
					co[i][1] == co[arg][1] &&
					co[i][0] < co[arg][0]){
				arg = i;
			}
		}
		boolean[] done = new boolean[n];
		int[] perm = new int[n];
		perm[0] = arg;
		done[arg] = true;
		{
			int larg = -1;
			int[] b = new int[]{-1000000007, co[arg][1]+1};
			for(int j = 0;j < n;j++){
				if(done[j])continue;
				if(larg == -1){
					larg = j;
					continue;
				}
				if(inArg(
						co[arg][0]-b[0], co[arg][1]-b[1],
						co[larg][0]-co[arg][0], co[larg][1]-co[arg][1], 
						co[j][0]-co[arg][0], co[j][1]-co[arg][1]
						) >= 0){
					larg = j;
				}
			}
			if(s[0] == 'L'){
				perm[1] = larg;
			}else{
				perm[1] = perm[0];
				perm[0] = larg;
			}
			done[larg] = true;
		}
		
		for(int i = 1;i < n-1;i++){
			if(s[i-1] == 'L'){
				if(i == n-2 || s[i] == 'L'){
					int larg = -1;
					for(int j = 0;j < n;j++){
						if(done[j])continue;
						if(larg == -1){
							larg = j;
							continue;
						}
						if(inArg(
								co[perm[i]][0]-co[perm[i-1]][0], co[perm[i]][1]-co[perm[i-1]][1],
								co[larg][0]-co[perm[i]][0], co[larg][1]-co[perm[i]][1], 
								co[j][0]-co[perm[i]][0], co[j][1]-co[perm[i]][1]
								) >= 0){
							larg = j;
						}
					}
					perm[i+1] = larg;
					done[larg] = true;
				}else{
					int larg = -1;
					for(int j = 0;j < n;j++){
						if(done[j])continue;
						if(larg == -1){
							larg = j;
							continue;
						}
						if(inArg(
								co[perm[i]][0]-co[perm[i-1]][0], co[perm[i]][1]-co[perm[i-1]][1],
								co[j][0]-co[perm[i]][0], co[j][1]-co[perm[i]][1],
								co[larg][0]-co[perm[i]][0], co[larg][1]-co[perm[i]][1]
								) >= 0){
							larg = j;
						}
					}
					perm[i+1] = larg;
					done[larg] = true;
				}
			}else{
				if(i == n-2 || s[i] == 'R'){
					int larg = -1;
					for(int j = 0;j < n;j++){
						if(done[j])continue;
						if(larg == -1){
							larg = j;
							continue;
						}
						if(inArg(
								co[larg][0]-co[perm[i]][0], co[larg][1]-co[perm[i]][1], 
								co[perm[i]][0]-co[perm[i-1]][0], co[perm[i]][1]-co[perm[i-1]][1],
								co[j][0]-co[perm[i]][0], co[j][1]-co[perm[i]][1]
								) >= 0){
							larg = j;
						}
					}
					perm[i+1] = larg;
					done[larg] = true;
				}else{
					int larg = -1;
					for(int j = 0;j < n;j++){
						if(done[j])continue;
						if(larg == -1){
							larg = j;
							continue;
						}
						if(inArg(
								co[larg][0]-co[perm[i]][0], co[larg][1]-co[perm[i]][1], 
								co[j][0]-co[perm[i]][0], co[j][1]-co[perm[i]][1],
								co[perm[i]][0]-co[perm[i-1]][0], co[perm[i]][1]-co[perm[i-1]][1]
								) >= 0){
							larg = j;
						}
					}
					perm[i+1] = larg;
					done[larg] = true;
				}
			}
		}
		
		for(int v : perm){
			out.print(v + 1  +" ");
		}
		out.println();
	}
	
	public static int inArg(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (int)(Long.signum(ax*cy-ay*cx)-Long.signum(bx*cy-by*cx)-Long.signum(ax*by-ay*bx));
	}
	
	public static int inArg(long x, long y, long ax, long ay, long bx, long by, long cx, long cy)
	{
		return inArg(ax-x, ay-y, bx-x, by-y, cx-x, cy-y);
	}
	
	public static int inArg(long[] t, long[] a, long[] b, long[] c){ return inArg(a[0]-t[0], a[1]-t[1], b[0]-t[0], b[1]-t[1], c[0]-t[0], c[1]-t[1]); }
	public static int inArg(int[] t, int[] a, int[] b, int[] c){ return inArg(a[0]-t[0], a[1]-t[1], b[0]-t[0], b[1]-t[1], c[0]-t[0], c[1]-t[1]); }

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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