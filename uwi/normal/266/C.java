//package round163x;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		boolean[][] g = new boolean[n][n];
		int[] rsum = new int[n];
		int[] csum = new int[n];
		for(int i = 0;i < n-1;i++){
			int r = ni()-1, c = ni()-1;
			g[r][c] = true;
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				rsum[i] += g[i][j] ? 1 : 0;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				csum[i] += g[j][i] ? 1 : 0;
			}
		}
		
		List<int[]> hands = new ArrayList<int[]>();
		for(int z = 0;z < n;z++){
			if(rsum[z] > 0){
				for(int j = z+1;j < n;j++){
					if(rsum[j] == 0){
						hands.add(new int[]{1, z+1, j+1});
						for(int k = 0;k < n;k++){
							boolean dum = g[j][k]; g[j][k] = g[z][k]; g[z][k] = dum;
						}
						rsum[j] = rsum[z];
						rsum[z] = 0;
						break;
					}
				}
			}
			if(csum[z] == 0){
				for(int j = z+1;j < n;j++){
					if(csum[j] > 0){
						hands.add(new int[]{2, z+1, j+1});
						for(int k = 0;k < n;k++){
							boolean dum = g[k][j]; g[k][j] = g[k][z]; g[k][z] = dum;
						}
						csum[z] = csum[j];
						csum[j] = 0;
						break;
					}
				}
			}
			for(int k = 0;k < n;k++){
				if(g[k][z])rsum[k]--;
			}
		}
		check(g);
		
		out.println(hands.size());
		for(int[] hand : hands){
			out.println(hand[0] + " " + hand[1] + " " + hand[2]);
		}
	}
	
	void check(boolean[][] g)
	{
		int n = g.length;
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				if(g[i][j]){
					throw new AssertionError(i + " " + j);
				}
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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