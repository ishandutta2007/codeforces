//package educational.round03;
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
		int n = ni(), m = ni(), K = ni(), s = ni();
		int[] a = na(n);
		int[] b = na(n);
		int[][][] cs = new int[2][m][];
		int[] pcs = new int[2];
		for(int i = 0;i < m;i++){
			int t = ni()-1, c = ni();
			cs[t][pcs[t]++] = new int[]{c, i};
		}
		Arrays.sort(cs[0], 0, pcs[0], Comparator.comparingInt(z -> z[0]));
		Arrays.sort(cs[1], 0, pcs[1], Comparator.comparingInt(z -> z[0]));
		int low = 0, high = n+1;
		outer:
		while(high - low > 1){
			int h = high+low>>>1;
			int argmina = 0, argminb = 0;
			for(int i = 0;i < h;i++){
				if(a[i] < a[argmina])argmina = i;
				if(b[i] < b[argminb])argminb = i;
			}
			int p = 0, q = 0;
			long rem = s;
			while(p+q < K){
				if(p == pcs[0]){
					rem -= (long)b[argminb] * cs[1][q][0];
					if(rem < 0){
						low = h;
						continue outer;
					}
					q++;
				}else if(q == pcs[1]){
					rem -= (long)a[argmina] * cs[0][p][0];
					if(rem < 0){
						low = h;
						continue outer;
					}
					p++;
				}else if((long)a[argmina] * cs[0][p][0] < (long)b[argminb] * cs[1][q][0]){
					rem -= (long)a[argmina] * cs[0][p][0];
					if(rem < 0){
						low = h;
						continue outer;
					}
					p++;
				}else{
					rem -= (long)b[argminb] * cs[1][q][0];
					if(rem < 0){
						low = h;
						continue outer;
					}
					q++;
				}
			}
			high = h;
		}
		if(high == n+1){
			out.println(-1);
			return;
		}
		{
			int h = high;
			int argmina = 0, argminb = 0;
			for(int i = 0;i < h;i++){
				if(a[i] < a[argmina])argmina = i;
				if(b[i] < b[argminb])argminb = i;
			}
			int p = 0, q = 0;
			while(p+q < K){
				if(p == pcs[0]){
					q++;
				}else if(q == pcs[1]){
					p++;
				}else if((long)a[argmina] * cs[0][p][0] < (long)b[argminb] * cs[1][q][0]){
					p++;
				}else{
					q++;
				}
			}
			out.println(high);
			for(int i = 0;i < p;i++){
				out.println(cs[0][i][1]+1 + " " + (argmina+1));
			}
			for(int i = 0;i < q;i++){
				out.println(cs[1][i][1]+1 + " " + (argminb+1));
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