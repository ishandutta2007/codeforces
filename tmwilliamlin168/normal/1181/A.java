import java.util.*;

public class A
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		long x = input.nextLong();
		long y = input.nextLong();
		long z = input.nextLong();

		if(x % z + y % z >= z)
		{
			System.out.print(x / z + y / z + 1);
			System.out.print(" ");
			if(x % z > y % z)
				System.out.println(z - x % z);
			else
				System.out.println(z - y % z);
		}
		else
		{
			System.out.print(x / z + y / z);
			System.out.print(" ");
			System.out.println(0);
		}
	}
}