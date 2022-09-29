//package round530;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int best = -1;
	char[][] arg = null;
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		
		go(map);
		int obest = best;
		go(trans(map));
		if(obest == best){
			for(char[] row : arg){
				out.println(new String(row));
			}
		}else{
			arg = trans(arg);
			for(char[] row : arg){
				out.println(new String(row));
			}
		}
	}
	
	public static char[][] trans(char[][] a)
	{
		if(a.length == 0)return new char[0][0];
		int n = a.length, m = a[0].length;
		char[][] ret = new char[m][n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				ret[i][j] = a[j][i];
			}
		}
		return ret;
	}

	
	void go(char[][] map)
	{		
		int n = map.length, m = map[0].length;
		int[] ord = new int[4];
		for(int i = 0;i < 4;i++)ord[i] = i;
		
		char[] T = "AGCT".toCharArray();
		
		int[][][] f = new int[m][2][4];
		for(int j = 0;j < m;j++){
			for(int i = 0;i < n;i++){
				int ind = (i&1);
				f[j][ind]["AGCT".indexOf(map[i][j])]++;
			}
		}
		do{
			// 01
			// 23
			char[][] lret = new char[n][m];
			int cor = 0;
			for(int j = 0;j < m;j++){
				int p = j&1;
				if(f[j][0][ord[0^p]] + f[j][1][ord[2^p]] > 
				f[j][0][ord[2^p]] + f[j][1][ord[0^p]]){
					cor += f[j][0][ord[0^p]] + f[j][1][ord[2^p]];
					for(int k = 0;k < n;k++){
						lret[k][j] = T[ord[(k&1)*2^p]];
					}
				}else{
					cor += f[j][0][ord[2^p]] + f[j][1][ord[0^p]];
					for(int k = 0;k < n;k++){
						lret[k][j] = T[ord[(k&1)*2^2^p]];
					}
				}
			}
			if(cor > best){
				best = cor;
				arg = lret;
			}
		}while(nextPermutation(ord));
	}
	
	public static boolean nextPermutation(int[] a) {
		int n = a.length;
		int i;
		for (i = n - 2; i >= 0 && a[i] >= a[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < n && a[i] < a[j]; j++)
			;
		int d = a[i];
		a[i] = a[j - 1];
		a[j - 1] = d;
		for (int p = i + 1, q = n - 1; p < q; p++, q--) {
			d = a[p];
			a[p] = a[q];
			a[q] = d;
		}
		return true;
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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