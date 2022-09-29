//package round394;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		char[][] map = nm(n,m);
		int[][] qs = new int[K][];
		for(int i = 0;i < K;i++){
			qs[i] = new int[]{ni()-1, ni()-1, ni()-1, ni()-1, nc()-'a'};
		}
		int[][][] imos = new int[26][n+2][m+2];
		for(int[] q : qs){
			imos[q[4]][q[0]][q[1]]++;
			imos[q[4]][q[2]+1][q[3]+1]++;
			imos[q[4]][q[0]][q[3]+1]--;
			imos[q[4]][q[2]+1][q[1]]--;
		}
		for(int i = 0;i < 26;i++){
			for(int j = 0;j <= n;j++){
				for(int k = 0;k <= m;k++){
					if(j-1 >= 0)imos[i][j][k] += imos[i][j-1][k];
					if(k-1 >= 0)imos[i][j][k] += imos[i][j][k-1];
					if(j-1 >= 0 && k-1 >= 0)imos[i][j][k] -= imos[i][j-1][k-1];
				}
			}
		}
		int[] f = new int[26];
		long[][][] ds = new long[26][n+2][m+2];
		long[][] defs = new long[n+2][m+2];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int s = 0;
				for(int k = 0;k < 26;k++){
					f[k] = imos[k][i][j];
					s += f[k];
				}
				f[map[i][j]-'a'] += K-s;
				long[] res = calc(f, K);
				for(int k = 0;k < 26;k++){
					ds[k][i+1][j+1] = res[k];
				}
				defs[i+1][j+1] = res[map[i][j]-'a'];
			}
		}
		for(int i = 0;i < 26;i++){
			for(int j = 0;j <= n+1;j++){
				for(int k = 0;k <= m+1;k++){
					if(j-1 >= 0)ds[i][j][k] += ds[i][j-1][k];
					if(k-1 >= 0)ds[i][j][k] += ds[i][j][k-1];
					if(j-1 >= 0 && k-1 >= 0)ds[i][j][k] -= ds[i][j-1][k-1];
				}
			}
		}
		for(int j = 0;j <= n+1;j++){
			for(int k = 0;k <= m+1;k++){
				if(j-1 >= 0)defs[j][k] += defs[j-1][k];
				if(k-1 >= 0)defs[j][k] += defs[j][k-1];
				if(j-1 >= 0 && k-1 >= 0)defs[j][k] -= defs[j-1][k-1];
			}
		}
		long min = Long.MAX_VALUE;
		for(int[] q : qs){
			long lret = defs[n+1][m+1]-
					(defs[q[2]+1][q[3]+1]-defs[q[0]][q[3]+1]-defs[q[2]+1][q[1]]+defs[q[0]][q[1]]) +
					(ds[q[4]][q[2]+1][q[3]+1]-ds[q[4]][q[0]][q[3]+1]-ds[q[4]][q[2]+1][q[1]]+ds[q[4]][q[0]][q[1]]);
			min = Math.min(min, lret);
		}
		
		out.println(min);
	}
	
	long[] calc(int[] f, int all)
	{
		long[] ret = new long[26];
		{
			long cum = 0;
			long sum = 0;
			for(int i = 0;i < 26;i++){
				sum += cum;
				ret[i] += sum;
				cum += f[i];
			}
		}
		{
			long cum = 0;
			long sum = 0;
			for(int i = 25;i >= 0;i--){
				sum += cum;
				ret[i] += sum;
				cum += f[i];
			}
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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