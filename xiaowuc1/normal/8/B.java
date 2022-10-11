import java.io.*;
import java.util.*;
public class B8 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		TreeSet<State> set = new TreeSet<State>();
		int[] count = new int[5];
		int x = 0;
		int y = 0;
		set.add(new State(x,y));
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) == 'L')
				y--;
			if(s.charAt(i) == 'R')
				y++;
			if(s.charAt(i) == 'U')
				x--;
			if(s.charAt(i) == 'D')
				x++;
			if(set.contains(new State(x,y))){
				System.out.println("BUG");
				return;
			}
			set.add(new State(x,y));
		}
		int[] dx = new int[]{1,-1,0,0};
		int[] dy = new int[]{0,0,-1,1};
		for(State state: set)	{
			int ret = 0;
			for(int i = 0; i < dx.length; i++)	{
				if(set.contains(new State(state.x + dx[i], state.y + dy[i])))
					ret++;
			}
			if(ret == 3 || ret == 4)	{
				System.out.println("BUG");
				return;
			}
			count[ret]++;
		}
		if(count[1] != 2)
			System.out.println("BUG");
		else
			System.out.println("OK");
	}
	static class State implements Comparable<State> {
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int compareTo(State s)	{
			if(x == s.x)
				return y-s.y;
			return x-s.x;
		}
	}
}