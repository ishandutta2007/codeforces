import java.util.Scanner;

public class kanaanddragonquestgame {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t= sc.nextInt();
		while(t>0) {
			int x = sc.nextInt();
			int m = sc.nextInt();
			int n = sc.nextInt();
			for(int i=0;i<m;i++) {
				if(x/2+10>=x) {
					break;
				}
				x = x/2+10;
			}
			for(int i=0;i<n;i++) {
				x-=10;
			}
			if(x<=0) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
			t--;
		}
	}
}