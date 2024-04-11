import java.util.Scanner;
import java.util.Arrays;

final public class Main {
	static private Scanner sc;
	static public void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ms = 1000000;
		int[] f = new int[ms];
		int[] l = new int[ms];
		int[] r = new int[ms];
		for(int i = 1; i <= n; i++) {
			int num = sc.nextInt() - 1;
			if(f[num] == 0)
				l[num] = i;
			r[num] = i;
			f[num]++;
		}
		int ans = 0;
		for(int i = 0; i < ms; i++) {
			if(f[i] > f[ans] || (f[i] == f[ans] && r[i] - l[i] < r[ans] - l[ans])) {
				ans = i;
			}
		}
		System.out.println(l[ans] + " " + r[ans]);
	}
}