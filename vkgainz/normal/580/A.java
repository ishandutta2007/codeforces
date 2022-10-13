import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] kefa = new int[n];
		for (int i=0;i<n;i++) {
			kefa[i] = sc.nextInt();
		}
		int count=1;
		int max = 1;
		for (int i=0;i<n-1;i++) {
			if (kefa[i+1] >=kefa[i]) {
				count++;
				if (count>max) {
					max=count;
				}
			}
			else if (kefa[i+1] < kefa[i]){
				if (count>max) {
					max=count;
				}
				count=1;
			}
		}
		
		
		System.out.println(max);
	}
}