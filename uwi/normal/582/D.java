//package round323;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int P = ni(), alpha = ni();
		if(alpha*Math.log10(P) >= 1100){
			out.println(0);
			return;
		}
		int mod = 1000000007;
		BigInteger b = new BigInteger(ns());
		int[] ds = new int[4000];
		BigInteger BP = BigInteger.valueOf(P);
		for(int i = 0;i < 4000;i++){
			if(b.signum() == 0){
				ds = Arrays.copyOf(ds, i);
				break;
			}
			BigInteger[] dm = b.divideAndRemainder(BP);
			ds[i] = dm[1].intValue();
			b = dm[0];
		}
		
		int m = ds.length;
		
		long[][][] pre = new long[alpha+1][2][2]; // [][edge][carry]
		long[][][] cur = new long[alpha+1][2][2];
		pre[0][1][0] = 1;
		
		long pmajor = (long)(P+1)*P/2%mod;
		long pminor = (long)(P-1)*P/2%mod;
		for(int i = m-1;i >= 0;i--){ // i
			for(int j = 0;j <= alpha;j++){
				cur[j][0][0] = cur[j][0][1] = 0;
				cur[j][1][0] = cur[j][1][1] = 0;
			}
			long edge = ds[i];
			long eminor0 = (edge+1)*edge/2%mod; // edge
			long eminor1 = edge*(edge-1)/2%mod; // edge-1
			long eminorx0 = edge+1; // edge
			long eminorx1 = edge; // edge-1
			long emajor0 = ((long)(P-1)*P/2-(long)(P-1-edge)*(P-1-edge+1)/2)%mod; // 1010+edge
			long emajor1 = ((long)(P+1)*P/2-(long)(P-1-edge+1)*(P-1-edge+2)/2)%mod; // 99+edge
			long emajorx0 = P-1-edge; // 10+edge
			long emajorx1 = P-edge; // 9+edge
			int lim = 0;
			for(int j = 0;j <= alpha;j++){
				if(pre[j][0][0] == 0 && pre[j][0][1] == 0 && pre[j][1][0] == 0 && pre[j][1][1] == 0)continue;
				
				int nj = Math.min(alpha, j+1);
				lim = nj;
				cur[j][0][0] += pre[j][0][0] * pmajor;
				cur[j][0][1] += pre[j][0][0] * pminor;
				cur[nj][0][0] += pre[j][0][1] * pminor;
				cur[nj][0][1] += pre[j][0][1] * pmajor;
				
				cur[j][0][0] += pre[j][1][0] * eminor0;
				cur[j][0][1] += pre[j][1][0] * eminor1;
				cur[nj][0][0] += pre[j][1][1] * emajor0;
				cur[nj][0][1] += pre[j][1][1] * emajor1;
				
				cur[j][1][0] += pre[j][1][0] * eminorx0;
				cur[j][1][1] += pre[j][1][0] * eminorx1;
				cur[nj][1][0] += pre[j][1][1] * emajorx0;
				cur[nj][1][1] += pre[j][1][1] * emajorx1;
			}
			for(int j = 0;j <= lim;j++){
				cur[j][0][0] %= mod;
				cur[j][0][1] %= mod;
				cur[j][1][0] %= mod;
				cur[j][1][1] %= mod;
			}
			long[][][] dum = pre; pre = cur; cur = dum;
		}
		long ret = pre[alpha][0][0] + pre[alpha][1][0];
		out.println(ret%mod);
	}
	
	void run() throws Exception
	{
//		int n = 4000, m = 99999;
//		Random gen = new Random(0);
//		StringBuilder sb = new StringBuilder();
//		sb.append(2 + " ");
//		sb.append(3333 + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(10));
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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