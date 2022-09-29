//package round543;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	void solve()
	{
		int m = ni(), K = ni(), n = ni(), s = ni();
		int[] a = na(m);
		int[] f = new int[500005];
		int np = 0;
		for(int i = 0;i < s;i++){
			if(++f[ni()] == 1){
				np++;
			}
		}
		
		int suf = np;
		int[] my = new int[500005];
		int p = 0;
		for(int i = 0;i < m;i++){
			while(p < m && suf > 0){
				my[a[p]]++;
				if(f[a[p]] > 0 && my[a[p]] == f[a[p]]){
					suf--;
				}
				p++;
			}
			if(suf == 0){
				int L = i, M = p-i, R = m-p;
				if(L/K + R/K + 1 >= n){
					int rl = n-1;
					int la = Math.min(rl, L/K);
					rl -= la;
					int ra = Math.min(rl, R/K);
					rl -= ra;
					
					boolean[] ok = new boolean[m];
					for(int j = 0;j < la*K;j++){
						ok[j] = true;
					}
					for(int j = 0;j < ra*K;j++){
						ok[m-1-j] = true;
					}
					int re = K;
					for(int t = i;t < p;t++){
						if(f[a[t]] > 0){
							ok[t] = true;
							f[a[t]]--;
							re--;
						}
					}
					for(int t = 0;t < m;t++){
						if(!ok[t] && re > 0){
							ok[t] = true;
							re--;
						}
					}
					assert re == 0;
					out.println(m-K*n);
					for(int t = 0;t < m;t++){
						if(!ok[t]){
							out.print((t+1) + " ");
						}
					}
					out.println();
					return;
				}
			}
			
			my[a[i]]--;
			if(f[a[i]] > 0 && my[a[i]] < f[a[i]]){
				suf++;
			}
		}
		out.println(-1);
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