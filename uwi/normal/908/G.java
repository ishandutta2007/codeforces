//package goodbye2017;
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
		char[] s = ns().toCharArray();
		int mod = 1000000007;
		int m = 702;
		
		long[] bases = new long[m+1];
		bases[0] = 1;
		for(int i = 1;i <= m;i++)bases[i] = bases[i-1] * 10 % mod;
		
		// 10*700^3*10
		long ans = 0;
		for(int d = 9;d >= 1;d--){
			int n = s.length;
			long[] sum = new long[m]; // base
			long[] num = new long[m]; // base
			long esum = 0;
			int ebase = 0;
			for(int i = 0;i < n;i++){
				long[] nsum = new long[m]; // base
				long[] nnum = new long[m]; // base
				for(int j = 0;j < m;j++){
					for(int k = 0;k <= 9;k++){
						if(k > d && j+1 < m){
							nsum[j+1] += sum[j] * 10;
							nsum[j+1] %= mod;
							nnum[j+1] += num[j];
							if(nnum[j+1] >= mod)nnum[j+1] -= mod;
						}
						if(k == d){
							nsum[j] += sum[j] * 10 + num[j] * bases[j];
							nsum[j] %= mod;
							nnum[j] += num[j];
							if(nnum[j] >= mod)nnum[j] -= mod;
						}
						if(k < d){
							nsum[j] += sum[j];
							if(nsum[j] >= mod)nsum[j] -= mod;
							nnum[j] += num[j];
							if(nnum[j] >= mod)nnum[j] -= mod;
						}
					}
				}
				
				for(int k = 0;k < s[i]-'0';k++){
					if(k > d){
						nsum[ebase+1] += esum * 10;
						nsum[ebase+1] %= mod;
						nnum[ebase+1] += 1;
						if(nnum[ebase+1] >= mod)nnum[ebase+1] -= mod;
					}
					if(k == d){
						nsum[ebase] += esum * 10 + bases[ebase];
						nsum[ebase] %= mod;
						nnum[ebase] += 1;
						if(nnum[ebase] >= mod)nnum[ebase] -= mod;
					}
					if(k < d){
						nsum[ebase] += esum;
						if(nsum[ebase] >= mod)nsum[ebase] -= mod;
						nnum[ebase] += 1;
						if(nnum[ebase] >= mod)nnum[ebase] -= mod;
					}
				}
				
				if(s[i]-'0' > d){
					esum = esum * 10;
					esum %= mod;
					ebase++;
				}else if(s[i]-'0' == d){
					esum = esum * 10 + bases[ebase];
					esum %= mod;
				}
				
				sum = nsum;
				num = nnum;
			}
			long all = esum;
			for(int j = 0;j < m;j++){
				all += sum[j];
			}
			ans += all % mod * d;
		}
		out.println(ans%mod);
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