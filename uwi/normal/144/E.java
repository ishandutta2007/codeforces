//package round103;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.TreeSet;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] sp = new int[m][2];
		for(int i = 0;i < m;i++){
			sp[i][0] = ni();
			sp[i][1] = ni();
		}
		
		int[][] r = new int[m][3];
		for(int i = 0;i < m;i++){
			r[i][0] = n-sp[i][0];
			r[i][1] = sp[i][1]-1;
			r[i][2] = i;
		}
		
		Arrays.sort(r, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] != b[1])return a[1] - b[1];
				return a[0] - b[0];
			}
		});
		
		TreeSet<Integer> left = new TreeSet<Integer>();
		for(int i = 0;i < n;i++)left.add(i);
		StringBuilder sb = new StringBuilder();
		int ct = 0;
		for(int i = 0;i < m;i++){
			Integer x = left.ceiling(r[i][0]);
			if(x != null && x <= r[i][1]){
				left.remove(x);
				ct++;
				sb.append(" " + (r[i][2]+1));
			}
		}
		
		out.println(ct);
		if(ct > 0){
			out.println(sb.substring(1));
		}
	}
	
	void run() throws Exception
	{
		int n = 100000, m = 100000;
		Random gen = new Random();
		StringBuilder sb = new StringBuilder();
		sb.append(n + " ");
		sb.append(m + " ");
		for (int i = 0; i < m; i++) {
			while(true){
				int a = gen.nextInt(n)+1;
				int b = gen.nextInt(n)+1;
				if(a + b >= n+1){
					sb.append(a + " " + b + " ");
					break;
				}
			}
		}
		INPUT = sb.toString();
		
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