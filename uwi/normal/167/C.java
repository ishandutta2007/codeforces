//package round114;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		cache = new HashMap<Long, Boolean>();
		for(int t = ni(); t >= 1;t--){
			long a = nl(), b = nl();
//			tr(a,b);
			out.println(rec(a, b) ? "First" : "Second");
		}
	}
	
	Map<Long, Boolean> cache;
	long A = 100L, B = 100L;
	
	boolean rec(long a, long b)
	{
		if(a > b){
			long d = a; a = b; b = d;
		}
		if(a == 0)return false;
		if(a == 1)return true;
		if(a % 2 == 0){
			if(a <= 1000000000L && b >= (a+1)*(a+1)){
				return rec(a, (b-a)%(a*(a+1))+a);
			};
			if((a > 1000000000L || (a <= 1000000000L && b-a < a*a)) && b-a >= 2*a){
				return rec(a, (b-a)%(2*a)+a);
			}
			if(b-a >= a){
				return true;
			}
		}else{
			if(b-a >= 2 * a){
				return rec(a, (b-a)%(2*a)+a);
			}
		}
		if(a <= A && b <= B){
			long code = a * (B+1) + b;
			if(cache.containsKey(code))return cache.get(code);
		}
		if(!rec(a, b%a)){
			if(a <= A && b <= B){
				long code = a * (B+1) + b;
				cache.put(code, true);
			}
			return true;
		}
		
		int e = (int)(Math.log(b)/Math.log(a)+1E-9);
		long q = a;
		for(int i = 1;i <= e;i++){
			if(b-q != b%a && !rec(a, b-q)){
				if(a <= A && b <= B){
					long code = a * (B+1) + b;
					cache.put(code, true);
				}
				return true;
			}
			q *= a;
		}
		if(a <= A && b <= B){
			long code = a * (B+1) + b;
			cache.put(code, false);
		}
		return false;
	}
	
	void run() throws Exception
	{
//		int n = 10000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < 2*n; i++) {
//			sb.append(Math.abs(gen.nextLong())%1000000000000000000L + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}