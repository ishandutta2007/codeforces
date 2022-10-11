import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		String s = br.readLine();
		for(int i = 0; i < s.length(); i++)	{
			for(int j = i+1; j <= s.length(); j++)	{
				if(!lucky(s.substring(i,j)))
					continue;
				if(!map.containsKey(s.substring(i,j)))
					map.put(s.substring(i,j), 0);
				map.put(s.substring(i,j), 1 + map.get(s.substring(i,j)));
			}
		}
		if(map.size() == 0)
			System.out.println(-1);
		else	{
			int best = 0;
			s = "";
			for(String key: map.keySet())		{
				if(map.get(key) > best || (map.get(key) == best && key.compareTo(s) < 0))		{
					best = map.get(key);
					s = key;
				}
			}
			System.out.println(s);
		}
	}
	public static boolean lucky(String s)	{
		if(s.charAt(0) == '0')
			return false;
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) != '4' && s.charAt(i) != '7')
				return false;
		}
		return true;
	}
}