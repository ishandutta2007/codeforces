//package abbyy2.hard;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class CS {
	InputStream is;
	PrintWriter out;
//	String INPUT = "10 2 7\r\n" + 
//			"+ 11 0\r\n" + 
//			"+ 22 2\r\n" + 
//			"+ 33 6\r\n" + 
//			"+ 44 0\r\n" + 
//			"+ 55 0\r\n" + 
//			"- 22\r\n" + 
//			"+ 66 0";
//	String INPUT = "5 1 6\r\n" + 
//			"+ 123 0\r\n" + 
//			"+ 234 1\r\n" + 
//			"+ 345 2\r\n" + 
//			"- 234\r\n" + 
//			"+ 456 0\r\n" + 
//			"+ 567 0";
	String INPUT = "";
	
	void solve()
	{
		int h = ni(), m = ni(), n = ni();
		int[] t = new int[h];
		Arrays.fill(t, -1);
		Map<Integer, Integer> imap = new HashMap<Integer, Integer>();
		
		long waste = 0;
		for(int i = 0;i < n;i++){
			char c = nc();
			if(c == '+'){
				int id = ni();
				int v = ni();
				while(t[v] != -1){
					v = (v + m) % h;
					waste++;
				}
				t[v] = id;
				imap.put(id, v);
			}else if(c == '-'){
				int id = ni();
				int v = imap.remove(id);
				t[v] = -1;
			}
		}
		out.println(waste);
	}
	
	char nc() {
		try{
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if(b == -1)
				return 0;
			return (char) b;
		}catch (IOException e){
		}
		return 0;
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
		new CS().run();
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