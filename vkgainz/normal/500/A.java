import java.util.*;
public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b =sc.nextInt();
		int [] nums = new int[a-1];
		for(int i=0;i<a-1;i++) {
			nums[i] = sc.nextInt();
		}
		if(search(1,b,nums)) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
	
	public static boolean search(int index,int b,int [] nums) {
		if(index>b) return false;
		
		if(index==b) return true;
		
		return search(index+nums[index-1],b,nums);
	}
	
}