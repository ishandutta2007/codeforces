import java.io.*;
import java.util.*;
public class B63 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] list = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < list.length; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int ret = 0;
		while(list[0] != k)		{
			ret++;
			for(int rank = k-1; rank > 0; rank--)	{
				for(int i = 0; i < n; i++)	{
					if(list[i] == rank)		{
						list[i]++;
						Arrays.sort(list);
						break;
					}
				}
			}
		}
		System.out.println(ret);
	}
}