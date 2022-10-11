import java.io.*;
import java.util.*;
public class B14 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int now = Integer.parseInt(st.nextToken());
		int ret = Integer.MAX_VALUE;
		int[] list = new int[1001];
		Arrays.fill(list, n);
		while(n-- > 0)		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			for(int i = Math.min(a,b); i <= Math.max(a,b); i++)
				list[i]--;
		}
		for(int i = 0; i < list.length; i++)		{
			if(list[i] == 0)
				ret = Math.min(ret, Math.abs(now-i));
		}
		System.out.println(ret == Integer.MAX_VALUE ? -1 : ret);
	}
}