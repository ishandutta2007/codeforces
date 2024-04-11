//package round149;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long H = 1000000007L;
		int r0 = ni(), c0 = ni(), r1 = ni(), c1 = ni();
		int n = ni();
		long[] h = new long[100001];
		int p = 0;
		for(int i = 0;i < n;i++){
			int r = ni(), a = ni(), b = ni();
			for(int j = a;j <= b;j++){
				h[p++] = r*H+j;
			}
		}
		Arrays.sort(h, 0, p);
		int z = 1;
		for(int i = 1;i < p;i++){
			if(h[i] != h[z-1]){
				h[z++] = h[i];
			}
		}
		h = Arrays.copyOf(h, z);
		Map<Long, Integer> imap = new HashMap<Long, Integer>();
		for(int i = 0;i < z;i++){
			imap.put(h[i], i);
		}
		Queue<Long> q = new ArrayDeque<Long>();
		long s = r0*H+c0;
		long g = r1*H+c1;
		q.add(s);
		int[] d = new int[z];
		Arrays.fill(d, 9999999);
		d[imap.get(s)] = 0;
		
		long[] ra = {1, -1, H, -H, H+1, H-1, -H-1, -H+1};
		while(!q.isEmpty()){
			long cur = q.poll();
			int dc = d[imap.get(cur)];
			for(int k = 0;k < 8;k++){
				long nex = cur + ra[k];
				if(imap.containsKey(nex)){
					int ind = imap.get(nex);
					if(d[ind] > dc + 1){
						d[ind] = dc + 1;
						q.add(nex);
					}
				}
			}
		}
		if(d[imap.get(g)] == 9999999){
			out.println(-1);
		}else{
			out.println(d[imap.get(g)]);
		}
	}
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int)(b[0]>>32);
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0) {
				p++;
				ret[p] = (int)(b[i]>>32);
			}
			a[(int)b[i]] = p;
		}
		return Arrays.copyOf(ret, p+1);
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
		new C2().run();
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