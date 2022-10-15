import java.util.Scanner;

public class Solution {
	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		String e = sc.next();

		int sMin = getMin(s);
		int eMin = getMin(e);

		int midMin = (sMin + eMin) / 2;

		System.out.println(getTime(midMin));
	}

	private static int getMin(String s) {

		String[] arr = s.split(":");
		return Integer.parseInt(arr[0]) * 60 + Integer.parseInt(arr[1]);

	}

	private static String getTime(int p) {
		String h = (p / 60) + "";
		String m = (p % 60) + "";

		if (h.length() == 1) {
			h = "0" + h;
		}

		if (m.length() == 1) {
			m = "0" + m;
		}

		return h + ":" + m;

	}
}