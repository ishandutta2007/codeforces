//package abbyy2.easy;
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
		char[] fb = new char[200000];
		fb[0] = 'b'; fb[1] = 'a';
		int b = 2, a = 1;
		while(b <= 100000){
			for(int i = 0;i < a;i++){
				fb[b+i] = fb[i];
			}
			int c = b + a;
			a = b; b = c;
		}
		
		int mod = 1000000007;
		int N = 4000;
		long[] f = new long[N];
		f[0] = f[1] = 1;
		for(int i = 2;i <= N-1;i++){
			f[i] = f[i-1] + f[i-2];
			if(f[i] >= mod)f[i] -= mod;
		}
		
		long[] na = new long[N+1];
		long[] nb = new long[N+1];
		long[] nab = new long[N+1];
		long[] nbb = new long[N+1];
		long[] nba = new long[N+1];
		na[0] = 1;
		nb[1] = 1;
		nba[2] = 1;
		for(int i = 2;i <= N;i++){
			na[i] = na[i-1] + na[i-2];
			nb[i] = nb[i-1] + nb[i-2];
			if(i >= 3){
				nab[i] = nab[i-1] + nab[i-2] + (i%2==1?1:0);
				nbb[i] = nbb[i-1] + nbb[i-2] + (i%2==0?1:0);
				nba[i] = nba[i-1] + nba[i-2];
				
				nab[i] %= mod;
				nbb[i] %= mod;
				nba[i] %= mod;
			}
			na[i] %= mod; nb[i] %= mod;
		}
		
		int n = ni()-1;
		int z = ni();
		for(int r = 0;r < z;r++){
			char[] s = ns().toCharArray();
			long ret = 0;
			if(n == 0){
				if(s.length == 1 && s[0] == 'a'){
					ret = 1;
				}else{
					ret = 0;
				}
			}else if(s.length == 1){
				if(s[0] == 'a'){
					ret = na[n];
				}else{
					ret = nb[n];
				}
			}else{
				int[] kmp = kmpTable(s);
				int ind = Arrays.binarySearch(f, 1, 30, s.length);
				if(ind < 0)ind = -ind-1;
				int o = ind;
				if(n <= ind){
					ret = count(kmp, s, Arrays.copyOf(fb, (int)f[n])) % mod;
				}else{
					long ca = count(kmp, s, Arrays.copyOf(fb, (int)f[o]));
					long cb = count(kmp, s, Arrays.copyOf(fb, (int)f[o+1]));
					
					char[] ab = new char[(int)(f[o]+f[o+1])];
					System.arraycopy(fb, 0, ab, 0, (int)f[o]);
					System.arraycopy(fb, 0, ab, (int)f[o], (int)f[o+1]);
					long cab = count(kmp, s, ab) - ca - cb;
					
					char[] ba = new char[(int)(f[o]+f[o+1])];
					System.arraycopy(fb, 0, ba, 0, (int)f[o+1]);
					System.arraycopy(fb, 0, ba, (int)f[o+1], (int)f[o]);
					long cba = count(kmp, s, ba) - ca - cb;
					
					char[] bb = new char[(int)(f[o+1]+f[o+1])];
					System.arraycopy(fb, 0, bb, 0, (int)f[o+1]);
					System.arraycopy(fb, 0, bb, (int)f[o+1], (int)f[o+1]);
					long cbb = count(kmp, s, bb) - cb - cb;
					
					ret = (
							ca * na[n-ind] % mod
							+ cb * nb[n-ind] % mod
							+ cab * nab[n-ind] % mod
							+ cbb * nbb[n-ind] % mod
							+ cba * nba[n-ind] % mod
							+ 5L*mod
							) % mod;
				}
			}
			out.println(ret);
		}
	}
	
	static int count(int[] kmp, char[] q, char[] h)
	{
		int p = 0;
		int hit = 0;
		for(char element : h){
			while(p >= 0 && q[p] != element)p = kmp[p];
			if(++p == q.length){
				hit++;
				p = kmp[p];
			}
		}
		return hit;
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
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