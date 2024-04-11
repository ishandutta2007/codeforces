//package croc2012.mbtu.fin;
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
		int n = ni();
		for(int i = 0;i < n;i++){
			String line = ns();
			if(line.equals("::")){
				for(int j = 0;j < 7;j++){
					out.print("0000:");
				}
				out.println("0000");
				continue;
			}
			
			String ret = "";
			if(line.startsWith("::")){
				int plus = 9-countc(line);
				for(int j = 0;j < plus;j++){
					ret += "0000:";
				}
				ret += line.substring(2);
			}else if(line.endsWith("::")){
				int plus = 9-countc(line);
				ret += line.substring(0, line.length()-2);
				for(int j = 0;j < plus;j++){
					ret += ":0000";
				}
			}else{
				int ind = line.indexOf("::");
				if(ind >= 0){
					ret += line.substring(0, ind);
					int plus = 8-countc(line);
					for(int j = 0;j < plus;j++){
						ret += ":0000";
					}
					ret += line.substring(ind+1);
				}else{
					ret = line;
				}
			}
			
			out.println(process(ret));
		}
	}
	
	int countc(String u)
	{
		int ct = 0;
		for(int i = 0;i < u.length();i++){
			if(u.charAt(i) == ':')ct++;
		}
		return ct;
	}
	
	String process(String line)
	{
		String[] sp = line.split(":");
		StringBuilder sb = new StringBuilder();
		for(String s : sp){
			sb.append(":");
			for(int i = 0;i < 4-s.length();i++){
				sb.append("0");
			}
			sb.append(s);
		}
		return sb.substring(1);
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