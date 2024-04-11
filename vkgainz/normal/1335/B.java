
import java.util.Scanner;

public class constructthestring {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			int n = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			String ref = "abcdefghijklmnopqrstuvwxyz";
			String copy = "";
			for(int i=0;i<b;i++) {
				copy+=ref.charAt(i);
			}
			for(int i=b;i<a;i++) {
				copy+=ref.charAt(b-1);
			}
			String ret = "";
			for(int i=0;i<n;i++) {
				ret+=copy.charAt(i%a);
			}
			System.out.println(ret);
			t--;
			
		}
	}
}