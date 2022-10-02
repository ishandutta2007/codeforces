//package round13;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class C2 {
	private Scanner in;
	private PrintWriter out;
	
	private static class Pair implements Comparable<Pair>
	{
		public int a;
		public long b;
		
		@Override
		public int compareTo(Pair o) {
			return Long.signum(b - o.b);
		}
	}
	
	public void solve()
	{
		int n = ni();
		long[] s = new long[n];
		for(int i = 0;i < n;i++){
			s[i] = ni();
		}
		
		Pair[] ps = new Pair[n];
		for(int i = 0;i < n;i++){
			ps[i] = new Pair();
			ps[i].a = i;
			ps[i].b = s[i];
		}
		Arrays.sort(ps);
		
		long[] map = new long[n];
		for(int i = 0;i < n;i++){ // phase
			long[] mapmin = new long[n];
			mapmin[0] = map[ps[0].a];
			for(int j = 1;j < n;j++){
				mapmin[j] = Math.min(mapmin[j-1], map[ps[j].a]);
			}
			for(int j = 0;j < n;j++){ // height
				map[ps[j].a] = mapmin[j] + Math.abs(s[i] - s[ps[j].a]);
			}
		}
		
		long retmin = Long.MAX_VALUE;
		for(long l : map){
			if(retmin > l){
				retmin = l;
			}
		}
		out.println(retmin);
	}
	
	public void run() throws Exception
	{
//		Random r = new Random(55);
//		StringBuilder sb = new StringBuilder("5000 ");
//		for(int i = 0;i < 5000;i++){
//			sb.append(r.nextInt() % 1000000000);
//			sb.append(" ");
//		}
//		in = new Scanner(new StringReader(sb.toString()));
//		in = new Scanner(new StringReader("5 3 2 -1 2 11"));
//		in = new Scanner(new StringReader("5 2 1 1 1 1"));
//		in = new Scanner(new StringReader("1 999"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(long[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}