import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n==1) {
			System.out.println(15);
			for(int i=0;i<=2;i++) {
				for(int j=-2;j<=0;j++) {
					if(!(i==1 && j==-1)) {
						System.out.println(i + " " + j);
					}
				}
			}
			for(int i=2;i<=4;i++) {
				for(int j=0;j<=2;j++) {
					if(((i==2 && j==0) || (i==3 && j==1))) {
						continue;
					}
					else {
						System.out.println(i + " "+ j);
					}
				}
			}

		}
		else if(n%2==0) {
			System.out.println(5*n+10);
			for(int i=0;i<=(3*n)/2+2;i++) {
				System.out.println(i + " " + 0);
			}
			System.out.println(0 + " " + -1);
			System.out.println(0 + " " + -2);
			System.out.println((3*n+4)/2 + " " + -1);
			System.out.println((3*n+4)/2 + " " + -2);
			for(int i=0;i<=(3*n)/2+2;i++) {
				System.out.println(i +" " + -3);
			}
			for(int i=1;i<=n/2;i++) {
				int a = 3*i;
				int b = 3*i-1;
				System.out.println(b + " " + 1);
				System.out.println(b + " " + -1);
				System.out.println(a + " " + 1);
				System.out.println(a + " " + -1);
			}
			
		}
		
		else {
			n--;
			System.out.println(5*n+17);
			for(int i=0;i<=(3*n)/2+2;i++) {
				System.out.println(i + " " + 0);
			}
			System.out.println(0 + " " + -1);
			System.out.println(0 + " " + -2);
			
			System.out.println((3*n+4)/2 + " " + -1);
			System.out.println((3*n+4)/2 + " " + -2);
			for(int i=0;i<=(3*n)/2+2;i++) {
				System.out.println(i +" " + -3);
			}
			for(int i=1;i<=n/2;i++) {
				int a = 3*i;
				int b = 3*i-1;
				System.out.println(b + " " + 1);
				System.out.println(b + " " + -1);
				System.out.println(a + " " + 1);
				System.out.println(a + " " + -1);
			}
			System.out.println((3*n+6)/2 + " " + 0);
			System.out.println((3*n+6)/2 + " " + 2);

			System.out.println((3*n+8)/2 + " " + 0);

			System.out.println((3*n+8)/2 + " " + 1);
			System.out.println((3*n+8)/2 + " " + 2);
			System.out.println((3*n+4)/2 + " " + 2);
			System.out.println((3*n+4)/2 + " " + 1);




			
		}
		
	}
}