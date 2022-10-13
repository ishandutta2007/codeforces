import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int [] heights = new int[4];
		for (int i=0;i<4;i++) {
			heights[i]=sc.nextInt();
		}
		Arrays.sort(heights);
		int distinct =4;
		for (int i=0;i<3;i++) {
			if (heights[i]==heights[i+1])
				distinct--;
		}
		System.out.println(4-distinct);
		
		
		
	}
}