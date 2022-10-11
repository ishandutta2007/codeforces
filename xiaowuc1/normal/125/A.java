import java.util.*;
public class A127 {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int f = 0;
		int i = 0;
		while(n >= 36)	{
			n -= 36;
			f++;
		}
		while(n >= 3)	{
			n -= 3;
			i++;
		}
		if(n==2)
			i++;
		while(i >= 12)	{
			f++;
			i-=12;
		}
		System.out.println(f + " " + i);
	}
}