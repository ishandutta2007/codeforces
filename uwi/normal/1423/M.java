//package bubblecup13.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class M {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		int n = ni(), m = ni();
		List<Integer> cols = new ArrayList<>();
		for(int i = 0;i < m;i++){
			cols.add(i);
		}
		int[] minima = new int[n];
		Arrays.fill(minima, m-1);
		int[] valmin = new int[n];
		Arrays.fill(valmin, Integer.MAX_VALUE);
		SMAWK(cols, 0, n-1, 1, minima, valmin);

		int ans = 0;
		for(int i = 0;i < n;i++){
			if(valmin[i] < valmin[ans]){
				ans = i;
			}
		}
		out.println("! " + valmin[ans]);
		out.flush();
	}

	Map<Long, Integer> cache = new HashMap<>();

	int f(int i, int j)
	{
		long code = (long)i<<32|j;
		if(cache.containsKey(code))return cache.get(code);
		out.println("? " + (i+1) + " " + (j+1));
		out.flush();
		int ret = ni();
		cache.put(code, ret);
		return ret;
	}

	void SMAWK(List<Integer> js, int ib, int ie, int id, int[] minima, int[] valmin) {
		if (ib > ie) return;

		Deque<Integer> js2 = new ArrayDeque<>();
		for (int q = 0, i = ib; q < js.size(); ++q) {
			while (!js2.isEmpty() && f(i, js2.getLast()) >= f(i, js.get(q))) {
				js2.pollLast(); i -= id; }
			if ( js2.size() != (ie-ib)/id ) {
				js2.addLast(js.get(q)); i += id; }
		}

		SMAWK(new ArrayList<>(js2), ib+id, ie, id*2, minima, valmin);

		for (int i = ib, q = 0; i <= ie; i += id*2) {
			int jt = (i + id <= ie ? minima[i+id] : js.get(js.size()-1));
			int fm = Integer.MAX_VALUE, fq;
			for (; q < js.size(); ++q) {
				if ( fm > (fq = f(i, js.get(q))) ) {
					fm = fq;
					minima[i] = js.get(q);
					valmin[i] = fq;
				}
				if (js.get(q).equals(jt)) break;
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
	
	public static void main(String[] args) throws Exception { new M().run(); }
	
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