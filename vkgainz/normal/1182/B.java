import java.util.ArrayList;
import java.util.Scanner;

public class PlusfromPicture {
	static String[] grid;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int numFill = 0;
		grid = new String[h];
		for(int i=0;i<h;i++) {
			grid[i] = sc.next();
			for(int j=0;j<w;j++) {
				if(grid[i].charAt(j) == '*') {
					numFill++;
				}
			}
		}
		boolean found = false;
		for(int i=1;i<h-1;i++) {
			for(int j=1;j<w-1;j++) {
				if(grid[i].substring(j, j+1).equals("*") && isCandidate(i,j)) {
					int count=1;
					int temp = j;
					temp++;
					while(temp < w&& grid[i].charAt(temp) == '*') {
						count++;
						temp++;
					}
					temp=j-1;
					while(temp>=0 && grid[i].charAt(temp) == '*') {
						count++;
						temp--;
					}
					temp=i+1;
					while(temp<h && grid[temp].charAt(j) == '*' ) {
						count++;
						temp++;
					}
					temp=i-1;
					while(temp >=0 && grid[temp].charAt(j) =='*') {
						count++;
						temp--;
					}
					if(count==numFill++) {
						System.out.println("YES");
						return;
					}
					else {
						System.out.println("NO");
						return;
					}
				}
			}
		}
		System.out.println("NO");
	}
	static boolean isCandidate(int row, int col) {
		return (grid[row+1].charAt(col) == '*' && grid[row-1].charAt(col)=='*' && grid[row].charAt(col+1)=='*' && grid[row].charAt(col-1) == '*');
	}
	
}