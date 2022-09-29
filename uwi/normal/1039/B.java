//package round507;
import java.io.PrintWriter;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class BT {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	boolean get(long l, long r)
	{
		out.println(l + " " + r);
		out.flush();
		return in.next().trim().equals("Yes");
	}
	
//	Random ggen = new Random();
//	long N = 1000000000000000000L;
//	long KK = 10;
//	long pos = Math.abs(ggen.nextLong() % N) + 1;
//	int num = 0;
//	
//	boolean get(long l, long r)
//	{
//		num++;
//		boolean ret = l <= pos && pos <= r;
//		pos = pos + ggen.nextInt((int)(2*KK+1)) - KK;
//		if(pos < 1)pos = 1;
//		if(pos > N)pos = N;
//		return ret;
//	}
	
	void solve()
	{
		long n = nl();
		int K = ni();
		
		
		long L = 1, R = n;
		
		Random gen = new SecureRandom();
		while(true){
			long H = (L+R)/2;
			if(L < H){
				if(get(L, H)){
					R = H + K;
					L = L - K;
				}else{
					L = H+1 - K;
					R = R + K;
				}
				L = Math.max(L, 1);
				R = Math.min(R, n);
			}
			
			while(R-L <= 41){
				long tar = gen.nextInt((int)(R-L+1)) + L;
				if(get(tar, tar)){
					return;
				}else{
					L -= K;
					R += K;
				}
				L = Math.max(L, 1);
				R = Math.min(R, n);
			}
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new BT().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}