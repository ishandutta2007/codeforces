//package round116;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
	void solve()
	{
		int b = ni(), d = ni();
		
		int v;
		if((v = isType2(b, d)) > 0){
			out.println("2-type");
			out.println(v);
		}else if(isType3(b, d)){
			out.println("3-type");
		}else if(isType11(b, d)){
			out.println("11-type");
		}else if(isType6(b, d)){
			out.println("6-type");
		}else{
			out.println("7-type");
		}
	}
	
	int isType2(int b, int d)
	{
		int[][] fb = factor(b, primes);
		int emax = 0;
		for(int[] f : fb){
			int e = 0;
			while(d % f[0] == 0){
				d /= f[0];
				e++;
			}
			emax = Math.max(emax, (e+f[1]-1)/f[1]);
		}
		return d != 1 ? 0 : emax;
	}
	
	boolean isType3(int b, int d)
	{
		if(b == 2)return false;
		return (b-1) % d == 0;
	}
	
	boolean isType11(int b, int d)
	{
		return (b+1) % d == 0;
	}
	
	boolean isType6(int b, int d)
	{
		int[][] fd = factor(d, primes);
		for(int[] f : fd){
			int mul = 1;
			for(int i = 0;i < f[1];i++){
				mul *= f[0];
			}
			if(isType2(b, mul) > 0 || isType3(b, mul) || isType11(b, mul)){
			}else{
				return false;
			}
		}
		return true;
	}
	
	public static int[][] factor(int n, int[] primes)
	{
		int[][] ret = new int[9][2];
		int rp = 0;
		for(int p : primes){
			if(p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				ret[rp][0] = p;
				ret[rp][1] = i;
				rp++;
			}
		}
		if(n != 1){
			ret[rp][0] = n;
			ret[rp][1] = 1;
			rp++;
		}
		return Arrays.copyOf(ret, rp);
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