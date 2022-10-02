//package abbyy2.hard;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class CM {
	InputStream is;
	PrintWriter out;
//	String INPUT = "10 2 7\r\n" + 
//			"+ 11 0\r\n" + 
//			"+ 22 2\r\n" + 
//			"+ 33 6\r\n" + 
//			"+ 44 0\r\n" + 
//			"+ 55 0\r\n" + 
//			"- 22\r\n" + 
//			"+ 66 0";
//	String INPUT = "5 1 6\r\n" + 
//			"+ 123 0\r\n" + 
//			"+ 234 1\r\n" + 
//			"+ 345 2\r\n" + 
//			"- 234\r\n" + 
//			"+ 456 0\r\n" + 
//			"+ 567 0";
	String INPUT = "";
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void solve()
	{
		int h = ni(), m = ni(), n = ni();
		int cy = h / gcd(h, m);
		int[] clus = new int[h];
		int[] ind = new int[h];
		for(int i = 0;i < h/cy;i++){
			int r = i;
			for(int j = 0;j < cy;j++, r = (r+m)%h){
				clus[r] = i;
				ind[r] = j;
			}
		}
		int[][] ft = new int[h/cy][];
		ft[0] = new int[2*cy+1];
		for(int i = 0;i < 2*cy+1;i++){
			addFenwick(ft[0], i, 1);
		}
		for(int i = 1;i < h/cy;i++){
			ft[i] = Arrays.copyOf(ft[0], ft[0].length);
		}
		
		int[] t = new int[h];
		Arrays.fill(t, -1);
		Map<Integer, Integer> imap = new HashMap<Integer, Integer>();
		
		long waste = 0;
		for(int i = 0;i < n;i++){
			char c = nc();
			if(c == '+'){
				int id = ni();
				int v = ni();
				int cl = clus[v];
				int nd = ind[v];
				if(nd == 0)nd = cy;
				int x = findGFenwick(ft[cl], sumFenwick(ft[cl], nd-1))+1;
				waste += x - nd;
				x %= cy;
				addFenwick(ft[cl], x, -1);
				addFenwick(ft[cl], x+cy, -1);
				imap.put(id, (int)((cl+(long)x*m)%h));
//				tr(restoreFenwick(ft[cl]));
//				tr(imap);
			}else if(c == '-'){
				int id = ni();
				int v = imap.remove(id);
				int cl = clus[v];
				int nd = ind[v];
				addFenwick(ft[cl], nd, 1);
				addFenwick(ft[cl], nd+cy, 1);
//				tr(restoreFenwick(ft[cl]));
			}
		}
		out.println(waste);
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
	
	char nc() {
		try{
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if(b == -1)
				return 0;
			return (char) b;
		}catch (IOException e){
		}
		return 0;
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
		new CM().run();
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