import java.io.*;
import java.util.*;
public class C6 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		int a = 0;
		int b = 0;
		int i = 0;
		int j = n-1;
		boolean bEating = false;
		while(i <= j)	{
			if(i == j)	{
				if(bEating)
					b++;
				else
					a++;
				break;
			}
			if(list[i] > list[j])	{
				list[i] -= list[j--];
				b++;
				bEating = false;
			}
			else if(list[j] > list[i]){
				list[j] -= list[i++];
				a++;
				bEating = true;
			}
			else	{
				bEating = false;
				i++;
				j--;
				a++;
				b++;
			}
		}
		System.out.println(a + " " + b);
	}
}