import java.io.*;
import java.util.*;
public class AMain	{
	static long[][] choose;
	public static void main(String[] args) throws IOException	{
		choose = new long[100][100];
		for(int i = 0; i < choose.length; i++)
			Arrays.fill(choose[i], -1);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		long ret = 0;
		for(int numBoys = 4; numBoys <= n && t-numBoys >= 1; numBoys++)	{
			ret += choose(n, numBoys) * choose(m, t-numBoys);
		}
		System.out.println(ret);
	}
	public static long choose(int n, int k)	{
		if(k > n)
			return 0;
		if(n==k || k==0)
			return 1;
		if(choose[n][k] != -1)
			return choose[n][k];
		choose[n][k] = choose(n-1,k) + choose(n-1,k-1);
		return choose[n][k];
	}
}