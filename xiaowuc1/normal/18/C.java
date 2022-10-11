import java.io.*;
import java.util.*;
public class C18 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int sum = 0;
		for(int x: list)	{
			sum += x;
		}
		int ret = 0;
		int curr = 0;
		for(int i = 0; i < n-1; i++)		{
			curr += list[i];
			if(2*curr == sum)
				ret++;
		}
		System.out.println(ret);
	}
}