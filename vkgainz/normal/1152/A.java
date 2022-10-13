import java.util.Scanner;

public class Round554 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[m];
		int x =0;
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
			a[i]%=2;
			x+=a[i];
		}
		int y= 0;
		for(int i=0;i<m;i++) {
			b[i] = sc.nextInt();
			b[i]%=2;
			y+=b[i];
		}
		System.out.println(Math.min(y,n-x)+Math.min(m-y,x));
	}
}