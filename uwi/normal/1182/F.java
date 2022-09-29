//package round566;
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
		for(int T = ni();T > 0;T--) {
			int a = ni(), b = ni(), P = ni(), Q = ni();
			long base = (Q-a*(2L*P)) % (2L*Q);
			if(base < 0)base += 2L*Q;
			// base-x*(2p) close to 0
			int S = (int)Math.sqrt(b-a+1);
			long[] comb = new long[S];
			for(int i = 0;i < S;i++) {
				comb[i] = (base - i*(2L*P)) % (2L*Q);
				if(comb[i] < 0)comb[i] += 2L*Q;
				comb[i] = comb[i]<<32|i;
			}
			Arrays.sort(comb);
			int p = 0;
			for(int i = 0;i < S;i++) {
				if(i > 0 && comb[i]>>>32 == comb[i-1]>>>32)continue;
				comb[p++] = comb[i];
			}
			comb = Arrays.copyOf(comb, p);
			
			long GS = (2L*P*S)%(2L*Q);
			long min = Long.MAX_VALUE;
			int argmin = -1;
			for(int j = 0;j < (b-a+1)/S;j++) {
				long h = j*GS%(2L*Q);
				int ind = Arrays.binarySearch(comb, h<<32|114514810);
				{
					int lind = -ind-2 >= 0 ? -ind-2 : p-1;
					long cha = toc((comb[lind]>>>32) - h, 2L*Q);
					int larg = a+j*S+(int)comb[lind];
					if(cha < min || cha == min && larg < argmin) {
						min = cha;
						argmin = larg;
					}
				}
				{
					int lind = -ind-1 < p ? -ind-1 : 0;
					long cha = toc((comb[lind]>>>32) - h, 2L*Q);
					int larg = a+j*S+(int)comb[lind];
					if(cha < min || cha == min && larg < argmin) {
						min = cha;
						argmin = larg;
					}
				}
			}
			for(int j = (b-a+1)/S*S;j <= b-a;j++) {
				long cha = toc(base-j*(2L*P), 2L*Q);
				if(cha < min) {
					min = cha;
					argmin = a+j;
				}
			}
			out.println(argmin);
		}
	}
	
	long toc(long cha, long mod)
	{
		cha %= mod;
		if(cha < 0)cha += mod;
		cha = Math.min(cha, mod-cha);
		return cha;
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