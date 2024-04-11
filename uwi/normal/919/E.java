//package round460;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// n=pk+t
		// n=(p-1)l+q
		
		// k=0 -> q=t
		// k=1 -> q=t+1
		
		int a = ni(), b = ni(), p = ni();
		long x = nl();
		long[] pa = new long[p-1];
		pa[0] = 1;
		int pe = 0;
		for(int i = 1;i < p-1;i++){
			pa[i] = pa[i-1] * a % p;
			if(pa[i] == 1 && pe == 0){
				pe = i;
			}
		}
		if(pe == 0)pe = p-1;
		
		int[] ipa = new int[p];
		Arrays.fill(ipa, -1);
		for(int i = 0;i < pe;i++){
			ipa[(int)pa[i]] = i;
		}
		
		long dup = x / ((long)p*pe);
		x %= (long)p*pe;
		long ans = pe * dup;
		
		int[] invs = enumInvs(p-1, p);
		for(int i = 1;i <= p-1;i++){
			int ii = (int)((long)invs[i] * b % p);
			int pos = ipa[ii];
			if(pos < 0)continue;
			
			// [t, t+(x-i)/p] % (p-1)?
			// 
			if(x-i < 0)continue;
			long inf = i, sup = i + (x-i)/p;
			if(i == p-1){
				inf -= p-1; sup -= p-1;
			}
			while(true){
				int lsup = (int)Math.min(sup, p-2);
				ans += (lsup-pos+pe)/pe - (inf-1-pos+pe)/pe;
				sup -= p-1;
				if(sup >= 0){
					inf = 0;
					continue;
				}else{
					break;
				}
			}
		}
		out.println(ans);
	}
	
	public static int[] enumInvs(int n, int mod) {
		int[] inv = new int[n + 1];
		inv[1] = 1;
		for (int i = 2; i <= n; i++) {
			inv[i] = (int) (inv[mod % i] * (long) (mod - mod / i) % mod);
		}
		return inv;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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