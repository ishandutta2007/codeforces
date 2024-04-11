import java.util.Scanner;

public class E {
	static int MOD = 998244353;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int L = sc.nextInt();
		int R = sc.nextInt();
		int pow = R-L+1;
		if(n%2==0 || m%2==0) {
			int a = 0;
			int b =0;
			if(R%2==0 && L%2==0) {
				a = (R-L)/2+1;
				b = (R-L)/2;
			}
			else if(R%2==1 && L%2==1) {
				a = (R-L)/2;
				b = (R-L)/2+1;
			}
			else {
				a = (R-L+1)/2;
				b =(R-L+1)/2;
			}
			int fir = (a+b);
			int sec = a-b;
			fir%=MOD;
			sec%=MOD;
			long exp = (long) n*m;
			exp%=(MOD-1);
			long ans = exp(fir,(int) exp);
			ans+=exp(sec,(int) exp);
			ans%=MOD;
			long mult  = exp(2,MOD-2);
			ans*=mult;
			ans%=MOD;
			System.out.println(ans);
		}
		else {
			long exp = (long) n*m;
			exp%=(MOD-1);
			long ans = exp(pow,(int) exp);
			System.out.println(ans);
		}
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