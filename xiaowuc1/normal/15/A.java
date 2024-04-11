import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		State[] s = new State[n];
		for(int i = 0; i < n; i++)	{
			st = new StringTokenizer(br.readLine());
			s[i] = new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		Arrays.sort(s);
		int num = 2;
		for(int i = 1; i < s.length; i++)	{
			int dist = s[i].x - s[i-1].x;
			dist *= 2;
			int size = s[i].d + s[i-1].d;
			size += 2 * t;
			if(dist == size)
				num++;
			else if(dist > size)
				num += 2;
		}
		System.out.println(num);
	}
	static class State implements Comparable<State> {
		public int x,d;
		public State(int a, int b)	{
			x=a;
			d=b;
		}
		public int compareTo(State s)	{
			return x - s.x;
		}
	}
}