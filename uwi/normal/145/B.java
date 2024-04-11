//package round104;
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
		int a1 = ni(), a2 = ni(), a3 = ni(), a4 = ni();
		// 1
		if(a3 > a4+1 || a4 > a3+1){
			out.println(-1);
		}else if(a3 == a4){
			if(a1 >= a3+1 && a2 >= a3){
				// 47474
				for(int i = 0;i < a1-a3;i++)out.print('4');
				for(int i = 0;i < a3-1;i++)out.print("74");
				for(int i = 0;i < a2-a3+1;i++)out.print('7');
				out.print('4');
				out.println();
			}else if(a1 >= a3 && a2 >= a3 + 1){
				// 74747
				out.print('7');
				for(int i = 0;i < a1-a3+1;i++)out.print('4');
				for(int i = 0;i < a3-1;i++)out.print("74");
				for(int i = 0;i < a2-a3;i++)out.print('7');
				out.println();
			}else{
				out.println(-1);
			}
		}else if(a3 == a4+1){
			if(a1 >= a3 && a2 >= a3){
				// 4747
				for(int i = 0;i < a1-a3+1;i++)out.print('4');
				for(int i = 0;i < a3-1;i++)out.print("74");
				for(int i = 0;i < a2-a3+1;i++)out.print('7');
				out.println();
			}else{
				out.println(-1);
			}
		}else if(a4 == a3+1){
			if(a1 > a4 && a2 > a4){
				// 7474
				out.print('7');
				for(int i = 0;i < a1-a4+1;i++)out.print('4');
				for(int i = 0;i < a4-2;i++)out.print("74");
				for(int i = 0;i < a2-a4+1;i++)out.print('7');
				out.print('4');
				out.println();
			}else if(a1 == a4 && a2 > a4-1){
				for(int i = 0;i < a4-1;i++)out.print("74");
				for(int i = 0;i < a2-a4+1;i++)out.print('7');
				out.print('4');
				out.println();
			}else if(a1 > a4-1 && a2 == a4){
				out.print('7');
				for(int i = 0;i < a1-a4+1;i++)out.print('4');
				for(int i = 0;i < a4-1;i++)out.print("74");
				out.println();
			}else{
				out.println(-1);
			}
		}else{
			out.println(-1);
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