import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		for(int i=0;i<n;i++) {
			a[sc.nextInt()-1] = i;
		}
		for(int i=0;i<n;i++) {
			b[sc.nextInt()-1] = i;
		}
		int [] freq = new int[n];
		for(int i=0;i<n;i++) {
			int dif = a[i]-b[i];
			dif+=n;
			dif%=n;
			freq[dif]++;
		}
		int max =0;
		for(int i=0;i<n;i++) {
			max = Math.max(max,freq[i]);
		}
		System.out.println(max);
		
	}
}