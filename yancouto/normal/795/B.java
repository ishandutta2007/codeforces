import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class B {
	public static class Cup implements Comparable<Cup> {
		int c, w;
		public Cup(int a, int b) { c = a; w = b; }
		public int compareTo(Cup other) {
			if(c != other.c) return other.c - c;
			return w - other.w;
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		long d = in.nextLong();
		ArrayList<Cup> l1 = new ArrayList<>(), l2 = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			int c = in.nextInt();
			int w = in.nextInt();
			l1.add(new Cup(c, w));
		}
		for(int i = 0; i < m; i++) {
			int c = in.nextInt();
			int w = in.nextInt();
			l2.add(new Cup(c, w));
		}
		Collections.sort(l1);
		Collections.sort(l2);
		if(l1.get(0).w + l2.get(0).w > d) {
			System.out.println("0");
		} else {
			d -= l1.get(0).w + l2.get(0).w;
			long tot = l1.get(0).c + l2.get(0).c;
			int i = 1, j = 1;
			while(j < m && l2.get(j).w <= d) {
				d -= l2.get(j).w;
				tot += l2.get(j).c;
				j++;
			}
			long ans = tot;
			for(i = 1; i < n; i++) {
				tot += l1.get(i).c;
				d -= l1.get(i).w;
				while(d < 0 && j > 1) {
					j--;
					d += l2.get(j).w;
					tot -= l2.get(j).c;
				}
				if(d >= 0 && tot > ans) ans = tot;
			}
			System.out.println(ans);
		}
	}
}