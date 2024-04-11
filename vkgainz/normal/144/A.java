import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] heights = new int[n];
		for (int i=0;i<n;i++) {
			heights[i] = sc.nextInt();
		}
		//find the minimum and maximum
		int min=2000;
		int max=0;
		for (int i=0;i<n;i++) {
			if (heights[i] < min) {
				min=heights[i];
			}
			if (heights[i] > max) {
				max=heights[i];
			}
		}
		//find positions of minimum and maximum
		int maxPos =0;
		int minPos =0;
		for (int i=0;i<n;i++) {
			if (heights[i] == max) {
				maxPos = i;
				break;
			}
		}
		for (int i=n-1;i>0;i--) {
			if (heights[i] == min) {
				minPos =i;
				break;
			}
		}
		//if maxmium pos > minimum position, returns stuff
		if (maxPos > minPos) {
			System.out.println(maxPos+n-minPos-2);
		}
		else {
			System.out.println(maxPos+n-minPos-1);
		}
	}
}