import java.io.*;
import java.util.*;
public class B99 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if(n == 2)	{
			int a = Integer.parseInt(br.readLine());
			int b = Integer.parseInt(br.readLine());
			if(a == b)		{
				System.out.println("Exemplary pages.");
				return;
			}
			if(a%2 != b%2)	{
				System.out.println("Unrecoverable configuration.");
				return;
			}
			if(a > b)		{
				System.out.println((a-b)/2 + " ml. from cup #" + 2 + " to cup #" + 1 + ".");
				return;
			}
			else	{
				System.out.println((b-a)/2 + " ml. from cup #" + 1 + " to cup #" + 2 + ".");
				return;
			}
		}
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = Integer.parseInt(br.readLine());
		}
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int x: list)	{
			set.add(x);
		}
		if(set.size() == 1)		{
			System.out.println("Exemplary pages.");
			return;
		}
		if(set.size() != 3)		{
			System.out.println("Unrecoverable configuration.");
			return;
		}
		int[] num = new int[3];
		int c = 0;
		for(int x: set)	{
			num[c++] = x;
		}
		int min = 0;
		int max = 0;
		for(int x: list)		{
			if(x == num[0])	{
				min++;
			}
			if(x == num[2])	{
				max++;
			}
		}
		if(min != 1 || max != 1)		{
			System.out.println("Unrecoverable configuration.");
			return;
		}
		if(num[0] + num[2] != 2 * num[1])	{
			System.out.println("Unrecoverable configuration.");
			return;
		}
		int minIndex = 0;
		int maxIndex = 0;
		int diff = num[1]-num[0];
		for(int i = 0; i < n; i++)		{
			if(list[i] == num[0])		{
				minIndex = i+1;
			}
			else if(list[i] == num[2])		{
				maxIndex = i+1;
			}
		}
		System.out.println(diff + " ml. from cup #" + minIndex + " to cup #" + maxIndex + ".");
	}
}