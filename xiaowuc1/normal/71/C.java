import java.io.*;
import java.util.*;
public class C71 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		boolean[] list = new boolean[n];
		for(int i = 0; i < n; i++)
			list[i] = st.nextToken().equals("1");
		for(int k = 1; k < n; k++)	{
			if(n%k != 0)
				continue;
			if(n/k <= 2)
				break;
			outer: for(int start = 0; start < k; start++)		{
				for(int mult = 0; mult < n/k; mult++)	{
					if(!list[start+mult*k])
						continue outer;
				}
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}