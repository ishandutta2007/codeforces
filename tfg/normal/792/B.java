import java.util.Scanner;

public final class Main
{
	private static int[] solve(int[] childs, int skip)
	{
		int n = childs.length;
		int to = skip % n;
		int[] nxt = new int[n - 1];
		for(int i=0;i<n-1;i++)
			nxt[i] = childs[(to + 1 + i) % n];
		System.out.print(childs[to]);
		return nxt;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n, k;
		n = sc.nextInt();
		k = sc.nextInt();
		int[] childs = new int[n];
		for(int i=0;i<n;i++)
			childs[i] = i + 1;
		
		for(int i=0;i<k;i++)
		{
			if(i != 0)
				System.out.print(" ");
			childs = solve(childs, sc.nextInt());
		}
		System.out.println();
	}
}