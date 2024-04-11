//package round510;
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
	
	int mod = 998244353;
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++)a[i] = na(m);
		
		int r = ni()-1, c = ni()-1;
		int[][] as = new int[n*m][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				as[p++] = new int[]{i, j, a[i][j]};
			}
		}
		
		Arrays.sort(as, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[2] - b[2]);
			}
		});
		
		long ans = 0;
		boolean boot = false;
		
		long r0, r1, r2;
		long c0, c1, c2;
		r0 = r1 = r2 = 0;
		c0 = c1 = c2 = 0;
		
		for(int i = 0;i < p;){
			int j = i;
			while(j < p && as[i][2] == as[j][2])j++;
			if(j == p)break;
			
			if(boot){
				for(int l = i;l < j;l++){
					r2--;
					r1 -= -as[l][0]*2;
					r0 -= as[l][0]*as[l][0];
					c2--;
					c1 -= -as[l][1]*2;
					c0 -= as[l][1]*as[l][1];
				}
			}
			boolean hit = false;
			for(int k = i;k < j;k++){
				if(as[k][0] == r && as[k][1] == c){
					boot = true;
					hit = true;
					for(int l = p-1;l >= j;l--){
						r2++;
						r1 += -as[l][0]*2;
						r0 += as[l][0]*as[l][0];
						c2++;
						c1 += -as[l][1]*2;
						c0 += as[l][1]*as[l][1];
					}
				}
			}
			if(boot){
				int num = p-j;
				long d = 0;
				for(int k = i;k < j;k++){
					if(hit){
						if(as[k][0] == r && as[k][1] == c){
						}else{
							continue;
						}
					}
					d += 
							((r2*as[k][0]+r1)*as[k][0]+r0) +
							((c2*as[k][1]+c1)*as[k][1]+c0);
					d %= mod;
				}
				ans += (hit ? 1 : invl(p-i, mod))*invl(num, mod) % mod * d;
				ans %= mod;
			}
			
			i = j;
		}
		
		out.println(ans);
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
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