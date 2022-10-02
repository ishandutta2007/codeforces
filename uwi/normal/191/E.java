//package round121;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long K = nl();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		
		long[] os = new long[n+1];
		long[][] s = new long[n+1][];
		s[0] = new long[]{0L, 0L};
		for(int i = 0;i < n;i++){
			s[i+1] = new long[]{s[i][0] + a[i], i+1};
			os[i+1] = s[i+1][0];
		}
		Arrays.sort(s, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.signum(a[0] - b[0]);
			}
		});
		long[] ss = new long[n+1];
		for(int i = 0;i < n+1;i++)ss[i] = 2*s[i][0];
		
		int[] iord = new int[n+1];
		for(int i = 0;i < n+1;i++){
			iord[(int)s[i][1]] = i;
		}
		
		long low = -100000000000005L;
		long high = 100000000000005L;
		while(high - low > 1){
			long x = (high + low) / 2;
			long q = test(x, iord, ss, os, n);
			if(q >= K){
				low = x;
			}else{
				high = x;
			}
		}
		out.println(low);
	}
	
	long test(long x, int[] iord, long[] ss, long[] os, int n)
	{
		int[] ft = new int[n+2];
		// os[i]-y>=x
		// y<=os[i]-x
		long q = 0;
		for(int i = 0;i < n+1;i++){
			int ind = Arrays.binarySearch(ss, 2*(os[i]-x)+1);
			ind = -ind-2;
			q += sumFenwick(ft, ind);
			addFenwick(ft, iord[i], 1);
		}
		return q;
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
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
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
		new E().run();
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