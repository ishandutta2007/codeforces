import java.util.*;

public class r540a {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		for(int tt=0;tt<t;tt++) {
			long x=scan.nextLong(), a=scan.nextInt(), b=scan.nextInt();
			if(a*2<b) {
				System.out.println(x*a);
			}
			else {
				if(x%2==1) {
					System.out.println(x/2*b+a);
				}
				else {
					System.out.println(x/2*b);
				}
			}
		}
	}
}