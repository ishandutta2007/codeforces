//package round138;
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
		char[] a = ns(100001);
		int n = a.length;
		char[] s = new char[n+1];
		int[] mile = new int[n+1];
		Arrays.fill(mile, -1);
		int[] brh = new int[n+1];
		Arrays.fill(brh, -1);
		int p = 0;
		int optbr = 0;
		int br = 0;
		int optst = -1, optend = -2;
		for(int i = 0;i < n;i++){
			if(a[i] == '('){
				if(mile[p] == -1)mile[p] = i;
				if(brh[p] == -1)brh[p] = br;
				s[p++] = '(';
			}else if(a[i] == '['){
				if(mile[p] == -1)mile[p] = i;
				if(brh[p] == -1)brh[p] = br;
				s[p++] = '[';
				br++;
			}else if(a[i] == ')'){
				if(p-1 >= 0 && s[p-1] == '('){
					if(br-brh[p-1] > optbr){
						optbr = br-brh[p-1];
						optend = i;
						optst = mile[p-1];
					}
					s[p-1] = 0;
					mile[p] = -1;
					brh[p] = -1;
					p--;
				}else{
					mile[p] = -1;
					brh[p] = -1;
					s[p] = 0;
					while(p > 0){
						mile[p-1] = -1;
						brh[p-1] = -1;
						s[p-1] = 0;
						p--;
					}
				}
			}else{
				if(p-1 >= 0 && s[p-1] == '['){
					if(br-brh[p-1] > optbr){
						optbr = br-brh[p-1];
						optend = i;
						optst = mile[p-1];
					}
					s[p-1] = 0;
					mile[p] = -1;
					brh[p] = -1;
					p--;
				}else{
					mile[p] = -1;
					brh[p] = -1;
					s[p] = 0;
					while(p > 0){
						mile[p-1] = -1;
						brh[p-1] = -1;
						s[p-1] = 0;
						p--;
					}
				}
			}
		}
		if(optbr == 0){
			out.println(0);
			out.println();
		}else{
			out.println(optbr);
			out.println(new String(a, optst, optend-optst+1));
		}
	}
	
	void run() throws Exception
	{
		System.out.println(INPUT);
		
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