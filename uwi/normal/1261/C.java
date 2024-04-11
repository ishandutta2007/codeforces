//package round602;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int[][] cum = new int[n+1][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + (map[i][j] == 'X' ? 1 : 0);
			}
		}
		
		int low = 0, high = Math.min(n,m)+1;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(h, map, cum)){
				low = h;
			}else{
				high = h;
			}
		}
		out.println(low);
		restore(low, map, cum);
	}
	
	boolean ok(int h, char[][] map, int[][] cum)
	{
		int n = map.length, m = map[0].length;
		int[][] stamp = new int[n+2][m+2];
		int o = 2*h+1;
		for(int i = 0;i+o <= n;i++){
			for(int j = 0;j+o <= m;j++){
				if(cum[i+o][j+o] - 
						cum[i+o][j] - 
						cum[i][j+o] +
						cum[i][j] == (o)*(o)){
					stamp[i+1][j+1]++;
					stamp[i+o+1][j+1]--;
					stamp[i+1][j+o+1]--;
					stamp[i+o+1][j+o+1]++;
				}
			}
		}
		boolean ret = true;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				stamp[i+1][j+1] += 
						stamp[i][j+1] + stamp[i+1][j]
								- stamp[i][j];
				if((stamp[i+1][j+1] > 0) != (map[i][j] == 'X')){
//					return false;
					ret = false;
				}
			}
		}
		return ret;
	}
	
	void restore(int h, char[][] map, int[][] cum)
	{
		int n = map.length, m = map[0].length;
		int o = 2*h+1;
		char[][] ret = new char[n][m];
		for(int i = 0;i < n;i++)Arrays.fill(ret[i], '.');
		for(int i = 0;i+o <= n;i++){
			for(int j = 0;j+o <= m;j++){
				if(cum[i+o][j+o] - 
						cum[i+o][j] - 
						cum[i][j+o] +
						cum[i][j] == (o)*(o)){
					ret[i+h][j+h] = 'X';
				}
			}
		}
		for(int i = 0;i < n;i++){
			out.println(new String(ret[i]));
		}
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 1;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m;j++){
//				sb.append("X");
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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