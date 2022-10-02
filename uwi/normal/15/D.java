//package round15;


import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class D2 {
	private IntReader in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int a = ni();
		int b = ni();
		int[][] h = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				h[i][j] = ni();
			}
		}
		
		int[][] minrow = new int[n][m-b+1];
		{
			for(int i = 0;i < n;i++){
				int[] ns = new int[b];
				int mini = 0;
				for(int j = 0;j < b;j++){
					ns[j] = h[i][j];
					if(ns[j] < ns[mini]){
						mini = j;
					}
				}
				for(int j = 0;j < m-b;j++){
					minrow[i][j] = ns[mini];
					ns[j%b] = h[i][j+b];
					if(j%b == mini){
						mini = 0;
						for(int k = 1;k < b;k++){
							if(ns[k] < ns[mini]){
								mini = k;
							}
						}
					}else{
						if(ns[j%b] < ns[mini]){
							mini = j%b;
						}
					}
				}
				minrow[i][m-b] = ns[mini];
			}
		}
//		for(int i = 0;i < n;i++){
//			System.out.println(Arrays.toString(minrow[i]));
//		}
		
		int[][] min = new int[n-a+1][m-b+1];
		{
			for(int i = 0;i < m-b+1;i++){
				int[] ns = new int[a];
				int mini = 0;
				for(int j = 0;j < a;j++){
					ns[j] = minrow[j][i];
					if(ns[j] < ns[mini]){
						mini = j;
					}
				}
				for(int j = 0;j < n-a;j++){
					min[j][i] = ns[mini];
					ns[j%a] = minrow[j+a][i];
					if(j%a == mini){
						mini = 0;
						for(int k = 1;k < a;k++){
							if(ns[k] < ns[mini]){
								mini = k;
							}
						}
					}else{
						if(ns[j%a] < ns[mini]){
							mini = j%a;
						}
					}
				}
				min[n-a][i] = ns[mini];
			}
		}
//		for(int i = 0;i < n-a+1;i++){
//			System.out.println(Arrays.toString(min[i]));
//		}
		
		long[][] sumrow = new long[n][m-b+1];
		for(int i = 0;i < n;i++){
			long s = 0L;
			for(int j = 0;j < b - 1;j++){
				s += h[i][j];
			}
			for(int j = 0;j < m-b+1;j++){
				s += h[i][j+b-1];
				sumrow[i][j] = s;
				s -= h[i][j];
			}
		}
		long[][] sum = new long[n-a+1][m-b+1];
		for(int i = 0;i < m-b+1;i++){
			long s = 0L;
			for(int j = 0;j < a - 1;j++){
				s += sumrow[j][i];
			}
			for(int j = 0;j < n-a+1;j++){
				s += sumrow[j+a-1][i];
				sum[j][i] = s;
				s -= sumrow[j][i];
			}
		}
//		for(long[] sss : sum){
//			System.out.println(Arrays.toString(sss));
//		}
		
		Pair[] ps = new Pair[(n-a+1) * (m-b+1)];
		Pair[][] map = new Pair[n-a+1][m-b+1];
		int p = 0;
		for(int i = 0;i < n - a + 1;i++){
			for(int j = 0;j < m - b + 1;j++){
				ps[p] = new Pair();
				ps[p].r = i;
				ps[p].c = j;
				ps[p].b = sum[i][j] - a * b * (long)min[i][j];
				map[i][j] = ps[p];
				p++;
			}
		}
		
		Arrays.sort(ps);
		
		int ret = 0;
		ArrayList<Pair> pl = new ArrayList<Pair>();
		for(Pair pa : ps){
			if(pa.b >= 0){
				ret++;
				pl.add(pa);
				int klim = Math.min(pa.r + a, n - a + 1);
				int llim = Math.min(pa.c + b, m - b + 1);
				int linf = Math.max(pa.c - b + 1, 0);
				long v = pa.b;
				for(int k = Math.max(pa.r - a + 1, 0);k < klim;k++){
					for(int l = linf;l < llim;l++){
						map[k][l].b = -1;
					}
				}
				pa.b = v;
			}
		}
		
		out.println(ret);
		
		for(Pair pa : pl){
			out.print(pa.r + 1);
			out.print(' ');
			out.print(pa.c + 1);
			out.print(' ');
			out.println(pa.b);
		}
	}
	
	private static class Pair implements Comparable<Pair>
	{
		public int r;
		public int c;
		public long b;
		
		@Override
		public int compareTo(Pair o) {
			if(b != o.b)return Long.signum(b - o.b);
			if(r != o.r)return r - o.r;
			return c - o.c;
		}
	}
	
	private static class Node implements Comparable<Node>
	{
		public int pos;
		public int val;
		
		@Override
		public int compareTo(Node o) {
			if(val != o.val)return val - o.val;
			return pos - o.pos;
		}
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("1000 1000 500 500 " + U.add(1, 1000000)));

//		in = new IntReader(new ByteArrayInputStream(("1000 1000 1 1 " + U.add(1, 1000000)).getBytes()));
//		in = new IntReader(new ByteArrayInputStream("2 2 1 2 1 2 3 5".getBytes()));
//		in = new Scanner(new StringReader("2 2 1 2 1 2 3 5"));
//		in = new Scanner(new StringReader("4 4 2 2 1 5 3 4 2 7 6 1 1 1 2 2 2 2 1 2"));
//		in = new Scanner(System.in);
		in = new IntReader(System.in);
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
	
	private static class IntReader
	{
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) != -1 && (num < '0' || num > '9'));
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b == -1)return num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	private int ni() { return in.nui(); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}