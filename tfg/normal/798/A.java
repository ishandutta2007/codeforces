import java.util.Scanner;

public final class Main
{
	static public void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		int n = a.length();
		boolean ans = false;
		for(int k = 0; k < n; k++)
		{
			int count = 0;
			for(int l = 0, r = n - 1; l < r; l++, r--)
			{
				if(l == k || r == k)
				{
					if(a.charAt(l) == a.charAt(r))
						count++;
					continue;
				}
				if(a.charAt(l) != a.charAt(r))
					count++;
			}
			if(count == 0)
				ans = true;
		}
		if(ans)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}