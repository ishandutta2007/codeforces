//package round306;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni();
		if(K % 2 == 0){
			out.println("NO");
		}else{
			for(int n = 1;n <= 300;n+=2){
				int[] d = new int[n];
				d[0] = K-1;
				for(int i = 1;i < n;i++){
					d[i] = K;
				}
				int[][] g = giveSimpleGraph(d);
				if(g != null){
					out.println("YES");
					out.println(2*n + " " + K*n);
					out.println(1 + " " + (n+1));
					for(int[] row : g){
						out.println((row[0]+1) + " " + (row[1]+1));
						out.println((row[0]+n+1) + " " + (row[1]+n+1));
					}
					return;
				}
			}
			out.println("NO");
		}
	}
	
	public static int[][] giveSimpleGraph(int[] d)
	{
		int n = d.length;
		int dsum = 0;
		for(int v : d)dsum += v;
		if((dsum&1) == 1)return null;
		int[][] es = new int[dsum/2][];
		int p = 0;
		
		int[][] dr = new int[n][];
		for(int i = 0;i < n;i++){
			dr[i] = new int[]{d[i], i};
		}
		Arrays.sort(dr, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[][] temp = new int[n][];
		for(int i = n-1;i >= 0;i--){
			if(dr[i][0] > i)return null;
			int j;
			for(j = i-1;dr[i][0] > 0 && j >= 0 && dr[j][0] > 0;j--){
				dr[j][0]--; dr[i][0]--;
				es[p++] = new int[]{dr[i][1], dr[j][1]};
			}
			if(dr[i][0] > 0)return null;
			
			j++;
			int q = 0;
			int r = 0;
			for(int k = j;k < i;k++){
				while(q < j && dr[q][0] < dr[k][0])temp[r++] = dr[q++];
				temp[r++] = dr[k];
			}
			while(q < j)temp[r++] = dr[q++];
			for(int k = 0;k < i;k++)dr[k] = temp[k];
		}
		return es;
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