import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		while(t>0) {
			t--;
			int n= sc.nextInt();
			int k = sc.nextInt();
			int [] arr = new int[n];
			for(int i=0;i<n;i++) {
				arr[i] = sc.nextInt();
			}
			HashSet<Integer> set = new HashSet<Integer>();
			for(int i=0;i<n;i++) {
				set.add(arr[i]);
			}
			if(set.size()>k) {
				sb.append(-1);
				sb.append("\n");
				continue;
			}
			ArrayList<Integer> x = new ArrayList<Integer>();
			for(int r : set) {
				x.add(r);
			}
			int []res = new int[n*k];
			for(int i=0;i<n;i++) {
				for(int j=0;j<k;j++) {
					if(j>=x.size()) {
						res[k*i+j] = x.get(0);
					}
					else {
						res[k*i+j] = x.get(j);
					}
				}
			}
			
			
			
			
			
			sb.append(res.length);
			sb.append("\n");
			for(int i=0;i<res.length-1;i++) {
				sb.append(res[i] + " ");
			}
			sb.append(res[res.length-1]);
			sb.append("\n");
		}
		System.out.println(sb.toString());
			
	}
}