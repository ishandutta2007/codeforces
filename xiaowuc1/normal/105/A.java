import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		double k = Double.parseDouble(st.nextToken());
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		TreeSet<String> set = new TreeSet<String>();
		TreeSet<String> must = new TreeSet<String>();
		while(n-- > 0)	{
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			map.put(name, Integer.parseInt(st.nextToken()));
			set.add(name);
		}
		while(m-- > 0)	{
			String name = br.readLine();
			must.add(name);
			set.add(name);
		}
		ArrayList<String> ans = new ArrayList<String>();
		ArrayList<Integer> val = new ArrayList<Integer>();
		for(String s: set)	{
			int amt = 0;
			if(map.containsKey(s))	{
				amt = (int) Math.round(100 * k * map.get(s));
				amt /= 100;
				if(amt < 100)
					amt = 0;
			}
			if(amt != 0 || must.contains(s))	{
				ans.add(s);
				val.add(amt);
			}
		}
		System.out.println(ans.size());
		for(int i = 0; i < ans.size(); i++)
			System.out.println(ans.get(i) + " " + val.get(i));
	}
}