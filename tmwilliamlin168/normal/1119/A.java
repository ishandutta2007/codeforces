import java.util.*;
public class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n;i++)
		a[i] = sc.nextInt();
		int ans1 = 0, ans2 = 0;
		for(int i = n-1;i > 0;i--)
		if(a[i]!=a[0])
		{
		ans1 = i;
		break;
		}
		for(int i = 0;i < n-1;i++)
		if(a[i]!=a[n-1])
		{
		ans2 = n-i-1;
		break;
		}
		System.out.println(Math.max(ans1,ans2));
	}
}