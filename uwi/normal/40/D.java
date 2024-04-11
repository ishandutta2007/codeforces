//package round39;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "" + BigInteger.valueOf(12).pow(280).shiftLeft(1);
	String INPUT = "";
	
	void solve()
	{
		BigInteger b = new BigInteger(ns());
//		tr(b.toString().length());
		char[] tw = b.toString(12).toCharArray();
		int n = tw.length;
		int[] ct = new int[3];
		for(int i = 0;i < n;i++){
			if(tw[i] >= '0' && tw[i] <= '2'){
				ct[tw[i]-'0']++;
			}else{
				out.println("NO");
				return;
			}
		}
		if(ct[1]+ct[2]*2 == 2){
			int tx = -1, ty = -1;
			if(ct[1] == 2){
				for(int i = n-1;i >= 0;i--){
					if(tw[i] == '1'){
						tx = n-1-i;
						break;
					}
				}
				ty = n-1;
			}else{
				tx = ty = n-1;
			}
			out.println("YES");
			out.println(1);
			out.println(tx+ty+1);
			int h = (tx+ty)/2;
			out.println(h+1-1);
			int count = 0;
			for(int i = 0;i <= h && count < 1000;i++){
				int x = h-i, y = tx+ty-h+i;
				if(x == tx && y == ty)continue;
				count++;
				BigInteger ret = BigInteger.valueOf(12).pow(x).add(BigInteger.valueOf(12).pow(y));
				out.println(ret);
			}
		}else{
			out.println("NO");
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
		new D2().run();
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