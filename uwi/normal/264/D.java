//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D162 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		
		int n = s.length;
		int m = t.length;
		
		int[] rlim = new int[m];
		for(int i = 0;i < m-1;i++){
			if(rlim[i] < n && s[rlim[i]] == t[i]){
				rlim[i+1] = rlim[i] + 1;
			}else{
				rlim[i+1] = rlim[i];
			}
		}
		int[] clim = new int[n];
		for(int i = 0;i < n-1;i++){
			if(clim[i] < m && t[clim[i]] == s[i]){
				clim[i+1] = clim[i] + 1;
			}else{
				clim[i+1] = clim[i];
			}
		}
//		tr(rlim, clim);
		
		long ret = 0;
		ret += go('R', 'B', rlim, clim, s, t);
		ret += go('B', 'R', rlim, clim, s, t);
		ret += go('R', 'G', rlim, clim, s, t);
		ret += go('G', 'R', rlim, clim, s, t);
		ret += go('G', 'B', rlim, clim, s, t);
		ret += go('B', 'G', rlim, clim, s, t);
		
		long all = (long)n*m;
		for(int i = 0;i < m;i++){
			all -= rlim[i];
		}
		for(int j = 0;j < n;j++){
			all -= clim[j];
		}
		out.println(all - ret);
	}
	
	public static void tf(boolean[][] b) {
		for(boolean[] r : b){
			char[] s = new char[r.length];
			for(int i = 0;i < r.length;i++)
				s[i] = r[i] ? '#' : '.';
			System.out.println(new String(s));
		}
		System.out.println();
	}
	
	long go(char r, char b, int[] rlim, int[] clim, char[] s, char[] t)
	{
		int n = s.length, m = t.length;
		int[] ss = new int[n];
		int ps = 0;
		int[] ts = new int[m];
		int pt = 0;
		
		for(int i = 0;i < n-1;i++){
			if(s[i] == r && s[i+1] == b){
				ss[ps++] = i;
			}
		}
		for(int i = 0;i < m-1;i++){
			if(t[i] == b && t[i+1] == r){
				ts[pt++] = i;
			}
		}
//		tr(Arrays.copyOf(ss, ps), Arrays.copyOf(ts, pt));
		
		int q = 0;
		long dis = 0;
		for(int i = 0;i < ps;i++){
			while(q < pt && ts[q] < clim[ss[i]])q++;
			dis += q;
		}
		q = 0;
		for(int i = 0;i < pt;i++){
			while(q < ps && ss[q] < rlim[ts[i]])q++;
			dis += q;
		}
		return (long)ps*pt - dis;
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
	
	public static void main(String[] args) throws Exception { new D162().run(); }
	
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