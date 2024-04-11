import java.io.*;
import java.util.*;
public class B82 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if(n == 2)		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();
			System.out.println("1 " + st.nextToken());
			ArrayList<String> list = new ArrayList<String>();
			while(st.hasMoreTokens())
				list.add(st.nextToken());
			System.out.print(list.size() + " ");
			for(int q = 0; q < list.size()-1; q++)
				System.out.print(list.get(q) + " ");
			System.out.println(list.get(list.size()-1));
			return;
		}
		Set<Integer>[] sets = new HashSet[(n*n-n)>>1];
		boolean[] has = new boolean[201];
		for(int i = 0; i < sets.length; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			sets[i] = new HashSet<Integer>();
			st.nextToken();
			while(st.hasMoreTokens())	{
				int curr = Integer.parseInt(st.nextToken());
				sets[i].add(curr);
				has[curr] = true;
			}
		}
		for(int i = 0; i < has.length; i++)	{
			if(has[i])	{
				Map<Integer, Integer> map = new HashMap<Integer, Integer>();
				for(Set<Integer> set: sets)		{
					if(set.contains(i))	{
						for(int curr: set)		{
							if(!map.containsKey(curr))
								map.put(curr, 1);
							else
								map.put(curr, 1+map.get(curr));
						}
					}
				}
				ArrayList<Integer> list = new ArrayList<Integer>();
				for(int key: map.keySet())	{
					if(map.get(key) == n-1)
						list.add(key);
				}
				System.out.print(list.size() + " ");
				for(int q = 0; q < list.size()-1; q++)
					System.out.print(list.get(q) + " ");
				System.out.println(list.get(list.size()-1));
				for(int out: list)
					has[out] = false;
			}
		}
	}
}