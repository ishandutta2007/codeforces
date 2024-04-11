import java.util.Scanner;

public class candies {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0){
			t--;
			int n = sc.nextInt();
			for(int k=2;k<=30;k++) {
				int mod = (int) (Math.pow(2,k)-1);
				if(n%mod==0) {
					System.out.println(n/mod);
					break;
				}
			}
		}
	}
}