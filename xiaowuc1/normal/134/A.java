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
		int sum = 0;
		for(int out: list)
			sum += out;
		ArrayList<Integer> ret = new ArrayList<Integer>();
		for(int i = 0; i < n; i++)	{
			if(list[i] * n == sum)
				ret.add(i+1);
		}
		System.out.println(ret.size());
		for(int out: ret)
			System.out.print(out + " ");
	}
}