import java.util.*;
import java.io.*;
public class Solution1{


	public static void main(String args[]){

		Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int n=in.nextInt();
		char arr[]=in.next().toCharArray();
		
		int i;
		for(i=1;i<n;i++)
			if(arr[i-1]>arr[i])
				break;

		if(i==n)
			System.out.println("NO");
		else{
			System.out.println("YES");
			System.out.println(i+" "+(i+1));
		}
	}
}