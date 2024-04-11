//package evc.elim;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[] cum;
	int ii;
	int n;
	
	void solve()
	{
		n = ni();
		int[] a = radixSort(na(n));
		cum = new long[n+1];
		for(int i = 0;i < n;i++)cum[i+1] = cum[i] + a[i];
		
		long[] best = {Long.MIN_VALUE / 10, 1};
		int[] argbest = null;
		for(int i = 0;i < n;i++){
			ii = i;
			long low = -1, high = Math.min(i, n-1-i)+1;
			final double tau = (Math.sqrt(5)-1)/2;
			long nl = Math.round(high + tau * (low - high));
			long nh = Math.round(low + tau * (high - low));
//			tr(i, nl, nh, high, low);
			long[] vl = f(nl);
			long[] vh = f(nh);
			while(high - low > 2){
//				tr(vl, vh, high, low);
				if(comp(vl, vh) > 0){
					high = nh;
					vh = vl;
					nh = nl;
					nl = Math.round(high + tau * (low - high));
					if(nl == nh)nl--;
					vl = f(nl);
				}else{
					low = nl;
					vl = vh;
					nl = nh;
					nh = Math.round(low + tau * (high - low));
					if(nh == nl)nh++;
					vh = f(nh);
				}
			}
			for(long u = Math.max(low-2, 0);u <= Math.min(high+2, Math.min(i, n-1-i));u++){
				long[] v = f(u);
				v[0] -= v[1] * a[i];
//				tr(i, u, v);
//				tr(v, best, comp(v, best));
				if(comp(v, best) > 0){
					best = v;
					argbest = new int[]{i, (int)u};
				}
			}
		}
		
		out.println(argbest[1]*2+1);
		for(int i = argbest[0]-argbest[1];i <= argbest[0];i++){
			out.print(a[i] + " ");
		}
		for(int i = n-argbest[1];i < n;i++){
			out.print(a[i] + " ");
		}
		out.println();
	}
	
	public static int[] radixSort(int[] f)
	{
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
	}

	
	public int comp(long[] a, long[] b)
	{
		return Long.compare(a[0]*b[1], a[1]*b[0]);
	}
	
	public long[] f(long xl)
	{
		if(xl < 0)return new long[]{-1L, 1};
		if(ii-xl < 0 || n-xl <= ii)return new long[]{-1L, 1};
		int x = (int)xl;
		// [ii-x,ii], [n-x,n-1]
		return new long[]{cum[ii+1] - cum[ii-x] + cum[n-1+1] - cum[n-x], 2*x+1};
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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