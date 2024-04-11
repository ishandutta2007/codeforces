import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long x = Long.parseLong(st.nextToken());
		long y = Long.parseLong(st.nextToken());
		if(y < n)	{
			System.out.println(-1);
			return;
		}
		long sum = n-1 + (y-(n-1))*(y-(n-1));
		if(sum < x)	{
			System.out.println(-1);
			return;
		}
		for(int i = 1; i < n; i++)
			System.out.print("1 ");
		System.out.println(y-n+1);
	}
}