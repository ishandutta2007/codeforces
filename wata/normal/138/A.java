import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	boolean[] vowel = new boolean[256];
	{
		vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = true;
	}
	
	boolean check(char[] cs, char[] ds, int k) {
		int p1 = cs.length - 1, p2 = ds.length - 1;
		while (p1 >= 0 && p2 >= 0 && cs[p1] == ds[p2]) {
			if (vowel[cs[p1]]) {
				if (--k == 0) return true;
			}
			p1--;
			p2--;
		}
		return false;
	}
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		boolean aabb = true, abab = true, abba = true;
		for (int i = 0; i < n; i++) {
			char[][] cs = new char[4][];
			for (int j = 0; j < 4; j++) {
				cs[j] = sc.next().toCharArray();
			}
			if (!check(cs[0], cs[1], k) || !check(cs[2], cs[3], k)) aabb = false;
			if (!check(cs[0], cs[2], k) || !check(cs[1], cs[3], k)) abab = false;
			if (!check(cs[0], cs[3], k) || !check(cs[1], cs[2], k)) abba = false;
		}
		if (aabb && abab && abba) System.out.println("aaaa");
		else if (aabb) System.out.println("aabb");
		else if (abab) System.out.println("abab");
		else if (abba) System.out.println("abba");
		else System.out.println("NO");
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}