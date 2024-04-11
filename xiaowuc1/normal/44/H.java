import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		long[][] dp = new long[s.length()][10];
		Arrays.fill(dp[0], 1);
		for(int i = 1; i < s.length(); i++)		{
			for(int j = 0; j < 10; j++)	{
				dp[i][((s.charAt(i)-'0')+j)/2] += dp[i-1][j];
				if(((s.charAt(i)-'0'+j+1) / 2) != (s.charAt(i)-'0'+j)/2)
					dp[i][((s.charAt(i)-'0')+j+1)/2] += dp[i-1][j];
			}
		}
		boolean isSelf = true;
		for(int i = 1; i < s.length(); i++)	{
			int last = s.charAt(i-1) - '0';
			int now = s.charAt(i) - '0';
			if(now != (last+now)/2 && now != (last+now+1)/2)	{
				isSelf = false;
				break;
			}
		}
		long ret = 0;
		if(isSelf)
			ret--;
		for(long out: dp[s.length()-1])
			ret += out;
		System.out.println(ret);
	}
}