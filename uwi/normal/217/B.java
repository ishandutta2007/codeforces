//package round134;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), r = ni();
		if(n == 1 && r == 1){
			out.println(0);
			out.println('T');
			return;
		}
		
		int min = 99999999;
		int mini = -1;
		int ml = -1;
		outer:
		for(int i = r;i >= 0;i--){
			int a = r, b = i;
			int mis = 0;
			int prev = -1;
			for(int j = 0;j < n;j++){
				if(a > b){
					a -= b;
					if(prev == 0){
						mis++;
						if(mis >= min)continue outer;
					}
					prev = 0;
				}else if(a < b){
					b -= a;
					if(prev == 1){
						mis++;
						if(mis >= min)continue outer;
					}
					prev = 1;
				}else{
					if(prev == 1){
						a -= b;
						prev = 0;
					}else{
						b -= a;
						prev = 1;
					}
				}
				if(j < n-1 && (a == 0 || b == 0))continue outer;
			}
			if(a + b == 1 && mis < min){
				min = mis;
				mini = i;
				ml = b;
			}
		}
		if(mini == -1){
			out.println("IMPOSSIBLE");
		}else{
			out.println(min);
			StringBuilder sb = new StringBuilder();
			int a, b;
			if(ml == 1){
				a = r; b = mini;
			}else{
				a = mini; b = r;
			}
			int prev = -1;
			for(int j = 0;j < n;j++){
				if(a > b){
					a -= b;
					prev = 0;
					sb.append('T');
				}else if(a < b){
					b -= a;
					prev = 1;
					sb.append('B');
				}else{
					if(prev == 1){
						a -= b;
						prev = 0;
						sb.append('T');
					}else{
						b -= a;
						prev = 1;
						sb.append('B');
					}
				}
			}
			out.println(sb.reverse());
		}
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
		new B2().run();
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