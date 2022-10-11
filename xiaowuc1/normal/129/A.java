import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int odd = 0;
		int even = 0;
		while(n-- > 0)	{
			if(scan.nextInt() % 2 == 0)
				even++;
			else
				odd++;
		}
		if(odd%2==1)
			System.out.println(odd);
		else
			System.out.println(even);
	}
}