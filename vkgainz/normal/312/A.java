import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class susbus {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(sc.readLine());

		for (int i = 0; i < n; i++) {
			String s = sc.readLine();
			if (s.length() < 5)
				System.out.println("OMG>.< I don't know!");
			else {
				String sub = s.substring(s.length() - 5);
				String first = s.substring(0, 5);
				if (sub.equals("lala.") && first.equals("miao."))
					System.out.println("OMG>.< I don't know!");
				else if (sub.equals("lala."))
					System.out.println("Freda's");

				else if (first.equals("miao."))
					System.out.println("Rainbow's");

				else
					System.out.println("OMG>.< I don't know!");
			}
		}
	}
}