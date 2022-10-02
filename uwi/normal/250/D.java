//package croc2012.mbtu.fin;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), a = ni(), b = ni();
		double[] l = new double[n];
		for(int i = 0;i < n;i++)l[i] = ni();
		double[] r = new double[m];
		for(int i = 0;i < m;i++)r[i] = ni();
		int[] plus = new int[m];
		for(int i = 0;i < m;i++)plus[i] = ni();
		
		double opt = Double.POSITIVE_INFINITY;
		int opti = -1;
		int optj = -1;
		int cur = 0;
		for(int i = 0;i < m;i++){
			double y = r[i]*a/b;
			while(cur < n && l[cur] < y)cur++;
			if(cur < n){
				double yy = l[cur];
				double d = Math.sqrt(d2(0, 0, a, yy)) + Math.sqrt(d2(a, yy, b, r[i])) + plus[i];
				if(d < opt){
					opt = d;
					opti = i;
					optj = cur;
				}
			}
			if(cur-1 >= 0){
				double yy = l[cur-1];
				double d = Math.sqrt(d2(0, 0, a, yy)) + Math.sqrt(d2(a, yy, b, r[i])) + plus[i];
				if(d < opt){
					opt = d;
					opti = i;
					optj = cur-1;
				}
			}
		}
		out.println((optj+1) + " " + (opti+1));
	}
	
	public static double d2(double ax, double ay, double bx, double by)
	{
		return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
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
		new D2().run();
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