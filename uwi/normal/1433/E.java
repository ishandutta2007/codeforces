//package round677;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Iterator;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] C = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		long F = 1;
		for(int i = 1;i <= n/2-1;i++)F *= i;

		long s = n/2 <= 2 ? 1 : F;
		out.println(C[n][n/2] / 2 * s * s);
	}

		public static class IterablePermutation implements Iterable<int[]>, Iterator<int[]>
			{
				int[] a;
				boolean first = true;

				public IterablePermutation(int n) {
					assert n >= 1;
					a = new int[n];
					for(int i = 0;i < n;i++)a[i] = i;
				}

				public IterablePermutation(int... a) {
					this.a = Arrays.copyOf(a, a.length);
				}

				@Override
				public boolean hasNext() {
					if(first)return true;
					int n = a.length;
					int i;
					for(i = n - 2;i >= 0 && a[i] >= a[i+1];i--);
					return i != -1;
				}

				@Override
				public int[] next() {
					if(first) {
						first = false;
						return a;
					}
					int n = a.length;
					int i;
					for(i = n - 2;i >= 0 && a[i] >= a[i+1];i--);
					assert i != -1;
					int j;
					for(j = i + 1;j < n && a[i] < a[j];j++);
					int d = a[i]; a[i] = a[j - 1]; a[j - 1] = d;
					for(int p = i + 1, q = n - 1;p < q;p++,q--){
						d = a[p]; a[p] = a[q]; a[q] = d;
					}
					return a;
				}

				@Override
				public Iterator<int[]> iterator() {
					return this;
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