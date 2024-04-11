import java.io.*;
import java.util.*;
public class B56 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= n; i++)	{
			outer: for(int j = i+1; j <= n; j++)	{
				if(list[i] == j && list[j] == i)	{
					for(int k = i+1; k <= j; k++)		{
						if(list[k] > list[k-1])	{
							continue outer;
						}
					}
					for(int k = 1; k <= i; k++)		{
						if(list[k] < list[k-1])	{
							continue outer;
						}
					}
					for(int k = j+1; k <= n; k++)		{
						if(list[k] < list[k-1])	{
							continue outer;
						}
					}
					System.out.println(i + " " + j);
					return;
				}
			}
		}
		System.out.println("0 0");
	}
}