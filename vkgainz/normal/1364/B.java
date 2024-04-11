import java.util.ArrayList;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int p[] = new int[n];
			for(int i=0;i<n;i++) {
				p[i] = sc.nextInt();
			}
			boolean inc = true;
			ArrayList<Integer> idx = new ArrayList<Integer>();
			if(p[1]<p[0]) {
				inc = false;
			}
			idx.add(0);
			for(int i=1;i<n;i++) {
				if(inc) {
					if(p[i]<p[i-1]) {
						idx.add(i-1);
						inc = false;
					}
				}
				else {
					if(p[i]>p[i-1]) {
						idx.add(i-1);
						inc = true;
					}
				}
			}
			if(!idx.contains(n-1)) {
				idx.add(n-1);
			}
			sb.append(idx.size());
			sb.append("\n");
			for(int j=0;j<idx.size();j++) { 
//				System.out.println(idx.get(j));
				sb.append(p[idx.get(j)] + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}

}