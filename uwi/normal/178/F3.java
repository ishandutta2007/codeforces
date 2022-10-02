//package abbyy2.hard;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class FH {
	InputStream is;
	PrintWriter out;
//	String INPUT = "17 8 ab baa aaba aaaab a bbbba abb b b aa baa ab aaaab abb aa bba ba";
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		String[] ss = new String[n];
		for(int i = 0;i < n;i++){
			ss[i] = new String(ns(501));
		}
		Arrays.sort(ss);
		
		int[] f = new int[n-1];
		for(int i = 0;i < n-1;i++){
			int k = 0;
			for(;k < ss[i].length() && k < ss[i+1].length() && ss[i].charAt(k) == ss[i+1].charAt(k);k++);
			f[i] = k;
		}
		
		out.println(rec(0, n-1, m, f, 0)[m]);
	}
	
	long[] rec(int s, int e, int m, int[] f, int p)
	{
		if(s == e){
			return new long[]{0, 0};
		}else{
			int prev = s;
			long[] ret = null;
			for(int i = s;i <= e;i++){
				if(i == e || f[i] <= p){
					long[] res = rec(prev, i, m, f, p+1);
					if(ret == null){
						ret = res;
					}else{
						int len = Math.min(m+1, i-s+1+1);
						long[] nret = new long[len];
						Arrays.fill(nret, -999999999999999L);
						for(int j = 0;j < ret.length;j++){
							for(int k = 0;k < res.length && j+k < len;k++){
								nret[j+k] = Math.max(nret[j+k], ret[j] + res[k]);
							}
						}
						ret = nret;
					}
					prev = i+1;
				}
			}
			if(p > 0){
				for(int i = 0;i <= m && i <= e-s+1;i++){
					ret[i] += i*(i-1)/2;
				}
			}
			return ret;
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
		new FH().run();
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