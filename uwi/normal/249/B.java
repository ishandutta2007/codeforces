//package round152;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), t = ni();
		char[] b = ns(n);
		int low = -1, high = 500001;
		if(simulate(b, 500001) >= t){
			out.println(-1);
			return;
		}
		while(high - low > 1){
			int x = (high+low)/2;
			if(simulate(b, x) < t){
				high = x;
			}else{
				low = x;
			}
		}
		out.println(high);
	}
	
	long simulate(char[] b, int x)
	{
		int n = b.length;
		int first = -1;
		int has = x;
		int[][] fs = new int[n][];
		int fp = 0;
		int last = -1;
		for(int i = n-1;i >= 0;i--){
			if(b[i] == 'H'){
				last = i;
				break;
			}
		}
		if(last == -1)return 0L;
		
		long step = n-1;
		int gain = -1;
		
		// SSS HH
		// HHH SSS
		// H SSH
		for(int i = 0;i < n;i++){
			if(b[i] == 'H'){
				if(has > 0){
					has--;
					first = i;
				}else{
					if(has == 0){
						first = i;
					}
					has--;
				}
			}else if(b[i] == 'S'){
				if(has < 0){
					has++;
					if(has == 0){
						gain = i;
						fs[fp++] = new int[]{first, i};
						step += (i-first)*2;
					}
				}else{
					has++;
				}
			}
		}
		if(has < 0)return Long.MAX_VALUE;
		
		long minstep = 99999999;
		last = Math.max(gain, last);
		step -= (n-1)-last;
		minstep = step;
		for(int i = fp-1;i >= 0;i--){
			step -= (fs[i][1]-fs[i][0])*2;
			minstep = Math.min(minstep, step+last-fs[i][0]);
		}
		
		return minstep;
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
		new B2().run();
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