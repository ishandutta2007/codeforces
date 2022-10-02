//package round20;


import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class C {
	private IntReader in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = in.nui();
		int m = in.nui();
		
//		long ss = System.currentTimeMillis();
		HashMap<Long, Integer> map = new HashMap<Long, Integer>();
		for(int i = 0;i < m;i++){
			int a = in.nui() - 1;
			int b = in.nui() - 1;
			int w = in.nui();
			if(a == b)continue;
			if(a > b){
				int du = a; a = b; b = du;
			}
			long code = (long)a * (long)n + b;
			if(!map.containsKey(code) || map.get(code) < w){
				map.put(code, w);
			}
		}
		
		int[] ns = new int[n];
		for(Long key : map.keySet()){
			int a = (int)(key / n);
			int b = (int)(key % n);
			ns[a]++;
			ns[b]++;
		}
		
		int[] ps = new int[n];
		int[][] d = new int[n][];
		for(int i = 0;i < n;i++){
			d[i] = new int[2 * ns[i]];
		}
		
		for(Map.Entry<Long, Integer> entry : map.entrySet()){
			int a = (int)(entry.getKey() / n);
			int b = (int)(entry.getKey() % n);
			int w = entry.getValue();
			d[a][ps[a]++] = b;
			d[a][ps[a]++] = w;
			d[b][ps[b]++] = a;
			d[b][ps[b]++] = w;
		}
//		System.err.println(System.currentTimeMillis() - ss);
		
		int[] ret = dijkh(n, d, 0, n - 1);
		if(ret.length <= 1){
			out.println(-1);
		}else{
//			out.println(ret.length);
			for(int r : ret){
				out.print((r + 1) + " ");
			}
		}
	}
	
	public static int[] dijkh(int n, int[][] d, int from, int to)
	{
		final long[] td = new long[n];
		Arrays.fill(td, -1);
		int[] prev = new int[n]; // 
		Arrays.fill(prev, -1);
//		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
//			@Override
//			public int compare(Integer a, Integer b) {
//				if(td[a] != td[b])return Long.signum(td[a] - td[b]);
//				return a - b;
//			}
//		});
//		q.add(from);
		
		PriorityQueue<Integer> q = new PriorityQueue<Integer>(100000, new Comparator<Integer>(){
			@Override
			public int compare(Integer a, Integer b) {
				if(td[a] != td[b])return Long.signum(td[a] - td[b]);
				return a - b;
			}
		});
		q.add(from);
		td[from] = 0;
		
		Integer cur;
		while((cur = q.poll()) != null){
			
			for(int j = 0;j < d[cur].length;j+=2){
				int i = d[cur][j];
				if(i == from)continue;
				long nd = td[cur] + d[cur][j+1];
				if(td[i] == -1 || nd < td[i]){
					td[i] = nd;
					prev[i] = cur;
//					q.remove(i);
					q.add(i);
				}
			}
		}
		
		int ct = 0;
		for(int u = to;u != -1;u = prev[u]){
			ct++;
		}
		int[] h = new int[ct];
		for(int u = to, pp = ct - 1;u != -1;u = prev[u], pp--)h[pp] = u;
		return h;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("5 6 1 2 2 2 5 5 2 3 4 1 4 1 4 3 3 3 5 1"));
//		int nn = 100000;
//		StringBuilder sb = new StringBuilder("" + nn + " 99999 ");
//		Random r = new Random();
//		for(int i = 0;i < 100000;i++){
////			sb.append("" + (r.nextInt(nn) + 1) + " " + (r.nextInt(nn) + 1) + " " + (r.nextInt(1000000) + 1) + " ");
//			if(i < 50000){
//				sb.append("" + 1 + " " + (i + 2) + " 1 ");
//			}else{
//				sb.append("" + (i - 50000 + 2) + " " + 100000 + " " + (r.nextInt(1000000) + 1) + " ");
//			}
//		}
		
//		for(int i = 0;i < 99999;i++){
//			sb.append("" + (i + 1) + " " + (i + 2) + " 1000000 ");
//		}
//		in = new IntReader(new ByteArrayInputStream(sb.toString().getBytes()));
//		in = new Scanner(new StringReader(sb.toString()));
		in = new IntReader(System.in);
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
		new C().run();
	}
	
//	private int ni() { return Integer.parseInt(in.next()); }
//	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
	public static class IntReader {
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
}