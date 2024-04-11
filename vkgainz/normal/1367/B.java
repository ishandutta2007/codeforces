import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int a[] = new int[n];
			int numEv =0;
			int numO = 0;
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt();
				if(a[i]%2 != i%2) {
					if(a[i]%2==0) {
						numEv++;
					}
					else {
						numO++;
					}
				}
			}
			if(numEv==numO) {
				System.out.println(numEv);
			}
			else {
				System.out.println(-1);
			}
		}
	}
}