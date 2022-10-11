import java.io.*;
import java.util.*;
public class B69 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int total = Integer.parseInt(st.nextToken());
		int ret = 0;
		int n = Integer.parseInt(st.nextToken());
		int[] start = new int[n];
		int[] end = new int[n];
		int[] time = new int[n];
		int[] profit = new int[n];
		for(int i = 0; i < n; i++)	{
			st = new StringTokenizer(br.readLine());
			start[i] = Integer.parseInt(st.nextToken());
			end[i] = Integer.parseInt(st.nextToken());
			time[i] = Integer.parseInt(st.nextToken());
			profit[i] = Integer.parseInt(st.nextToken());
		}
		for(int i = 1; i <= total; i++)	{
			int p = 0;
			int t = Integer.MAX_VALUE;
			for(int k = 0; k < n; k++)	{
				if(start[k] <= i && i <= end[k] && time[k] < t)			{
					t = time[k];
					p = profit[k];
				}
			}
			if(t != Integer.MAX_VALUE)
				ret += p;
		}
		System.out.println(ret);
	}
}