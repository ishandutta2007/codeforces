//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class ECRF2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int A = ni(), B = ni();
		int n = A+B;
		
		int s = (int)Math.sqrt(n);
		long all = 0;
		for(int i = 1;i <= n/(s+1);i++){
			// u(d+1)+vd = A+B
			// u+v=i
			// id+u = A+B
			// (A+B)/i = d > s
			// (A+B) >= (s+1) * i
			// i <= (A+B)/(s+1)
			
			int u = (A+B) % i;
			int d = (A+B) / i;
			int v = i-u;
			if(v == 0)continue;
			
			long K = A%d;
			long L = (A-K*(d+1)) /d;
			assert K * (d+1) + L*d == A;
			long up = Math.min((u-K)/d, (L-1)/(d+1));
			long k = K + up * d;
			long l = L - up * (d+1);
			if(k >= 0 && k <= u && l >= 0 && l <= v){
				all++;
			}
		}
		
		for(int d = 1;d <= s;d++){
			// k(d+1)+ld=A // A=17,d=2,(k,l)=(1,7),(3,4),(5,1)
			// k = A%d + xd
			// x1lk-1
			// (A-k(d+1))/d >= 1
			// A-k(d+1) >= d
			// (A-d)/(d+1) >= k
			// ((A-d)/(d+1) - A%d) / d
			int av = (A/(d+1) - A%d + d)/d;
			int bv = (B/(d+1) - B%d + d)/d;
//			tr(av, bv);
			if(!(av <= 0 || bv <= 0)){
				all += av;
				all += bv;
				all--;
				if(A % (d+1) == 0 && B % (d+1) == 0)all--;
			}
		}
		out.println(all);
	}
	
	public static int[] mpTable(int[] str)
	{
		int n = str.length;
		int[] mp = new int[n+1];
		mp[0] = -1;
		for(int i = 1, j = 0;i < n;i++){
			while(j >= 0 && str[i] != str[j])j = mp[j];
			mp[i+1] = ++j;
		}
		return mp;
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
	
	public static void main(String[] args) throws Exception { new ECRF2().run(); }
	
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