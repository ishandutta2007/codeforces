import java.util.*;
import java.io.*;
public class Main {
	static int[] primes;
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		primes = new int[]{2,3,5,7,11,13,17,19,23,29};
		long[] max = new long[primes.length];
		long MAX = 1000000000000000000L;
		for(int i = 0; i < primes.length; i++)	{
			max[i] = MAX / primes[i];
		}
		long[] dp = new long[n+1];
		Arrays.fill(dp, Long.MAX_VALUE);
		dp[1] = 1;
		for(int i = 1; i < n; i++)	{
			for(int q = 0; q < primes.length; q++) {
				long curr = dp[i];
				while(curr <= max[q])	{
					curr *= primes[q];
					int index = count(curr);
					if(index > n)
						break;
					dp[index] = Math.min(dp[index], curr);
				}
			}
		}
		System.out.println(dp[n]);
	}
	public static int count(long now)	{
		int ret = 1;
		for(int out: primes)	{
			int x = 1;
			while(now%out==0)		{
				now/=out;
				x++;
			}
			ret *= x;
		}
		return ret;
	}
}