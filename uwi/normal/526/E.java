//package zepto2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), q = ni();
		int[] a = new int[2*n];
		for(int i = 0;i < n;i++){
			a[i] = a[i+n] = ni();
		}
		long[] cum = new long[2*n+1];
		for(int i = 0;i < 2*n;i++){
			cum[i+1] = cum[i] + a[i];
		}
		
		int[] next = new int[2*n];
		for(int Q = q;Q >= 1;Q--){
			long b = nl();
			if(b >= cum[n]){
				out.println(1);
				continue;
			}
			
			int p = 0;
			for(int i = 0;i < 2*n;i++){
				while(p < 2*n && cum[p+1] - cum[i] <= b)p++;
				next[i] = p;
			}
//			boolean[] ved = new boolean[2*n];
			int minstep = Integer.MAX_VALUE;
			
			int minoff = 2*n;
			int argmin = -1;
			for(int i = next[0];i < 2*n;i++){
				if(next[i]-i < minoff && next[i] > next[i-1]){
					minoff = next[i]-i;
					argmin = i;
				}
			}
			for(int i = argmin, v = argmin%n;i < next[argmin];i++, v++){
				if(v == n)v = 0;
				int step = 0;
				for(int j = v;j < v+n;j = next[j], step++);
				minstep = Math.min(minstep, step);
			}
//			for(int i = 0;i < n;i++){
//				if(ved[i])continue;
//				int step = 0;
//				for(int j = i;j < i+n;j = next[j], step++){
////					if(ved[j])continue inner;
//					ved[j] = true;
//				}
//				minstep = Math.min(minstep, step);
//			}
			out.println(minstep);
			
//			int[][] g = sparseNext(next);
		}
	}
	
	public static int[][] sparseNext(int[] f)
	{
		int n = f.length;
		final int m = 31; // 
		int[][] sf = new int[m][n];
		sf[0] = Arrays.copyOf(f, n);
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sf[i][j] = sf[i-1][j] == -1 ? -1 : sf[i-1][sf[i-1][j]];
			}
		}
		return sf;
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