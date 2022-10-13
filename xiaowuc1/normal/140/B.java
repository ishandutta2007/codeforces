import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] grid = new int[n][n];
		for(int i = 0; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++)	{
				grid[i][Integer.parseInt(st.nextToken())-1] = j;
			}
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] prefer = new int[n];
		for(int i = 0; i < n; i++)	{
			prefer[Integer.parseInt(st.nextToken())-1] = i;
		}
		int[] bestRank = new int[n];
		Arrays.fill(bestRank, 1 << 20);
		int[] bestCard = new int[n];
		Arrays.fill(bestCard, -1);
		ArrayList<State> list = new ArrayList<State>();
		for(int i = 0; i < n; i++)	{
			list.add(new State(i, prefer[i]));
			Collections.sort(list);
			for(int k = 0; k < grid.length; k++)	{
				for(State card: list)	{
					if(card.card == k)
						continue;
					if(grid[k][card.card] < bestRank[k])	{
						bestRank[k] = grid[k][card.card];
						bestCard[k] = i+1;
					}
					break;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int out: bestCard)
			sb.append(out + " ");
		System.out.println(sb.toString().trim());
	}
	static class State implements Comparable<State>	{
		public int card, rank;
		public State(int a, int b)	{
			card= a;
			rank = b;
		}
		public int compareTo(State s)	{
			return rank - s.rank;
		}
	}
}