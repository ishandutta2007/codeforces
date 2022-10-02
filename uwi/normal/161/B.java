//package vkcup2012.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), k = ni();
		int[][] stool = new int[n][];
		int[][] pencil = new int[n][];
		int p = 0, q = 0;
		long sum = 0;
		int min = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			int v = ni();
			int kind = ni();
			if(kind == 1){
				stool[p++] = new int[]{v, i+1};
			}else{
				pencil[q++] = new int[]{v, i+1};
			}
			sum += v;
			min = Math.min(min, v);
		}
		stool = Arrays.copyOf(stool, p);
		pencil = Arrays.copyOf(pencil, q);
		Arrays.sort(stool, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] - b[0] != 0)return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		Arrays.sort(pencil, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] - b[0] != 0)return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		if(k == 1){
			if(p == 0)min = 0;
			out.printf("%.1f\n", sum - (double)min/2);
			out.print(n);
			for(int i = 0;i < n;i++){
				out.print(" ");
				out.print(i+1);
			}
			out.println();
			return;
		}
		
		if(p >= k){
			long all = 0;
			for(int i = 0;i < k-1;i++){
				all += stool[p-1-i][0];
			}
			if(q > 0){
				all += Math.min(stool[0][0], pencil[0][0]);
			}else{
				all += stool[0][0];
			}
			
			long other = 0;
			for(int i = 0;i < k-2;i++){
				other += stool[p-1-i][0];
			}
			other += stool[0][0];
			
			if(all >= other){
				out.printf("%.1f\n", sum-(double)all/2);
				for(int i = 0;i < k-1;i++){
					out.println("1 " + stool[p-1-i][1]);
				}
				out.print(n-(k-1));
				for(int i = 0;i <= p-1-(k-1);i++){
					out.print(" ");
					out.print(stool[i][1]);
				}
				for(int[] h : pencil){
					out.print(" ");
					out.print(h[1]);
				}
				out.println();
			}else{
				out.printf("%.1f\n", sum-(double)other/2);
				for(int i = 0;i < k-2;i++){
					out.println("1 " + stool[p-1-i][1]);
				}
				out.print(p-1-(k-2)+1);
				for(int i = 0;i <= p-1-(k-2);i++){
					out.print(" ");
					out.print(stool[i][1]);
				}
				out.println();
				out.print(pencil.length);
				for(int[] h : pencil){
					out.print(" ");
					out.print(h[1]);
				}
				out.println();
			}
		}else{
			long all = 0;
			for(int i = 0;i < p;i++)all += stool[i][0];
			out.printf("%.1f\n", sum-(double)all/2);
			for(int i = 0;i < p;i++){
				out.println("1 " + stool[i][1]);
			}
			for(int i = 0;i < k-p-1;i++){
				out.println("1 " + pencil[i][1]);
			}
			out.print((q-1)-(k-p-1)+1);
			for(int i = k-p-1;i < q;i++){
				out.print(" ");
				out.print(pencil[i][1]);
			}
			out.println();
		}
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