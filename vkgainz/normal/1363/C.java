import java.util.ArrayList;
import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc=  new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int x = sc.nextInt()-1;
			ArrayList<Integer>[] tree = new ArrayList[n];
			for(int i=0;i<n;i++) tree[i] = new ArrayList<>();
			for(int i=0;i<n-1;i++) {
				int a = sc.nextInt()-1;
				int b = sc.nextInt()-1;
				tree[a].add(b);
				tree[b].add(a);
			}
			if(tree[x].size()<=1 || n==1) {
				System.out.println("Ayush");
			}
			else {
				if((n-2)%2==0) {
					System.out.println("Ayush");
				}
				else {
					System.out.println("Ashish");
				}
			}
		}
	}
}