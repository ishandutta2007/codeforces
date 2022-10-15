import java.io.BufferedInputStream;
import java.util.Scanner;

public class Task
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		int k = scanner.nextInt();
		int[] tab = new int[k];
		for(int i=0;i<n;i++) {
			int num = scanner.nextInt();
			tab[num % k]++;
		}
		int count = 0;
		for(int i=0;i<k;i++) {
			int ind1 = i;
			int ind2 = (k-i)%k;
			int num1 = tab[ind1];
			int num2 = tab[ind2];
			if(ind1 == ind2) {
				count += num1 - num1%2;
			} else {
				count += Math.min(num1, num2);
			}
		}
		System.out.println(count);
	}
	
}