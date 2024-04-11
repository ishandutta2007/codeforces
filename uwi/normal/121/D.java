//package round91;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	long[] lucky;
	
	void solve()
	{
		lucky = new long[1050000];
		int pos = rec(lucky, 0, 0);
		lucky = Arrays.copyOf(lucky, pos);
		Arrays.sort(lucky);
		
		int n = ni();
		long k = nl();
		long[][] rs = new long[n][2];
		for(int i = 0;i < n;i++){
			rs[i][0] = nl();
			rs[i][1] = nl();
		}
		
		long mr = Long.MAX_VALUE;
		for(int i = 0;i < n;i++){
			mr = Math.min(mr, rs[i][1]-rs[i][0]);
		}
		
		Arrays.sort(rs, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				return Long.signum(a[1] - b[1]);
			}
		});
		long INF = 1000000000000000001L;
		long[] rsum = new long[pos];
		int p = 0;
		for(int i = 0;i < pos;i++){
			if(i-1 >= 0 && rsum[i-1] >= INF){
				rsum[i] = rsum[i-1] = INF;
				continue;
			}
			if(i > 0){
				rsum[i] = rsum[i-1];
				if(p == 0 || Math.log10(lucky[i]-lucky[i-1])+Math.log10(p) < 18.0001){
					rsum[i] += (lucky[i]-lucky[i-1])*p;
					if(rsum[i] >= INF)rsum[i] = INF;
				}
			}
			while(p < n && rs[p][1] < lucky[i]){
				rsum[i] += lucky[i] - rs[p][1];
				if(rsum[i] >= INF)rsum[i] = INF;
				p++;
			}
		}
		
		Arrays.sort(rs, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				return Long.signum(a[0] - b[0]);
			}
		});
		p = 0;
		long[] lsum = new long[pos];
		for(int i = pos-1;i >= 0;i--){
			if(i+1 < pos && lsum[i+1] >= INF){
				lsum[i] = lsum[i+1] = INF;
				continue;
			}
			if(i < pos-1){
				lsum[i] = lsum[i+1];
				if(p == 0 || Math.log10(lucky[i+1]-lucky[i])+Math.log10(p) < 18.0001){
					lsum[i] += (lucky[i+1]-lucky[i])*p;
					if(lsum[i] >= INF)lsum[i] = INF;
				}
			}
			while(p < n && rs[n-1-p][0] > lucky[i]){
				lsum[i] += rs[n-1-p][0] - lucky[i];
				if(lsum[i] >= INF)lsum[i] = INF;
				p++;
			}
		}
		for(int i = 0;i < pos;i++){
			lsum[i] *= 2;
			rsum[i] *= 2;
		}
		
		int max = 0;
		for(int i = 0;i < pos;i++){
			long left = k*2 - lsum[i];
			if(left >= 0){
				if(left < rsum[i])continue;
				int low = Arrays.binarySearch(lucky, i, pos, lucky[i]+mr);
				if(low < 0)low = -low-2;
				
				int b = Arrays.binarySearch(rsum, i, low+1, left+1);
				if(b < 0)b = -b-2;
				max = Math.max(max, b-i+1);
			}
		}
		out.println(max);
	}
	
	int rec(long[] lucky, int pos, long n)
	{
		if(n != 0)lucky[pos++] = n;
		if(n <= 1000000000000000000L){
			pos = rec(lucky, pos, n*10+4);
			pos = rec(lucky, pos, n*10+7);
		}
		return pos;
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
		new D().run();
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