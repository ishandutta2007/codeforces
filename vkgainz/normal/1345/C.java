import java.util.HashSet;
import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t =sc.nextInt();
		while(t>0) {
			t--;
			int n= sc.nextInt();
			int [] vals = new int[n];
			int [] pos = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
				vals[i] = (n+vals[i])%n;
				
				pos[i] = i+vals[i];
				pos[i]%=n;
				pos[i] = (pos[i]+n)%n;
			}
			HashSet<Integer> set = new HashSet<Integer>();
			boolean w=  true;
			for(int i=0;i<n;i++) {
				if(set.contains(pos[i])) {
					w = false;
					break;
				}
				set.add(pos[i]);
				
			}
			if(w) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
}