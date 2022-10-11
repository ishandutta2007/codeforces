import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class E {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine().toLowerCase();
		int[] currentScore = new int[s.length()+1];
		PriorityQueue<State> q = new PriorityQueue<State>();
		q.add(new State(0,0));
		for(int i = 1; i <= s.length(); i++)	{
			currentScore[i] = currentScore[i-1] + contrib(s.charAt(i-1));
			q.add(new State(i, currentScore[i]));
		}
		int num = 0;
		int len = 0;
		int min = Integer.MAX_VALUE;
		int lastLoc = 1 << 29;
		while(!q.isEmpty())	{
			State curr = q.poll();
			int propLen = curr.loc - lastLoc;
			if(propLen > len)	{
				len = propLen;
				num = 0;
			}
			if(propLen == len)
				num++;
			lastLoc = Math.min(lastLoc, curr.loc);
		}
		if(num == 0)	{
			System.out.println("No solution");
			return;
		}
		System.out.println(len + " " + num);
	}
	public static int contrib(char ch)	{
		switch (ch)	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return -1;
		default:
			return 2;
		}
	}
	static class State implements Comparable<State> {
		public int loc,val;
		public State(int a, int b)	{
			loc=a;
			val=b;
		}
		public int compareTo(State s) {
			if(val == s.val)
				return loc - s.loc;
			return val - s.val;
		}
	}
}