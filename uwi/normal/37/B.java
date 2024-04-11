//package round37;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 10 3 100 3 99 1";
//	String INPUT = "2 100 10 100 11 90 9";
//	String INPUT = "3 100 2 100 1 100 1 100 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int max = ni();
		int reg = ni();
		int[] pow = new int[n];
		int[] dmg = new int[n];
		for(int i = 0;i < n;i++){
			pow[i] = ni();
			dmg[i] = ni();
		}
		
		int hp = max;
		BitSet used = new BitSet();
		StringBuilder sb = new StringBuilder();
		int t = 0;
		int ldm = 0;
		for(t = 0;t < 4000;t++){
			int mdm = 0;
			int mj = -1;
			for(int j = 0;j < n;j++){
				if(hp * 100 <= max * pow[j] && !used.get(j)){
					if(mdm < dmg[j]){
						mdm = dmg[j];
						mj = j;
					}
				}
			}
			if(mj != -1){
				used.set(mj);
				ldm += mdm;
				sb.append(t + " " + (mj+1));
				sb.append('\n');
			}
			hp -= ldm;
			hp += reg;
			if(hp <= 0){
				break;
			}
			hp = Math.min(hp, max);
		}
		if(t == 4000){
			out.println("NO");
		}else{
			out.println("YES");
			out.println((t+1) + " " + used.cardinality());
			out.println(sb);
		}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}