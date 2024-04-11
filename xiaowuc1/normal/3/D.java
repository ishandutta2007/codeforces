import java.io.*;
import java.util.*;
public class D3 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int diff = 0;
		long ret = 0;
		char[] fin = new char[s.length()];
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) == '('){
				fin[i] = '(';
				diff++;
			}
			else if(s.charAt(i) == ')')	{
				fin[i] = ')';
				diff--;
			}
			else {	
				StringTokenizer st = new StringTokenizer(br.readLine());
				int first = Integer.parseInt(st.nextToken());
				int second = Integer.parseInt(st.nextToken());
				q.add(new State(i, first-second));
				ret += second;
				fin[i] = ')';
				diff--;
			}
			if(diff < 0)	{
				if(q.isEmpty())	{
					System.out.println(-1);
					return;
				}
				State curr = q.poll();
				diff += 2;
				fin[curr.i] = '(';
				ret += curr.c;
			}
		}
		if(diff == 0)	{
			System.out.println(ret);
			System.out.println(new String(fin));
		}
		else	{
			System.out.println(-1);
		}
	}
	static class State implements Comparable<State> {
		public int i,c;
		public State(int a, int b)	{
			i=a;
			c=b;
		}
		public int compareTo(State s)	{
			return c - s.c;
		}
	}
}