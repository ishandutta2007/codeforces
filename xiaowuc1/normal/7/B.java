import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class B {
	static ArrayList<State> list;
	static int max;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		max = Integer.parseInt(st.nextToken());
		int currIdentify = 1;
		list = new ArrayList<State>();
		outer: while(n-- > 0)	{
			Collections.sort(list);
			st = new StringTokenizer(br.readLine());
			String action = st.nextToken();
			if(action.equals("alloc"))	{
				int amount = Integer.parseInt(st.nextToken());
				int index = check(amount);
				if(index != -1)	{
					System.out.println(currIdentify);
					list.add(new State(currIdentify++, index, amount));
				}
				else	{
					System.out.println("NULL");
				}
			}
			if(action.equals("erase"))	{
				int amount = Integer.parseInt(st.nextToken());
				for(int i = 0; i < list.size(); i++)
					if(list.get(i).identify == amount)	{
						list.remove(i);
						continue outer;
					}
				System.out.println("ILLEGAL_ERASE_ARGUMENT");
			}
			if(action.equals("defragment"))	{
				Collections.sort(list);
				if(list.size() > 0)	{
					list.get(0).start = 0;
				}
				for(int i = 1; i < list.size(); i++)	{
					list.get(i).start = list.get(i-1).start + list.get(i-1).size;
				}
			}
		}
	}
	public static int check(int size){
		boolean[] taken = new boolean[max];
		for(State s: list)	{
			for(int i = s.start; i < s.start + s.size; i++)
				taken[i] = true;
		}
		outer: for(int i = 0; i <= taken.length - size; i++)	{
			for(int j = 0; j < size; j++)	{
				if(taken[i+j])
					continue outer;
			}
			return i;
		}
		return -1;
	}
	static class State implements Comparable<State> {
		public int identify, start, size;
		public State(int a, int b, int c)	{
			identify = a;
			start = b;
			size = c;
		}
		public int compareTo(State s)	{
			return start-s.start;
		}
	}
}