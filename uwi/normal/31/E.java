//package round31;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 1234";
//	private String INPUT = "10 99887766554433221100";
//	private String INPUT = "4 00099990";
//	private String INPUT = "4 00009999";
//	private String INPUT = "18 123456789012345678901234567890123456";
//	private String INPUT = "18 000000000000000009099999999999999999";
//	private String INPUT = "18 000000000000000055000000000000000000";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		char[] dc = in.next().toCharArray();
		int[] d = new int[2*n];
		for(int i = 0;i < dc.length;i++){
			d[i] = dc[i] - '0';
		}
		
		BitSet[] bs = new BitSet[n + 1];
		for(int i = 0;i <= n;i++){
			bs[i] = new BitSet();
		}
		BigInteger[] t = new BigInteger[n + 1];
		Arrays.fill(t, BigInteger.ZERO);
		BigInteger v;
		for(int i = 0;i < n;i++){
			BigInteger[] nt = new BigInteger[n + 1];
			Arrays.fill(nt, BigInteger.ZERO);
			BitSet[] nbs = new BitSet[n + 1];
			for(int j = 0;j <= n;j++){
				nbs[j] = new BitSet();
			}
			for(int j = 0;j <= i;j++){
				if(j >= 1){
					v = t[j].add(BigInteger.valueOf(10).pow(2 * j - 2).multiply(BigInteger.valueOf(10 * d[2*i] + d[2*i+1])));
					if(nt[j-1].compareTo(v) <= 0){
						nt[j-1] = v;
						nbs[j-1].clear();
						nbs[j-1].or(bs[j]);
						if(nbs[j-1].cardinality() < i){
							nbs[j-1].set(2*i);
							nbs[j-1].set(2*i+1);
						}
					}
				}
				{
					int max = Math.max(d[2*i], d[2*i+1]);
					int min = Math.min(d[2*i], d[2*i+1]);
					v = t[j].multiply(BigInteger.valueOf(10)).add(BigInteger.valueOf(10).pow(2 * j).multiply(BigInteger.valueOf(max)).add(BigInteger.valueOf(min)));
					if(nt[j].compareTo(v) <= 0){
						nt[j] = v;
						nbs[j].clear();
						nbs[j].or(bs[j]);
						if(nbs[j].cardinality() < i){
							if(d[2*i] == max){
								nbs[j].set(2*i);
							}else{
								nbs[j].set(2*i+1);
							}
						}else{
							if(d[2*i] == max){
								nbs[j].set(2*i+1);
							}else{
								nbs[j].set(2*i);
							}
						}
					}
				}
				{
					v = t[j].multiply(BigInteger.valueOf(100)).add(BigInteger.valueOf(10 * d[2*i] + d[2*i+1]));
					if(nt[j+1].compareTo(v) <= 0){
						nt[j+1] = v;
						nbs[j+1].clear();
						nbs[j+1].or(bs[j]);
						if(nbs[j+1].cardinality() >= i){
							nbs[j+1].set(2*i);
							nbs[j+1].set(2*i+1);
						}
					}
				}
			}
//			tr(nt);
//			tr(nbs[1]);
			t = nt;
			bs = nbs;
		}
		
		if(bs[0].cardinality() != n)throw new AssertionError();
		for(int i = 0;i < 2*n;i++){
			if(bs[0].get(i)){
				out.print('H');
			}else{
				out.print('M');
			}
		}
		out.println();
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}