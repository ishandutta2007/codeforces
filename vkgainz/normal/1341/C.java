import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc=  new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int [] appear = new int[n+1];
			for(int i=0;i<n;i++) {
				appear[sc.nextInt()] = (i+1);
			}
//			System.out.println(appear[2]);
			boolean work = true;
			int last = n;
			
			int [] permutation = new int[n+1];
			
			for(int l=1;l<=n;l++) {
				if(!work) break;
				permutation[appear[l]] = l;
				if(appear[l]==last) {
					last--;
					continue;
				}
				for(int r=l+1;r<=l+last-appear[l];r++) { //whats it bound?
//					System.out.println(r + " " + appear[r] + " " + last);
					if(appear[r]==appear[l]+r-l) {
						permutation[appear[r]] = r;
					}
					else {
						work = false;
						break;
					}
					
				}
				int temp = last;
				last = appear[l]-1;

				l+=temp-appear[l];
			}
			
			
			
			
			
			if(work) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}
}