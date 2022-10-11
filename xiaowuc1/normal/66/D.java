import java.io.*;
import java.math.*;
import java.util.*;
public class D66 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if(n == 2)		{
			System.out.println(-1);
			return;
		}
		BigInteger[] primes = new BigInteger[n];
		BigInteger val = BigInteger.valueOf(2);
		for(int k = 0; k < n; k++)	{
			while(!val.isProbablePrime(10))
				val = val.add(BigInteger.ONE);
			primes[k] = val;
			val = val.add(BigInteger.ONE);
		}
		for(int i = 0; i < n; i++)	{
			BigInteger ret = BigInteger.valueOf(1);
			for(int j = 0; j < n; j++)
				if(i != j)
					ret = ret.multiply(primes[j]);
			System.out.println(ret);
		}
	}
}