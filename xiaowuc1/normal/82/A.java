import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int diff = 1; true; diff <<= 1)	{
			n -= diff;
			if(n <= 0)	{
				System.out.println("Sheldon");
				return;
			}
			n -= diff;
			if(n <= 0)	{
				System.out.println("Leonard");
				return;
			}
			n -= diff;
			if(n <= 0)	{
				System.out.println("Penny");
				return;
			}
			n -= diff;
			if(n <= 0)	{
				System.out.println("Rajesh");
				return;
			}
			n -= diff;
			if(n <= 0)	{
				System.out.println("Howard");
				return;
			}
		}
	}
}