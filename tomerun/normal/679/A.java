import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int[] ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
		int yes = 0;
		for (int i = 0; i < ps.length; ++i) {
			System.out.println(ps[i]);
			System.out.flush();
			String ans = sc.next();
			if (ans.equals("yes")) ++yes;
		}
		System.out.println(yes >= 2 ? "composite" : "prime");
	}

}