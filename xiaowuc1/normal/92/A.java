import java.io.*;
import java.util.*;
public class A92 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int total = Integer.parseInt(st.nextToken());
		outer: while(true)		{
			for(int i = 1; i <= n; i++)		{
				if(i > total)
					break outer;
				total -= i;
			}
		}
		System.out.println(total);
	}
}