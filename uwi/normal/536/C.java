//package round299;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni(), i};
		}
		Arrays.sort(co, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return -Long.compare(a[1], b[1]);
			}
		});
		int[] stack = new int[n+1];
		Arrays.fill(stack, -1);
		int sp = 0;
		for(int i = 0;i < n;i++){
			if(i > 0 && co[i][0] == co[i-1][0])continue;
			while(sp > 0){
				long[] i1 = inter(co[i], co[stack[sp-1]]);
				if(i1[0] <= 0){
					sp--;
					continue;
				}else if(sp-2 >= 0){
					long[] i2 = inter(co[stack[sp-1]], co[stack[sp-2]]);
					long ng = gcd(i1[0], i2[0]);
					i1[0] /= ng; i2[0] /= ng;
					long dg = gcd(i1[1], i2[1]);
					i1[1] /= dg; i2[1] /= dg;
					assert (double)i2[0] * i1[1] < 9E18;
					assert (double)i2[1] * i1[0] < 9E18;
					if(i2[0] * i1[1] > i2[1] * i1[0]){
						sp--;
						continue;
					}
				}
				break;
			}
			stack[sp++] = i;
		}
		boolean[] ok = new boolean[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p < sp && stack[p] == i){
				p++;
				ok[(int)co[i][2]] = true;
			}else if(i > 0 && ok[(int)co[i-1][2]] && co[i][0] == co[i-1][0] && co[i][1] == co[i-1][1]){
				ok[(int)co[i][2]] = true;
			}
		}
		for(int i = 0;i < n;i++){
			if(ok[i]){
				out.print(i+1 + " ");
			}
		}
		out.println();
	}
	
	static long[] inter(long[] a, long[] b)
	{
		long[] ret = new long[]{a[0]*b[0]*(b[1]-a[1]), a[1]*b[1]*(a[0]-b[0])};
		if(ret[1] < 0){
			ret[0] = -ret[0];
			ret[1] = -ret[1];
		}
		return ret;
	}
	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void run() throws Exception
	{
//		int n = 200000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(10000)+1 + " ");
//			sb.append(gen.nextInt(10000)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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