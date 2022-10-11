import java.io.*;
import java.util.*;
public class A31 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] list = new int[Integer.parseInt(br.readLine())];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < list.length; i++)
			list[i] = Integer.parseInt(st.nextToken());
		for(int j = 0; j < list.length; j++)		{
			for(int k = j+1; k < list.length; k++)		{
				for(int i = 0; i < list.length; i++)	{
					if(list[i] == list[j] + list[k])		{
						System.out.println((i+1) + " " + (j+1) + " " + (k+1));
						return;
					}
				}
			}
		}
		System.out.println(-1);
	}
}