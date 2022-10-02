//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class P124D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int d = ni();
		char[] s = ns(400003);
		int n = s.length;
		
		// 
		for(int i = n-1;i >= 0;i--){
			s[i]++;
			if(s[i] <= 'z')break;
			if(i == 0){
				out.println("Impossible");
				return;
			}
			s[i] = 'a';
		}
		
		int H = 31;
		long[] es = new long[n+3];
		es[0] = 1;
		for(int i = 0;i < n+2;i++){
			es[i+1] = es[i] * H;
		}
		
		long[] hs = new long[n];
		for(int i = 0;i < n;i++){
			hs[i] = es[i] * (s[i]-'a'+1);
		}
		long[] rhs = new long[n];
		for(int i = 0;i < n;i++){
			rhs[i] = es[n-1-i] * (s[i]-'a'+1);
		}
		
		long[] hft = buildFenwick(hs);
		long[] rhft = buildFenwick(rhs);
		
		boolean first = true;
		for(int i = d-1;i < n;i++){
			// ipalindrome
			if(palin(i, d, n, hft, rhft, es) || palin(i, d+1, n, hft, rhft, es)){
				// i
				s[i]++;
				addFenwick(hft, i, es[i]);
				addFenwick(rhft, i, es[n-1-i]);
				if(first){
					// 
					for(int j = i+1;j < n;j++){
						addFenwick(hft, j, ('a'-s[j])*es[j]);
						addFenwick(rhft, j, ('a'-s[j])*es[n-1-j]);
						s[j] = 'a';
					}
					first = false;
				}
				while(s[i] > 'z'){
					if(i == 0){
						out.println("Impossible");
						return;
					}
					s[i] = 'a';
					addFenwick(hft, i, -26*es[i]);
					addFenwick(rhft, i, -26*es[n-1-i]);
					i--;
					s[i]++;
					addFenwick(hft, i, es[i]);
					addFenwick(rhft, i, es[n-1-i]);
				}
				i--;
			}
		}
		out.println(new String(s));
	}
	
	boolean palin(int end, int d, int n, long[] hft, long[] rhft, long[] es)
	{
		if(end-d < -1)return false;
		long first = (sumFenwick(hft, end) - sumFenwick(hft, end-d)) * es[n-1-end];
		long last = (sumFenwick(rhft, end) - sumFenwick(rhft, end-d)) * es[end-d+1];
		return first == last;
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static long[] buildFenwick(long[] a)
	{
		int n = a.length;
		long[] ft = new long[n+1];
		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}
	
	void run() throws Exception
	{
//		int n = 40, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(gen.nextInt(10)+1 + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((char)('y'+gen.nextInt(2)));
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new P124D().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}