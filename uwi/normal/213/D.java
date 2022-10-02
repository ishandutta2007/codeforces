//package round131;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double D = 10;
		double U = D * (Math.sqrt(5)+1)/2;
		double S = Math.sqrt((-Math.sqrt(5)+5)/8) * D;
		double T = Math.sqrt((Math.sqrt(5)+5)/8) * D;
		
		double x = 0, y = 0;
		out.println(5*n-(n-1));
		out.printf("%.10f %.10f\n", x, y);
		double[][] P = new double[][]{
				{U/2, S},
				{U, 0},
				{U/2+0.5*D, -T},
				{U/2-0.5*D, -T}
		};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				out.printf("%.10f %.10f\n", x+P[j][0], y+P[j][1]);
			}
			x += U;
		}
		out.println("1 2 3 4 5");
		for(int i = 1;i < n;i++){
			out.print("" + (4*i-1));
			out.print(" " + (4*i+2));
			out.print(" " + (4*i+3));
			out.print(" " + (4*i+4));
			out.print(" " + (4*i+5));
			out.println();
		}
		out.println();
		out.print("1");
		for(int i = 0;i < n;i++){
			out.print(" " + (4*i+3));
		}
		for(int i = n-1;i >= 0;i--){
			out.print(" " + (4*i+5));
			out.print(" " + (4*i+2));
			out.print(" " + (4*i+4));
			if(i > 0)out.print(" " + (4*i-1));
		}
		out.print(" " + 1);
		out.println();
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
		new D().run();
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