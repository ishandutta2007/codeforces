//package round152;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static long mod = 10000000000L*912345;
	
	long right(int r1, int c1, int r2, int c2)
	{
		if(r1 > r2)return 0;
		if(c1 > c2)return 0;
		return (mul(c3(c2-1)-c3(c1-2), r2-r1+1)+mul(c2(r2)-c2(r1-1), c2-c1+1))%mod;
	}
	
	long left(int r1, int c1, int r2, int c2)
	{
		if(r1 > r2)return 0;
		if(c1 > c2)return 0;
		return (mul(c3(r2)-c3(r1-1), c2-c1+1)-mul(c2(c2-1)-c2(c1-2), r2-r1+1)+mod)%mod;
	}
	
	long diagr(int r1, int c1, int c2)
	{
		if(c1 > c2)return 0;
		return ((c4(c2)-2*c3(c2)+c2(c2))-(c4(c1-1)-2*c3(c1-1)+c2(c1-1))+
				mul(-r1+1, (c3(c2)-2*c2(c2)+c2)-(c3(c1-1)-2*c2(c1-1)+(c1-1)))+
				(q3(c2)-q3(c1-1))-
				mul(c2(r1-1), c2-c1+1)
				+20*mod)%mod;
	}
	
	long diagl(int c1, int r1, int r2)
	{
		if(r1 > r2)return 0;
		return ((c4(r2)-c4(r1-1))+
				mul(-c1, c3(r2)-c3(r1-1))-
				(q3(r2-2)-q3(r1-3))+
				mul(c2(c1-2), r2-r1+1)
				+20*mod)%mod;
	}
	
	long calc(int r1, int c1, int r2, int c2)
	{
		if(r2 <= c1){
			return right(r1, c1, r2, c2);
		}else if(r1 >= c2){
			return left(r1, c1, r2, c2);
		}else if(r2 > c1 && r1 <= c1){
			if(r2 <= c2){
				return (diagr(r1, c1, r2)+right(r1,r2+1,r2,c2)+diagl(c1, c1+1, r2))%mod;
			}else{
				return (diagr(r1, c1, c2)+diagl(c1, c1+1, c2)+left(c2+1, c1, r2, c2))%mod;
			}
		}else{
			if(r2 > c2){
				return (diagr(r1, r1, c2)+diagl(c1, r1, c2)+left(c2+1, c1, r2, c2))%mod;
			}else{
				return (diagr(r1, r1, r2)+diagl(c1, r1, r2)+right(r1, r2+1, r2, c2))%mod;
			}
		}
	}
	
	void solve()
	{
//		long[] f = new long[]{1234567890123L, 9876543210987L, 1010101010101L};
		long[] f = new long[]{1234567890123L};
		
		outer:
		for(int T = ni();T >= 1;T--){
			int r1 = ni(), c1 = ni(), r2 = ni(), c2 = ni();
			long S = (long)(r2-r1+1)*(c2-c1+1);
//			mod = 10000000000L*912345;
			long ret = calc(r1, c1, r2, c2);
			
			if(S >= 10000000000L || ret >= 10000000000L){
				out.print("...");
				String rs = Long.toString(ret%10000000000L);
				for(int i = rs.length();i<10;i++){
					out.print("0");
				}
				out.println(rs);
			}else{
				out.println(ret);
			}
//			for(long s : f){
//				mod = s;
//				long rets = calc(r1, c1, r2, c2);
//				if(rets != ret){
//					out.print("...");
//					String rs = Long.toString(ret);
//					for(int i = rs.length();i<10;i++){
//						out.print("0");
//					}
//					out.println(rs);
////					out.printf("...%010d\n", ret);
//					continue outer;
//				}
//			}
//			out.println(ret);
		}
	}
	
	public static long mul(long a, long b)
	{
		while(a < 0)a+=mod;
		while(a >= mod)a-=mod;
		while(b < 0)b+=mod;
//		while(b >= mod)b-=mod;
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(ret >= mod)ret -= mod;
			if(b<<63-x<0){
				ret += a;
				if(ret >= mod)ret -= mod;
			}
		}
		return ret;
	}
	
	public static long c3(long r)
	{
		if(r <= 0)return 0;
		long a = r, b = r+1, c = 2*r+1;
		if(a % 2 == 0){
			a /= 2;
		}else{
			b /= 2;
		}
		if(a % 3 == 0){
			a /= 3;
		}else if(b % 3 == 0){
			b /= 3;
		}else{
			c /= 3;
		}
		return mul(mul(a, b), c);
	}	
	
	public static long q3(long r)
	{
		if(r <= 0)return 0;
		long a = r, b = r+1, c = r+2;
		if(a % 2 == 0){
			a /= 2;
		}else{
			b /= 2;
		}
		if(a % 3 == 0){
			a /= 3;
		}else if(b % 3 == 0){
			b /= 3;
		}else{
			c /= 3;
		}
		return mul(mul(a, b), c);
	}	
	
	static long c2(long r)
	{
		if(r <= 0)return 0;
		if(r % 2 == 0){
			return mul(r/2, r+1);
		}else{
			return mul(r, (r+1)/2);
		}
	}
	
	static long c4(long r)
	{
		long v = c2(r);
		return mul(v, v);
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(1000)+1 + " ");
//			sb.append(gen.nextInt(1000)+1 + " ");
//			sb.append(1000000000-gen.nextInt(1000) + " ");
//			sb.append(1000000000-gen.nextInt(1000) + " ");
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