import java.io.*;
import java.math.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(list);
		if(list[n-1] == 1)	{
			for(int i = 0; i < n-1; i++)
				System.out.print("1 ");
			System.out.println(2);
			return;
		}
		System.out.print("1 ");
		for(int i = 1; i < n; i++)	{
			System.out.print(list[i-1] + " ");
		}
	}
}