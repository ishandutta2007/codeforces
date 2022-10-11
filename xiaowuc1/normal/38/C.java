import java.io.*;
import java.util.*;
public class C38 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int ret = 0;
		st = new StringTokenizer(br.readLine());
		int[] list = new int[101];
		while(n-- > 0)	{
			int curr = Integer.parseInt(st.nextToken());
			for(int l = d; l <= 100; l++)
				list[l] += curr/l;
		}
		for(int i = 0; i < list.length; i++)
			ret = Math.max(ret, i * list[i]);
		System.out.println(ret);
	}
}