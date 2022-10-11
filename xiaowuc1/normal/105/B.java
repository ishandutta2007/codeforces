import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	static int ourLevel;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		ourLevel = Integer.parseInt(st.nextToken());
		State[] list = new State[n];
		for(int i = 0; i < n; i++)	{
			st = new StringTokenizer(br.readLine());
			list[i] = new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())/10);
		}
		System.out.println(solve(list, 0, k));
	}
	public static double solve(State[] s, int index, int left)		{
		if(index == s.length)
			return prob(s);
		double ret = 0;
		for(int c = 0; c <= left && s[index].prob + c <= 10; c++)	{
			s[index].prob += c;
			ret = Math.max(ret, solve(s, index+1, left-c));
			s[index].prob -= c;
		}
		return ret;
	}
	public static double prob(State[] s)	{
		double win = 1;
		for(int i = 0; i < (1<<s.length); i++)	{
			int numLose = s.length - Integer.bitCount(i);
			if(2*numLose >= s.length)	{
				int level = 0;
				double p = 1;
				for(int j = 0; j < s.length; j++)	{
					if((i&(1<<j)) == 0)	{
						p *= (10-s[j].prob)/10.;
						level += s[j].level;
					}
					else	{
						p *= s[j].prob/10.;
					}
				}
				double lose = level * 1.0 / (ourLevel + level);
				win -= p * lose;
			}
		}
		return win;
	}
	static class State	{
		public int level,prob;
		public State(int a, int b)	{
			level = a;
			prob = b;
		}
	}
}