//package round612;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] f = {n/2, (n+1)/2};
		
		int[][] uc = uniqcount(a);
		int m = uc.length;
		int ans = 0;
		for(int i = 0;i < m-1;i++) {
			if(uc[i][0] != 0 && uc[i+1][0] != 0) {
				if(uc[i][0] % 2 != uc[i+1][0] % 2) {
					ans++;
				}
			}
		}
		for(int i = 0;i < m;i++) {
			if(uc[i][0] != 0) {
				f[uc[i][0]%2]--;
			}
		}
		
		List<Integer> same0 = new ArrayList<>();
		List<Integer> same1 = new ArrayList<>();
		
		if(m == 1 && uc[0][0] == 0) {
			out.println(n == 1 ? 0 : 1);
			return;
		}
		
		int ls = 0, rs = 0;
		int lp = -1, rp = -1;
		for(int i = 0;i < m;i++) {
			if(uc[i][0] == 0) {
				if(i == 0) {
					lp = uc[i+1][0] % 2;
					ls = uc[i][1];
				}else if(i == m-1) {
					rp = uc[i-1][0] % 2;
					rs = uc[i][1];
				}else {
					if(uc[i-1][0] % 2 != uc[i+1][0] % 2) {
						ans++;
					}else if(uc[i-1][0] % 2 == 0) {
						same0.add(uc[i][1]);
					}else {
						same1.add(uc[i][1]);
					}
				}
			}
		}
		
		
		Collections.sort(same0);
		Collections.sort(same1);
		int min =999999999;
		for(int i = 0;i < 2;i++) {
			for(int j = 0;j < 2;j++) {
				int lans = 0;
				int[] g = Arrays.copyOf(f, 2);
				if(i == 1 && lp != -1) {
					g[lp] -= ls;
				}else if(lp != -1) {
					lans++;
				}
				if(j == 1 && rp != -1) {
					g[rp] -= rs;
				}else if(rp != -1) {
					lans++;
				}
				
				if(g[0] < 0 || g[1] < 0)continue;
				
				for(int t : same0) {
					if(t <= g[0]) {
						g[0] -= t;
					}else {
						g[0] = 0;
						lans+=2;
					}
				}
				for(int t : same1) {
					if(t <= g[1]) {
						g[1] -= t;
					}else {
						g[1] = 0;
						lans+=2;
					}
				}
				min = Math.min(min, lans+ans);
			}
		}
		out.println(min);
	}
	
	public static int[][] uniqcount(int[] a)
	{
		int n = a.length;
		int p = 0;
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1])b[p++] = new int[]{a[i], 0};
			b[p-1][1]++;
		}
		return Arrays.copyOf(b, p);
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