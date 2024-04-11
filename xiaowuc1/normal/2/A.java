import java.io.*;
import java.util.*;
public class A2 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] inputStr = new String[n];
		int[] inputInt = new int[n];
		for(int i = 0; i < n; i++)		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			inputStr[i] = st.nextToken();
			inputInt[i] = Integer.parseInt(st.nextToken());
		}
		String[] name = new String[n];
		int[] score = new int[n];
		Arrays.fill(score, -1000000000);
		outer: for(int qq = 0; qq < n; qq++)		{
			String nameIn = inputStr[qq];
			int scoreIn = inputInt[qq];
			int i = 0;
			for(i = 0; i < n; i++)		{
				if(name[i] == null)
					break;
				if(name[i].equals(nameIn))	{
					score[i] += scoreIn;
					continue outer;
				}
			}
			name[i] = nameIn;
			score[i] = scoreIn;
		}
		int maxScore = -1000000000;
		for(int x: score)	{
			maxScore = Math.max(maxScore, x);
		}
		Set<String> winner = new HashSet<String>();
		for(int i = 0; i < n; i++)
			if(score[i] == maxScore && name[i] != null)
				winner.add(name[i]);
		name = new String[n];
		score = new int[n];
		Arrays.fill(score, -1000000000);
		outer: for(int qq = 0; qq < n; qq++)		{
			String nameIn = inputStr[qq];
			int scoreIn = inputInt[qq];
			int i = 0;
			for(i = 0; i < n; i++)		{
				if(name[i] == null)
					break;
				if(name[i].equals(nameIn))	{
					score[i] += scoreIn;
					if(score[i] >= maxScore && winner.contains(name[i]))		{
						System.out.println(name[i]);
						return;
					}
					continue outer;
				}
			}
			name[i] = nameIn;
			score[i] = scoreIn;
			if(score[i] >= maxScore && winner.contains(name[i]))		{
				System.out.println(name[i]);
				return;
			}
		}
	}
}