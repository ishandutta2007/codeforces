import java.util.Scanner;

public class compressstring {
	static String s;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		 s = sc.next();
		int [] dp = new int[n];
		dp[0] = a;
		for(int i=1;i<n;i++) {
			dp[i] = a+dp[i-1];
			if(!s.substring(0,i).contains(s.substring(i,i+1))){
				continue;
			}
			int insert = findSpot(0,i,i);
//			System.out.println(insert);
			for(int j=insert;j<=i;j++) {
				dp[i] = Math.min(dp[i],b+dp[j-1]);
			}
		}
//		for(int i=0;i<n;i++) {
//			System.out.print(dp[i] + " ");
//		}
		System.out.println(dp[n-1]);
	}

	private static int findSpot(int low, int hi, int fin) {
		// TODO Auto-generated method stub
		int mid = (low+hi)/2;
		if(mid==hi) {
			return hi; 
		}
		if(s.substring(0,mid).contains(s.substring(mid,fin+1))){
			return findSpot(low,mid,fin);
			
		}
		else {
			return findSpot(mid+1,hi,fin);
		}
		
	}
}