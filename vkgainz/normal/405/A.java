import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] heights = new int[n];
		for (int i=0;i<n;i++) {
			heights[i] = sc.nextInt();
		}
		Arrays.sort(heights);
		for(int i=0; i<n; i++)
			   System.out.println(heights[i]);
		
	}
}