import java.util.*;
public class A127 {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String now = scan.nextLine();
		int blank = 0;
		while(now.length() > 0)	{
			int last = now.indexOf(">");
			if(last == 2)	{
				print(blank);
				System.out.println(now.substring(0, last+1));
				blank += 2;
			}
			else	{
				blank -= 2;
				print(blank);
				System.out.println(now.substring(0, last+1));
			}
			now = now.substring(last+1);
		}
	}
	public static void print(int blank)	{
		for(int i = 0; i < blank; i++)
			System.out.print(' ');
	}
}