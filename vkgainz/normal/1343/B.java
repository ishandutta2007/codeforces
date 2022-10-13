import java.util.Scanner;

public class balancedarray {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			StringBuilder sb = new StringBuilder();
			t--;
			int n = sc.nextInt();
			
			if((n/2)%2==0) {
				System.out.println("YES");
				for(int i=1;i<=(n/2);i++) {
					sb.append(2*i + " ");
				}
				for(int i=1;i<n/2;i++) {
					sb.append((2*i-1) + " ");
				}
				sb.append(3*n/2-1);
				System.out.println(sb.toString());
			}
			else {
				System.out.println("NO");
			}
		}
	}
}