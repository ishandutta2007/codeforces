import java.util.*;
public class A124 {
	public static void main(String[] args)	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int a = scan.nextInt();
		int b = scan.nextInt();
		int ret = 0;
		for(int i = 1; i <= n; i++)	{
			if(i >= a+1 && i >= n-b)
				ret++;
		}
		System.out.println(ret);
	}
}