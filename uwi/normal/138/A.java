//package round99;
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
		boolean[] vow = new boolean[256];
		vow['a'] = true;
		vow['e'] = true;
		vow['i'] = true;
		vow['o'] = true;
		vow['u'] = true;
		int n = ni(), k = ni();
		int flag = 7;
		ooo:
		for(int i = 0;i < n;i++){
			String[] ps = new String[4];
			outer:
			for(int j = 0;j < 4;j++){
				char[] po = ns(10000);
				int ct = 0;
				for(int l = po.length-1;l >= 0;l--){
					if(vow[po[l]]){
						ct++;
						if(ct == k){
							ps[j] = new String(po, l, po.length-l);
							continue outer;
						}
					}
				}
				flag = 0;
				break ooo;
			}
			int lf = 0;
			if(ps[0].equals(ps[3]) && ps[1].equals(ps[2])){
				lf |= 1<<2;
			}
			if(ps[0].equals(ps[1]) && ps[2].equals(ps[3])){
				lf |= 1<<0;
			}
			if(ps[0].equals(ps[2]) && ps[1].equals(ps[3])){
				lf |= 1<<1;
			}
			flag &= lf;
		}
		if(flag == 0){
			out.println("NO");
		}else if(flag == 7){
			out.println("aaaa");
		}else if((flag&1) != 0){
			out.println("aabb");
		}else if((flag&2) != 0){
			out.println("abab");
		}else if((flag&4) != 0){
			out.println("abba");
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