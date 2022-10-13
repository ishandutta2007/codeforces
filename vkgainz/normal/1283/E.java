import java.util.Arrays;
import java.util.Scanner;

public class newyearparties {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] vals = new int[n];
		for(int i=0;i<n;i++) { vals[i] = sc.nextInt();}
		Arrays.sort(vals);
		int [][] mindp = new int[n][3];
		mindp[0][0] = 1; mindp[0][1] = 1; mindp[0][2] = 1;
		for(int i=1;i<n;i++) {
			if(vals[i-1]==vals[i]) {
				mindp[i][0] = mindp[i-1][0];
				mindp[i][1] = Math.min(mindp[i-1][0]+1,mindp[i-1][1]);
				mindp[i][2] = Math.min(Math.min(mindp[i-1][0]+1,mindp[i-1][1]+1),mindp[i-1][2]);
			}
			else if(vals[i-1]+1==vals[i]) {
				mindp[i][0] = Math.min(mindp[i-1][1],mindp[i-1][0]+1);
				mindp[i][1]  = Math.min(Math.min(mindp[i-1][0]+1,mindp[i-1][1]+1),mindp[i-1][2]);
				mindp[i][2] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
			}
			else if(vals[i-1]+2==vals[i]) {
				mindp[i][0] = Math.min(Math.min(mindp[i-1][0]+1,mindp[i-1][1]+1),mindp[i-1][2]);
				mindp[i][1] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
				mindp[i][2] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
			}
			else {
				mindp[i][0] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
				mindp[i][1] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
				mindp[i][2] = 1 + Math.min(Math.min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2]);
			}
		}
		int [][] maxdp = new int[n][3];
		maxdp[0][0] = 1; maxdp[0][1] = 1;maxdp[0][2] = 1;
		for(int i=1;i<n;i++) {
			if(vals[i-1]==vals[i]) {
				maxdp[i][0] = maxdp[i-1][0];
				maxdp[i][1] = Math.max(maxdp[i-1][0]+1,maxdp[i-1][1]);
				maxdp[i][2] = Math.max(Math.max(maxdp[i-1][0]+1,maxdp[i-1][1]+1),maxdp[i-1][2]);
			}
			else if(vals[i-1]+1==vals[i]) {
				maxdp[i][0] = Math.max(maxdp[i-1][1],maxdp[i-1][0]+1);
				maxdp[i][1]  = Math.max(Math.max(maxdp[i-1][0]+1,maxdp[i-1][1]+1),maxdp[i-1][2]);
				maxdp[i][2] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
			}
			else if(vals[i-1]+2==vals[i]) {
				maxdp[i][0] = Math.max(Math.max(maxdp[i-1][0]+1,maxdp[i-1][1]+1),maxdp[i-1][2]);
				maxdp[i][1] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
				maxdp[i][2] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
			}
			else {
				maxdp[i][0] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
				maxdp[i][1] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
				maxdp[i][2] = 1 + Math.max(Math.max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2]);
			}
		}

		
			System.out.println(Math.min(Math.min(mindp[n-1][0],mindp[n-1][1]),mindp[n-1][2]));
			System.out.println(Math.max(Math.max(maxdp[n-1][0],maxdp[n-1][1]),maxdp[n-1][2]));
		
	}
}