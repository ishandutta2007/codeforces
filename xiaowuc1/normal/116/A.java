import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int curr = 0;
		int max = 0;
		for(int i = 0; i < n; i++)	{
			curr -= scan.nextInt();
			curr += scan.nextInt();
			max = Math.max(max, curr);
		}
		System.out.println(max);
	}
}