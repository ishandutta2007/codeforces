import java.io.*;
import java.util.*;
public class Main {
	static String[] types;
	public static void main(String[] args) throws IOException {
		types = new String[]{"S", "M", "L", "XL", "XXL"};
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[5];
		for(int i = 0; i < 5; i++) {
			list[i] = Integer.parseInt(st.nextToken());
		}
		int qq = Integer.parseInt(br.readLine());
		while(qq-- > 0) {
			String now = br.readLine();
			int curr = find(now);
			for(int k = 0; true; k++)
				if(valid(curr+k) && list[curr+k]-- > 0) {
					System.out.println(types[curr+k]);
					break;
				}
				else if(valid(curr-k) && list[curr-k]-- > 0) {
					System.out.println(types[curr-k]);
					break;
				}
		}
	}
	public static boolean valid(int x) {
		return x >= 0 && x < 5;
	}
	public static int find(String s) {
		for(int k = 0; true; k++) {
			if(s.equals(types[k]))
				return k;
		}
	}
}