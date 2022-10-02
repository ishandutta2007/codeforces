//package round132;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long a = nl(), b = nl();
		out.println(count(b)-count(a-1));
	}
	
//	long countNaive(long n)
//	{
//		long ct = 0;
//		outer:
//		for(long i = 1;i <= n;i++){
//			char[] c = Long.toBinaryString(i).toCharArray();
//			int u = c.length;
//			inner:
//			for(int k = 1;k < u;k++){
//				if(u % k == 0){
//					for(int l = 0;l+k<u;l++){
//						if(c[l] != c[l+k]){
//							continue inner;
//						}
//					}
//					ct++;
//					continue outer;
//				}
//			}
//		}
//		return ct;
//	}
	
	long count(long n)
	{
		if(n == 0)return 0;
		long ret = 0;
		int h = Long.numberOfTrailingZeros(Long.highestOneBit(n))+1;
		for(int i = h;i >= 2;i--){
			if(i < h){
				long[] num = new long[i];
				for(int d = 1;d < i;d++){
					if(i % d == 0){
						num[d] = 1<<d-1;
					}
				}
				for(int d = 1;d < i;d++){
					for(int j = 2*d;j < i;j+=d){
						if(i % j == 0){
							num[j] -= num[d];
						}
					}
				}
				long lret = 0;
				for(int d = 0;d < i;d++){
					lret += num[d];
				}
				ret += lret;
			}else{
				long[] num = new long[i];
				for(int d = 1;d < i;d++){
					if(i % d == 0){
						long mul = n>>>i-d;
						long u = 0;
						for(int j = 0;j < i/d;j++){
							u = u<<d|mul;
						}
//						tr(n, u, mul);
						num[d] = (mul^(1<<d-1)) + (n >= u ? 1 : 0);
					}
				}
				for(int d = 1;d < i;d++){
					for(int j = 2*d;j < i;j+=d){
						if(i % j == 0){
							num[j] -= num[d];
						}
					}
				}
				long lret = 0;
				for(int d = 0;d < i;d++){
					lret += num[d];
				}
				ret += lret;
			}
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
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