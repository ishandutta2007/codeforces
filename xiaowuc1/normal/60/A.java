import java.io.*;
import java.util.*;
public class A60 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int left = n+1;
		int right = 0;
		int k = Integer.parseInt(st.nextToken());
		while(k-- > 0)		{
			st = new StringTokenizer(br.readLine());
			st.nextToken();
			st.nextToken();
			String test = st.nextToken();
			st.nextToken();
			int num = Integer.parseInt(st.nextToken());
			if(test.equals("left"))
				left = Math.min(left, num);
			else
				right = Math.max(right, num);
		}
		int ret = left-right-1;
		if(ret <= 0)	{
			System.out.println(-1);
		}
		else
			System.out.println(ret);
	}
}