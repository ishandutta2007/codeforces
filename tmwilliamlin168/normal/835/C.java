import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Reader in = new Reader();
		PrintWriter out = new PrintWriter(System.out);
		int n=in.nextInt(), q=in.nextInt(), c=in.nextInt();
		int[][][] states = new int[c+1][101][101];
		for(int i=0; i<n; ++i) {
			int x=in.nextInt(), y=in.nextInt(), s=in.nextInt();
			for(int j=0; j<=c; ++j)
				states[j][x][y]+=(s+j)%(c+1);
		}
		int[][][] cumSum = new int[c+1][101][101];
		for(int i=0; i<=c; ++i)
			for(int x=1; x<=100; ++x)
				for(int y=1; y<=100; ++y)
					cumSum[i][x][y]=cumSum[i][x-1][y]+cumSum[i][x][y-1]-cumSum[i][x-1][y-1]+states[i][x][y];
		for(int i=0; i<q; ++i) {
			int t=in.nextInt()%(c+1), x1=in.nextInt(), y1=in.nextInt(), x2=in.nextInt(), y2=in.nextInt();
			out.println(cumSum[t][x2][y2]-cumSum[t][x1-1][y2]-cumSum[t][x2][y1-1]+cumSum[t][x1-1][y1-1]);
		}
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