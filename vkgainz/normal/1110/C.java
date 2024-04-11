import java.util.Scanner;
import java.util.TreeSet;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		int a[] = new int[q];
		for(int i=0;i<q;i++) {
			a[i] = sc.nextInt();
		}
		TreeSet<Integer> x = new TreeSet<>();
		for(int i=1;i<=25;i++) {
			x.add((int) Math.pow(2,i)-1);
		}
		for(int i=0;i<q;i++) {
			if(x.contains(a[i])) {
				System.out.println(find(a[i]));
			}
			else {
				System.out.println(x.higher(a[i]));
			}
		}
	}
	static int find(int a) {
		for(int i=2;i<=Math.sqrt(a);i++) {
			if(a%i==0) {
				return a/i;
			}
		}
		return 1;
	}
}