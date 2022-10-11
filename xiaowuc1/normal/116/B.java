import java.util.*;
import java.io.*;
public class Main {
	static boolean[][] pig;
	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		pig = new boolean[r][c];
		boolean[][] wolf = new boolean[r][c];
		for(int i = 0; i < r; i++)	{
			String s = br.readLine();
			for(int j = 0; j < c; j++)	{
				pig[i][j] = s.charAt(j) == 'P';
				wolf[i][j] = s.charAt(j) == 'W';
			}
		}
		int ret = 0;
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				if(!wolf[i][j])
					continue;
				for(int k = 0; k < dx.length; k++)	{
					if(valid(i+dx[k], j+dy[k]))	{
						ret++;
						break;
					}
				}
			}
		}
		System.out.println(ret);
	}
	public static boolean valid(int x, int y)	{
		return x >= 0 && x < pig.length && y >= 0 && y < pig[x].length && pig[x][y];
	}
}