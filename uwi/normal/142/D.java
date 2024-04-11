//package round102;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "3 3 2\r\n" + 
			"G-R\r\n" + 
			"R-G\r\n" + 
			"G-R"; 
	boolean[][] g = new boolean[101][101];
	boolean[][] d = new boolean[101][101];
	
	void solve()
	{
		int n = ni(), m = ni(), k = ni();
		int[] ds = new int[8];
		boolean f1 = false;
		boolean f2 = false;
		for(int i = 0;i < n;i++){
			char[] str = ns(m);
			int r = -1, g = -1;
			int num = 0;
			for(int j = 0;j < m;j++){
				if(str[j] == 'R'){ r = j; num++;}
				if(str[j] == 'G'){ g = j; num++;}
			}
			if(r == -1 && g >= 0 && m > num)f1 = true;
			if(g == -1 && r >= 0 && m > num)f2 = true;
			if(r >= 0 && g >= 0){
				int dist = Math.abs(r-g)-1;
				for(int j = 0;j < 8;j++){
					ds[j] += dist>>>j&1;
				}
			}
		}
		if(f1 && f2){
			out.println("Draw");
		}else if(f1){
			out.println("First");
		}else if(f2){
			out.println("Second");
		}else{
			boolean jud = false;
			for(int j = 0;j < 8;j++){
				if(ds[j] % (k+1) != 0)jud = true;
			}
			if(jud){
				out.println("First");
			}else{
				out.println("Second");
			}
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