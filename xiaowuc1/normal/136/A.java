import java.io.*;
import java.math.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = Integer.parseInt(st.nextToken());
		}
		int[] ret = new int[n];
		for(int i = 0; i < n; i++)	{
			ret[list[i]-1] = i;
		}
		for(int out: ret)
			System.out.print((out+1) + " ");
	}
}