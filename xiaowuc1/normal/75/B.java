import java.io.*;
import java.util.*;
public class B75 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String test = br.readLine();
		int n = Integer.parseInt(br.readLine());
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		while(n-- > 0)		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			String first = st.nextToken();
			String action = st.nextToken();
			if(!action.equals("likes"))
				st.nextToken();
			int value = 0;
			if(action.startsWith("p"))
				value = 15;
			if(action.startsWith("c"))
				value = 10;
			if(action.startsWith("l"))
				value = 5;
			String second = st.nextToken();
			second = second.substring(0, second.length()-2);
			if(!first.equals(test) && !map.containsKey(first))
				map.put(first, 0);
			if(!second.equals(test) && !map.containsKey(second))
				map.put(second, 0);
			if(first.equals(test))	{
				map.put(second, value + map.get(second));
			}
			else if(second.equals(test))	{
				map.put(first, value + map.get(first));
			}
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(String name: map.keySet())	{
			q.add(new State(name, map.get(name)));
		}
		while(!q.isEmpty())
			System.out.println(q.poll());
	}
	static class State implements Comparable<State>	{
		public String name;
		public int val;
		public State(String a, int b)		{
			name = a;
			val = b;
		}
		public int compareTo(State s)		{
			if(val == s.val)
				return name.compareTo(s.name);
			return s.val-val;
		}
		public String toString()	{
			return name;
		}
	}
}