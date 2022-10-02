//package round18;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] co = new int[3][];
		for(int i = 0;i < 3;i++){
			co[i] = new int[]{ni(), ni()};
		}
		for(int i = 0;i < 3;i++){
			if(right(co[i], co[(i+1)%3], co[(i+2)%3])){
				out.println("RIGHT");
				return;
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int i = 0;i < 3;i++){
			for(int k = 0;k < 4;k++){
				co[i][0] += dr[k];
				co[i][1] += dc[k];
				for(int j = 0;j < 3;j++){
					if(right(co[j], co[(j+1)%3], co[(j+2)%3])){
						out.println("ALMOST");
						return;
					}
				}
				co[i][0] -= dr[k];
				co[i][1] -= dc[k];
			}
		}
		out.println("NEITHER");
	}
	
	boolean right(int[] a, int[] b, int[] c)
	{
		int bx = b[0]-a[0];
		int by = b[1]-a[1];
		int cx = c[0]-a[0];
		int cy = c[1]-a[1];
		
		if(bx*bx+by*by == 0)return false;
		if(cx*cx+cy*cy == 0)return false;
		if(bx*cy-cx*by == 0)return false;
		return bx*cx+by*cy == 0;
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