//package round491;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class F {
	InputStream is;
	PrintWriter out;
//	String INPUT = "2846161151"; // 7*9^9+8^9
//	String INPUT = "387430488";
	String INPUT = "";
	
	String best;
	
	void solve()
	{
		long n = nl();
		best = Long.toString(n);
		
		// <=5
		Map<Long, String> map = new HashMap<>();
		for(long b = 2;b <= 999;b++){
			long val = b;
			for(int e = 2;;e++){
				val *= b;
				if(val > n)break;
				String ex = b + "^" + e;
				if(ex.length() > 5)continue;
				
				if(!map.containsKey(val) ||
						map.get(val).length() > ex.length()
						){
					if(ex.length() < ("" + val).length()){
						map.put(val, ex);
					}
				}
				
				if(ex.length() == 3){
					for(int i = 2;i <= 9;i++){
						String lex = i + "*" + ex;
						long lval = val*i;
						if(!map.containsKey(lval) ||
								map.get(lval).length() > lex.length()
								){
							if(ex.length() < ("" + lval).length()){
								map.put(val, ex);
							}
							map.put(lval, lex);
						}
					}
				}
			}
		}
		
		int all = 0;
		for(long b = 2;b <= 100000;b++){
			long val = b;
			for(int e = 2;;e++){
				val *= b;
				if(val > n)break;
				if(n % val == 0){
					{
						// const*b^e
						String x = b + "^" + e;
						if(n/val == 1){
						}else{
							x = (n/val) + "*" + x;
						}
						if(x.length() < best.length()){
							best = x;
						}
					}
					{
						// a^c*b^e
						long t = n/val;
						if(map.containsKey(t)){
							String x = map.get(t) + "*" + b + "^" + e;
							if(x.length() < best.length()){
								best = x;
							}
						}
					}
				}
				// a^c*b^e+f
				{
					String x = b + "^" + e;
					if(x.length() + 4 + 2 < best.length()){
						for(long key : map.keySet()){
							if(key * val < n &&
									(double)key * val <= n
									){
								long rem = n - key*val;
								String ex = map.get(key) + "*" + x + "+" + rem;
								if(ex.length() < best.length()){
									best = ex;
								}
							}
						}
					}
				}
				
				// +
				
				// b^e+const
				String x = b + "^" + e;
				{
					long rem = n-val;
					String ex = x + "+" + rem;
					if(ex.length() < best.length()){
						best = ex;
					}
				}
				// b^e+c^d??
				{
					long rem = n-val;
					if(map.containsKey(rem)){
						String ex = x + "+" + map.get(rem);
						if(ex.length() < best.length()){
							best = ex;
						}
					}
				}
				
				for(int k = 2;;k++){
					String y = k + "*" + x;
					if(y.length() + 2 >= best.length())break;
					{
						long rem = n-val*k;
						if(rem > 0){
							String ex = y + "+" + rem;
							if(ex.length() < best.length()){
								best = ex;
							}
						}
					}
					{
						long rem = n-val*k;
						if(rem > 0){
							if(map.containsKey(rem)){
								tr(n-val*k, map.containsKey(rem));
							}
							if(map.containsKey(rem)){
								String ex = y + "+" + map.get(rem);
								if(ex.length() < best.length()){
									best = ex;
								}
							}
						}
					}
				}
			}
		}
		// a^d*b^c*.. + ~~~
		out.println(best);
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