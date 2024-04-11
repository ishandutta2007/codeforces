import java.util.Scanner;

public final class Main
{
	static public void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] a = new String[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.next();
		int s = a[0].length();
		int cycle;
		for(int i = 1; ; i++)
		{
			boolean equal = true;
			for(int j = 0; j < s; j++)
				equal = equal && a[0].charAt(j) == a[0].charAt((j + i) % s);
			if(equal)
			{
				cycle = i;
				break;
			}
		}
		int[] cost = new int[n];
		for(int i = 0; i < n; i++)
		{
			cost[i] = s + 1;
			for(int j = 0; j < s; j++)
			{
				boolean equal = true;
				for(int k = 0; k < s; k++)
					equal = equal && a[0].charAt(k) == a[i].charAt((j + k) % s);
				if(equal)
				{
					cost[i] = j;
					break;
				}
			}
			if(cost[i] == s + 1)
			{
				System.out.println(-1);
				return;
			}
		}
		int ans = n * s;
		for(int j = 0; j < cycle; j++)
		{
			int cur_ans = 0;
			for(int i = 0; i < n; i++)
				cur_ans += (cost[i] + j) % cycle;
			if(cur_ans < ans)
				ans = cur_ans;
		}
		System.out.println(ans);
	}
}