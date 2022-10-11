import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[n];
		for(int i = 0; i < list.length; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int odd = 0;
		int even = 0;
		for(int x: list)
			if(x%2==1)	{
				odd++;
			}
			else	{
				even++;
			}
		for(int i = 1; i <= list.length; i++)	{
			if(list[i-1]%2==1 && odd == 1)	{
				System.out.println(i);
				return;
			}
			else if(list[i-1]%2 == 0 && even == 1){
				System.out.println(i);
				return;
			}
		}
	}

}