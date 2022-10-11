import java.util.Scanner;

public class Main {
	static private Scanner sc;
	
	static public void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ms = 100100;
		int[] cost = new int[ms];
		int[] got = new int[ms];
		for(int i = 0; i < n; i++) {
			int num = sc.nextInt();
			//System.out.println("Got number: " + num);
			for(int j = 0, k = num; k > 0; j++, k /= 2) {
				cost[0]++;
				for(int jj = 0, kk = k; kk < ms; jj++, kk *= 2) {
					if(kk == k)
						continue;
					got[kk]++;
					cost[kk] += j + jj;
					//System.out.println("Going up to " + kk + ", cost " + (j + jj));
				}
				got[k]++;
				cost[k] += j;
				cost[0]++;
				//System.out.println("Going down, base is " + k + ", cost is " + j);
				while(k % 2 == 0) {
					k /= 2;
					j++;
					//System.out.println("Going down, base is " + k + ", cost is " + j);
					
					got[k]++;
					cost[k] += j;
					cost[0]++;
				}
			}
			got[0]++;
		}
		int ans = 1000000000;
		for(int i = 0; i < ms; i++) {
			if(cost[i] < ans && got[i] == n) {
				//System.out.println("got on " + i);
				ans = cost[i];
			}
		}
		for(int i = 0; i < 10; i++) {
			//System.out.println("(" + got[i] + ", " + cost[i] + ")");
		}
		System.out.println(ans);
	}
}