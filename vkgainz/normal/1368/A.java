import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int a = sc.nextInt();
			int b = sc.nextInt();
			int n = sc.nextInt();
			int steps = 0;
			while(a<=n && b<=n) {
				if(a<b) {
					a+=b;
				}
				else {
					b+=a;
				}
				steps++;
			}
			System.out.println(steps);
		}
		
	}
}