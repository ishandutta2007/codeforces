//package round50;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		char[] p = in.next().toCharArray();
		char[] sh = in.next().toCharArray();
		int[] ret = new int[n];
		Arrays.fill(ret, (1<<k)-1);
		BitSet stock = new BitSet();
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			int code = (1<<k)-1;
			for(int j = 0;j <= i && j < sh.length;j++){
				if(sh[j] == '1' && i < j + p.length){
					code &= 1<<(p[i-j]-'a');
				}
			}
			if(code == 0){
				out.println("No solution");
				return;
			}
			for(int j = 0;j <= i && j < sh.length;j++){
				if(sh[j] == '0' && i < j + p.length && !stock.get(j)){
					int nc = code & (~(1<<(p[i-j]-'a')));
					if(nc == 0)continue;
					code = nc;
					stock.set(j);
				}
			}
			for(int j = 0;j < k;j++){
				if(((code>>j)&1) == 1){
					sb.append((char)('a'+j));
					break;
				}
			}
		}
		
		for(int j = 0;j < sh.length;j++){
			if(sh[j] == '0'){
				if(!stock.get(j)){
					out.println("No solution");
					return;
				}
			}
		}
		
		out.println(sb.toString());
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}