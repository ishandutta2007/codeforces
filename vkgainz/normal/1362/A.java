import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			long a = sc.nextLong();
			long b = sc.nextLong();
			if(a>b) {
				if(a%b==0) {
					long x = (long) a/b;
					int log = -1;
					for(int i=0;i<=63;i++) {
						long temp = (long) Math.pow(2,i);
						if(temp==x) {
							log = i;
						}
					}
					if(log==-1) {
						System.out.println(-1);

					}
					else {
						int ans = (int) (log+2)/3;
						System.out.println(ans);
					}
				}
				else {
					System.out.println(-1);
				}
			}
			else {
				long te = a;
				a = b;
				b = te;
				if(a%b==0) {
					long x = (long) a/b;
					int log = -1;
					for(int i=0;i<=63;i++) {
						long temp = (long) Math.pow(2,i);
						if(temp==x) {
							log = i;
						}
					}
					if(log==-1) {
						System.out.println(-1);

					}
					else {
						int ans = (int) (log+2)/3;
						System.out.println(ans);
					}
				}
				else {
					System.out.println(-1);
				}
				
			}
		}
	}
}