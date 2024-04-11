//package vkcup2012.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), l = ni(), v1 = ni(), v2 = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		double[][] x = new double[2*n+2][3];
		for(int i = 0;i < n;i++){
			x[i+1][0] = a[i];
			x[i+1][1] = i;
			x[i+1][2] = 0;
		}
		double plus = (double)l*v2 / (v1+v2);
		for(int i = 0;i < n;i++){
			x[n+i+1][0] = (a[i]+plus) % (2*l);
			x[n+i+1][1] = i;
			x[n+i+1][2] = 1;
		}
		x[0][0] = 0;
		x[0][1] = -1;
		x[0][2] = -1;
		x[2*n+1][0] = 2*l;
		x[2*n+1][1] = -1;
		x[2*n+1][2] = -1;
		
		Arrays.sort(x, 1, 2*n+1, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return (int)Math.signum(a[0] - b[0]);
			}
		});
		
		int[][] ra = new int[n][2];
		for(int i = 0;i < 2*n+2;i++){
			if(x[i][1] == -1)continue;
			ra[(int)x[i][1]][(int)x[i][2]] = i;
		}
		int[] ft0 = new int[2*n+3];
		int[] ft1 = new int[2*n+3];
		
		for(int i = 0;i < n;i++){
			if(ra[i][0] < ra[i][1]){
				addRangeFenwick(ft0, ft1, ra[i][1]-1, 1);
				addRangeFenwick(ft0, ft1, ra[i][0]-1, -1);
			}else{
				addRangeFenwick(ft0, ft1, 2*n+1, 1);
				addRangeFenwick(ft0, ft1, ra[i][0]-1, -1);
				addRangeFenwick(ft0, ft1, ra[i][1]-1, 1);
			}
		}
		
		long prev = 0;
		double[] ret = new double[n+1];
		for(int i = 1;i <= 2*n+1;i++){
			long cur = sumRangeFenwick(ft0, ft1, i-1);
			ret[(int)(cur - prev)] += x[i][0]-x[i-1][0];
			prev = cur;
		}
		
		for(int i = 0;i <= n;i++){
			out.printf("%.11f\n", ret[i] / (2*l));
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static void addRangeFenwick(int[] ft0, int[] ft1, int i, int v)
	{
		addFenwick(ft1, i+1, -v);
		addFenwick(ft1, 0, v);
		addFenwick(ft0, i+1, v*(i+1));
	}
	
	public static void addRangeFenwick(int[] ft0, int[] ft1, int a, int b, int v)
	{
		if(a <= b){
			addFenwick(ft1, b+1, -v);
			addFenwick(ft0, b+1, v*(b+1));
			addFenwick(ft1, a, v);
			addFenwick(ft0, a, -v*a);
		}
	}
	
	public static long sumRangeFenwick(int[] ft0, int[] ft1, int i)
	{
		return (long)sumFenwick(ft1, i) * (i+1) + sumFenwick(ft0, i);
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