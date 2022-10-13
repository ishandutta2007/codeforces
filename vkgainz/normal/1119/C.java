import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [] row1 = new int[n];
		int [] col1 = new int[m];
		int [] row2 = new int[n];
		int [] col2 =new int[m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int x = sc.nextInt();
				row1[i]+=x;
				col1[j]+=x;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int x = sc.nextInt();
				row2[i]+=x;
				col2[j]+=x;
			}
		}
		for(int i=0;i<n;i++) {
			row1[i]%=2;
			row2[i]%=2;
		}
		for(int i=0;i<m;i++) {
			col1[i]%=2;
			col2[i]%=2;
		}
		boolean works = true;
		for(int i=0;i<n;i++) {
			works = works&&(row1[i]==row2[i]);
		}
		for(int i=0;i<m;i++) {
			works = works&&(col1[i]==col2[i]);
		}
		if(works) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}