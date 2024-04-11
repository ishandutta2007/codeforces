import java.io.*;
import java.util.*;
public class D83 {
	static int max;
	static int[][] grid;
	static int[] primes;
	static int gridLength = 5000;
	static int numPrimes = 5000;
	public static void main(String[] args) throws IOException	{
		primes = new int[numPrimes];
		int c = 1;
		primes[0] = 2;
		for(int i = 3; c < primes.length; i += 2)
			if(prime(i))
				primes[c++] = i;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		max = Integer.parseInt(st.nextToken());
		grid = new int[gridLength][numPrimes];
		for(int i = 0; i < grid.length; i++)
			Arrays.fill(grid[i], -1);
		if(!prime(max))	{
			System.out.println(0);
			return;
		}
		System.out.println(compute(b/max, 0) - compute((a-1)/max, 0));
	}
	public static boolean prime(int x)	{
		if(x==1)
			return false;
		if(x<=3)
			return true;
		if(x%2==0 || x%3==0)
			return false;
		for(int d = 5; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		for(int d = 7; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		return true;
	}
	public static int compute(int num, int p)	{
		if(primes[p] >= max || num <= 1)
			return num;
		if(num / primes[p] == 0)
			return num;
		if(num < gridLength && p < numPrimes && grid[num][p] != -1)
			return grid[num][p];
		int ret = compute(num,p+1) - compute(num/primes[p],p+1);
		if(num < gridLength && p < numPrimes)
			grid[num][p] = ret;
		return ret;
	}
}