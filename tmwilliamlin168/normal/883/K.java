import java.io.*;
import java.util.*;

public class Main {
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		int[] s = new int[n], g = new int[n], min = new int[n], max = new int[n];
		for(int i=0; i<n; ++i) {
			s[i]=in.nextInt();
			g[i]=in.nextInt();
			min[i]=s[i];
			max[i]=s[i]+g[i];
		}
		for(int i=1; i<n; ++i) {
			min[i]=Math.max(min[i-1]-1, min[i]);
			max[i]=Math.min(max[i-1]+1, max[i]);
		}
		for(int i=n-2; i>=0; --i) {
			min[i]=Math.max(min[i+1]-1, min[i]);
			max[i]=Math.min(max[i+1]+1, max[i]);
		}
		for(int i=0; i<n; ++i) {
			if(min[i]>max[i]) {
				System.out.println(-1);
				return;
			}
		}
		long ans=0;
		for(int i=0; i<n; ++i)
			ans+=max[i]-s[i];
		out.println(ans);
		for(int i=0; i<n; ++i)
			out.print(max[i]+" ");
		out.close();
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