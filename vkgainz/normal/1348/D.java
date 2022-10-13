import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		while(t>0) {
			t--;
			int n= sc.nextInt();
			int x = (n+1);
			int log = 0;
			for(int i=0;i<=31;i++) {
				if(Math.pow(2,i)>=x) {
					log = i;
					break;
				}
			}
			int d = log-1;
//			System.out.println(d);
			int make = n-1-d;
			int lessThan = 1;
			int [] arr = new int[d];
			for(int i=0;i<d;i++) {
				arr[i] = Math.min(lessThan,make/(d-i));
				make-=arr[i]*(d-i);
				lessThan+=arr[i];
			}
			sb.append(d);
			sb.append("\n");
			for(int i=0;i<d;i++) {
				sb.append(arr[i] + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}