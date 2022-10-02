//package round132;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), x = ni();
		long ret = 0;
		for(int b = 0;2*b+1 <= n;b++){
			for(int c = 0;2*c+1 <= m;c++){
				int q = (2*b+1)*(2*c+1) - x;
//				tr(b,c,q,x);
				if(q > 0){
					for(int e = 1;e * e <= q;e++){
						if(q % e == 0){
							{
								int dd = (2*b+1) - e, aa = (2*c+1) - q/e;
								if(dd % 2 == 1 && aa % 2 == 1){
									int d = dd/2, a = aa/2;
									ret += (n-(2*b+1)+1)*(m-(2*c+1)+1)*2;
								}
							}
							if(e * e != q){
								int dd = (2*b+1) - q/e, aa = (2*c+1) - e;
								if(dd % 2 == 1 && aa % 2 == 1){
									int d = dd/2, a = aa/2;
									ret += (n-(2*b+1)+1)*(m-(2*c+1)+1)*2;
								}
							}
						}
					}
				}
			}
		}
		
		for(int b = 0;2*b+1 <= n;b++){
			if(x % (2*b+1) == 0 && x / (2*b+1) % 2 == 1){
				int c = x/(2*b+1)/2;
				if(2*c+1 <= m){
					ret += (long)(n-(2*b+1)+1)*(m-(2*c+1)+1)*(2*(b+1)*(c+1)-1);
				}
			}
		}
		out.println(ret);
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
		new C().run();
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