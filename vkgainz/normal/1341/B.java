import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int k = sc.nextInt();
			int [] vals = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
			}
			int max = 0;
			int curr =0;
			int lmax =0;
			for(int i=1;i<k-1;i++) {
				if(vals[i]>vals[i-1] && vals[i]>vals[i+1]) {
					curr++;
				}
			}
			for(int l=0;l<=n-k;l++) {
				if(curr>max) {
					max = curr;
					lmax = l;
				}
				if(vals[l+1]>vals[l] && vals[l+1]>vals[l+2]) {
					curr--;
				}
				int r = l+k-1;
				if(r<n-1 && vals[r]>vals[r-1] && vals[r]>vals[r+1]) {
					curr++;
				}
			}
			if(curr>max) {
				max = curr;
				lmax = n-k;
			}
			System.out.println((max+1) + " " + (lmax+1));
			
		}
	}
}