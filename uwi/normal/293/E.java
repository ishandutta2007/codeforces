//package croc2013.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int L, W;
	
	void solve()
	{
		int n = ni();
		L = ni(); W = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = i+1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		
		long ct = separate(g, 0, new boolean[n], new int[n], new int[n], new int[n]);
		out.println(ct);
	}
	
	long separate(int[][][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0] && !sed[nex[0]]){
					ord[r++] = nex[0];
					par[nex[0]] = cur;
				}
			}
		}
		// if(r == 1)return;
		
		// DP and find a separator
		int sep = -1; // always exists
		outer:
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			for(int[] e : g[cur]){
				if(par[cur] != e[0] && !sed[e[0]])des[cur] += des[e[0]];
			}
			if(r-des[cur] <= r/2){
				for(int[] e : g[cur]){
					if(par[cur] != e[0] && !sed[e[0]] && des[e[0]] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		
		int[] curs = new int[r];
		int[] pres = new int[r];
		int[] inds = new int[r];
		int[] ds = new int[r];
		long[] fs = new long[r];
		int[] dlist = new int[r];
		long[] flist = new long[r];
		int lp = 0;
		long ret = 0;
//		tr("sep", sep);
		for(int[] e : g[sep]){
			if(!sed[e[0]]){
				int sp = 0;
				curs[sp] = e[0]; pres[sp] = sep; inds[sp] = 0; ds[sp] = 1; fs[sp] = e[1]; sp++;
				int slp = lp;
				while(sp > 0){
					int cur = curs[sp-1], pre = pres[sp-1], ind = inds[sp-1], d = ds[sp-1];
					long f = fs[sp-1];
					if(ind == 0){
						dlist[lp] = d;
						flist[lp] = f;
						if(d <= L && f <= W){
							ret++;
						}
						lp++;
					}
					if(ind < g[cur].length){
						int[] le = g[cur][ind];
						inds[sp-1]++;
						if(le[0] != pre & !sed[le[0]]){
							curs[sp] = le[0]; pres[sp] = cur; inds[sp] = 0; ds[sp] = d + 1; fs[sp] = f + le[1]; sp++;
						}
						continue;
					}else{
						sp--;
					}
				}
				ret -= total(dlist, flist, slp, lp);
			}
		}
		ret += total(dlist, flist, 0, lp);
//		tr(ret, dlist, flist, sep);
		
		for(int[] e : g[sep]){
			if(!sed[e[0]])ret += separate(g, e[0], sed, par, ord, des);
		}
		return ret;
	}
	
	long total(int[] dlist, long[] flist, int l, int r)
	{
		int n = r-l;
		int[][] co = new int[2*n][];
		long count = 0;
		for(int i = 0;i < n;i++){
			co[2*i] = new int[]{(int)Math.min(flist[l+i], W+1), dlist[l+i], 0};
			co[2*i+1] = new int[]{W-(int)Math.min(flist[l+i], W+1), L-dlist[l+i], 1};
			if(co[2*i][0] <= co[2*i+1][0] && co[2*i][1] <= co[2*i+1][1]){
				count--;
			}
		}
		// 0:put, 1:get
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[2] - b[2];
			}
		});
		int[] ft = new int[n+2];
		for(int i = 0;i < 2*n;i++){
			if(co[i][2] == 0){
				addFenwick(ft, co[i][1], 1);
			}else{
				if(co[i][1] >= 0){
					count += sumFenwick(ft, Math.min(n, co[i][1]));
				}
			}
		}
//		tr(co);
//		tr("count", count);
		return count/2;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}