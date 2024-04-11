import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		Reader in = new Reader();
		int n=in.nextInt();
		if(n%2==0)
			System.out.println(3*n/2);
		else
			System.out.println(n+n/2);
		for(int i=2; i<=n; i+=2)
			System.out.print(i+" ");
		for(int i=1; i<=n; i+=2)
			System.out.print(i+" ");
		for(int i=2; i<=n; i+=2)
			System.out.print(i+" ");
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