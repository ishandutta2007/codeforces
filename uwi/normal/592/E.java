//package round328;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), c = ni(), d = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni()-c, ni()-d};
		}
		long[][] es = new long[2*n][];
		for(int i = 0;i < n;i++){
			es[i] = new long[]{co[i][0], co[i][1], 1};
			es[i+n] = new long[]{-co[i][0], -co[i][1], -1};
		}
		Arrays.sort(es, compArgl);
		long nin = 0;
		for(int i = 0;i < n;i++){
			if(co[i][1] < 0 || co[i][1] == 0 && co[i][0] < 0){
				nin++;
			}
		}
		long all = 0;
		
		for(long[] e : es){
			nin += e[2];
			if(e[2] == 1){
				all += (nin-1)*(nin-2)/2;
			}
		}
		for(int i = 0;i < 2*n;){
			if(es[i][1] < 0 || es[i][1] == 0 && es[i][0] < 0)break;
			int j = i;
			for(;j < 2*n && es[i][0] * es[j][1] - es[j][0] * es[i][1] == 0 && es[i][0] * es[j][0] + es[i][1] * es[j][1] > 0;j++);
			
			long pos = 0, neg = 0;
			for(int k = i;k < j;k++){
				if(es[k][2] == 1){
					pos++;
				}else{
					neg++;
				}
			}
			all += pos*(pos-1)/2*neg + neg*(neg-1)/2*pos + pos*neg * (n-pos-neg);
			
			i = j;
		}
		all = (long)n*(n-1)*(n-2)/6-all;
		out.println(all);
	}
	
	public static Comparator<long[]> compArgl = new Comparator<long[]>(){
		public int compare(long[] a, long[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || (ay == 0 && ax > 0) ? 0 : 1;
			int zb = by > 0 || (by == 0 && bx > 0) ? 0 : 1;
			if(za != zb)return za - zb;
			int v = Long.compare(ay*bx, ax*by);
			if(v != 0)return v;
			return Long.compare(a[2], b[2]);
		}
	};

	
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