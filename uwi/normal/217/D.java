//package round134;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D52 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "20 20 20\r\n" + 
//			"12 6 1 9 14 15 6 19 13 4 6 19 19 12 16 10 6 5 7 18";
	
	void solve()
	{
		int n = ni(), m = ni(), t = ni();
		int[] a = new int[t];
		for(int i = 0;i < t;i++)a[i] = ni();
		
		// 120->[0,60]
		// 119->[0,59]
		int[] ct = new int[m/2+1];
		for(int i = 0;i < t;i++){
			int v = a[i]%m;
			v = Math.min(v, m-v);
			ct[v]++;
		}
		
		mask |= (1L<<ct.length)-1;
//		tr(ct);
		dfs(ct, 1, 0, m, 0L, 1L);
		out.println(ret % mod);
	}
	
	long mask;
	long ret = 1;
	int mod = 1000000007;
	
	void dfs(int[] ct, int pos, int dep, int m, long pre, long x)
	{
		if(pos == ct.length)return;
//		if(dep == 0)tr(pos);
		
		int h = ct.length;
		if(ct[pos] > 0 && pre<<63-pos>=0 && dep < 6){
			long l = 63-m+pos >= 0 ? Long.reverse(pre>>>h-pos<<h-pos)>>>63-m+pos : Long.reverse(pre>>>h-pos<<h-pos)<<-(63-m+pos);
			long cur = (pre|pre<<pos|pre>>>pos|l|Long.reverse(pre&(1L<<pos)-1)>>>63-pos|1L<<pos)&mask;
			
//			long cur = pre;
//			for(int j = 0;j < h;j++){
//				if(pre<<63-j<0){
//					cur |= 1L<<(j+pos>=h?m-(j+pos):j+pos);
//					cur |= 1L<<(j-pos<0?-(j-pos):j-pos);
//				}
//			}
//			cur |= 1L<<pos;
//			if(cur != ccur){
//				tr(pre, cur, ccur, pos, h, m);
//			}
			
			long nx = x * ct[pos] % mod;
			ret += (int)nx;
//				tr(Arrays.copyOf(hist, dep), x);
			dfs(ct, pos+1, dep+1, m, cur, nx);
		}
		dfs(ct, pos+1, dep, m, pre, x);
	}
	
	void run() throws Exception
	{
//		int n = 120, m = 10000;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(100000 + " ");
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < m;i++){
//			sb.append((gen.nextInt(1000000000)+1) + " ");
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
		new D52().run();
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