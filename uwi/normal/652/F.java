//package educational.round10;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long t = nl();
		int[][] poss = new int[n][];
		int r = 0;
		for(int i = 0;i < n;i++){
			int x = ni();
			char c = nc();
			poss[r++] = new int[]{x, i, c};
		}
		Arrays.sort(poss, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		long shift = 0;
		if(poss[0][2] == 'R'){
			for(int i = 0;i < n;i++){
				if(poss[i][2] == 'L'){
					if(2L*t+poss[0][0]-poss[i][0] >= 0){
						shift += (2L*t+poss[0][0]-poss[i][0])/m+1;
					}
				}
			}
			shift %= n;
		}else{
			for(int i = 0;i < n;i++){
				if(poss[i][2] == 'R'){
					if((2L*t-poss[0][0]-(m-poss[i][0])) >= 0){
						shift += (2L*t-poss[0][0]-(m-poss[i][0]))/m+1;
					}
				}
			}
			shift = -shift;
			shift %= n;
			if(shift < 0)shift += n;
		}
		long[] arets = new long[n];
		long[] srets = new long[n];
		for(int i = 0;i < n;i++){
			arets[i] = to(poss[i][0]*4L, (char)poss[i][2], 4L*m, 4L*t+1, 1);
			srets[i] = to(poss[i][0], (char)poss[i][2], m, t, 0);
		}
		Arrays.sort(arets);
		Arrays.sort(srets);
		long f = to(poss[0][0]*4L, (char)poss[0][2], 4L*m, 4L*t+1, 1);
		long[] rets = new long[n];
		for(int i = 0;i < n;i++){
			if(arets[i] == f){
				// i = shift
				for(int j = 0, k = (int)shift, l = i;j < n;j++,k++,l++){
					if(k == n)k = 0;
					if(l == n)l = 0;
					rets[poss[k][1]] = srets[l];
				}
				for(int j = 0;j < n;j++){
					out.print(rets[j] + " ");
				}
				out.println();
				return;
			}
		}
	}
	
	long to(long x, char dir, long m, long t, int inf)
	{
		long ret = x + t*(dir == 'R' ? 1 : -1);
		ret %= m;
		if(ret <= inf)ret += m;
		if(ret <= inf)ret += m;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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