//package abbyy2.easy;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class EL {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), c = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		double[] lab = new double[n];
		boolean all0 = true;
		for(int i = 0;i < n;i++){
			a[i] = ni();
			b[i] = ni();
			if(a[i] == 0){
				lab[i] = Long.MIN_VALUE;
			}else{
				all0 = false;
				lab[i] = Math.log10(a[i])-Math.log10(b[i]);
			}
		}
		if(all0){
			out.println(n == c ? -1 : 0);
			return;
		}
		if(n > c){
			out.println(0);
			return;
		}
		
		long sup = 0;
		{
			long low = 0;
			long high = 1000000100000000001L;
			while(high - low > 1){
				long x = (high+low)/2;
				long s = 0;
				double lx = Math.log10(x);
				for(int i = 0;i < n;i++){
					if(lx+lab[i] > 9.3){
						s = Integer.MAX_VALUE;
						break;
					}
					s += x*a[i]/b[i]+1;
					if(s > c)break;
				}
				if(s > c){
					high = x;
				}else{
					low = x;
				}
			}
			sup = low;
		}
		
		long inf = 0;
		{
			long low = 0;
			long high = 1000000100000000001L;
			while(high - low > 1){
				long x = (high+low)/2;
				long s = 0;
				double lx = Math.log10(x);
				for(int i = 0;i < n;i++){
					if(lx+lab[i] > 9.3){
						s = Integer.MAX_VALUE;
						break;
					}
					s += x*a[i]/b[i]+1;
					if(s > c)break;
				}
				if(s >= c){
					high = x;
				}else{
					low = x;
				}
			}
			inf = low;
		}
		out.println(sup-inf);
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
		new EL().run();
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