//package round466;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{1, ni()-1, ni()-1, i, -1};
			}else{
				qs[i] = new int[]{2, ni()-1, ni(), -1};
			}
		}
		int[] vs = Arrays.copyOf(a, n+Q);
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2)vs[n+i] = qs[i][2];
		}
		vs = shrink(vs);
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2)qs[i][2] = vs[n+i];
		}
		for(int i = 0;i < n;i++){
			a[i] = vs[i];
		}
		
		int[] b = Arrays.copyOf(a, n);
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2){
				qs[i][3] = b[qs[i][1]];
				b[qs[i][1]] = qs[i][2];
			}
		}
		
		int[][] qos = new int[Q][];
		int p = 0;
		for(int[] q : qs){
			if(q[0] == 1)qos[p++] = q;
		}
		qos = Arrays.copyOf(qos, p);
		
//		int B = (int)Math.sqrt(n);
		int B = (int)Math.pow(2*n-1, 2./3)*7/6;
		Arrays.sort(qos, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[3]/B != b[3]/B)return a[3] - b[3];
				if(a[1]/B != b[1]/B)return a[1] - b[1];
				return a[1]/B%2 == 0 ? a[2] - b[2] : b[2] - a[2];
			}
		});

		Freqs f = new Freqs(n+Q+3);
		int L = 0, R = -1, T = -1;
		for(int[] q : qos){
			while(T < q[3]){
				int[] tar = qs[++T];
				if(tar[0] == 2){
					if(L <= tar[1] && tar[1] <= R){
						f.dec(tar[3]);
						f.inc(tar[2]);
					}
					a[tar[1]] = tar[2];
				}
			}
			while(T > q[3]){
				int[] tar = qs[T--];
				if(tar[0] == 2){
					if(L <= tar[1] && tar[1] <= R){
						f.dec(tar[2]);
						f.inc(tar[3]);
					}
					a[tar[1]] = tar[3];
				}
			}
			while(R < q[2])f.inc(a[++R]);
			while(L > q[1])f.inc(a[--L]);
			while(R > q[2])f.dec(a[R--]);
			while(L < q[1])f.dec(a[L++]);
			
			q[4] = f.mex();
		}
		for(int[] q : qs){
			if(q[0] == 1){
				out.println(q[4]);
			}
		}
	}
	
	public static class Freqs {
		public int[] f;
		public int[] ff;
		public int max;
		
		public Freqs(int n)
		{
			f = new int[n];
			ff = new int[n+1];
			ff[0] = n;
			max = 0;
		}
		
		int mex()
		{
			for(int i = 0;;i++){
				if(ff[i] == 0)return i;
			}
		}
		
		public void inc(int x)
		{
			if(x < 0 || x >= ff.length)throw new RuntimeException();
			ff[f[x]]--;
			ff[f[x]+1]++;
			if(max == f[x])max = f[x]+1;
			f[x]++;
		}
		
		public void dec(int x)
		{
			if(x < 0 || x >= ff.length)throw new RuntimeException();
			if(f[x] == 0)throw new RuntimeException();
			ff[f[x]]--;
			ff[f[x]-1]++;
			if(max == f[x] && ff[f[x]] == 0)max = f[x]-1;
			f[x]--;
		}
	}
	
	public static int[] shrink(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		b = radixSort(b);
		int[] ret = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0)
				p++;
			ret[(int) b[i]] = p;
		}
		return ret;
	}
	
	public static long[] radixSort(long[] f){ return radixSort(f, f.length); }
	public static long[] radixSort(long[] f, int n)
	{
		long[] to = new long[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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