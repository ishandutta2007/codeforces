//package gb2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[n-1-i] = new long[]{ni(), ni()};
		}
		int mod = 1000000007;
		long[] op = new long[n];
		long[] yy = new long[n];
		long[] xx = new long[n];
		for(int i = 0, j = 1;i < n;i++,j++){
			if(j == n)j = 0;
			op[i] = co[i][0]*co[j][1]-co[i][1]*co[j][0];
			op[i] %= mod;
			if(op[i] < 0)op[i] += mod;
			
			yy[i] = co[i][1]-co[j][1];
			yy[i] %= mod;
			if(yy[i] < 0)yy[i] += mod;
			
			xx[i] = co[i][0]-co[j][0];
			xx[i] %= mod;
			if(xx[i] < 0)xx[i] += mod;
		}
		
		long[] ops = new long[2*n+1];
		long[] opws = new long[2*n+1];
		for(int i = 1, j = 0;i <= 2*n;i++,j++){
			if(j == n)j = 0;
			ops[i] = ops[i-1] + op[j];
			if(ops[i] >= mod)ops[i] -= mod;
			opws[i] = (opws[i-1] + op[j] * (i-1)) % mod;
		}
		long[] xxs = new long[2*n+1];
		long[] xxws = new long[2*n+1];
		for(int i = 1, j = 0;i <= 2*n;i++,j++){
			if(j == n)j = 0;
			xxs[i] = xxs[i-1] + xx[j];
			if(xxs[i] >= mod)xxs[i] -= mod;
			xxws[i] = (xxws[i-1] + xx[j] * (i-1)) % mod;
		}
		long[] yys = new long[2*n+1];
		long[] yyws = new long[2*n+1];
		for(int i = 1, j = 0;i <= 2*n;i++,j++){
			if(j == n)j = 0;
			yys[i] = yys[i-1] + yy[j];
			if(yys[i] >= mod)yys[i] -= mod;
			yyws[i] = (yyws[i-1] + yy[j] * (i-1)) % mod;
		}
		long S = areaPoly2(co);
		
		int j = 0;
		long H = 0;
		long ret = 0;
		for(int i = 0;i < n;i++){
			while(Long.compareUnsigned(2*H, S) <= 0){
				int pj = j;
				j++;
				if(j == n)j = 0;
				H += ((co[pj][0]-co[i][0])*(co[j][1]-co[i][1])-(co[j][0]-co[i][0])*(
						co[pj][1]-co[i][1]));
			}
			
			int right = j-i-2;
			while(right < 0)right += n;
			int left = n-3-right;
			// [left-right,left+right]
			// [i+1,i+right+1]
			// -2 0 2
			// -2*9+0*9+2*18
			// 1 1 -1
			// -1 1 1
			// 0 2 0
			// 6 27 3
			{
				int L = i+1, R = i+right+1;
				int base = left-right;
				// 21 -6 -16
				// 3 0 -1
				// 0 3 6
				// (5,4)
				// 21-3*4+0*5=9
				// -6-0*4+3*5=9
				// -16-(-1)*4+6*5=18
				
				{
					long lret = base*(ops[R+1]-ops[L]) + 2*(opws[R+1]-opws[L])-2L*L*(ops[R+1]-ops[L]);
					ret += lret % mod;
					ret %= mod;
				}
				{
					long lret = base*(xxs[R+1]-xxs[L]) + 2*(xxws[R+1]-xxws[L])-2L*L*(xxs[R+1]-xxs[L]);
					ret += lret % mod * -co[i][1];
					ret %= mod;
				}
				{
					long lret = base*(yys[R+1]-yys[L]) + 2*(yyws[R+1]-yyws[L])-2L*L*(yys[R+1]-yys[L]);
					ret += lret % mod * co[i][0];
					ret %= mod;
				}
			}
			
			// [left+right-2,right-left]
			// [i+right+2,i+n-2]
			if(i+right+2 <= i+n-2){
				int L = i+right+2, R = i+n-2;
				int base = left+right-2;
				{
					long lret = base*(ops[R+1]-ops[L]) - 2*(opws[R+1]-opws[L])+2L*L*(ops[R+1]-ops[L]);
					ret += lret % mod;
					ret %= mod;
				}
				{
					long lret = base*(xxs[R+1]-xxs[L]) - 2*(xxws[R+1]-xxws[L])+2L*L*(xxs[R+1]-xxs[L]);
					ret += lret % mod * -co[i][1];
					ret %= mod;
				}
				{
					long lret = base*(yys[R+1]-yys[L]) - 2*(yyws[R+1]-yyws[L])+2L*L*(yys[R+1]-yys[L]);
					ret += lret % mod * co[i][0];
					ret %= mod;
				}
			}
			int ni = (i+1)%n;
			H -= ((co[i][0]-co[j][0])*(co[ni][1]-co[j][1])-(co[ni][0]-co[j][0])*(co[i][1]-co[j][1]));
		}
		if(ret < 0)ret += mod;
		ret = ret * invl(2, mod) % mod;
		out.println(ret);
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
	
	public static long areaPoly2(long[][] co)
	{
		int n = co.length;
		long s = 0;
		for(int i = 0, j = 1;i < n;i++,j++){
			if(j == n)j = 0;
			s += (long)co[i][0]*co[j][1]-(long)co[j][0]*co[i][1];
		}
		return Math.abs(s);
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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