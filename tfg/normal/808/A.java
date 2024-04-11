import java.util.Scanner;

final public class Main {
	
	private static int normalize(int x)
	{
		if(x / 10 == 0)
			return x + 1;
		else
			return 10 * normalize(x / 10);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int o = normalize(n);
		System.out.println(o - n);
	}
}