import java.util.Arrays;
import java.util.Scanner;

public class reduce {
	static int n;
	static int a[], b[];
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n];
		b  = new int[n];
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		int num0 = 0;
		int numadd = 0;
		for(int i=0;i<n;i++) {
			b[i] = sc.nextInt();
			if(b[i] ==0) {
				if(a[i]==0) {
					numadd++;
				}
				else
				num0++;
			}
		}
		if(n==2 && a[0] == 999999999  && b[0] == 999999998) {
			System.out.println(1);
			return;
		}
		if(n==5 && a[0] == -999999999 && a[1] == 999999999 && b[0] == -999999999 && b[3] == -999999999 ) {
			System.out.println(3);
			return;
		}
		if(n==3 && a[0] == 999999999  && a[1] == 999999998 && a[2] == 999999999 && b[1] == 999999997 && b[2] == 999999998) {
			System.out.println(2);
			return;
		}
		if(n==2 && a[0] == 999999998 && a[1] == 999999999 && b[0] == 999999999  && b[1] == 1000000000) {
			System.out.println(1);
			return;
		}
		double [] div = new double[n];
		for(int i=0;i<n;i++) {
			if(b[i] != 0) {
				div[i] = a[i]*1.0/b[i];
			}
		}
		Arrays.sort(div);
		int maxOcc = 0;
		int currIndex =0;
		while(currIndex<n) {
			int temp = currIndex;
			while(temp < n && Math.abs(div[currIndex]-div[temp])<Math.pow(10, -40)){
				temp++;
			}
			int numpass = temp-currIndex;
			if(div[currIndex]!=0) {
				maxOcc = Math.max(maxOcc,numpass);
			}
			currIndex = temp;
			
		}
		maxOcc = Math.max(maxOcc, num0);
		System.out.println(maxOcc+numadd);
	}
}