import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			int x = n*(a-b); int y = c-d;
			int w = n*(a+b); int z = c+d;
//			System.out.println(x + " " + w);
//			System.out.println(w + " " + z);
			if((x<y && w<y) || (x>z && w>z)) {
				System.out.println("No");
			}
			else {
				System.out.println("Yes");
			}
		}
	}
}