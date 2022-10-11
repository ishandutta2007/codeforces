import java.io.*;
import java.util.*;
public class A {
	static int[] dx = new int[3];
	static int[] dy = new int[3];
	static ArrayList<State> list;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ss = " abcdefgh";
		list = new ArrayList<State>();
		String first = br.readLine();
		int x1 = ss.indexOf(first.substring(0,1));
		int y1 = Integer.parseInt(first.substring(1,2));
		String second = br.readLine();
		int x2 = ss.indexOf(second.substring(0,1));
		int y2 = Integer.parseInt(second.substring(1,2));
		int[][] dist = new int[9][9];
		for(int i = 0; i < dist.length; i++)
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		dist[x1][y1] = 0;
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(x1,y1));
		dx[1] = -1;
		dx[2] = 1;
		dy[1] = -1;
		dy[2] = 1;
		while(!q.isEmpty())	{
			State s = q.removeFirst();
			for(int x: dx)	{
				for(int y: dy)	{
					if(valid(s.x+x,s.y+y))	{
						if(dist[s.x+x][s.y+y] > 1 + dist[s.x][s.y])	{
							dist[s.x+x][s.y+y] = 1 + dist[s.x][s.y];
							q.addLast(new State(s.x+x, s.y+y));
						}
					}
				}
			}
		}
		find(x1, y1, x2, y2, dist[x2][y2]);
		System.out.println(dist[x2][y2]);
		for(int i = list.size() - 1; i > 0; i--)		{
			int xDiff = list.get(i).x - list.get(i-1).x;
			int yDiff = list.get(i).y - list.get(i-1).y;
			StringBuilder sb = new StringBuilder();
			if(xDiff == -1)
				sb.append("R");
			else if(xDiff == 1)
				sb.append("L");
			if(yDiff == -1)
				sb.append("U");
			else if(yDiff == 1)
				sb.append("D");
			System.out.println(sb);
		}
	}
	public static boolean find(int x1, int y1, int x2, int y2, int dist)	{
		if(dist == 0)	{
			if(x1 == x2 && y1 == y2)	{
				list.add(new State(x1, y1));
				return true;
			}
			return false;
		}
		for(int x: dx)	{
			for(int y: dy)	{
				if(valid(x1+x,y1+y) && find(x1+x, y1+y, x2, y2, dist-1))	{
					list.add(new State(x1, y1));
					return true;
				}
			}
		}
		return false;
	}
	public static boolean valid(int x, int y)	{
		return x >= 1 && x <= 8 && y >= 1 && y <= 8;
	}
	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
	}
}