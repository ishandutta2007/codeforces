import java.io.*;
import java.util.*;
public class C12 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] prices = new int[Integer.parseInt(st.nextToken())];
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < prices.length; i++)		{
			prices[i] = Integer.parseInt(st.nextToken());
		}
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		while(m-- > 0)		{
			String curr = br.readLine();
			if(!map.containsKey(curr))
				map.put(curr, 1);
			else
				map.put(curr, map.get(curr)+1);
		}
		int[] other = new int[map.keySet().size()];
		int c = 0;
		for(String s: map.keySet())	{
			other[c++] = map.get(s);
		}
		Arrays.sort(other);
		Arrays.sort(prices);
		int min = 0;
		for(int i = 0; i < other.length; i++)		{
			min += other[other.length-1-i] * prices[i];
		}
		int max = 0;
		for(int i = 0; i < other.length; i++)
			other[i] = -other[i];
		for(int i = 0; i < prices.length; i++)
			prices[i] = -prices[i];
		Arrays.sort(other);
		Arrays.sort(prices);
		for(int i = 0; i < other.length; i++)		{
			max += other[i] * prices[i];
		}
		System.out.println(min + " " + max);
	}
	
}