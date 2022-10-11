import java.io.*;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int[] prefix = new int[n];
		int[] suffix = new int[n];
		prefix[0] = -2*list[0];
		suffix[n-1] = -2*list[n-1];
		for(int i = 1; i < n; i++)		{
			prefix[i] = prefix[i-1] - 2 * list[i];
			suffix[n-1-i] = suffix[n-i] - 2 * list[n-1-i];
		}
		for(int i = 1; i < n; i++)	{
			prefix[i] = Math.max(prefix[i], prefix[i-1]);
			suffix[n-1-i] = Math.max(suffix[n-1-i], suffix[n-i]);
		}
		int max = Math.max(0, Math.max(prefix[n-1], suffix[0]));
		for(int i = 0; i < n-1; i++)	{
			max = Math.max(max, prefix[i] + suffix[i+1]);
		}
		for(int out: list)
			max += out;
		System.out.println(max);
	}
}