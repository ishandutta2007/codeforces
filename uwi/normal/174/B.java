//package vkcup2012.r3;
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
		char[] a = ns(400001);
		int n = a.length;
		int[] pe = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == '.')pe[p++] = i;
		}
		if(p == 0){
			out.println("NO");
			return;
		}
		int[][] div = new int[p][2];
		if(pe[0] >= 1 && pe[0] <= 8){
			div[0][0] = pe[0];
		}else{
			out.println("NO");
			return;
		}
		if(n-1-pe[p-1] >= 1 && n-1-pe[p-1] <= 3){
			div[p-1][1] = n-1-pe[p-1];
		}else{
			out.println("NO");
			return;
		}
		for(int i = 0;i < p-1;i++){
			if(pe[i+1]-pe[i]-1 >= 2 && pe[i+1]-pe[i]-1 <= 11){
				for(int v = 1;v <= 3;v++){
					if(pe[i+1]-pe[i]-1 >= v && pe[i+1]-pe[i]-1-v >= 1 && pe[i+1]-pe[i]-1-v <= 8){
						div[i][1] = v;
						div[i+1][0] = pe[i+1]-pe[i]-1-v;
						break;
					}
				}
			}else{
				out.println("NO");
				return;
			}
		}
		
		out.println("YES");
		for(int i = 0;i < p;i++){
			out.println(new String(a, pe[i]-div[i][0], div[i][0]+1+div[i][1]));
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