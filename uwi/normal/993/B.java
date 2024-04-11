//package round488;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] ap = new int[n][];
		for(int i = 0;i < n;i++)ap[i] = na(2);
		int[][] bp = new int[m][];
		for(int i = 0;i < m;i++)bp[i] = na(2);
		
		int[][] valids = new int[200][];
		int p = 0;
		for(int i = 0;i < n;i++){
			inner:
			for(int j = 0;j < m;j++){
				int[] f = new int[10];
				for(int v : ap[i])f[v]++;
				for(int v : bp[j])f[v]++;
				int common = -1;
				for(int k = 0;k < 10;k++){
					if(f[k] == 2){
						if(common != -1)continue inner;
						common = k;
					}
				}
				if(common == -1)continue inner;
				
				valids[p++] = new int[]{i, j, common};
			}
		}
		
		assert p > 0;
		valids = Arrays.copyOf(valids, p);
		// you know
		boolean youknow = true;
		for(int i = 1;i < p;i++){
			if(valids[i][2] != valids[0][2]){
				youknow = false;
			}
		}
		
		// bknow
		boolean bknow = true;
		Arrays.sort(valids, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
		for(int i = 0;i < p;){
			int j = i;
			while(j < p && valids[i][1] == valids[j][1])j++;
			for(int k = i+1;k < j;k++){
				if(valids[i][2] != valids[k][2])bknow = false;
			}
			i = j;
		}
		
		// aknow
		boolean aknow = true;
		Arrays.sort(valids, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		for(int i = 0;i < p;){
			int j = i;
			while(j < p && valids[i][0] == valids[j][0])j++;
			for(int k = i+1;k < j;k++){
				if(valids[i][2] != valids[k][2])aknow = false;
			}
			i = j;
		}
		
		if(youknow){
			out.println(valids[0][2]);
		}else if(aknow && bknow){
			out.println(0);
		}else{
			out.println(-1);
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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