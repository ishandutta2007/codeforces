import java.util.*;
public class Xor_Codeforces_Manthan {
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0)
		{
			int a=sc.nextInt();
			int b=sc.nextInt();
			int n=sc.nextInt();
			
			int c=a^b;
			
			
			
			if(n%3==0)
				System.out.println(a);
			else if(n%3==1)
				System.out.println(b);
			else if(n%3==2)
				System.out.println(c);
			t--;
		}
		
	}
 
}