import java.util.*;
public class A127 {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int p = scan.nextInt();
		long now = p;
		int index = 0;
		long desire = scan.nextInt();
		while(now < desire)	{
			now *= p;
			index++;
		}
		if(now == desire)	{
			System.out.println("YES\n" + index);
		}
		else	{
			System.out.println("NO");
		}
	}
	public static void print(int blank)	{
		for(int i = 0; i < blank; i++)
			System.out.print(' ');
	}
}