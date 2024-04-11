import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int x= sc.nextInt();
			int a[] = new int[n];
			int z = 0;
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt()%2;
				if(a[i]==0) z++;
			}
			boolean w = false;
			for(int b=0;b<=z;b++) {
				int r = x-b;
				if(r<=(n-z)) {
					if(r%2==1) {
						w = true;
						break;
					}
				}
			}
			if(w) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}
}