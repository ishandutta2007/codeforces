//package round225;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] co = new int[m][];
		for(int i = 0;i < m;i++){
			co[i] = new int[]{ni(), ni()};
		}
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] != b[1])return a[1] - b[1];
				return a[0] - b[0];
			}
		});
		int y = 0;
		int p = 0;
		int[][] row = null;
		while(p < m){
			int fp = p;
			while(p < m && co[p][1] == co[fp][1])p++;
			if(y == 0){
				if(co[fp][1] > 1){
					row = new int[][]{{1, n}};
					row = process(row, co, fp, p, n);
				}else{
					row = new int[][]{{1, co[fp][0]-1}};
				}
			}else{
				if(co[fp][1] > y+1){
					if(row.length > 0){
						row = new int[][]{{row[0][0], n}};
					}
				}
				row = process(row, co, fp, p, n);
			}
			y = co[fp][1];
		}
		if(y < n){
			if(row.length > 0){
				row = new int[][]{{row[0][0], n}};
			}
		}
		if(row.length > 0 && row[row.length-1][1] == n){
			out.println(2*n-2);
		}else{
			out.println(-1);
		}
	}
	
	int[][] process(int[][] prev, int[][] co, int s, int t, int n)
	{
		int[][] ret = new int[prev.length+t-s+1][];
		int z = 0;
		for(int p = 0, q = s;p < prev.length && q <= t;){
			int ql = q == s ? 1 : co[q-1][0]+1;
			int qr = q == t ? n : co[q][0]-1;
			if(ql > qr){
				q++;
			}else{
				if(Math.max(prev[p][0], ql) <= Math.min(prev[p][1], qr)){
					ret[z++] = new int[]{Math.max(prev[p][0], ql), qr};
				}
				if(prev[p][1] < qr){
					p++;
				}else{
					q++;
				}
			}
		}
		return Arrays.copyOf(ret, z);
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
	
	public static void main(String[] args) throws Exception { new B3().run(); }
	
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