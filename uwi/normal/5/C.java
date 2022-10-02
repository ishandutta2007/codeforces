//package round5;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = ")((())))(()())";
//	String INPUT = "(())()";
	String INPUT = "";
	
	void solve()
	{
		char[] str = in.next().toCharArray();
		int n = str.length;
		int[] hs = new int[2000001];
		Arrays.fill(hs, -1);
		int h = 1000000;
		BitSet valid = new BitSet();
		for(int i = 0;i < n;i++){
			hs[h] = i;
			if(str[i] == '('){
				h++;
			}else{
				hs[h] = -1;
				h--;
				if(hs[h] != -1){
					valid.set(hs[h]);
					valid.set(i);
				}
			}
		}
		
		int max = 0;
		int ct = 1;
		for(int i = valid.nextSetBit(0);i != -1;i = valid.nextSetBit(i + 1)){
			int j = valid.nextClearBit(i);
			if(max < j-i){
				max = j-i;
				ct = 1;
			}else if(max == j-i){
				ct++;
			}
			i = j;
		}
		
		out.println(max + " " + ct);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}