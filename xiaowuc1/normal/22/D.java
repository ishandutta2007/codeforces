import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	final static int MOD = 100000000;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		PriorityQueue<State> q = new PriorityQueue<State>();
		while(n-- > 0)	{
			q.add(new State(readInt(), readInt()));
		}
		LinkedList<Integer> ret = new LinkedList<Integer>();
		while(!q.isEmpty())		{
			State curr = q.poll();
			if(ret.size() > 0 && curr.a <= ret.peekLast())
				continue;
			ret.addLast(curr.b);
		}
		System.out.println(ret.size());
		StringBuilder sb = new StringBuilder();
		for(int out: ret)
			sb.append(out + " ");
		System.out.println(sb.toString().trim());
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
	static class State implements Comparable<State>	{
		public int a,b;
		public State(int x, int y)	{
			a=Math.min(x,y);
			b=Math.max(x,y);
		}
		public int compareTo(State s)	{
			return b-s.b;
		}
	}
}