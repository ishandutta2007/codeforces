import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long x = sc.nextLong();
		long d[] = new long[n];
		for(int i=0;i<n;i++) {
			d[i] = sc.nextLong();
//			d[i] = 1000000;
		}
		int r = n-1;
		int l = n-1;
		long currSum = 0;
		long max = 0;
		long currInt =0;
		while(r>=0) {

			while((currSum+d[l])<=x) {
				currSum+=d[l];
				long temp = d[l]*(d[l]+1);
				temp/=2;
				currInt+=temp;
				l--;
				if(l<0) l = n-1;

			}
			long left = x-currSum;
			long add = left*(2*d[l]-left+1);
			add/=2;
			currInt+=add;

			max = Math.max(max,currInt);
			long sub = d[r]*(d[r]+1);
			sub/=2;
			if(d[r]<=x) {
				currInt-=sub;
			}
			currInt-=add;
			if(d[r]<=x) {
				currSum-=d[r];
			}
			else {
				currSum = 0;
				l--;
			}
			r--;
		}
		System.out.println(max);
	}
}