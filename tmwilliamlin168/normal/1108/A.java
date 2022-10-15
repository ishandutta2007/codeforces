//package Codeforces;
import java.util.*;

public class dpoints {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int l=0; l<n; l++) {
			int l1 = in.nextInt();
			int r1 = in.nextInt();
			int l2 = in.nextInt();
			int r2 = in.nextInt();
			if(l1 == l2)
				System.out.println(l1+" "+(l2+1));
			else
				System.out.println(l1+" "+l2);
		}
	}
}