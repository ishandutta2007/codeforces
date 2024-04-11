import java.io.*;
import java.util.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int r = readInt();
		int c = readInt();
		int bad = readInt();
		int query = readInt();
		State[] list = new State[bad];
		for(int i = 0; i < list.length; i++)	{
			list[i] = new State(readInt()-1, readInt()-1);
		}
		Arrays.sort(list);
		while(query-- > 0)	{
			State curr = new State(readInt()-1, readInt()-1);
			int find = Arrays.binarySearch(list, curr);
			if(find >= 0)	{
				System.out.println("Waste");
			}
			else	{
				long now = curr.x * c + curr.y - Math.abs(find);
				now += 3000000000L;
				now %= 3;
				if(now == 2)	{
					System.out.println("Carrots");
				}
				else if(now == 0)	{
					System.out.println("Kiwis");
				}
				else if(now == 1)	{
					System.out.println("Grapes");
				}
			}
		}
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
	static class State implements Comparable<State>	{
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