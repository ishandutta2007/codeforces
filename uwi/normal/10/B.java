//package round10;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int k = ni();
		int[] slr = new int[k];
		int[] srl = new int[k];
		for(int i = 0;i < k;i++){
			slr[i] = k;
		}
		
		for(int i = 0;i < n;i++){
			int m = ni();
			if(m > k){
				out.println(-1);
				continue;
			}
			int min = Integer.MAX_VALUE;
			int minj = -1;
			int minl = -1;
			int f = 0;
			for(int j = 0;j < k;j++){
				if(slr[j] == k){
					int sd = (m - 1) / 2;
					int sum = sd * (sd + 1) + Math.abs(j - (k-1)/2) * m;
					if(m % 2 == 0)sum += (m/2); // + Math.abs(j - (k-1)/2);
					if(sum < min){
						min = sum;
						minj = j;
						minl = (k - 1) / 2 - (m - 1) / 2 - ((m % 2 == 0) ? 1 : 0);
						f = 0;
					}
				}else{
					if(slr[j] >= m){
						int l = slr[j] - m;
						int sum = (k-1)/2*m-l*m-m*(m-1)/2 + Math.abs(j - (k-1)/2) * m;
						if(sum < min){
							min = sum;
							minj = j;
							minl = l;
							f = 1;
						}
					}
					if(k - srl[j] >= m){
						int l = srl[j];
						int sum = l*m+m*(m-1)/2-(k-1)/2*m + Math.abs(j - (k-1)/2) * m;
						if(sum < min){
							min = sum;
							minj = j;
							minl = l;
							f = 2;
						}
					}
				}
			}
			if(minl == -1){
				out.println(-1);
				continue;
			}
			
			if(f == 0){
				slr[minj] = minl;
				srl[minj] = minl + m;
			}else if(f == 1){
				slr[minj] = minl;
			}else if(f == 2){
				srl[minj] = minl + m;
			}
			
			out.printf("%d %d %d\n", minj + 1, minl + 1, minl + m - 1 + 1);
		}
		
		out.println();
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("2 1 1 1"));
//		in = new Scanner(new StringReader("4 3 1 2 3 1"));
//		in = new Scanner(new StringReader("6 3 1 3 3 1 1 1"));
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
		new B().run();
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