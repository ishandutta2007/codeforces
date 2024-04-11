import java.util.Scanner;

public final class Main
{
	static int[][][] dp;
	static boolean[][][] way;
	static int n;
	
	static public void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String num = sc.next();
		n = num.length();
		dp = new int[n+1][3][2];
		way = new boolean[n+1][3][2];
		int INF = 0x3f3f3f3f;
		for(int i=n;i>=0;i--)
		for(int j=0;j<3;j++)
		for(int k=0;k<2;k++)
		{
			if(i==n)
			{
				if(j == 0 && k == 1)
					dp[i][j][k] = 0;
				else
					dp[i][j][k] = INF;
				continue;
			}
			way[i][j][k] = false;
			int ans = dp[i+1][j][k] + 1;
			int a2 = INF;
			if(num.charAt(i) != '0' || k == 1)
				a2 = dp[i+1][(j + num.charAt(i) - '0')%3][1];
			if(ans > a2)
			{
				ans = a2;
				way[i][j][k] = true;
			}
			dp[i][j][k] = ans;
		}
		if(dp[0][0][0] >= INF)
		{
			boolean zero = false;
			for(int i=0;i<n;i++)
				zero = zero || num.charAt(i) == '0';
			if(zero)
				System.out.println("0");
			else
				System.out.println("-1");
		}
		else
		{
			int m = 0;
			int h = 0;
			for(int i=0;i<n;i++)
			{
				if(way[i][m][h])
				{
					System.out.print(num.charAt(i));
					m = (m + num.charAt(i) - '0')%3;
					h = 1;
				}
			}
			System.out.println();
		}
		
	}
}