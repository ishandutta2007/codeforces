//package round366;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] nots = new int[Q];
		int p = 0;
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int w = ni()-1;
				nots[p++] = w;
				qs[i] = new int[]{t, w};
			}else if(t == 2){
				int id = ni()-1;
				qs[i] = new int[]{t, id};
			}else if(t == 3){
				int num = ni();
				qs[i] = new int[]{t, num};
			}
		}
		int[][] g = makeBuckets(nots, n+1, p);
		Random gen = new Random();
		for(int[] row : g){
			shuffle(row, gen);
			Arrays.sort(row);
		}
		int np = 0;
		boolean[] read = new boolean[Q];
		int tail = 0;
		int unread = 0;
		for(int[] q : qs){
			if(q[0] == 1){
				np++;
				unread++;
			}else if(q[0] == 2){
				int ind = Arrays.binarySearch(g[q[1]], np-1);
				if(ind < 0)ind = -ind-2;
				while(ind >= 0 && !read[g[q[1]][ind]]){
					read[g[q[1]][ind]] = true;
					unread--;
					ind--;
				}
			}else if(q[0] == 3){
				while(tail < q[1]){
					if(!read[tail])unread--;
					read[tail] = true;
					tail++;
				}
			}
			out.println(unread);
		}
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	public static int[][] makeBuckets(int[] a, int sup, int n)
	{
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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