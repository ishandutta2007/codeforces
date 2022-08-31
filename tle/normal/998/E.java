import java.util.*;
import java.io.*;

public class Main
{
	static long mod = 998244353;

	public static void main(String[] args)
	{
		FastReader reader = new FastReader();
		PrintWriter writer = new PrintWriter(System.out);

		long n = reader.nextLong();
		long[] factorial = new long[(int)n+1];
		long[] invf = new long[(int)n+1];
		factorial[0] = 1;
		for (int i=1; i<=n; i++)
			factorial[i] = (factorial[i-1]*i)%mod;
		invf[(int)n]=inverse(factorial[(int)n]);
		for(int i=(int)n;i>=1;--i)
		    invf[i-1]=invf[i]*i%mod;

		long ans = power(3, n*n);
		ans -= power((power(3, n) - 3 + mod)%mod, n);
		ans += mod;
		ans %= mod;
		long i3=inverse(3),t=1,u=power(3,n),
		ru=inverse(u),p=power(u,n);


		for (int i=1; i<=n; i++)
		{
			long temp = factorial[(int)n];
			temp *= invf[i];
			temp %= mod;
			temp *= invf[(int)n-i];
			temp %= mod;
			t=t*3%mod; u=u*i3%mod;

			if (i%2 == 1)
				temp = mod - temp;
			p=p*ru%mod;

			long a = 3*power((u - 1 + mod)%mod, n);
			a %= mod;

			long b = ((t - 3 + mod)%mod) * p;
			b %= mod;

			ans -= (temp * (a + b))%mod;
			ans += mod;
			ans %= mod;
		}

		writer.println(ans);
		writer.close();
	}

	static long inverse (long a)
	{
		return power(a, mod-2);
	}

	static long power (long a, long p)
	{
		if (p==0)
			return 1;
		else
		{
			long got = power(a, p/2);
			got = got*got;

			got %= mod; 

			if (p%2 == 1)
				got *= a;

			return got%mod;
		}
	}

	static class FastReader
	{
		BufferedReader br;
		StringTokenizer st;

		public FastReader()
		{
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next()
		{
			while (st == null || !st.hasMoreElements())
			{
				try
				{
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt()
		{
			return Integer.parseInt(next());
		}

		long nextLong()
		{
			return Long.parseLong(next());
		}

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String nextLine()
		{
			String str = "";
			try
			{
				str = br.readLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
			return str;
		}
	}
}