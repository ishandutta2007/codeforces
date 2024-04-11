import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static int[] d, a;
	
	public static void main(String[] args) {
		Reader in = new Reader();
		n=in.nextInt();
		m=in.nextInt();
		d = new int[n];
		a = new int[m];
		for(int i=0; i<n; ++i)
			d[i]=in.nextInt();
		for(int i=0; i<m; ++i)
			a[i]=in.nextInt();
		
		int l=m, r=n, ans=-1;
		for(int i=0; i<m; ++i)
			l+=a[i];
		while(l<=r) {
			int mid=(l+r)/2;
			if(can(mid)) {
				ans=mid;
				r=mid-1;
			} else
				l=mid+1;
		}
		System.out.println(ans);
	}
	
	static boolean can(int days) {
		int[] lastExamDays = new int[m];
		Arrays.fill(lastExamDays, -1);
		for(int i=0; i<days; ++i)
			if(d[i]>0)
				lastExamDays[d[i]-1]=i;
		int[] d2 = new int[days];
		Arrays.fill(d2, -1);
		for(int i=0; i<m; ++i)
			if(lastExamDays[i]==-1)
				return false;
			else
				d2[lastExamDays[i]]=i;
		
		int daysLeft=0;
		Queue<Integer> subjects = new LinkedList<Integer>();
		for(int i=days-1; i>=0; --i) {
			if(d2[i]!=-1)
				subjects.add(d2[i]);
			else {
				if(daysLeft==0&&!subjects.isEmpty())
					daysLeft=a[subjects.poll()];
				if(daysLeft>0)
					--daysLeft;
			}
		}
		return daysLeft==0&&subjects.isEmpty();
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