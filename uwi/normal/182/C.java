//package round117;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "8 3 -5 -3 3 4 -3 7 0 -5 1";
	
	void solve()
	{
		int n = ni(), len = ni();
		int[] a = new int[n];
		int[][] plus = new int[n][];
		int[][] minus = new int[n][];
		int p = 0, m = 0;
		for(int i = 0;i < n;i++){
			a[i] = ni();
			if(a[i] >= 0){
				plus[p++] = new int[]{a[i], i};
			}else{
				minus[m++] = new int[]{-a[i], i};
			}
		}
		int K = ni();
		plus = Arrays.copyOf(plus, p);
		minus = Arrays.copyOf(minus, m);
		Arrays.sort(plus, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return -(a[0] - b[0]);
			}
		});
		Arrays.sort(minus, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return -(a[0] - b[0]);
			}
		});
//		tr(plus, minus);
//		
//		tr(a);
		long[] ftp = new long[p+1];
		int[] ftnp = new int[p+1];
		long[] ftm = new long[m+1];
		int[] ftnm = new int[m+1];
		int[] imap = new int[n];
		for(int i = 0;i < p;i++){
			imap[plus[i][1]] = i;
		}
		for(int i = 0;i < m;i++){
			imap[minus[i][1]] = i;
		}
		
		long max = Long.MIN_VALUE;
		long min = Long.MAX_VALUE;
		long S = 0;
		int np = 0, nm = 0;
		for(int i = 0;i < n;i++){
			S += a[i];
			if(a[i] >= 0){
				addFenwick(ftnp, imap[i], 1);
				addFenwick(ftp, imap[i], a[i]);
				np++;
			}else{
				addFenwick(ftnm, imap[i], 1);
				addFenwick(ftm, imap[i], -a[i]);
				nm++;
			}
//			tr(i, S, np, nm, restoreFenwick(ftnp), restoreFenwick(ftnm));
			
			if(i >= len-1){
				if(K > 0){
					{
						int ind = nm < K ? m-1 : findGFenwick(ftnm, K-1)+1;
						max = Math.max(max, S + sumFenwick(ftm, ind)*2);
					}
					{
						int ind = np < K ? p-1 : findGFenwick(ftnp, K-1)+1;
						min = Math.min(min, S - sumFenwick(ftp, ind)*2);
					}
				}else{
					max = Math.max(max, S);
					min = Math.min(min, S);
				}
				
				int v = a[i-len+1];
				S -= v;
				if(v >= 0){
					addFenwick(ftnp, imap[i-len+1], -1);
					addFenwick(ftp, imap[i-len+1], -v);
					np--;
				}else{
					addFenwick(ftnm, imap[i-len+1], -1);
					addFenwick(ftm, imap[i-len+1], v);
					nm--;
				}
			}
		}
		out.println(Math.max(max, -min));
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		if(i < 0)return 0;
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
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
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