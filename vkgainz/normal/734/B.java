import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int [] numbers = new int[4];
		for (int i=0;i<4;i++) {
			numbers[i] = sc.nextInt();
		}
		int min = Math.min(numbers[0], numbers[2]);
		int totmin = Math.min(min, numbers[3]);
		int minasdf = Math.min(numbers[0]-totmin, numbers[1]);
		if (minasdf > 0) {
			System.out.println(256*totmin+32*minasdf);
		}
		else {
			System.out.println(256*totmin);
		}
	}
}