import java.io.*;
import java.util.*;
public class A19 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] team = new String[n];
		for(int i = 0; i < n; i++)
			team[i] = br.readLine();
		Arrays.sort(team);
		int[] points = new int[n];
		int[] goals = new int[n];
		int[] lost = new int[n];
		for(int i = 0; i < (n*n-n)/2; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			StringTokenizer teams = new StringTokenizer(st.nextToken(), "-");
			StringTokenizer scores = new StringTokenizer(st.nextToken(), ":");
			String firstT = teams.nextToken();
			String secondT = teams.nextToken();
			int first = Integer.parseInt(scores.nextToken());
			int second = Integer.parseInt(scores.nextToken());
			int fT = Arrays.binarySearch(team, firstT);
			int sT = Arrays.binarySearch(team, secondT);
			goals[fT] += first;
			lost[fT] += second;
			goals[sT] += second;
			lost[sT] += first;
			if(first > second)
				points[fT] += 3;
			else if(first < second)
				points[sT] += 3;
			else	{
				points[fT]++;
				points[sT]++;
			}
		}
		ArrayList<Team> list = new ArrayList<Team>();
		for(int i = 0; i < n; i++)		{
			list.add(new Team(points[i], goals[i], lost[i], team[i]));
		}
		Collections.sort(list);
		ArrayList<String> ret = new ArrayList<String>();
		for(int i = 0; i < n>>1; i++)
			ret.add(list.get(i).name);
		Collections.sort(ret);
		for(String ss: ret)
			System.out.println(ss);
	}
	static class Team implements Comparable<Team> {
		public int point;
		public int lost;
		public int goal;
		public String name;
		public Team(int a, int b, int c, String d)		{
			point=a;
			goal=b;
			lost=c;
			name = d;
		}
		public int compareTo(Team t)		{
			if(point == t.point)	{
				if(goal-lost == t.goal-t.lost)
					return t.goal-goal;
				return (t.goal-t.lost)-(goal-lost);
			}
			return t.point-point;
		}
	}
}