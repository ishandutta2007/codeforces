import java.io.*;
import java.util.*;

public class D_Java {
	public static final int MOD = 998244353;
	
	public static int mul(int a, int b) {
		return (int)((long)a * (long)b % MOD);
	}
	
	int[] f;
	int[] rf;
	
	public int C(int n, int k) {
		return (k < 0 || k > n) ? 0 : mul(f[n], mul(rf[n-k], rf[k]));
	}
	
	public static int pow(int a, int n) {
		int res = 1;
		while (n != 0) {
			if ((n & 1) == 1) {
				res = mul(res, a);
			}
			a = mul(a, a);
			n >>= 1;
		}
		return res;
	}
	
	static void shuffleArray(int[] a) {
		Random rnd = new Random();
		for (int i = a.length-1; i > 0; i--) {
			int index = rnd.nextInt(i + 1);
			int tmp = a[index];
			a[index] = a[i];
			a[i] = tmp;
		}
	}
	
	public static int inv(int a) {
		return pow(a, MOD-2);
	}
	
	public void doIt() throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int k = Integer.parseInt(tok.nextToken());
		
		f = new int[n+42];
		rf = new int[n+42];
		f[0] = rf[0] = 1;
		for (int i = 1; i < f.length; ++i) {
			f[i] = mul(f[i-1], i);
			rf[i] = mul(rf[i-1], inv(i));
		}
		
		int[] events = new int[2*n];
		for (int i = 0; i < n; ++i) {
			tok = new StringTokenizer(in.readLine());
			int le = Integer.parseInt(tok.nextToken());
			int ri = Integer.parseInt(tok.nextToken());
			events[i] = le*2;
			events[i + n] = ri*2 + 1;
		}
		shuffleArray(events);
		Arrays.sort(events);
		
		int ans = 0;
		int balance = 0;
		for (int r = 0; r < 2*n;) {
			int l = r;
			while (r < 2*n && events[l] == events[r]) {
				++r;
			}
			int added = r - l;
			if (events[l] % 2 == 0) {
				// Open event
				ans += C(balance + added, k);
				if (ans >= MOD) ans -= MOD;
				ans += MOD - C(balance, k);
				if (ans >= MOD) ans -= MOD;
				balance += added;
			} else {
				// Close event
				balance -= added;
			}
		}
		
		in.close();
		System.out.println(ans);
	}
	
	public static void main(String[] args) throws IOException {
		(new D_Java()).doIt();
	}
}