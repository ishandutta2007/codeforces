//package round123;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] K = new int[n];
		int[] b = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			K[i] = ni();
			b[i] = ni();
			if(K[i] != 0)p++;
		}
		
		long[][] fs = new long[p][];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(K[i] == 0)continue;
			long[] fr = Arrays.copyOf(reduce(new long[]{-b[i], K[i]}), 3);
			fr[2] = K[i];
			fs[q++] = fr;
		}
		Arrays.sort(fs, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.signum(a[0] * b[1] - a[1] * b[0]);
			}
		});
		
		int ct = 0;
		for(int i = 0;i < p;){
			int j;
			for(j = i+1;j < p;j++){
				if(fs[i][0] * fs[j][1] - fs[i][1] * fs[j][0] != 0){
					break;
				}
			}
			ct++;
			i = j;
		}
		out.println(ct);
	}
	
	public static long[] reduce(long[] f)
	{
		if(f[1] == 0) {
		}else if(f[0] == 0) {
			f[1] = 1;
		}else {
			if(f[1] < 0) {
				f[0] = -f[0];
				f[1] = -f[1];
			}
			long g = gcd(Math.abs(f[0]), f[1]);
			f[0] /= g;
			f[1] /= g;
		}
		return f;
	}
	
	public static long[] add(long[] a, long[] b){	return reduce(new long[]{a[0]*b[1]+a[1]*b[0], a[1]*b[1]}); }
	public static long[] sub(long[] a, long[] b){	return reduce(new long[]{a[0]*b[1]-a[1]*b[0], a[1]*b[1]}); }
	public static long[] mul(long[] a, long[] b){	return reduce(new long[]{a[0]*b[0], a[1]*b[1]}); }
	public static long[] div(long[] a, long[] b){	return reduce(new long[]{a[0]*b[1], a[1]*b[0]}); }
		
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
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
		new D().run();
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