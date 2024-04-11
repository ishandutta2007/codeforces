import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class F {
	static boolean [] used;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int a[] = new int[n];
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt();
			}
			int b[] = new int[n];
			for(int i=0;i<n;i++) {
				b[i] = sc.nextInt();
			}
			if(n%2==1 && b[n/2]!=a[n/2]){
				System.out.println("no");
				continue;
			}
			used = new boolean[n];
			boolean works = true;
			for(int i=0;i<n/2;i++) {
				int x = a[i];
				int y=  a[n-i-1];
				if(!inside(x,y,b)) {
					works = false;
				}
			}
			if(works) {
				System.out.println("yes");
			}
			else {
				System.out.println("no");
			}
		}
	}
	static boolean inside(int x,int y,int [] b) {
		int n = b.length;
		for(int i=0;i<n/2;i++) {
			if(!used[i] && ((b[i]==x && b[n-i-1]==y) || (b[n-i-1]==x && b[i]==y))){
				used[i] = true;
				return true;
			}
		}
		return false;
		
	}
}