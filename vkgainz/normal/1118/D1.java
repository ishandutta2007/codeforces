import java.util.Arrays;
import java.util.Scanner;

public class coffee {
	static int n,m;
	static int [] coffee;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		n= sc.nextInt();
		m = sc.nextInt();
		coffee = new int[n];
		for(int i=0;i<n;i++) {
			coffee[i] = sc.nextInt();
		}
		Arrays.sort(coffee);
		int [] boffee = new int[n];
		for(int i=0;i<n;i++) {
			boffee[i] = coffee[n-i-1];
		}
		coffee=boffee;
		
		for(int i=1;i<=n;i++) {
			if(satisfies(i)) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(-1);
		
	}
	public static boolean satisfies(int days) {
		int num=0;
		int counter=0;
		for(int c=1;c<=n/days+1;c++) {
		for(int i=0;i<days;i++) {
			num+=Math.max(0, coffee[counter]-c+1);
			counter++;
			if(num>=m) {
				return true;
			}
			if(counter>=n) {
				return num>=m;
			}
		}
		}
		return num>=m;
	}
}