import java.util.HashSet;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int s[] = new int[n];
			for(int i=0;i<n;i++) {
				s[i] = sc.nextInt();
			}
			HashSet<Integer> nums = new HashSet<Integer>();
			for(int i=0;i<n;i++) {
				nums.add(s[i]);
			}
			int ans = -1;
			for(int x=1;x<1024;x++) {
				HashSet<Integer> vals = new HashSet<Integer>();
				for(int i=0;i<n;i++) {
					vals.add(s[i]);
					int k = s[i]^x;
					vals.add(k);
				}
				if(vals.size()==n) {
					ans = x;
					break;
				}
			}
			System.out.println(ans);
		}
	}
}