//package round33;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "uayd uxxd 3 a x 8 x y 13 d c 3";
//	private String INPUT = "a b 3 a b 2 a b 3 b a 5";
//	private String INPUT = "abc bca 6 a b 4 a b 7 b a 8 c b 11 c a 3 a c 0";
	private String INPUT = "";
	
	public void solve()
	{
		char[] s = in.next().toCharArray();
		char[] t = in.next().toCharArray();
		
		if(s.length != t.length){
			out.println(-1);
			return;
		}
		int n = ni();
		int M = 26;
		int[][] w = new int[M][M];
		for(int i = 0;i < M;i++){
			Arrays.fill(w[i], Integer.MAX_VALUE);
			w[i][i] = 0;
		}
		for(int i = 0;i < n;i++){
			char a = in.next().charAt(0);
			char b = in.next().charAt(0);
			int wi = ni();
			w[a-'a'][b-'a'] = Math.min(w[a-'a'][b-'a'], wi);
		}
		
		for(int k = 0;k < M;k++){
			for(int i = 0;i < M;i++){
				for(int j = 0;j < M;j++){
					if(w[i][k] < Integer.MAX_VALUE && w[k][j] < Integer.MAX_VALUE && w[i][j] > w[i][k] + w[k][j]){
						w[i][j] = w[i][k] + w[k][j];
					}
				}
			}
		}
		
		int[][] d = new int[M][M];
		int[][] st = new int[M][M];
		for(int i = 0;i < M;i++){
			for(int j = 0;j < M;j++){
				int min = Integer.MAX_VALUE;
				int stc = -1;
				for(int k = 0;k < M;k++){
					if(w[i][k] < Integer.MAX_VALUE && w[j][k] < Integer.MAX_VALUE && min > w[i][k] + w[j][k]){
						min = w[i][k] + w[j][k];
						stc = k;
					}
				}
				d[i][j] = min;
				st[i][j] = stc;
			}
		}
		
		long sum = 0;
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < s.length;i++){
			if(s[i] != t[i]){
				if(d[s[i]-'a'][t[i]-'a'] == Integer.MAX_VALUE){
					out.println(-1);
					return;
				}
				sum += d[s[i]-'a'][t[i]-'a'];
				sb.append((char)('a' + st[s[i]-'a'][t[i]-'a']));
			}else{
				sb.append(s[i]);
			}
		}
		out.println(sum);
		out.println(sb.toString());
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		Random r = new Random();
//		for(int i = 0;i < 100000;i++){
//			sb.append((char)('a' + r.nextInt(24)));
//		}
//		sb.append(' ');
//		for(int i = 0;i < 100000;i++){
//			sb.append((char)('a' + r.nextInt(24)));
//		}
//		sb.append(' ');
//		sb.append("500 ");
//
//		for(int i = 0;i < 500;i++){
//			sb.append((char)('a' + r.nextInt(24)));
//			sb.append(' ');
//			sb.append((char)('a' + r.nextInt(24)));
//			sb.append(' ');
//			sb.append(r.nextInt(101));
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}