import java.util.Scanner;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int k = sc.nextInt();
			String s = sc.next();
			int [] freq = new int[26];
			for(int i=0;i<n;i++) {
				freq[s.charAt(i)-97]++;
			}
			for(int len=n;len>=1;len--) {
				int numNeeded = gcd(len,k);
				int occ = len/gcd(len,k);
//				System.out.println(numNeeded + " " + occ);
				int a=0;
				for(int i=0;i<26;i++) {
					a+=freq[i]/occ;
				}
//				System.out.println(a);
				if(a>=numNeeded) {
					System.out.println(len);
					break;
				}
			}
		}
	}
	static int gcd(int a,int b) {
		if(b==0) return a;
		return gcd(b,a%b);
	}
}