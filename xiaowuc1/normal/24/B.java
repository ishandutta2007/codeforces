import java.io.*;
import java.util.*;
public class B24 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[][] name = new String[n][];
		for(int i = 0; i < n; i++)		{
			name[i] = new String[Integer.parseInt(br.readLine())];
			for(int j = 0; j < name[i].length; j++)		{
				name[i][j] = br.readLine();
			}
		}
		TreeSet<String> set = new TreeSet<String>();
		for(String[] a: name)	{
			for(String s: a)
				set.add(s);
		}
		String[] nameList = new String[set.size()];
		int c = 0;
		for(String ss: set)	{
			nameList[c++] = ss;
		}
		State[] people = new State[nameList.length];
		for(int i = 0; i < people.length; i++)		{
			people[i] = new State(nameList[i], new int[50], 0);
		}
		StateA[] peopleA = new StateA[nameList.length];
		for(int i = 0; i < people.length; i++)		{
			peopleA[i] = new StateA(nameList[i], new int[50], 0);
		}
		int[] total = new int[50];
		total[0] = 25;
		total[1] = 18;
		total[2] = 15;
		total[3] = 12;
		total[4] = 10;
		total[5] = 8;
		total[6] = 6;
		total[7] = 4;
		total[8] = 2;
		total[9] = 1;
		for(int i = 0; i < name.length; i++)		{
			for(int j = 0; j < name[i].length; j++)			{
				int index = Arrays.binarySearch(nameList, name[i][j]);
				people[index].points += total[j];
				people[index].places[j]++;
				peopleA[index].points += total[j];
				peopleA[index].places[j]++;
			}
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(State s: people)	{
			q.add(s);
		}
		System.out.println(q.peek());
		PriorityQueue<StateA> q2 = new PriorityQueue<StateA>();
		for(StateA s: peopleA)	{
			q2.add(s);
		}
		System.out.println(q2.peek());
		
	}
	static class State implements Comparable<State> {
		public String name;
		public int points;
		public int[] places;
		public State(String b, int[] c, int d)		{
			name = new String(b);
			places = Arrays.copyOf(c, c.length);
			points = d;
		}
		public int compareTo(State s)		{
			if(points != s.points)
				return s.points - points;
			for(int i = 0; i < places.length; i++)		{
				if(places[i] != s.places[i])	{
					return s.places[i] - places[i];
				}
			}
			return 0;
		}
		public String toString()	{
			return name;
		}
	}
	static class StateA implements Comparable<StateA> {
		public String name;
		public int points;
		public int[] places;
		public StateA(String b, int[] c, int d)		{
			name = new String(b);
			places = Arrays.copyOf(c, c.length);
			points = d;
		}
		public int compareTo(StateA s)		{
			if(places[0] != s.places[0])	{
				return s.places[0] - places[0];
			}
			if(points != s.points)
				return s.points - points;
			for(int i = 1; i < places.length; i++)		{
				if(places[i] != s.places[i])	{
					return s.places[i] - places[i];
				}
			}
			return 0;
		}
		public String toString()	{
			return name;
		}
	}
	
}