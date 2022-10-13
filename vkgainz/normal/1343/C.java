import java.util.Scanner;

public class alternatingsubsequences {
	static boolean pos;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int [] a = new int[n];
			for(int i=0;i<n;i++) a[i] =sc.nextInt();
			pos = false;
			if(a[0]>0) {
				pos = true;
			}
			int l = 0;
			long bestSum = 0;
			while(l<n) {
				int tempMax = Integer.MIN_VALUE;
				if(pos) {
					while(l<n && a[l]>0) {
//						System.out.println(a[l]);
						tempMax = Math.max(tempMax,a[l]);
						l++;
					}
					
						
					
				}
				else {
					while(l<n && a[l]<0) {
//						System.out.println(a[l]);
						tempMax = Math.max(tempMax,a[l]);
						l++;
					}
					
				}
				pos = !pos;
				bestSum+=tempMax;
			}
			System.out.println(bestSum);
		}
	}
}