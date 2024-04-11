import java.io.*;
import java.util.*;

public class A{

	static int []a;
	static int n,days;
	static int [][]memo;
	static int dp(int idx,int put,int day,int minus) {
		if(idx==n)
			return 0;
		if(memo[idx][put]!=-1)
			return memo[idx][put];
		int ans=dp(idx+1,put,day,minus);
		int x=a[idx];
		if(x-minus>0) {
			boolean done=(put+1)%days==0;
			ans=Math.max(ans, dp(idx+1,put+1,done?0:day,done?minus+1:minus)+x-minus);
		}
		return memo[idx][put]=ans;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner();
		PrintWriter out=new PrintWriter(System.out);
		n=sc.nextInt();
		int m=sc.nextInt();
		a=new int [n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		Arrays.sort(a);
		int ans=-1;
		memo=new int [n][n];
		for(days=1;days<=n;days++) {
			for(int []x:memo)
				Arrays.fill(x, -1);
			int dp=dp(0, 0, 0,0);
//			System.out.println(days+" "+dp);
			if(dp>=m) {
				ans=days;
				break;
			}
		}
		out.println(ans);
		out.close();
	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		Scanner(String fileName) throws FileNotFoundException{
			br=new BufferedReader(new FileReader(fileName));
		}
		String next() throws IOException {
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		String nextLine() throws IOException {
			return br.readLine();
		}
		int nextInt() throws IOException{
			return Integer.parseInt(next());
		}
		long nextLong()  throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}
	}
}