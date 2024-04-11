import java.io.*;
import java.util.*;

public class MainB {
	
	public static void main(String[] args) {
		Reader in = new Reader();
		PrintWriter out = new PrintWriter(System.out);
		int n=in.nextInt();
		int[] xor1 = new int[n], xor2 = new int[n];
		for(int i=0; i<n; ++i) {
			out.println("? "+i+" 0");
			out.flush();
			xor1[i]=in.nextInt();
		}
		for(int i=0; i<n; ++i) {
			out.println("? "+i+" "+i);
			out.flush();
			xor2[i]=in.nextInt();
		}
		//out.flush();
		int[] perm = null;
		/*for(int i=0; i<n; ++i) {
			xor1[i] = in.nextInt();
			if(xor1[i]==-1)
				System.exit(0);
		}
		for(int i=0; i<n; ++i) {
			xor2[i] = in.nextInt();
			if(xor2[i]==-1)
				System.exit(0);
		}*/
		int cnt=0;
		for(int i=0; i<n; ++i) {
			int[] cPerm = new int[n];
			cPerm[0]=i;
			boolean works=true;
			for(int j=1; j<n; ++j) {
				cPerm[j]=i^xor1[0]^xor1[j];
				if(cPerm[j]>=n) {
					works=false;
					break;
				}
			}
			if(works) {
				int[] iPerm = new int[n];
				for(int j=0; j<n; ++j)
					iPerm[cPerm[j]]=j;
				for(int j=0; j<n; ++j) {
					if((cPerm[j]^iPerm[j])!=xor2[j]) {
						works=false;
						break;
					}
				}
			}
			if(works) {
				++cnt;
				perm=cPerm;
				//System.out.println(Arrays.toString(cPerm));
			}
		}
		out.println("!");
		out.println(cnt);
		for(int i=0; i<n; ++i)
			out.print(perm[i]+" ");
		out.println();
		out.flush();
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