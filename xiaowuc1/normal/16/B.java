import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		PriorityQueue<State> q = new PriorityQueue<State>();
		while(p-- > 0)	{
			st = new StringTokenizer(br.readLine());
			q.add(new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		long total = 0;
		while(!q.isEmpty())	{
			State s = q.poll();
			if(s.n <= n)	{
				n-=s.n;
				total += ((long)s.n)*s.m;
			}
			else	{
				total += n * s.m;
				break;
			}
		}
		System.out.println(total);
	}
	static class State implements Comparable<State> {
		public int n,m;
		public State(int a, int b)	{
			n=a;
			m=b;
		}
		public int compareTo(State s)	{
			return s.m-m;
		}
		public String toString()		{
			return n + " " + m;
		}
	}
}