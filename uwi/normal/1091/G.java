//package goodbye2018;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class G3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	BigInteger nb(BigInteger N, Random gen)
	{
		while(true) {
			byte[] x = new byte[130];
			gen.nextBytes(x);
			BigInteger X = new BigInteger(x);
			X = X.mod(N);
			if(X.gcd(N).compareTo(BigInteger.ONE) > 0)continue;
			return X;
		}
	}
	
	BigInteger sqrt(BigInteger x)
	{
		out.println("sqrt " + x);
		out.flush();
		return new BigInteger(in.next());
	}
	Random gen = new Random(1);
	
	void solve()
	{
		BigInteger N = new BigInteger(in.next());
		
		ans = new ArrayList<>();
		dfs(N);
		
		out.print("! " + ans.size());
		for(BigInteger u : ans) {
			out.print(" " + u);
		}
		out.println();
		out.flush();
	}
	
	List<BigInteger> ans;
	
	void dfs(BigInteger N)
	{
		if(N.equals(BigInteger.ONE))return;
		if(N.isProbablePrime(100)) {
			ans.add(N);
			return;
		}
		while(true) {
			BigInteger X = nb(N, gen);
			out.println("* " + X + " " + X);
			out.flush();
			BigInteger X2 = new BigInteger(in.next());
			BigInteger res = sqrt(X2);
			BigInteger G = res.subtract(X).gcd(N);
			if(!G.equals(N) && G.compareTo(BigInteger.ONE) > 0) {
				BigInteger L = N.divide(G);
				dfs(L);
				dfs(G);
				break;
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
		new G3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}