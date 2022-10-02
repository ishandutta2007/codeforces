//package round180;
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
		int n = ni();
		int[][] ls = new int[4*n][];
		for(int i = 0;i < n;i++){
			int a = ni()-1, b = ni()-1;
			if(a > b){
				int d = a; a = b; b = d;
			}
			ls[i] = new int[]{a, b};
			ls[n+i] = new int[]{b, 2*n+a};
			ls[2*n+i] = new int[]{a+2*n, b+2*n};
			ls[3*n+i] = new int[]{b+2*n, b+4*n};
		}
		int[] conts = enumContains(ls);
		long P1 = 0;
		for(int i = 0;i < n;i++){
			P1 += (long)conts[2*n+i] * conts[n+i];
		}
		long P34 = 0;
		for(int i = 0;i < n;i++){
			int z = n-1-conts[2*n+i]-conts[n+i];
			P34 += (long)z * (conts[2*n+i] + conts[n+i]);
		}
		P34 /= 2;
		long all = (long)n*(n-1)*(n-2)/6;
		out.println(all-P1-P34);
	}
	
	int[] enumContains(int[][] rs)
	{
		int n = rs.length;
		int[][] es = new int[2*n][];
		for(int i = 0;i < n;i++){
			es[2*i] = new int[]{rs[i][0], 1, i};
			es[2*i+1] = new int[]{rs[i][1], -1, i};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int[] ft = new int[n+1];
		int all = 0;
		int p = 0;
		int[] imap = new int[n];
		int[] contains = new int[n];
		for(int i = 0;i < 2*n;i++){
			int[] e = es[i];
			if(e[1] == 1){
				// begin
				imap[e[2]] = p;
				p++;
			}else{
				// end
				contains[e[2]] = all - sumFenwick(ft, imap[e[2]]);
				all++;
				addFenwick(ft, imap[e[2]], 1);
			}
		}
		return contains;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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