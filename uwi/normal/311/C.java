//package round185;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		nl();
		int n = ni(), m = ni(), K = ni();
		long[][] tre = new long[n][];
		for(int i = 0;i < n;i++){
			tre[i] = new long[]{nl()-1, ni()};
		}
		
		long M = 200000L;
		long[] d = new long[K];
		Arrays.fill(d, Long.MAX_VALUE / 3);
		d[0] = 0;
		MinHeapL all = new MinHeapL(n);
		for(int i = 0;i < n;i++){
			if(tre[i][0] % K == 0){
				all.add(i, -tre[i][1]*M-M+i+1);
			}
		}
		
		for(int r = 0;r < m;r++){
			int t = ni();
			if(t == 1){
				long x = nl();
				MinHeapL H = new MinHeapL(K);
				for(int i = 0;i < K;i++)H.add(i, d[i]);
				int px = (int)(x%K);
				while(H.size() > 0){
					int cur = H.argmin();
					long mind = H.remove(cur);
					int nex = cur + px;
					if(nex >= K)nex -= K;
					if(d[nex] > mind + x){
						d[nex] = mind + x;
						H.update(nex, d[nex]);
					}
				}
				for(int i = 0;i < n;i++){
					if(tre[i][1] > 0){
						int cp = (int)(tre[i][0]%K);
						if(tre[i][0] >= d[cp]){
							all.update(i, -tre[i][1]*M-M+i+1);
						}
					}
				}
			}else if(t == 2){
				int x = ni()-1;
				int y = ni();
				tre[x][1] -= y;
				if(tre[x][1] > 0){
					int cp = (int)(tre[x][0]%K);
					if(tre[x][0] >= d[cp]){
						all.update(x, -tre[x][1]*M-M+x+1);
					}
				}
			}else{
				int am = all.argmin();
				if(am == -1){
					out.println(0);
				}else{
					out.println(-all.remove(am)/M);
					tre[am][1] = 0;
				}
			}
		}
	}
	
	public static class MinHeapL {
		public long[] a;
		public int[] map; // 
		public int[] imap; // 
		public int n;
		public int pos;
		public static long INF = Long.MAX_VALUE;
		
		public MinHeapL(int m)
		{
			n = Integer.highestOneBit((m+1)<<1);
			a = new long[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public long add(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public long update(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				a[ret] = x;
				up(ret);
				down(ret);
			}
			return x;
		}
		
		public long remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			long ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public long min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					long d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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
	
	private long nl()
	{
		long num = 0;
		int b;
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