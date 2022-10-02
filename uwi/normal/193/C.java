//package round122;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "10 10 8 8 8 10";
	
	void solve()
	{
		int[] a = new int[6];
		for(int i = 0;i < 6;i++)a[i] =  ni();
		
		// 12 13 14 23 24 34
		// 0001
		// 0010
		// 0011
		// 0100
		// 0101
		// 0110
		// 0111
		
		outer:
		for(int i = 1;i <= 200000;i++){
			double[][] M = new double[][]{
					{0, 0, 0, 1, 1, 1, 1},
					{0, 1, 1, 0, 0, 1, 1},
					{1, 0, 1, 0, 1, 0, 1},
					{0, 1, 1, 1, 1, 0, 0},
					{1, 0, 1, 1, 0, 1, 0},
					{1, 1, 0, 0, 1, 1, 0},
					{1, 1, 1, 1, 1, 1, 1}
			};
			double[] v = new double[7];
			for(int j = 0;j < 6;j++){
				v[j] = a[j];
			}
			v[6] = i;
			v = gaussianElimination(M, v);
			if(v == null)continue;
			for(int j = 0;j < 7;j++){
				if(Double.isNaN(v[j]))continue outer;
				if(Math.abs(Math.round(v[j]) - v[j]) > 1E-8)continue outer;
				if(Math.round(v[j]) < 0)continue outer;
			}
			
			StringBuilder[] sb = new StringBuilder[4];
			for(int j = 0;j < 4;j++){
				sb[j] = new StringBuilder();
			}
			
			for(int j = 0;j < 7;j++){
				int q = (int)Math.round(v[j]);
				if(q > 0){
					for(int k = 0;k < q;k++){
						for(int l = 0;l < 4;l++){
							sb[3-l].append(j+1<<31-l<0 ? 'b' : 'a');
						}
					}
				}
			}
			out.println(i);
			for(int j = 0;j < 4;j++){
				out.println(sb[j]);
			}
			return;
		}
		out.println(-1);
	}
	
	public double[] gaussianElimination(double[][] a, double[] c)
	{
		int n = a.length;
		int[] ps = new int[n];
		for(int i = 0;i < n;i++)ps[i] = i;
		
		// 
		for(int i = 0;i < n;i++){
			int pivot = -1;
			int from = -1;
			double amax = 0;
			for(int j = i;j < n;j++){
				if(Math.abs(a[ps[j]][i]) > amax){
					amax = Math.abs(a[ps[j]][i]);
					pivot = ps[j];
					from = j;
				}
			}
			if(pivot == -1)return null;
			int d = ps[i]; ps[i] = ps[from]; ps[from] = d;
			
			for(int j = i+1;j < n;j++){
				a[ps[i]][j] /= a[ps[i]][i];
			}
			c[ps[i]] /= a[ps[i]][i];
			a[ps[i]][i] = 1.0;
			for(int j = i+1;j < n;j++){
				for(int k = i+1;k < n;k++){
					a[ps[j]][k] -= a[ps[j]][i] * a[ps[i]][k];
				}
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
				a[ps[j]][i] = 0.0;
			}
			
		}
		
		// 
		for(int i = n-1;i >= 0;i--){
			for(int j = i-1;j >= 0;j--){
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
			}
		}
		
		double[] ret = new double[n];
		for(int i = 0;i < n;i++){
			ret[i] = c[ps[i]];
		}
		
		return ret;
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