//package round77;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] str = in.next().toCharArray();
		int n = str.length;
		if(n % 2 == 1){
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < (n+1)/2;i++)sb.append('4');
			for(int i = 0;i < (n+1)/2;i++)sb.append('7');
			out.println(sb);
		}else{
			int f = 0;
			int s = 0;
			int[] h = new int[n];
			for(int i = 0;i < n;i++){
				if(str[i] <= '4' && f < n/2){
					f++;
					h[i] = 4;
					if(str[i] < '4'){
						StringBuilder sb = new StringBuilder();
						for(int k = 0;k <= i;k++)sb.append(h[k]);
						for(int k = 0;k < n/2-f;k++)sb.append('4');
						for(int k = 0;k < n/2-s;k++)sb.append('7');
						out.println(sb);
						return;
					}
				}else if(str[i] <= '7' && s < n/2){
					h[i] = 7;
					s++;
					if(str[i] < '7'){
						StringBuilder sb = new StringBuilder();
						for(int k = 0;k <= i;k++)sb.append(h[k]);
						for(int k = 0;k < n/2-f;k++)sb.append('4');
						for(int k = 0;k < n/2-s;k++)sb.append('7');
						out.println(sb);
						return;
					}
				}else{
					int j;
					for(j = i-1;j >= 0;j--){
						tr(j,f,s);
						if(h[j] == 4){
							if(str[j] < '4'){
								break;
							}
							f--;
							h[j] = 7;
							s++;
							if(s <= n/2)break;
							s--;
							h[j] = 0;
						}else{
							if(str[j] < '7'){
								break;
							}
							s--;
						}
					}
					tr(j,f,s);
					if(j == -1){
						StringBuilder sb = new StringBuilder();
						for(int k = 0;k < (n+2)/2;k++)sb.append('4');
						for(int k = 0;k < (n+2)/2;k++)sb.append('7');
						out.println(sb);
						return;
					}else{
						StringBuilder sb = new StringBuilder();
						for(int k = 0;k <= j;k++)sb.append(h[k]);
						for(int k = 0;k < n/2-f;k++)sb.append('4');
						for(int k = 0;k < n/2-s;k++)sb.append('7');
						out.println(sb);
						return;
					}
				}
			}
			
			StringBuilder sb = new StringBuilder();
			for(int k = 0;k < n;k++)sb.append(h[k]);
			out.println(sb);
		}
	}
	
	void run() throws Exception
	{
//		int n = 8;
//		StringBuilder sb = new StringBuilder();
//		Random r = new Random();
//		int[] y = {4,7};
//		for(int i = 0;i < n;i++){
//			sb.append(y[r.nextInt(2)]);
//		}
//		INPUT = sb.toString();
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}