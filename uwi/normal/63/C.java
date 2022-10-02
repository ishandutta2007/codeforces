//package round59;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		BitSet bs = new BitSet();
		for(int i = 0;i <= 9;i++){
			for(int j = 0;j <= 9;j++){
				if(i == j)continue;
				for(int k = 0;k <= 9;k++){
					if(i == k || j == k)continue;
					for(int l = 0;l <= 9;l++){
						if(i == l || j == l || k == l)continue;
						bs.set(i*1000+j*100+k*10+l);
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			char[] a = in.next().toCharArray();
			int b = ni();
			int c = ni();
			for(int j = bs.nextSetBit(0);j != -1;j = bs.nextSetBit(j + 1)){
				if(!match(j, a, b, c)){
					bs.clear(j);
				}
			}
		}
		
		if(bs.cardinality() == 0){
			out.println("Incorrect data");
		}else if(bs.cardinality() == 1){
			out.printf("%04d\n", bs.nextSetBit(0));
		}else{
			out.println("Need more data");
		}
	}
	
	boolean match(int j, char[] a, int b, int c)
	{
		int[] ctj = new int[10];
		int[] cta = new int[10];
		int m = 0;
		for(int i = 0;i < 4;i++){
			ctj[j%10]++;
			cta[a[3-i]-'0']++;
			if(j%10 == a[3-i]-'0'){
				m++;
			}
			j /= 10;
		}
		int mc = -m;
		for(int i = 0;i < 10;i++){
			mc += Math.min(ctj[i], cta[i]);
		}
		return b == m && c == mc;
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}