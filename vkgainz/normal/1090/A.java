
import java.util.Scanner;

public class measurement {

	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int glomax =0;
		int [][] companies = new int[n][2];
		for(int i=0;i<n;i++) {
			int m=sc.nextInt();
			companies[i][0]=m;
			int currmax=0;
			for(int j=0;j<m;j++) {
				int a = sc.nextInt();
				currmax=Math.max(currmax, a);
			}
			glomax = Math.max(glomax, currmax);
			companies[i][1]=currmax;
		}
		long sum=0;
		for(int i=0;i<n;i++) {
			sum+=(long) (glomax-companies[i][1])*companies[i][0];
		}
		System.out.println(sum);
	}

}