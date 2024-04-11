//package round136;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long w = ni(), h = ni();
		long ct = 0;
		long ee = (w/2+1)*(h/2+1);
		long eo = (w/2+1)*((h+1)/2);
		long oe = ((w+1)/2)*(h/2+1);
		long oo = ((w+1)/2)*((h+1)/2);
		int mod = 1000000007;
		// ee
		ct += ee*((oo*oo+ee*oo+ee*oe+oe*oe+ee*eo+ee*ee+oe*ee+eo*eo+eo*ee+oo*ee)%mod);
		ct += eo*((oe*oe+eo*oe+eo*oo+oo*oo+eo*ee+eo*eo+oo*eo+ee*ee+ee*eo+oe*eo)%mod);
		ct += oo*((ee*ee+oo*ee+oo*eo+eo*eo+oo*oe+oo*oo+eo*oo+oe*oe+oe*oo+ee*oo)%mod);
		ct += oe*((eo*eo+oe*eo+oe*ee+ee*ee+oe*oo+oe*oe+ee*oe+oo*oo+oo*oe+eo*oe)%mod);
		ct %= mod;
		
		long minus = 0;
		int[][] gcd = new int[4001][4001];
		for(int i = 1;i <= 4000;i++)gcd[i][0] = i;
		for(int i = 1;i <= 4000;i++){
			for(int j = 1;j <= i;j++){
				if(i == 1 || j == 1){
					gcd[i][j] = 1;
				}else if(i == j){
					gcd[i][j] = i;
				}else{
					gcd[i][j] = gcd[j][i%j];
				}
//				tr(i,j,gcd[i][j]);
				if(w+1-i > 0 && h+1-j > 0){
					minus += (w+1-i)*(h+1-j)*(gcd[i][j]-1)*6*2%mod;
				}
				if(i != j && w+1-j > 0 && h+1-i > 0){
					minus += (w+1-j)*(h+1-i)*(gcd[i][j]-1)*6*2%mod;
				}
			}
		}
		minus += (w+1)*w*(w-1)*(h+1)%mod;
		minus += (h+1)*h*(h-1)*(w+1)%mod;
		minus += 3L*(w+1)*(h+1)*((w+1)*(h+1)-1)%mod;
		minus += (w+1)*(h+1)%mod;
		minus %= mod;
		
		out.println((ct-minus+mod)%mod);
	}
	
	int S(int ax, int ay, int bx, int by, int cx, int cy)
	{
		return (bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
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
		new D2().run();
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