import java.io.*;
import java.util.*;
public class A83 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long ret = 0;
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i =0 ; i < n; i++)	{
			list[i] = Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i < list.length;)	{
			int j = i+1;
			while(j < list.length && list[i] == list[j])
				j++;
			long diff = j-i;
			ret += (diff*diff+diff)/2;
			i=j;
		}
		System.out.println(ret);
	}
}