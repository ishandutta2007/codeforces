//package vkcup1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		if(n == K){
			out.println(86400);
			return;
		}
		int[] t = new int[n];
		int[] d = new int[n];
		for(int i = 0;i < n;i++){
			t[i] = ni();
			d[i] = ni();
		}
		int[][] end = new int[n+1][n-K+1];
		Arrays.fill(end[0], 999999999);
		end[0][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= n-K;j++){
				end[i][j] = end[i-1][j];
				if(j-1 >= 0){
					end[i][j] = Math.min(end[i][j], Math.max(end[i-1][j-1],t[i-1])+d[i-1]);
				}
			}
		}
		
		int max = 0;
		for(int i = 0;i < n-1;i++){
			// i+1, n-(i+1)
			for(int j = 0;j <= K;j++){
				if(i+1 >= j && n-(i+1) >= K-j){
					int st = i+1==j?1:end[i+1][i+1-j];
					int en = n-(i+1)==K-j?86400:t[i+1+K-j]-1;
					en = Math.min(en, 86400);
					max = Math.max(max, en-st+1);
				}
			}
		}
		{
			int st = 1;
			int en = t[K]-1;
			max = Math.max(max, en-st+1);
		}
		{
			int st = end[n][n-K];
			int en = 86400;
			max = Math.max(max, en-st+1);
		}
		out.println(max);
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