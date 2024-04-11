//package round245;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Set;
import java.util.TreeSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + a[i];
		}
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{i, cum[i+1]};
		}
		out.println(findClosestPair(co));
	}
	
	public static long findClosestPair(long[][] co)
	{
		Arrays.sort(co, new Comparator<long[]>() {
			public int compare(long[] a, long[] b)
			{
				return Long.compare(a[0], b[0]);
			}
		});
		// y,ind
		TreeSet<long[]> ts = new TreeSet<long[]>(new Comparator<long[]>() {
			public int compare(long[] a, long[] b)
			{
				if(a[0] - b[0] != 0)return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		int N = co.length;
		long h = 105000L*105000L+2000005000L*2000050000L;
		long sq = (long)Math.sqrt(h);
		int p = 0;
		for(int i = 0;i < N;i++) {
			while(co[p][0] < co[i][0]-sq) {
				ts.remove(new long[]{co[p][1], p});
				p++;
			}
			long[] inf = ts.higher(new long[]{co[i][1]-sq, -1});
			long[] sup = ts.higher(new long[]{co[i][1]+sq+1, -1});
			Set<long[]> sub = null;
			if(inf != null && sup != null){
				sub = ts.subSet(inf, sup);
			}else if(inf != null){
				sub = ts.tailSet(inf);
			}else if(sup != null){
				sub = ts.headSet(sup);
			}
			if(sub != null){
				for(long[] cur : sub) {
					int j = (int)cur[1];
					long v = (long)(co[i][0]-co[j][0])*(co[i][0]-co[j][0])+
							 (long)(co[i][1]-co[j][1])*(co[i][1]-co[j][1]);
					if(h > v){
						h = v;
						sq = (int)Math.sqrt(h);
					}
				}
			}
			
			ts.add(new long[]{co[i][1], i});
		}
		return h;
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((i % 2 == 0 ? 10000 : -10000) + " ");
////			sb.append(gen.nextInt(20000)-10000 + " ");
//		}
//		INPUT = sb.toString();
		
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