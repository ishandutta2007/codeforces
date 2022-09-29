//package educational.round34;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Datum
	{
		int[] hs;
		int cost;
		public Datum(int[] hs, int cost) {
			this.hs = hs;
			this.cost = cost;
		}
		
		public long h()
		{
			long h = 0;
			for(int o : hs){
				h = h * 100 + o;
			}
			return h;
		}
	}
	
	void solve()
	{
		int n = ni();
		int[] cost = na(4);
		char[][] map = nm(4, n);
		
		int[] w = new int[4];
		
		Map<Long, Datum> cans = new HashMap<>();
		
		outer:
		do{
			for(int i = 0;i < 4;i++){
				if(i+w[i] > 4)continue outer;
			}
			int[] h = new int[4];
			int sc = 0;
			for(int i = 0;i < 4;i++){
				if(w[i] > 0)sc += cost[w[i]-1];
				for(int j = i;j < i+w[i];j++){
					h[j] = Math.max(h[j], w[i]);
				}
			}
			Datum d = new Datum(h, sc);
			long dh = d.h();
			if(!cans.containsKey(dh) || cans.get(dh).cost > sc){
				cans.put(dh, d);
			}
		}while(inc(w, 5));
//		tr(cans.size());
		
		List<Datum> ds = new ArrayList<>(cans.values());
		long[][][][] dp = new long[4][4][4][4];
		for(int u = 0;u < 4;u++){
			for(int v = 0;v < 4;v++){
				for(int x = 0;x < 4;x++){
					Arrays.fill(dp[u][v][x], Long.MAX_VALUE / 3);
				}
			}
		}
		dp[0][0][0][0] = 0;
		for(int i = 0;i < n;i++){
			long[][][][] ndp = new long[4][4][4][4];
			for(int u = 0;u < 4;u++){
				for(int v = 0;v < 4;v++){
					for(int x = 0;x < 4;x++){
						Arrays.fill(ndp[u][v][x], Long.MAX_VALUE / 3);
					}
				}
			}
			
			int[] a = new int[4];
			do{
				long myc = dp[a[0]][a[1]][a[2]][a[3]];
				int[] na = Arrays.copyOf(a, 4);
				for(int k = 0;k < 4;k++){
					if(na[k] > 0)na[k]++;
					if(map[k][i] == '*' && na[k] == 0)na[k] = 1;
				}
				int[] nna = new int[4];
				inner:
				for(Datum d : ds){
					System.arraycopy(na, 0, nna, 0, 4);
//					int[] nna = Arrays.copyOf(na, 4);
					for(int k = 0;k < 4;k++){
						if(d.hs[k] >= nna[k])nna[k] = 0;
						if(nna[k] == 4)continue inner;
					}
//					tr(a, na, nna);
					ndp[nna[0]][nna[1]][nna[2]][nna[3]] = 
							Math.min(
							ndp[nna[0]][nna[1]][nna[2]][nna[3]], 
							myc + d.cost
							);
				}
			}while(inc(a, 4));
			
			dp = ndp;
		}

		out.println(dp[0][0][0][0]);
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
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
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
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