import java.io.*;
import java.util.*;
public class B66 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int ret = 1;
		for(int i = 0; i < n; i++)	{
			int j;
			for(j = i-1; j >= 0; j--)		{
				if(list[j] > list[j+1])
					break;
			}
			int k;
			for(k = i+1; k < n; k++)	{
				if(list[k] > list[k-1])
					break;
			}
			ret = Math.max(ret, 1 + ((i-1)-j) + (k-(i+1)));
		}
		System.out.println(ret);
	}
}