import java.util.Scanner;

public class basketball {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int [][] heights  =new int[n][2];
		for(int i=0;i<n;i++) {
			heights[i][0] = sc.nextInt();
			
		}
		for(int i=0;i<n;i++) {
			heights[i][1] = sc.nextInt();
		}
		long [] up = new long[n];
		long [] down = new long[n];
		up[0] = heights[0][0];
		down[0] = heights[0][1];
		for(int i=1;i<n;i++) {
			up[i] = Math.max(heights[i][0]+down[i-1],up[i-1]);
			down[i] = Math.max(heights[i][1]+up[i-1],down[i-1]);
		}
		
		System.out.println(Math.max(up[n-1],down[n-1]));
	}
}