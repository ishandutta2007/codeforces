import java.io.*;
import java.util.*;
public class E59 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		LinkedList<Integer>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++)
			edges[i] = new LinkedList<Integer>();
		while(m-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			edges[a].add(b);
			edges[b].add(a);
		}
		Set<Triple> bad = new HashSet<Triple>();
		while(k-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			bad.add(new Triple(--a,--b,--c));
		}
		int[][] best = new int[n][n];
		for(int i = 0; i < n; i++)
			Arrays.fill(best[i], 1<<30);
		best[0][0] = 0;
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(0,0));
		int lastPlace = -1;
		outer: while(!q.isEmpty())	{
			State curr = q.removeFirst();
			for(int out: edges[curr.y])	{
				if(!bad.contains(new Triple(curr.x,curr.y,out)) && best[curr.y][out] > 1 + best[curr.x][curr.y])	{
					best[curr.y][out] = 1 + best[curr.x][curr.y];
					if(out == n-1)	{
						q.clear();
						lastPlace = curr.y;
						break outer;
					}
					q.addLast(new State(curr.y, out));
				}
			}
		}
		if(lastPlace == -1)	{
			System.out.println(-1);
			return;
		}
		LinkedList<Integer> ret = new LinkedList<Integer>();
		ret.addLast(n);
		ret.addFirst(lastPlace+1);
		int lastPlace2 = n-1;
		while(best[lastPlace][lastPlace2] != 1)	{
			for(int out: edges[lastPlace]){
				if(best[out][lastPlace] + 1 == best[lastPlace][lastPlace2])	{
					ret.addFirst(out+1);
					lastPlace2 = lastPlace;
					lastPlace = out;
					break;
				}
			}
		}
		System.out.println(ret.size() - 1);
		for(int x: ret)
			System.out.print(x + " ");
	}
	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
	}
	static class Triple	{
		public int a,b,c;
		public Triple(int x, int y, int z)	{
			a=x;
			b=y;
			c=z;
		}
		public int hashCode()	{
			return 1000000007*a+10007*b+c;
		}
		public boolean equals(Object o)	{
			Triple s = (Triple)o;
			return a==s.a && b==s.b && c==s.c;
		}
	}
}