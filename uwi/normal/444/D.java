//package round254;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int z = 27*27*27*27;
		int n = s.length;
		
		int m = 0;
		m += n;
		m += Math.max(n-1, 0);
		m += Math.max(n-2, 0);
		m += Math.max(n-3, 0);
		int[] from = new int[m];
		int[] to = new int[m];
		int p = 0;
		for(int len = 1;len <= 4;len++){
			for(int i = 0;i+len-1 < n;i++){
				int d = 0;
				for(int j = 0;j < len;j++){
					d = d * 27 + (1 + s[i+j] - 'a');
				}
				from[p] = d; to[p] = i; p++;
			}
		}
		int[][] g = packD(z, from, to);
		for(int[] x : g){
			Arrays.sort(x);
		}
		int sq = (int)Math.sqrt(p);
		if(sq == 0)sq = 1;
		
		int[] major = new int[z];
		int[] imajor = new int[z];
		Arrays.fill(imajor, -1);
		int mp = 0;
		for(int i = 0;i < z;i++){
			if(g[i].length >= sq){
				major[mp] = i;
				imajor[i] = mp;
				mp++;
			}
		}
		
		int[][] d = new int[mp][mp];
//		for(int i = 0;i < mp;i++){
//			for(int j = i;j < mp;j++){
//				d[i][j] = d[j][i] = getCloseDistance(major[i], major[j], g);
//			}
//		}
		
		int Q = ni();
		for(int q = 0;q < Q;q++){
			char[] qs = ns().toCharArray();
			char[] qt = ns().toCharArray();
			int scode = code(qs);
			int tcode = code(qt);
			if(imajor[scode] >= 0 && imajor[tcode] >= 0){
				int x = imajor[scode], y = imajor[tcode];
				if(d[x][y] == 0){
					d[x][y] = d[y][x] = getCloseDistance(major[x], major[y], g);
				}
				out.println(d[x][y]);
			}else{
				int dd = getCloseDistance(scode, tcode, g);
				out.println(dd == Integer.MAX_VALUE ? -1 : dd);
			}
		}
	}
	
	int getCloseDistance(int scode, int tcode, int[][] g)
	{
		int[] shorter = g[scode];
		int[] longer = g[tcode];
		int slen = len(scode);
		int llen = len(tcode);
		if(shorter.length > longer.length){
			int[] dum = shorter; shorter = longer; longer = dum;
			int dd = slen; slen = llen; llen = dd;
		}
		int close = Integer.MAX_VALUE;
		for(int spos : shorter){
			int ind = Arrays.binarySearch(longer, spos);
			if(ind < 0){
				int bef = -ind-2;
				if(bef >= 0){
					int inf = Math.min(longer[bef], spos);
					int sup = Math.max(longer[bef] + llen-1, spos+slen-1);
					close = Math.min(close, sup-inf+1);
				}
				int aft = -ind-1;
				if(aft < longer.length){
					int inf = Math.min(longer[aft], spos);
					int sup = Math.max(longer[aft] + llen-1, spos+slen-1);
					close = Math.min(close, sup-inf+1);
				}
			}else{
				close = Math.min(close, Math.max(slen, llen));
			}
		}
		return close;
	}
	
	static int code(char[] s)
	{
		int d = 0;
		for(char c : s){
			d = d * 27 + (1 + c - 'a');
		}
		return d;
	}
	
	static int len(int code)
	{
		if(code < 27)return 1;
		if(code < 27*27)return 2;
		if(code < 27*27*27)return 3;
		return 4;
	}
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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