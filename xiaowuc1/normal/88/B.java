import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int dist = Integer.parseInt(st.nextToken());
		dist *= dist;
		char[][] grid = new char[r][c];
		Set<Character> has = new HashSet<Character>();
		for(int i = 0; i < r; i++)	{
			String s = br.readLine();
			for(int j = 0; j < c; j++)	{
				has.add(s.charAt(j));
				grid[i][j] = s.charAt(j);
			}
		}
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				if(grid[i][j] == 'S')	{
					for(int k = 0; k < r; k++)	{
						for(int l = 0; l < c; l++)	{
							if(grid[k][l] == 'S')
								continue;
							if(!map.containsKey(grid[k][l]))
								map.put(grid[k][l], Integer.MAX_VALUE);
							int min = Math.min(map.get(grid[k][l]), (i-k)*(i-k) + (j-l)*(j-l));
							map.put(grid[k][l], min);
						}
					}
				}
			}
		}
		br.readLine();
		String text = br.readLine();
		String brute = text.toLowerCase();
		for(int i = 0; i < brute.length(); i++)	{
			if(!has.contains(brute.charAt(i)))	{
				System.out.println(-1);
				return;
			}
		}
		int ret = 0;
		for(int i = 0; i < brute.length(); i++)	{
			if(Character.isUpperCase(text.charAt(i)) && map.get(brute.charAt(i)) == null)	{
				System.out.println(-1);
				return;
			}
			if(Character.isUpperCase(text.charAt(i)) && map.get(brute.charAt(i)) > dist)
				ret++;
		}
		System.out.println(ret);
	}
}