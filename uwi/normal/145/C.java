//package round104;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	
	void solve()
	{
		int[] lus = generateLucky(1000000000);
		Map<Integer, Integer> lmap = new HashMap<Integer, Integer>();
		for(int i = 0;i < lus.length;i++){
			lmap.put(lus[i], i);
		}
		int m = lmap.size();
		
		int n = ni(), k = ni();
		int none = 0;
		int[] b = new int[m];
		for(int i = 0;i < n;i++){
			int v = ni();
			if(lmap.containsKey(v)){
				b[lmap.get(v)]++;
			}else{
				none++;
			}
		}
		int[] fact = new int[200001];
		fact[0] = 1;
		for(int i = 1;i <= 200000;i++){
			fact[i] = (int)((long)fact[i-1] * i % mod);
		}
		// 3 2 1 5
		// 5C3
		// 5C2*1+5C2*2+5C2*3
		// 5C1*(1*2+2*3+3*1)
		
		long[][] co = new long[m+1][m+1];
		co[0][0] = 1;
		int u = 0;
		for(int i = 0;i < m;i++){
			if(b[i] == 0){
				for(int j = 0;j <= i;j++){
					co[i+1][j] = co[i][j];
				}
			}else{
				u++;
				for(int j = 0;j <= i;j++){
					co[i][j] %= mod;
					co[i+1][j+1] += co[i][j];
					co[i+1][j] += co[i][j]*b[i];
				}
			}
		}
		for(int j = 0;j <= m;j++){
			co[m][j] %= mod;
		}
		
		long c = 1;
		long ret = 0;
		for(int i = 0;i <= k && i <= none;i++){
			if(k-i <= u){
//				tr(c, co[m][u-(k-i)]);
				ret += c * co[m][u-(k-i)] % mod;
			}
			c = c * (none-i) % mod;
			c = c * inv(i+1, mod) % mod;
		}
		out.println(ret%mod);
	}
	
	public static long inv(long a, int p) {
		long ret = 1;
		long mul = a;
		for (long n = p - 2; n > 0; n >>>= 1) {
			if ((n & 1) == 1)
				ret = ret * mul % p;
			mul = mul * mul % p;
		}
		return ret;
	}
	
	public static int[] generateLucky(int n)
	{
		int[] lucky = new int[2000];
		lucky[0] = 4;
		lucky[1] = 7;
		int r = 2;
		for(int p = 0;p < r;p++){
			if((long)lucky[p]*10+4 <= n){
				lucky[r++] = lucky[p]*10+4;
			}
			if((long)lucky[p]*10+7 <= n){
				lucky[r++] = lucky[p]*10+7;
			}
		}
		return Arrays.copyOf(lucky, r);
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + 50000 + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(10) + " ");
//		}
//		INPUT = sb.toString();
//		
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