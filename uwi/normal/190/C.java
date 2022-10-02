//package round120;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String[] sp = split(ns(), ' ');
		if(sp.length == 1 && sp[0].equals("int")){
			out.println("int");
			return;
		}else if(sp.length < 3){
			out.println("Error occurred");
			return;
		}
		
		int dep = 0;
		int[] pos = new int[sp.length+1];
		for(int i = 0;i < sp.length;i++){
			if(sp[i].equals("pair")){
				dep++;
				pos[dep] = 0;
			}else{
				if(pos[dep] == 0){
					pos[dep] = 1;
				}else if(pos[dep] == 1){
					do{
						dep--;
						if(dep == -1){
							out.println("Error occurred");
							return;
						}
						pos[dep]++;
					}while(pos[dep] == 2);
				}
			}
//			tr(dep, pos[dep]);
		}
		if(dep != 0 || pos[0] != 1){
			out.println("Error occurred");
		}else{
			Arrays.fill(pos, 0);
			dep = 0;
			for(int i = 0;i < sp.length;i++){
				if(sp[i].equals("pair")){
					out.print("pair<");
					dep++;
					pos[dep] = 0;
				}else{
					out.print("int");
					if(pos[dep] == 0){
						pos[dep] = 1;
						out.print(",");
					}else if(pos[dep] == 1){
						do{
							dep--;
							out.print(">");
							pos[dep]++;
						}while(pos[dep] == 2);
						if(dep > 0)out.print(",");
					}
				}
			}
			out.println();
		}
	}
	
	public static String[] split(String str, char sep)
	{
		char[] ar = str.toCharArray();
		String[] l = new String[ar.length/2+3];
		int p = 0;
		int prev = 0;
		for(int i = 0;i < ar.length;i++){
			if(ar[i] == sep){
				if(prev < i){
					l[p++] = str.substring(prev, i);
				}
				prev = i+1;
			}
		}
		if(prev < ar.length){
			l[p++] = str.substring(prev);
		}
		return Arrays.copyOf(l, p);
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
		new C().run();
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
			while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n')return sb.toString();
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