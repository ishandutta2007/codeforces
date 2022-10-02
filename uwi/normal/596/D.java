//package round331;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class DS {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), h = ni();
		double p = nd();
		int[] x = shuffle(na(n), gen);
		Arrays.sort(x);
		
		int[] reachr = new int[n];
		reachr[n-1] = n-1;
		for(int i = n-2;i >= 0;i--){
			reachr[i] = x[i+1]-x[i] < h ? reachr[i+1] : i;
		}
		int[] reachl = new int[n];
		reachl[0] = 0;
		for(int i = 1;i < n;i++){
			reachl[i] = x[i] - x[i-1] < h ? reachl[i-1] : i;
		}
		
		double[][] E = new double[n][n];
		double[][] pll = new double[n][n];
		double[][] prr = new double[n][n];
		for(int len = 1;len <= n;len++){
			for(int i = 0;i+len-1 < n;i++){
				int j = i+len-1;
				if(len == 1){
					pll[i][j] = p;
					prr[i][j] = 1-p;
					E[i][j] = h;
				}else{
					// left
					pll[i][j] += 0.5*p;
					if(reachr[i] >= j){
						prr[i][j] += 0.5*(1-p);
					}else{
						prr[i][j] += 0.5*(1-p)*prr[reachr[i]+1][j];
					}
					prr[i][j] += 0.5*p*prr[i+1][j];
					
					E[i][j] += 0.5*p*(h + E[i+1][j] - pll[i+1][j]*Math.max(h-(x[i+1]-x[i]), 0));
					E[i][j] += 0.5*(1-p)*(x[Math.min(j, reachr[i])]-x[i]+h);
					if(reachr[i] < j){
						E[i][j] += 0.5*(1-p)*E[reachr[i]+1][j];
						E[i][j] -= 0.5*(1-p)*pll[reachr[i]+1][j]*Math.max(2*h-(x[reachr[i]+1]-x[reachr[i]]), 0);
					}
					
					// right
					prr[i][j] += 0.5*(1-p);
					if(reachl[j] <= i){
						pll[i][j] += 0.5*p;
					}else{
						pll[i][j] += 0.5*p*pll[i][reachl[j]-1];
					}
					pll[i][j] += 0.5*(1-p)*pll[i][j-1];
					
					E[i][j] += 0.5*(1-p)*(h + E[i][j-1] - prr[i][j-1]*Math.max(h-(x[j]-x[j-1]), 0));
					E[i][j] += 0.5*p*(x[j]-x[Math.max(i, reachl[j])]+h);
					if(reachl[j] > i){
						E[i][j] += 0.5*p*E[i][reachl[j]-1];
						E[i][j] -= 0.5*p*prr[i][reachl[j]-1]*Math.max(2*h-(x[reachl[j]]-x[reachl[j]-1]), 0);
					}
				}
			}
		}
		out.printf("%.14f\n", E[0][n-1]);
	}
	
	static Random gen = new Random();
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new DS().run(); }
	
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