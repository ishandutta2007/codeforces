import java.util.*;

public class Solution
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int k=in.nextInt();
		int count=0;
		if((k-1)<=(n-k))
			count=2*(k-1)+(n-k)+2*n+1;
		else
			count=2*(n-k)+(k-1)+2*n+1;
		System.out.println(count);
	}
}