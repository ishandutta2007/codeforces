//package round141;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		int m = ni();
		
		long[][][] ft = new long[7][11][];
		for(int i = 2;i <= 6;i++){
			for(int j = 0;j < 2*(i-1);j++){
				ft[i][j] = new long[n+1];
				for(int k = 0;k < n;k++){
					int o = (k-j+2*(i-1))%(2*(i-1));
					int co = o <= i-1 ? o+1 : 2*(i-1)+1-o;
					tr(i, j, k, o, co);
					addFenwick(ft[i][j], k, co*a[k]);
				}
//				tr(i, j, restoreFenwick(ft[i][j]));
			}
		}
		
		for(int q = 0;q < m;q++){
			int t = ni();
			if(t == 1){
				int p = ni()-1, v = ni();
				long d = v - a[p];
				for(int i = 2;i <= 6;i++){
					for(int j = 0;j < 2*(i-1);j++){
						int o = (p-j+2*(i-1))%(2*(i-1));
						int co = o <= i-1 ? o+1 : 2*(i-1)+1-o;
						addFenwick(ft[i][j], p, co*d);
					}
				}
				a[p] = v;
			}else{
				int l = ni()-1, r = ni()-1, z = ni();
				out.println(sumFenwick(ft[z][l%(2*(z-1))], r) - sumFenwick(ft[z][l%(2*(z-1))], l-1));
			}
		}
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static long valFenwick(long[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(1000000000)+1 + " ");
//		}
//			sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(1000000000)+1 + " ");
//		}
//		INPUT = sb.toString();
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