import java.util.Scanner;

public class D {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		sc.nextLine();
		int ans = 0;
		int prevTime = 25 * 60;
		int count = 0;
		for (int i = 0; i < N; ++i) {
			String line = sc.nextLine();
			int time = getTime(line);
			if (time == prevTime) {
				if (count == 10) {
					++ans;
					count = 1;
				} else {
					++count;
				}
			} else if (time > prevTime) {
				prevTime = time;
				count = 1;
			} else {
				prevTime = time;
				++ans;
				count = 1;
			}
		}
		System.out.println(ans);
	}

	static int getTime(String line) {
		int hour = (line.charAt(1) - '0') * 10 + (line.charAt(2) - '0');
		if (hour == 12) {
			hour = 0;
		}
		int time = (line.charAt(4) - '0') * 10 + (line.charAt(5) - '0');
		boolean pm = line.charAt(7) == 'p';
		if (pm) {
			hour += 12;
		}
		return (hour * 60 + time) % (24 * 60);
	}
}