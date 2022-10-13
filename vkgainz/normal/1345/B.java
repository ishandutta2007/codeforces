import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int numMove =0;
			while(n>=2) {
				int remo = 0;
				long a = (long) 24*n+1;
				double x = Math.sqrt(a);
//				System.out.println(x);
				int y = (int) ((x-1)/6);
//				System.out.println(y);
				n-=(3*y*y+y)/2;
				numMove++;
				
			}
			System.out.println(numMove);
		}
	}
}