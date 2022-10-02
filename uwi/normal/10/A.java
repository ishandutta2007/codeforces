//package round10;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int p1 = ni();
		int p2 = ni();
		int p3 = ni();
		int t1 = ni();
		int t2 = ni();
		
		int[] l = new int[2 * n];
		for(int i = 0;i < 2 * n;i++){
			l[i] = ni();
		}
		
		int t = l[0];
		int p = 0;
		int state = 0;
		long w = 0L;
		while(true){
			if(state == 0){
				int sle = t + t1;
				int nex = l[2 * p];
				if(nex <= sle){
					w += (l[2 * p + 1] - t) * p1;
					t = l[2 * p + 1];
					p++;
					if(p == n)break;
				}else{
					w += (sle - t) * p1;
					t = sle;
					state = 1;
				}
			}else if(state == 1){
				int sle = t + t2;
				int nex = l[2 * p];
				if(nex <= sle){
					w += (nex - t) * p2 + (l[2 * p + 1] - nex) * p1;
					t = l[2 * p + 1];
					state = 0;
					p++;
					if(p == n)break;
				}else{
					w += (sle - t) * p2;
					t = sle;
					state = 2;
				}
			}else if(state == 2){
				int nex = l[2 * p];
				w += (nex - t) * p3 + (l[2 * p + 1] - nex) * p1;
				t = l[2 * p + 1];
				state = 0;
				p++;
				if(p == n)break;
			}
		}
		out.println(w);
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("1 3 2 1 5 10 0 10"));
//		in = new Scanner(new StringReader("2 8 4 2 5 10 20 30 50 100"));
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