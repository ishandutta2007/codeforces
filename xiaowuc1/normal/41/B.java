import java.io.*;
import java.util.*;
public class B41 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int[] list = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)		{
			list[i] = Integer.parseInt(st.nextToken());
		}
		int ret = b;
		for(int i = 0; i < n; i++)	{
			for(int j = i+1; j < n; j++)		{
				if(list[j] > list[i])	{
					int diff = b/list[i];
					ret = Math.max(ret, b + diff * (list[j] - list[i]));
				}
			}
		}
		System.out.println(ret);
	}
}