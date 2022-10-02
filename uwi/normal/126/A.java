//package round93;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

//t0U=t1U+(t2-t1)y2
//t0U=t2U+(t1-t2)y1
// t0(y1+y2)=t1y1+t2y2
// max y1+y2
public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "999997 1000000 1000000 1 999999";
	
	void solve()
	{
		int t1 = ni(), t2 = ni(), x1 = ni(), x2 = ni(), t0 = ni();
		if(t0 == t1){
			if(t1 == t2){
				out.println(x1 + " " + x2);
			}else{
				out.println(x1 + " " + 0);
			}
		}else{
			if(t0 == t2){
				out.println(0 + " " + x2);
			}else{
				int oy1 = 0;
				int oy2 = 0;
				long onum = 1;
				long oden = 0;
				// (t1y1+t2y2)/(y1+y2)>=t0
				for(int y1 = 0;y1 <= x1;y1++){
					// (t2-t0)y2>=(t0-t1)y1
					long v = (long)(t0-t1)*y1;
					long y2 = (v+(t2-t0-1))/(t2-t0);
//					if(y2 == 0)y2++;
					if(y2 > x2)continue;
					long num = (long)t1*y1+(long)t2*y2;
					long den = y1+y2;
					
					if(onum*den-oden*num > 0){
						onum = num;
						oden = den;
						oy1 = y1;
						oy2 = (int)y2;
					}else if(onum*den-oden*num == 0){
						if(oden < den){
							onum = num;
							oden = den;
							oy1 = y1;
							oy2 = (int)y2;
						}
					}
				}
				if(oy1 == 0){
					oy2 = x2;
				}
				out.println(oy1 + " " + oy2);
			}
		}
	}
	
	public static int gcd(int a, int b)
	{
		while(b > 0){
			int c = a; a = b; b = c % b;
		}
		return a;
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
		new A().run();
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