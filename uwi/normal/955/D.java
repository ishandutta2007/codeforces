//package round474;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		char[] s = ns(n);
		char[] t = ns(m);
		if(m > 2*K){
			out.println("No");
			return;
		}
		
		char[] rt = Arrays.copyOf(t, m);
		for(int i = 0, j = m-1;i < j;i++,j--){
			char c = rt[i]; rt[i] = rt[j]; rt[j] = c;
		}
		int[] rmp = mpTable(rt);
		
		int[] last = new int[m+1];
		Arrays.fill(last, -1);
		int p = 0;
		for(int i = 0;i < n;i++){
			while(p >= 0 && rt[p] != s[n-1-i])p = rmp[p];
			
			++p;
			if(i >= K-1 && last[p] == -1){
				last[p] = n-1-i;
			}
			if(i+K < n){
				if(Math.min(p, K) >= m){
					out.println("Yes");
					out.println(1 + " " + Math.min(n-K+1, n-i));
					int l = 1, r = Math.min(n-K+1, n-i);
					assert l >= 1 && r <= n && l+K <= r;
					return;
				}
			}
			if(p == t.length){
				p = rmp[p];
			}
		}
		last[0] = n-K;
		
		int[] mp = mpTable(t);
		int[] first = new int[m+1];
		Arrays.fill(first, n+1);
		int o = 0;
		for(int i = 0;i < n;i++){
			while(o >= 0 && t[o] != s[i])o = mp[o];
			++o;
			
			if(i >= K-1 && first[o] == n+1){
				first[o] = i;
			}
			if(i+K < n){
				if(Math.min(o, K) >= m){
					out.println("Yes");
					out.println(Math.max(1, i-K+1+1) + " " + (n-K+1));
					int l = Math.max(1, i-K+1+1), r = n-K+1;
					assert l >= 1 && r <= n && l+K <= r;
					return;
				}
			}
			
			if(o == t.length){
				o = mp[o];
			}
		}
		for(int i = m;i > 0;i--){
			int f = rmp[i];
			last[f] = Math.max(last[f], last[i]);
		}
		for(int i = m;i > 0;i--){
			int f = mp[i];
			first[f] = Math.min(first[f], first[i]);
		}
		for(int i = 1;i <= m-1;i++){
			if(i <= K && m-i <= K && first[i] != n+1 && last[m-i] != -1){
				if(first[i] < last[m-i]){
					out.println("Yes");
					out.println(first[i]-K+1+1 + " " + (last[m-i]+1));
					int l = first[i]-K+1+1, r = last[m-i]+1;
					assert l >= 1 && r <= n && l+K <= r;
					return;
				}
			}
		}
		
		out.println("No");
	}
	
	public static int[] mpTable(char[] str)
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
	
	
	
	public static int[] Z(char[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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