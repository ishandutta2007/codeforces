import java.io.*;
import java.util.*;
public class AMain {
	static int n;
	static int[] best;
	static int[][] dist;
	static int[] home;
	static LinkedList<Integer> ret;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		State curr = new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		n = Integer.parseInt(br.readLine());
		State[] list = new State[n];
		for(int i = 0; i < n; i++)	{
			st = new StringTokenizer(br.readLine());
			list[i] = new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		dist = new int[n][n];
		home = new int[n];
		for(int i = 0; i < n; i++)	{
			home[i] = dist(curr, list[i]);
		}
		for(int i = 0; i < n; i++)	{
			dist[i][i] = 2 * home[i];
			for(int j = i+1; j < n; j++)		{
				dist[i][j] = dist(list[i], list[j]) + home[i] + home[j];
			}
		}
		best = new int[1 << (n)];
		Arrays.fill(best, -1);
		best[0] = 0;
		System.out.println(solve(-1 + (1<<n)));
		ret = new LinkedList<Integer>();
		resolve(-1 + (1<<n));
		for(int x: ret)
			System.out.print(x + " ");
	}
	public static int dist(State a, State b)	{
		int x = a.x-b.x;
		int y = a.y-b.y;
		return x*x+y*y;
	}
	public static void resolve(int curr)	{
		ret.addLast(0);
		for(int i = 0; i < n; i++)	{
			if((curr & (1<<i)) == 0)
				continue;
			for(int j = i+1; j < n; j++)	{
				if((curr & (1 << j)) == 0)		{
					continue;
				}
				if(dist[i][j] + solve(curr ^ (1<<i) ^ (1 << j)) == best[curr])	{
					ret.addLast(i+1);
					ret.addLast(j+1);
					resolve(curr - (1<<i) - (1<<j));
					return;
				}
			}
			if(best[curr] == dist[i][i] + solve(curr ^ (1<<i)))	{
				ret.addLast(i+1);
				resolve(curr - (1<<i));
				return;
			}
		}
	}
	public static int solve(int curr)	{
		if(best[curr] != -1)
			return best[curr];
		int ret = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++)	{
			if((curr & (1<<i)) == 0)
				continue;
			for(int j = i+1; j < n; j++)	{
				if((curr & (1 << j)) == 0)		{
					continue;
				}
				ret = Math.min(ret, dist[i][j] + solve(curr ^ (1<<i) ^ (1 << j)));
			}
			ret = Math.min(ret, dist[i][i] + solve(curr ^ (1<<i)));
			break;
		}
		best[curr] = ret;
		return ret;
	}
	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
	}
}