import java.io.*;
import java.util.*;
public class C63 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Set<String> can = new HashSet<String>();
		for(int i = 0; i < 10000; i++)		{
			String s = Integer.toString(i);
			while(s.length() < 4)
				s = '0'+s;
			if(valid(s))
				can.add(s);
		}
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)	{
			Set<String> now = new HashSet<String>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			String first = st.nextToken();
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			for(String ss: can)	{
				int[] list = compute(ss, first);
				if(list[0] == a && list[1] == b)
					now.add(ss);
			}
			can = now;
		}
		if(can.size() == 0)
			System.out.println("Incorrect data");
		else if(can.size() > 1)
			System.out.println("Need more data");
		else
			for(String ss: can)
				System.out.println(ss);
	}
	public static boolean valid(String s)	{
		Set<Character> can = new HashSet<Character>();
		can.add(s.charAt(0));
		can.add(s.charAt(1));
		can.add(s.charAt(2));
		can.add(s.charAt(3));
		return can.size() == 4;
	}
	public static int[] compute(String real, String guess) {
		int p = 0, c = 0;
		for (int i = 3; i >= 0; i--) {
			if (real.charAt(i) == guess.charAt(i)) {
				p++;
				real = real.substring(0, i) + real.substring(i + 1);
				guess = guess.substring(0, i) + guess.substring(i + 1);
			}
		}
		for (int i = guess.length() - 1; i >= 0; i--) {
			if (real.indexOf(guess.charAt(i)) != -1) {
				c++;
				int j = real.indexOf(guess.charAt(i));
				real = real.substring(0, j) + real.substring(j + 1);
				guess = guess.substring(0, i) + guess.substring(i + 1);
			}
		}
		return new int[]{p, c};
	}
}