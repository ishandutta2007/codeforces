import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String[] data = new String[5];
		for(int i = 0; i < data.length; i++)	{
			data[i] = nextToken() + " " + nextToken() + " " + nextToken();
		}
		TreeSet<String> teamName = new TreeSet<String>();
		for(int i = 0; i < 5; i++)	{
			StringTokenizer su = new StringTokenizer(data[i]);
			teamName.add(su.nextToken());
			teamName.add(su.nextToken());
		}

		Team[] list = new Team[4];
		int c = 0;
		HashMap<String, Integer> fastAccess = new HashMap<String, Integer>();
		for(String out: teamName)	{
			fastAccess.put(out, c);
			list[c++] = new Team(out, 0, 0, 0);
		}
		HashMap<String, Integer> game = new HashMap<String, Integer>();
		for(String out: teamName)
			game.put(out, 0);
		for(int i = 0; i < 5; i++)	{
			StringTokenizer su = new StringTokenizer(data[i]);
			int first = fastAccess.get(su.nextToken());
			int second = fastAccess.get(su.nextToken());
			game.put(list[first].name, 1 + game.get(list[first].name));
			game.put(list[second].name, 1 + game.get(list[second].name));
			String score = su.nextToken();
			list[first].scored += score.charAt(0) - '0';
			list[first].lost += score.charAt(2) - '0';
			list[second].scored += score.charAt(2) - '0';
			list[second].lost += score.charAt(0) - '0';
			if(score.charAt(0) > score.charAt(2)){
				list[first].points += 3;
			}
			if(score.charAt(0) < score.charAt(2)){
				list[second].points += 3;
			}
			if(score.charAt(0) == score.charAt(2)){
				list[first].points++;
				list[second].points++;
			}
		}
		int berland = -1;
		int notBerland = -1;
		for(String out: game.keySet())	{
			if(game.get(out) == 2)	{
				if(out.equals("BERLAND"))
					berland = fastAccess.get(out);
				else
					notBerland = fastAccess.get(out);
			}
		}
		int ret1 = 10000000;
		int ret2 = 1000000;
		for(int a = 1; a < 100; a++)	{
			for(int b = a-1; b > -1; b--)	{
				Team[] temp = copy(list);
				temp[berland].scored += a;
				temp[notBerland].scored += b;
				temp[berland].lost += b;
				temp[notBerland].lost += a;
				temp[berland].points += 3;
				Arrays.sort(temp);
				if(temp[0].name.equals("BERLAND") || temp[1].name.equals("BERLAND"))	{
					if(a-b < ret1 - ret2)	{
						ret1 = a;
						ret2 = b;
					}
					else if(a-b == ret1 - ret2 && b < ret2)	{
						ret1 = a;
						ret2 = b;
					}
				}
			}
		}
		if(ret1 == 10000000)
			pw.println("IMPOSSIBLE");
		else
			pw.println(ret1 + ":" + ret2);
		pw.close();
	}

	public static Team[] copy(Team[] team)	{
		Team[] ret = new Team[team.length];
		for(int i = 0; i < ret.length; i++)	{
			ret[i] = new Team(team[i]);
		}
		return ret;
	}

	static class Team implements Comparable<Team> {
		public String name;
		public int points;
		public int scored;
		public int lost;
		public Team(String a, int b, int c, int d)	{
			name = a;
			points = b;
			scored = c;
			lost = d;
		}
		public Team(Team team)	{
			name = team.name;
			points = team.points;
			scored = team.scored;
			lost = team.lost;
		}
		public int compareTo(Team team)	{
			if(points != team.points)
				return team.points - points;
			if(scored - lost != team.scored - team.lost)
				return (team.scored-team.lost) - (scored-lost);
			if(scored != team.scored)
				return team.scored - scored;
			return name.compareTo(team.name);
		}
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}