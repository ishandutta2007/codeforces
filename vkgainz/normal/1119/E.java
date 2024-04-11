import java.util.Scanner;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		long sum =0;
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
			
		}
		long numBack =0;
		for(int i=0;i<n;i++) {
			sum+=(long) Math.min(numBack,a[i]/2);
			int temp = a[i];
			a[i]-=2*Math.min(numBack,temp/2);
			numBack-=(long) Math.min(numBack,temp/2);
			sum+=a[i]/3;
			a[i]%=3;
			numBack+=(long) a[i];
		}
		
		System.out.println(sum);
	}
}