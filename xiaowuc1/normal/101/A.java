import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		for(int i = 0; i < s.length(); i++)	{
			char ch = s.charAt(i);
			if(!map.containsKey(ch))
				map.put(ch,1);
			else
				map.put(ch, map.get(ch)+1);
		}
		int k = Integer.parseInt(br.readLine());
		Set<Character> bad = new HashSet<Character>();
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(char ch: map.keySet())	{
			q.add(new State(map.get(ch),ch));
		}
		while(!q.isEmpty())	{
			State curr = q.poll();
			if(curr.num > k)
				break;
			k -= curr.num;
			bad.add(curr.ch);
		}
		StringBuilder sb = new StringBuilder();
		Set<Character> good = new HashSet<Character>();
		for(int i = 0; i < s.length(); i++)
			if(!bad.contains(s.charAt(i)))	{
				sb.append(s.charAt(i));
				good.add(s.charAt(i));
			}
		System.out.println(good.size());
		System.out.println(sb);
	}
	static class State implements Comparable<State> {
		public int num;
		public char ch;
		public State(int a, char b)	{
			num=a;
			ch=b;
		}
		public int compareTo(State s)	{
			return num-s.num;
		}
	}
}