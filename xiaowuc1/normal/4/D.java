import java.io.*;
import java.util.*;
public class D4 {
	static int[] x,y,best;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		x = new int[n+1];
		y = new int[n+1];
		x[0] = Integer.parseInt(st.nextToken());
		y[0] = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= n; i++)	{
			st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
		}
		best = new int[n+1];
		Arrays.fill(best, -1);
		solve(0);
		if(best[0] == 0)	{
			System.out.println(0);
			return;
		}
		System.out.println(best[0]);
		int currLoc = 0;
		int currDist = best[0];
		while(currDist >= 1)	{
			for(int now = 0; now <= n; now++)	{
				if(best[now] + 1 != currDist)
					continue;
				if(x[now] > x[currLoc] && y[now] > y[currLoc] )	{
					currDist--;
					currLoc = now;
					System.out.print((currLoc) + " ");
					break;
				}
			}
		}
	}
	public static int solve(int curr)	{
		if(best[curr] != -1)
			return best[curr];
		int ret = 0;
		for(int i = 0; i < y.length; i++)	{
			if(x[i] > x[curr] && y[i] > y[curr])	{
				ret = Math.max(ret, 1 + solve(i));
			}
		}
		best[curr] = ret;
		return ret;
	}
}