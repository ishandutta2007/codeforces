import java.io.*;
import java.util.*;
public class E73 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Set<Integer> set = new HashSet<Integer>();
		int n = Integer.parseInt(st.nextToken());
		int max = Integer.parseInt(st.nextToken());
		if(max == 2)	{
			System.out.println(0);
			return;
		}
		st = new StringTokenizer(br.readLine());
		while(n-- > 0)
			set.add(Integer.parseInt(st.nextToken()));
		if(set.contains(1))	{
			System.out.println(1);
			return;
		}
		if(!set.contains(2))	{
			System.out.println(-1);
			return;
		}
		int curr = 3;
		int num = 1;
		while(curr < max)	{
			while(!prime(curr))
				curr += 2;
			if(curr < max && !set.contains(curr))	{
				System.out.println(-1);
				return;
			}
			if(curr < max && set.contains(curr))
				num++;
			curr += 2;
		}
		System.out.println(num);
	}
	public static boolean prime(int x)	{
		if(x <= 3)
			return true;
		if(x%3==0)
			return false;
		for(int d = 5; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		for(int d = 7; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		return true;
	}
}