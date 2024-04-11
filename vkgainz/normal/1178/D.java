import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n==1 || n==2) {
			System.out.println(-1);
			return;
		}
			int i=n;
			while(true) {
				if(isPrime(i)) {
					break;
				}
				else {
					i++;
				}
			}
			System.out.println(i);
			for(int x=1;x<=n-1;x++) {
				System.out.println(x + " " + (x+1));
			}
			System.out.println(n + " " + 1);
			i-=n;
			int curr =1;
			while(i>0) {
				i--;
				System.out.println(curr + " " + (curr+n/2));
				curr++;
			}
			
		}
		
	

	static boolean isPrime(int x) {
		for(int i=2;i<=Math.sqrt(x);i++) {
			if(x%i ==0) {
				return false;
			}
		}
		return true;
	}
}