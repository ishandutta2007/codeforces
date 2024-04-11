import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-- > 0)	{
			int curr = Integer.parseInt(st.nextToken());
			if(map.containsKey(curr))
				map.put(curr, 1 + map.get(curr));
			else
				map.put(curr, 1);
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(int key: map.keySet())
			q.add(new State(key, map.get(key)));
		int[] aa = new int[100000];
		int[] bb = new int[100000];
		int[] cc = new int[100000];
		int i;
		for(i = 0; q.size() >= 3; i++)	{
			State a = q.poll();
			State b = q.poll();
			State c = q.poll();
			int[] list = new int[]{a.val, b.val, c.val};
			Arrays.sort(list);
			aa[i] = list[0];
			bb[i] = list[1];
			cc[i] = list[2];
			a.num--;
			b.num--;
			c.num--;
			if(a.num != 0)
				q.add(a);
			if(b.num != 0)
				q.add(b);
			if(c.num != 0)
				q.add(c);
		}
		System.out.println(i);
		for(int k = 0; k < i; k++)	{
			System.out.println(cc[k] + " " + bb[k] + " " + aa[k]);
		}
	}
	static class State implements Comparable<State> {
		public int val,num;
		public State(int a, int b)	{
			val = a;
			num = b;
		}
		public int compareTo(State s)	{
			return s.num - num;
		}
	}
}