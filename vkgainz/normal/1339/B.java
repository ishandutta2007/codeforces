
import java.util.Arrays;
import java.util.Scanner;

public class sortedadjacentdifferences {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			int n = sc.nextInt();
			int [] vals = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
			}
			Arrays.sort(vals);
			int [] ret = new int[n];
			int counter = n-1;
			int l = 0;
			int r = n-1;
			while(counter>=0) {
				ret[counter] = vals[l];
				counter--;
				l++;
				if(counter>=0) {
					ret[counter] = vals[r];
					counter--;
					r--;
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int i=0;i<n-1;i++) {
				sb.append(ret[i] + " ");
			}
			sb.append(ret[n-1]);
			System.out.println(sb.toString());
			t--;
		}
	}
}