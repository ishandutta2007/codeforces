import java.io.*;
import java.util.*;
public class B3 {
	static ArrayList<State> one;
	static ArrayList<State> two;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int total = Integer.parseInt(st.nextToken());
		ArrayList<Integer> ret = new ArrayList<Integer>();
		one = new ArrayList<State>();
		two = new ArrayList<State>();
		int cap = 0;
		for(int i = 1; i <= n; i++)	{
			st = new StringTokenizer(br.readLine());
			int type = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			if(type == 1)	{
				one.add(new State(i,num));
			}
			else	{
				two.add(new State(i,num));
			}
		}
		Collections.sort(one);
		Collections.sort(two);
		if(total%2!=0)	{
			if(!one.isEmpty())	{
				State curr = one.remove(one.size()-1);
				cap += curr.v;
				ret.add(curr.i);
				total--;
			}
		}
		while(total > 0)	{
			if(one.isEmpty() && two.isEmpty())
				break;
			if(total == 1 && one.isEmpty())
				break;
			int onePoss = 0;
			if(one.size() > 0)
				onePoss += one.get(one.size()-1).v;
			if(one.size() > 1)
				onePoss += one.get(one.size()-2).v;
			int twoPoss = 0;
			if(two.size() > 0)
				twoPoss += two.get(two.size()-1).v;
			if(twoPoss > onePoss)	{
				State curr = two.remove(two.size()-1);
				total -= 2;
				cap += curr.v;
				ret.add(curr.i);
			}
			else	{
				State curr = one.remove(one.size()-1);
				total--;
				cap += curr.v;
				ret.add(curr.i);
				if(one.size() > 0)		{
					curr = one.remove(one.size()-1);
					total--;
					cap += curr.v;
					ret.add(curr.i);
				}
			}
		}
		System.out.println(cap);
		if(ret.size() > 0)	{
			for(int i = 0; i < ret.size()-1; i++)
				System.out.print(ret.get(i) + " ");
			System.out.println(ret.get(ret.size()-1));
		}
	}
	static class State implements Comparable<State> {
		public int i,v;
		public State(int a, int b)	{
			i = a;
			v = b;
		}
		public int compareTo(State s)	{
			return v-s.v;
		}
	}
}