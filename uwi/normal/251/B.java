//package round153;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni()-1;
		int[] b = new int[n];
		for(int i = 0;i < n;i++)b[i] = ni()-1;
		
		int[] now = new int[n];
		for(int i = 0;i < n;i++)now[i] = i;
		boolean zero = Arrays.equals(now, b);
		int upper = m+1;
		for(int i = 1;i <= m;i++){
			now = apply(now, a);
			if(Arrays.equals(now, b)){
				upper = i;
				break;
			}
		}
		int lower = m+1;
		for(int i = 0;i < n;i++)now[i] = i;
		for(int i = 1;i <= m;i++){
			now = applyi(now, a);
			if(Arrays.equals(now, b)){
				lower = i;
				break;
			}
		}
		
		if(zero){
			out.println("NO");
		}else{
			if(upper <= m && upper % 2 == m % 2){
				if(upper >= 2){
					out.println("YES");
					return;
				}else{
					if(m == 1 || lower >= 2){
						out.println("YES");
						return;
					}
				}
			}else if(lower <= m && lower % 2 == m % 2){
				if(lower >= 2){
					out.println("YES");
					return;
				}else if(m == 1 || upper >= 2){
					out.println("YES");
					return;
				}
			}
			out.println("NO");
		}
	}
	
	int[] apply(int[] a, int[] p)
	{
		int n = a.length;
		int[] b = new int[n];
		for(int i = 0;i < a.length;i++){
			b[p[i]] = a[i];
		}
		return b;
	}
	
	int[] applyi(int[] a, int[] p)
	{
		int n = a.length;
		int[] b = new int[n];
		for(int i = 0;i < a.length;i++){
			b[i] = a[p[i]];
		}
		return b;
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
		new B().run();
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