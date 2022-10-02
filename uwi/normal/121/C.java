//package round91;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	long[] lucky;
	
	void solve()
	{
		int n = ni(), k = ni();
		lucky = new long[2000];
		int pos = rec(lucky, 0, 0);
		lucky = Arrays.copyOf(lucky, pos);
		Arrays.sort(lucky);
		
		long[] fact = new long[14];
		fact[0] = 1;
		for(int i = 1;i < 14;i++)fact[i] = fact[i-1]*i;
		if(n <= 13){
			if(k > fact[n]){
				out.println(-1);
			}else{
				long p = k - 1;
				int ct = 0;
				BitSet used = new BitSet();
				for(int i = n-1;i >= 0;i--){
					long q = p / fact[i];
					p = p % fact[i];
					
					int tar = used.nextClearBit(0);
					for(int j = 0;j < q;j++){
						tar = used.nextClearBit(tar+1);
					}
					used.set(tar);
					if(isLucky(n-i) && isLucky(tar+1)){
						ct++;
					}
				}
				out.println(ct);
			}
		}else{
			int ct = 0;
			for(int i = 0;i < lucky.length;i++){
				if(lucky[i] <= n-13){
					ct++;
				}
			}
			
			long p = k - 1;
			BitSet used = new BitSet();
			for(int i = 12;i >= 0;i--){
				long q = p / fact[i];
				p = p % fact[i];
				
				int tar = used.nextClearBit(0);
				for(int j = 0;j < q;j++){
					tar = used.nextClearBit(tar+1);
				}
				used.set(tar);
				if(isLucky(n-i) && isLucky(tar+n-13+1)){
					ct++;
				}
			}
			out.println(ct);
		}
	}
	
	boolean isLucky(long n)
	{
		if(n == 0)return false;
		if(n==4 || n==7)return true;
		return (n%10==4||n%10==7) && isLucky(n/10);
	}
	
	int rec(long[] lucky, int pos, long n)
	{
		if(n > 1000000000)return pos;
		if(n != 0)lucky[pos++] = n;
		pos = rec(lucky, pos, n*10+4);
		pos = rec(lucky, pos, n*10+7);
		return pos;
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