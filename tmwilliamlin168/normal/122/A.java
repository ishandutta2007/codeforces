import java.io.*;
import java.util.*;

public class A {
	static List<Integer> lucky = new ArrayList<Integer>();

	public static void main(String[] args) {
		recur(4);
		recur(7);
		Reader in = new Reader();
		int n=in.nextInt();
		for(int div : lucky) {
			if(n%div==0) {
				System.out.println("YES");
				System.exit(0);
			}
		}
		System.out.println("NO");
	}
	
	static  void recur(int x) {
		if(x>1000)
			return;
		lucky.add(x);
		recur(x*10+4);
		recur(x*10+7);
	}
	
	static class Reader {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(Exception e) {}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
}