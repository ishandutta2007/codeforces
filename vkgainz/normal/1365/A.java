import java.util.HashSet;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int m = sc.nextInt();
			HashSet<Integer> col = new HashSet<>();
			HashSet<Integer> row = new HashSet<>();
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					int x = sc.nextInt();
					if(x==1) {
						col.add(j);
						row.add(i);
					}
				}
			}
			int min = Math.min(n-row.size(),m-col.size());
			if(min%2==1) {
				System.out.println("Ashish");
			}
			else {
				System.out.println("Vivek");
			}
		}
	}
}