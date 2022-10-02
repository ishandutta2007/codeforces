//package round17;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int k = ni();
		
		BitSet bs = new BitSet();
		for(int i = 3;i <= n;i+=2){
			boolean f = true;
			for(int j = 3;j * j <= i;j+=2){
				if(i % j == 0){
					f = false;
					break;
				}
			}
			if(f){
				bs.set(i);
			}
		}
		
		int prev = -1;
		int ct = 0;
		for(int i = bs.nextSetBit(0);i != -1;i = bs.nextSetBit(i + 1)){
			if(prev != -1){
				int v = prev + i + 1;
				if(bs.get(v)){
					ct++;
				}
				if(v > n)break;
			}
			prev = i;
		}
		
		out.println(ct >= k ? "YES" : "NO");
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("1000 5"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}