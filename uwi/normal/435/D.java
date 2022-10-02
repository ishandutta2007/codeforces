//package round249;
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
	
	int[][] down(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[][] down = new int[n][m];
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '1'){
					down[i][j] = 0;
				}else{
					down[i][j] = 1 + (i+1 < n ? down[i+1][j] : 0);
				}
			}
		}
		return down;
	}
	
	int[][] right(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[][] right = new int[n][m];
		for(int j = m-1;j >= 0;j--){
			for(int i = 0;i < n;i++){
				if(map[i][j] == '1'){
					right[i][j] = 0;
				}else{
					right[i][j] = 1 + (j+1 < m ? right[i][j+1] : 0);
				}
			}
		}
		return right;
	}
	
	int[][] rd(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[][] rd = new int[n][m];
		for(int j = m-1;j >= 0;j--){
			for(int i = n-1;i >= 0;i--){
				if(map[i][j] == '1'){
					rd[i][j] = 0;
				}else{
					rd[i][j] = 1 + (i+1 < n && j+1 < m ? rd[i+1][j+1] : 0);
				}
			}
		}
		return rd;
	}
	
	int[][] ld(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[][] ld = new int[n][m];
		for(int j = 0;j < m;j++){
			for(int i = n-1;i >= 0;i--){
				if(map[i][j] == '1'){
					ld[i][j] = 0;
				}else{
					ld[i][j] = 1 + (i+1 < n && j-1 >= 0 ? ld[i+1][j-1] : 0);
				}
			}
		}
		return ld;
	}
	
	int countDRLD(int[][] down, int[][] right, int[][] rd, int[][] ld)
	{
		int ct = 0;
		int n = down.length, m = down[0].length;
		// d+r+ld
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int w = Math.min(down[i][j], right[i][j]);
				for(int k = 1;k < w;k++){
					if(ld[i][j+k] >= k+1)ct++;
				}
			}
		}
		return ct;
	}
	
	int countDRDLD(int[][] down, int[][] right, int[][] rd, int[][] ld)
	{
		int ct = 0;
		int n = down.length, m = down[0].length;
		// d+rd+ld
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int w = Math.min(rd[i][j], (down[i][j]+1)/2);
				for(int k = 1;k < w;k++){
					if(ld[i+k][j+k] >= k+1)ct++;
				}
			}
		}
		return ct;
	}
	
	int countRRDLD(int[][] down, int[][] right, int[][] rd, int[][] ld) 
	{
		int ct = 0;
		int n = down.length, m = down[0].length;
		// r+rd+ld
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int w = Math.min(rd[i][j], (right[i][j]+1)/2);
				for(int k = 1;k < w;k++){
					if(ld[i][j+2*k] >= k+1)ct++;
				}
			}
		}
		return ct;
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		
		int ct = 0;
		{
			int[][] down = down(map);
			int[][] right = right(map);
			int[][] rd = rd(map);
			int[][] ld = ld(map);
		
			ct += 
					countDRLD(down, right, rd, ld) +
					countDRDLD(down, right, rd, ld) +
					countRRDLD(down, right, rd, ld);
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0, k = m-1;j < k;j++,k--){
				char c = map[i][j]; map[i][j] = map[i][k];  map[i][k] = c;
			}
		}
		
		{
			int[][] down = down(map);
			int[][] right = right(map);
			int[][] rd = rd(map);
			int[][] ld = ld(map);
		
			ct += 
					countDRLD(down, right, rd, ld) +
					countDRDLD(down, right, rd, ld);
		}
		for(int j = 0, k = n-1;j < k;j++,k--){
			char[] row = map[j]; map[j] = map[k]; map[k] = row;
		}
		{
			int[][] down = down(map);
			int[][] right = right(map);
			int[][] rd = rd(map);
			int[][] ld = ld(map);
		
			ct += 
					countDRLD(down, right, rd, ld) +
					countRRDLD(down, right, rd, ld);
		}
		for(int i = 0;i < n;i++){
			for(int j = 0, k = m-1;j < k;j++,k--){
				char c = map[i][j]; map[i][j] = map[i][k];  map[i][k] = c;
			}
		}
		{
			int[][] down = down(map);
			int[][] right = right(map);
			int[][] rd = rd(map);
			int[][] ld = ld(map);
		
			ct += 
					countDRLD(down, right, rd, ld);
		}
		out.println(ct);
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