using System;

public class Test {
	public static void Main() {
		string[] buf = Console.ReadLine().Split(' ');
		int n = int.Parse(buf[0]);
		string[] buf2 = Console.ReadLine().Split(' ');
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			int a = int.Parse(buf2[i]);
			if (a % 2 == 0) {
				x++;
			} else {
				y++;
			}
		}
		if (x < y) {
			y -= x;
			Console.WriteLine("{0}", x + (y / 3));
		} else {
			Console.WriteLine("{0}", y);
		}
	}
}