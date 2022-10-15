import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=scan.nextInt();
		}
		Arrays.sort(a);
		int[] b=new int[n];
		int i=0,j=n-1,k=0;
		while(i<j) {
			b[i]=a[k++];
			b[j]=a[k++];
			i++;j--;
		}
		if(n%2!=0) {
			b[n/2]=a[n-1];
		}
		for(int q=0;q<b.length;q++) {
			System.out.print(b[q]+" ");
		}

	}

}