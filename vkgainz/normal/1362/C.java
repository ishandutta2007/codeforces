import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			long n = sc.nextLong();
			n--;
			long [] pow =new long[64];
			for(int i=1;i<64;i++) {
				long tempSub = (long) Math.pow(2,i-1)-1;
				long r = 0;
				if(tempSub<=n) {
					
					r= n-tempSub;
				}
				else {
					continue;
				}
				long div = (long) Math.pow(2,i);
				long x = (long) r/div;
				pow[i] = x+1;
			}
			long res = 0;
			for(int i=1;i<64;i++) {
				res+=(long) pow[i]*i;
			}
			System.out.println(res);
		}
		
	}
}