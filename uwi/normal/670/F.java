//package round350;
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
		int[] f = new int[10];
		char[] s = ns().toCharArray();
		int n = s.length;
		for(char c : s){
			f[c-'0']++;
		}
		String T = ns();
		char[] t = T.toCharArray();
		int[] tf = new int[10];
		for(char c : t){
			tf[c-'0']++;
		}
		for(int i = 0;i < 10;i++){
			f[i] -= tf[i];
		}
		
		boolean[] sm = new boolean[10];
		for(int i = 0;i < 10;i++){
			char z = (char)('0'+i);
			if((z + T).compareTo(T + z) < 0){
				sm[i] = true;
			}
		}
		
		if(n == 2 && f[0] == 0 && f[1] == 1 && t.length == 1 && tf[0] == 1){
			out.println(0);
			return;
		}
		
		char[] ret = new char[n];
		Arrays.fill(ret, '9');
		outer:
		for(int ndl = 1, ndh = 10, mlen = 1;ndl <= 1000000;ndl*=10,ndh*=10,mlen++){
			int len = n-mlen;
			if(ndl <= len && len < ndh && len >= t.length){
				int[] lf = Arrays.copyOf(f, 10);
				int K = len;
				while(K > 0){
					if(--lf[K%10] < 0)continue outer;
					K /= 10;
				}
				{
					char[] res = go(Arrays.copyOf(lf, 10), len, t, sm);
					if(res != null && comp(res, ret) < 0){
						ret = res;
					}
				}
				{
					char[] res = go2(Arrays.copyOf(lf, 10), len, t);
					if(res != null && comp(res, ret) < 0){
						ret = res;
					}
				}
			}
		}
		out.println(new String(ret));
	}
	
	int comp(char[] a, char[] b)
	{
		if(a.length != b.length)return a.length - b.length;
		for(int i = 0;i < a.length;i++){
			if(a[i] != b[i])return a[i] - b[i];
		}
		return 0;
	}
	
	char[] go(int[] f, int len, char[] t, boolean[] sm)
	{
		char[] res = new char[len];
		int p = 0;
		for(int k = 1;k < 10;k++){
			if(f[k] > 0){
				res[p++] = (char)('0'+k);
				f[k]--;
				break;
			}
		}
		if(p == 0)return null;
		for(int k = 0;k < 10;k++){
			if(!sm[k] && (k == 0 || sm[k-1])){
				for(char c : t){
					res[p++] = c;
				}
			}
			for(int u = 0;u < f[k];u++){
				res[p++] = (char)('0'+k);
			}
		}
		if(sm[9]){
			for(char c : t){
				res[p++] = c;
			}
		}
		assert p == len;
		return res;
	}
	
	char[] go2(int[] f, int len, char[] t)
	{
		if(t[0] == '0')return null;
		char[] res = new char[len];
		int p = 0;
		for(char c : t){
			res[p++] = c;
		}
		if(p == 0)return null;
		for(int k = 0;k < 10;k++){
			for(int u = 0;u < f[k];u++){
				res[p++] = (char)('0'+k);
			}
		}
		assert p == len;
		return res;
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