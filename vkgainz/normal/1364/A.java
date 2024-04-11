import java.util.HashSet;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int x = sc.nextInt();
			int a[] = new int[n];
			int lz =-1;
			int fz =n;
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt();
			}
			int sum=0;
			int firstNonZero =n;
			int lastNonZero =-1;
			int numZero=0;
			for(int i=0;i<n;i++) {
				sum+=a[i];
				sum%=x;
				if(a[i]%x==0) {
					firstNonZero = Math.min(firstNonZero,i);
					lastNonZero = Math.max(lastNonZero,i);
					numZero++;
				}
				else {
					fz = Math.min(fz,i);
					lz = Math.max(lz,i);
				}
			}
			if(sum%x==0) {
				if(firstNonZero==n || lastNonZero==-1) { 
					//no zeroes
					System.out.println(n-1);
				}
				else {
					System.out.println(Math.max(n-fz-1,lz));
				}
			}
			else {
				System.out.println(n);
			}
			

			
			
		}
	}
}