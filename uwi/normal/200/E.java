//package round126;
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
		int n = ni(), s = ni();
		int[] c = new int[3];
		for(int i = 0;i < n;i++){
			c[ni()-3]++;
		}
		int g = gcd(c[0], c[2]);
		
		int minf = Integer.MAX_VALUE;
		int[] opt = null;
//		int p = 0;
		for(int k4 = 0;(c[1]+c[2])*k4 <= s;k4++){
			int r = s - k4*c[1];
			if(r % g != 0)continue;
			
			int e1 = c[1]*k4;
			int e2 = Math.max(r - e1, 0);
			if(e1 > e2){
				int d = e1; e1 = e2; e2 = d;
			}
			int k5 = -1;
			int inf = (e1+c[0]-1)/c[0];
			int k3 = -1;
			for(k3 = inf;c[0]*k3 <= e2 && k3 <= inf+n+1 && k3 <= k4;k3++){
//				p++;
				int rem = r - c[0]*k3;
				if(rem < 0 || rem / c[2] < k4)break;
				
				if(rem % c[2] == 0){
					k5 = rem / c[2];
					if(k5 >= k4)break;
				}
			}
			if(k5 != -1){
				int F = Math.abs(c[0]*k3 - c[1]*k4) + Math.abs(c[1]*k4 - c[2]*k5);
				if(F < minf){
					minf = F;
					opt = new int[]{k3, k4, k5};
					continue;
				}
			}else{
				// (r-c[0]*k3)/c[2]>=k4
				// r-k4*c[2]>=c[0]*k3
				k3 = Math.min(Math.min(inf-1, k4), (r-k4*c[2])/c[0]);
//				k3 = Math.min(inf-1, k4);
//				inf = k3;
				for(;k3 >= 0;k3--){
//					p++;
					int rem = r - c[0]*k3;
					if(rem % c[2] == 0){
						k5 = rem / c[2];
						if(k5 >= k4){
							int F = Math.abs(c[0]*k3 - c[1]*k4) + Math.abs(c[1]*k4 - c[2]*k5);
							if(F < minf){
								minf = F;
								opt = new int[]{k3, k4, k5};
							}
							break;
						}
					}
				}
				inf = e2 / c[0];
				for(k3 = e2 / c[0];k3 <= k4 && k3 <= inf + n+1;k3++){
//					p++;
					int rem = r - c[0]*k3;
					if(rem < 0 || rem / c[2] < k4)break;
					
					if(rem % c[2] == 0){
						k5 = rem / c[2];
						if(k5 >= k4){
							int F = Math.abs(c[0]*k3 - c[1]*k4) + Math.abs(c[1]*k4 - c[2]*k5);
							if(F < minf){
								minf = F;
								opt = new int[]{k3, k4, k5};
								break;
							}
						}else{
							break;
						}
					}
				}
			}
		}
//		tr(p);
		if(opt == null){
			out.println(-1);
		}else{
			out.println(opt[0] + " " + opt[1] + " " + opt[2]);
//			tr(minf);
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void run() throws Exception
	{
//		int n = 298;
//		StringBuilder sb = new StringBuilder();
//		sb.append("300 300000 4 5 ");
//		for(int i = 0;i < n;i++){
//			sb.append(3 + " ");
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