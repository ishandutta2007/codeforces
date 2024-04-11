import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int i = 1; i <= n; i++)	{
			if(lucky(i) && n%i==0)	{
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
	public static boolean lucky(int x)	{
		while(x > 0)	{
			if(x%10 != 4 && x%10 != 7)
				return false;
			x/=10;
		}
		return true;
	}
}