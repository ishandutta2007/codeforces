//package round29;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.TreeSet;

public class E3 {
	private IntReader in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = in.nui();
		int m = in.nui();
		
//		boolean[][] d = new boolean[n][n];
		BitSet[] db = new BitSet[n];
		for(int i = 0;i < n;i++)db[i] = new BitSet(n);
		
		for(int i = 0;i < m;i++){
			int f = in.nui() - 1;
			int t = in.nui() - 1;
//			d[f][t] = true;
//			d[t][f] = true;
			db[f].set(t);
			db[t].set(f);
		}
		
//		int[] ds = wf(n, db, 0);
//		if(ds[n - 1] == -1){
//			out.println(-1);
//			return;
//		}
		int[] h = dijkhb(n, db, 0 * n + (n - 1), (n - 1) * n + 0);
		if(h.length == 1){
			out.println(-1);
		}else{
			StringBuilder sba = new StringBuilder();
			StringBuilder sbb = new StringBuilder();
			for(int i = 0;i < h.length;i++){
				sba.append(h[i] / n + 1); sba.append(' ');
				sbb.append((h[i] % n) + 1); sbb.append(' ');
			}
			out.println(h.length - 1);
			out.println(sba.toString());
			out.println(sbb.toString());
		}
	}
	
	public static int[] wf(int n, boolean[][] d, int from)
	{
		final int[] td = new int[n];
		Arrays.fill(td, -1);
		td[from] = 0;
		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
			@Override
			public int compare(Integer a, Integer b) {
				if(td[a] - td[b] != 0)return td[a] - td[b];
				return a - b;
			}
		});
		q.add(from);
		
		while(q.size() > 0){
			int cur = q.pollFirst();
			
			for(int i = 0;i < n;i++){
				if(d[cur][i]){
					int nd = td[cur] + 1;
					if(td[i] == -1 || nd < td[i]){
						q.remove(i);
						td[i] = nd;
						q.add(i);
					}
				}
			}
		}
		
		return td;
	}
	
	public int[] dijkhb(int n, BitSet[] d, int from, int to)
	{
//		BitSet passed = new BitSet();
//		for(int i = 0;i < n;i++){
//			passed.set(i * n + i);
//		}
		BitSet[] passed = new BitSet[n];
		for(int i = 0;i < n;i++){
			passed[i] =  new BitSet(n);
			passed[i].set(i);
		}
		int[] prev = new int[n * n];
		Arrays.fill(prev, -1);
//		BitSet q = new BitSet();
//		q.set(from);
		BitSet[] q = new BitSet[n];
		for(int i = 0;i < n;i++){
			q[i] = new BitSet(n);
		}
		q[from/n].set(from%n);
		for(int i = 0;i < n;i++){
			passed[i].or(q[i]);
		}

		BitSet db = new BitSet(n);
		BitSet dbf = new BitSet(n);
		int[] ppp = new int[n];
		boolean emp = false;
		outer:
		while(!emp){
//			tr(q.cardinality());
			BitSet[] nq = new BitSet[n];
			for(int i = 0;i < n;i++){
				nq[i] = new BitSet(n);
			}
			for(int a = 0;a < n;a++){
				db.clear();
				Arrays.fill(ppp, 0);
				for(int b = q[a].nextSetBit(0);b != -1;b = q[a].nextSetBit(b+1)){
					db.or(d[b]);
					for(int j = d[b].nextSetBit(0);j != -1;j = d[b].nextSetBit(j+1)){
						ppp[j] = a * n + b;
					}
				}
				
				for(int i = d[a].nextSetBit(0);i != -1;i = d[a].nextSetBit(i+1)){
					dbf.clear();
					dbf.or(db);
					dbf.andNot(passed[i]);
					for(int j = dbf.nextSetBit(0);j != -1;j = dbf.nextSetBit(j+1)){
						prev[i * n + j] = ppp[j];
						if(i * n + j == to)break outer;
					}
					nq[i].or(dbf);
					passed[i].or(dbf);
				}
			}

			emp = true;
//			int sum = 0;
			for(int i = 0;i < n;i++){
				if(!nq[i].isEmpty())emp = false;
//				sum += nq[i].cardinality();
				q[i] = nq[i];
			}
//			tr(sum);
		}

		int ct = 0;
		for(int u = to;u != -1;u = prev[u])ct++;
		int[] h = new int[ct];
		for(int u = to, p = ct - 1;u != -1;u = prev[u], p--)h[p] = u;
		return h;
	}

	public void run()
	{
//		int n = 400;
//		int m = 10000;
////		for(int u = 0;u < 30;u++){
//		StringBuilder sb = new StringBuilder(n + " " + m + " ");
//		Random r = new Random(3);
//		for(int i = 0;i < m-1;i++){
//			int f = r.nextInt(n-1) + 1;
//			int t = r.nextInt(n-1) + 1;
//			if(f == t){
//				i--;
//				continue;
//			}
//			sb.append(f);
//			sb.append(' ');
//			sb.append(t);
//			sb.append(' ');
//		}
//		{
//			int f = r.nextInt(n-1) + 1;
//			int t = n;
//			sb.append(f);
//			sb.append(' ');
//			sb.append(t);
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);

		solve();
		out.flush();
//		}
	}
	
	
	public static void main(String[] args)
	{
		new E3().run();
	}
	
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	
	public class IntReader {
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