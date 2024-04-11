import java.util.Scanner;

public class E {
	public static void main(String[] args) {
		Scanner sc=  new Scanner(System.in);
		long max =0;
		int n = sc.nextInt();
		long a[] = new long[n];
		for(int i=0;i<n;i++) {
			a[i] = sc.nextLong();
		}
		if(n>=3) {
			for(int i=0;i<n;i++) {
				for(int j=i+1;j<n;j++) {
					for(int k=j+1;k<n;k++) {
						long x = (long) a[i]|a[j];
						long y = (long) x|a[k];
						max = Math.max(max,y);
					}
				}
			}
		}
		else if(n==2) {
			max = a[0];
			max = Math.max(max,a[1]);
			max = Math.max(max,(long) a[0]|a[1]);
		}
		else {
			max = a[0];
		}
		
		System.out.println(max);
	}
}