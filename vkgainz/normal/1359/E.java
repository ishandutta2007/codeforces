import java.util.Scanner;

public class E {
	static int [] factorial;
	static int MOD = 998244353;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		factorial = new int[n+1];
		factorial[0] = 1;
		for(int i=1;i<=n;i++) {
			long x = (long) factorial[i-1]*i;
			x%=MOD;
			factorial[i] = (int) x;
		}
		int ans =0;
		for(int i=1;i<=n;i++) {
			int top = n/i-1;
			int bot = k-1;
			ans+=choose(top,bot);
			ans%=MOD;
		}
		System.out.println(ans);
	}
	static int choose(int n,int r) {
		if(r==n) return 1;
		if(r>n) return 0;
		int a = factorial[n];
		int b = factorial[r];
		int c = factorial[n-r];
		b = (int) exp(b,MOD-2);
		c = (int) exp(c,MOD-2);
		long x = (long) a*b;
		x%=MOD;
		x*=(long) c;
		return (int) ((x+MOD)%MOD);
	}

	static long exp(int base,int power) {
		if(base==0) return 0;
		if(power==0) return 1;
		if(power==1) return (base+MOD)%MOD;
		long ans = exp(base,power/2);
		ans = (ans*ans+MOD)%MOD;
		if(power%2==1) ans = (ans*base+MOD)%MOD;
		return (ans+MOD)%MOD;
	}
	
}