import java.io.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		HashMap<Integer, Long> map = new HashMap<Integer, Long>();
		for(int i = -10; i <= 10; i++)	{
			map.put(i, 0L);
		}
		while(n-- > 0)	{
			int now = Integer.parseInt(st.nextToken());
			map.put(now, 1+map.get(now));
		}
		long ret = 0;
		for(int i = -10; i <= -1; i++)	{
			ret += map.get(i) * map.get(-i);
		}
		ret += map.get(0) * (map.get(0)-1)/2;
		System.out.println(ret);
	}
}