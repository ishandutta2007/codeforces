//package round419;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		List<String> best = null;
		outer:
		{
			List<String> hands = new ArrayList<>();
			int[][] b = new int[n][];
			for(int i = 0;i < n;i++)b[i] = Arrays.copyOf(a[i], m);
			for(int i = 0;i < n;i++){
				int min = 99999999;
				for(int j = 0;j < m;j++){
					min = Math.min(min, b[i][j]);
				}
				for(int j = 0;j < min;j++){
					hands.add("row " + (i+1));
				}
				for(int j = 0;j < m;j++){
					b[i][j] -= min;
				}
			}
			for(int i = 0;i < m;i++){
				int min = 99999999;
				for(int j = 0;j < n;j++){
					min = Math.min(min, b[j][i]);
				}
				for(int j = 0;j < min;j++){
					hands.add("col " + (i+1));
				}
				for(int j = 0;j < n;j++){
					b[j][i] -= min;
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(b[i][j] != 0)break outer;
				}
			}
			if(best == null || hands.size() < best.size()){
				best = hands;
			}
		}
		outer:
		{
			List<String> hands = new ArrayList<>();
			int[][] b = new int[n][];
			for(int i = 0;i < n;i++)b[i] = Arrays.copyOf(a[i], m);
			for(int i = 0;i < m;i++){
				int min = 99999999;
				for(int j = 0;j < n;j++){
					min = Math.min(min, b[j][i]);
				}
				for(int j = 0;j < min;j++){
					hands.add("col " + (i+1));
				}
				for(int j = 0;j < n;j++){
					b[j][i] -= min;
				}
			}
			for(int i = 0;i < n;i++){
				int min = 99999999;
				for(int j = 0;j < m;j++){
					min = Math.min(min, b[i][j]);
				}
				for(int j = 0;j < min;j++){
					hands.add("row " + (i+1));
				}
				for(int j = 0;j < m;j++){
					b[i][j] -= min;
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(b[i][j] != 0)break outer;
				}
			}
			if(best == null || hands.size() < best.size()){
				best = hands;
			}
		}
		if(best == null){
			out.println(-1);
		}else{
			out.println(best.size());
			for(String line : best){
				out.println(line);
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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