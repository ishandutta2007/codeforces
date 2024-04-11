import java.io.*;
import java.util.*;
public class A6 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[4];
		for(int i = 0; i < 4; i++)
			list[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(list);
		for(int i = 0; i < 4; i++)	{
			for(int j = i+1; j < 4; j++)	{
				for(int k = j+1; k < 4; k++)		{
					if(list[i] + list[j] > list[k])		{
						System.out.println("TRIANGLE");
						return;
					}
				}
			}
		}
		for(int i = 0; i < 4; i++)	{
			for(int j = i+1; j < 4; j++)	{
				for(int k = j+1; k < 4; k++)		{
					if(list[i] + list[j] == list[k])		{
						System.out.println("SEGMENT");
						return;
					}
				}
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}