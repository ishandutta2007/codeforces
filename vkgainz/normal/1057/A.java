import java.util.ArrayList;
import java.util.Scanner;

public class bmailcomputernetwork {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] vals = new int[n-1];
		
		for(int i=0;i<n-1;i++) {
			vals[i] = sc.nextInt();
		} //gets i+2th
		int a = n;
		ArrayList<Integer> add = new ArrayList<Integer>();
		while(a !=1) {
			add.add(a);
			a = vals[a-2];
		}
		System.out.println(1);
		for(int i=add.size()-1;i>=0;i--) {
			System.out.println(add.get(i));
		}
	}
}