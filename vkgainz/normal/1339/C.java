
import java.util.Scanner;

public class poweredaddition {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			int n = sc.nextInt();
			int [] vals = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
				
			}
			int k = 0;

			for(int i=1;i<n;i++) {
				if(vals[i]>=vals[i-1]) {
					continue;
				}
				int dif = vals[i-1]-vals[i];
				for(int j=0;j<=31;j++) {
					if(Math.pow(2,j)>dif) {
						k = Math.max(k,j);
						break;
					}
				}
				vals[i] = vals[i-1];
			}
			
//			for(int i=0;i<n;i++) {
//				System.out.println(vals[i]);
//			}
			System.out.println(k); 
			
			t--;
		}
	}
}