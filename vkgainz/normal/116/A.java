import java.util.*;
public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] in = new int[n][2];
		for(int i = 0; i < n; i++){
			in[i][0] = sc.nextInt();
			in[i][1] = sc.nextInt();
		}
		int max =0;
		int sumTot = 0;
		
		for (int i=0;i<n;i++) {
			sumTot = sumTot+in[i][1]-in[i][0];
			if (sumTot > max) {
				max = sumTot;
			}
		}
			System.out.println(max);
	}
}