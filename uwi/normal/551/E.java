//package round307;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		int s = (int)(Math.sqrt(Q)*3);
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{1, ni()-1, ni()-1, ni()};
			}else{
				qs[i] = new int[]{2, ni()};
			}
		}
		
		int[] xs = new int[2*s+2];
		long[] atemp = new long[n];
		long[] plus = new long[n];
		for(int i = 0;i < Q;i += s){
			int j = Math.min(Q, i+s);
			int p = 0;
			for(int k = i;k < j;k++){
				if(qs[k][0] == 1){
					xs[p++] = qs[k][1];
					xs[p++] = qs[k][2]+1;
				}
			}
			xs[p++] = 0;
			xs[p++] = n;
			Arrays.sort(xs, 0, p);
			int pp = 0;
			for(int k = 0;k < p;k++){
				if(k == 0 || xs[k] != xs[k-1]){
					xs[pp++] = xs[k];
				}
			}
			p = -1;
			for(int k = 0;k < n;k++){
				atemp[k] = a[k]<<20|k;
			}
			for(int k = 0;k < pp-1;k++){
				Arrays.sort(atemp, xs[k], xs[k+1]);
			}
			Arrays.fill(plus, 0L);
			for(int k = i;k < j;k++){
				int[] q = qs[k];
				if(q[0] == 1){
					int from = Arrays.binarySearch(xs, 0, pp, q[1]);
					int to = Arrays.binarySearch(xs, 0, pp, q[2]+1);
					for(int z = from;z < to;z++){
						plus[z] += q[3];
					}
				}else{
					int inf = 9999999;
					int sup = -1;
					for(int z = 0;z < pp-1;z++){
						if(q[1]-plus[z] < 0)continue;
						// inf
						int ind = Arrays.binarySearch(atemp, xs[z], xs[z+1], (q[1]-plus[z]<<20)-1);
						ind = -ind-1;
						if(ind < xs[z+1]){
							if((atemp[ind]>>>20) == q[1]-plus[z]){
								inf = (int)(atemp[ind]&(1<<20)-1);
								break;
							}
						}
					}
					for(int z = pp-2;z >= 0;z--){
						if(q[1]-plus[z] < 0)continue;
						// sup
						int ind = Arrays.binarySearch(atemp, xs[z], xs[z+1], (q[1]-plus[z]+1L<<20)-1);
						ind = -ind-2;
						if(ind >= xs[z]){
							if((atemp[ind]>>>20) == q[1]-plus[z]){
								sup = (int)(atemp[ind]&(1<<20)-1);
								break;
							}
						}
					}
					out.println(sup == -1 ? -1 : sup-inf);
				}
			}
			
			for(int k = 0;k < pp-1;k++){
				for(int l = xs[k];l < xs[k+1];l++){
					a[l] += plus[k];
					if(a[l] >= 1000000007)a[l] = 1000000007;
				}
			}
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