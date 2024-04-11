//package round178;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		long min = Long.MAX_VALUE;
		int[] par = new int[n], ord = new int[n], des = new int[n];
		for(int z = 0;z < n-1;z++){
			int cutf = from[z], cutt = to[z];
			
			// parent and level-order
			long[] res1 = separate(g, cutf, cutt, par, ord, des);
			long[] res2 = separate(g, cutt, cutf, par, ord, des);
			long ret = res1[0] + res2[0] + w[z] * res1[1] * res2[1];
			min = Math.min(min, ret);
		}
		out.println(min);
	}
	
	long[] separate(int[][][] g, int root, int ng, int[] par, int[] ord, int[] des)
	{
		int n = g.length;
		
		// parent and level-order
		ord[0] = root;
		par[root] = ng;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0]){
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
				if(par[cur] != e[0])des[cur] += des[e[0]];
			}
			if(r-des[cur] <= r/2){
				for(int[] e : g[cur]){
					if(par[cur] != e[0] && des[e[0]] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		ord[0] = sep;
		par[sep] = -1;
		r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0] && nex[0] != ng){
					ord[r++] = nex[0];
					par[nex[0]] = cur;
				}
			}
		}
		
		long sum = 0;
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			int pw = 0;
			for(int[] e : g[cur]){
				if(par[cur] != e[0] && e[0] != ng){
					des[cur] += des[e[0]];
				}else if(par[cur] == e[0]){
					pw = e[1];
				}
			}
			sum += (long)pw * des[cur] * (n-des[cur]);
		}
		return new long[]{sum, r};
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
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
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