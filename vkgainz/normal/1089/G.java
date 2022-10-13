
import java.util.*;
public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] days = new int[n];
		int [][] times = new int[n][7];
		//eve values store k, odd values, store a_i
		for (int i=0;i<n;i++) {
			days[i]=sc.nextInt();
			for (int j=0;j<7;j++) {
				times[i][j] = sc.nextInt();
			}
		}
		for (int i=0;i<n;i++) {
			int numstudy = days[i];
			if(numstudy%numOnes(times[i]) !=0){
				int numweeks = (numstudy/numOnes(times[i]));
				int numdays = numweeks*7;
				int nib = numstudy%numOnes(times[i]);
				int extra = determineLeastDistance(times[i],numstudy%numOnes(times[i]));
				System.out.println(numdays+extra);
			}
			else {
				int numweeks = (numstudy/numOnes(times[i]))-1;
				int numdays =numweeks*7;
				int nib = numstudy%numOnes(times[i]);
				int extra=determineLeastDistance(times[i],numOnes(times[i]));
				System.out.println(numdays+extra);

			}
		}

	}
	public static int determineLeastDistance(int [] nums, int count) {
	   int nibba = 0;
		int [] doublenums = new int[2*nums.length];
		for (int i=0;i<nums.length;i++) {
			doublenums[i] = nums[i];
			doublenums[i+nums.length]=nums[i];
		}
		int min =nums.length;
		if(count==1 || count==0) return 1;
		else {
			for (int i=0;i<nums.length;i++) {
				if(doublenums[i]==1) {
				  nibba = count;
				nibba--;
					for (int j=i+1;j<doublenums.length;j++) {
						if(doublenums[j]==1) nibba--;
						if(nibba==0) {
							min = Math.min(min, j-i+1);
						}
					}
				}
			}
		}
		return min;
	}
	public static int numOnes(int [] nums) {
		int count=0;
		for (int i=0;i<nums.length;i++) {
			if(nums[i] == 1) count++;
		}
		return count;
	}

}