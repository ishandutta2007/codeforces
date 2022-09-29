//package round407;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = shrink(na(n));
		int mod = 1000000007;
		int[] rb = new int[n];
		{
			int[] ft = new int[n+3];
			for(int i = n-1;i >= 0;i--){
				rb[i] = sumFenwick(ft, a[i]);
				addFenwick(ft, a[i], 1);
			}
		}
		int[] lb = new int[n];
		{
			int[] ft = new int[n+3];
			for(int i = 0;i < n;i++){
				lb[i] = sumFenwick(ft, a[i]);
				addFenwick(ft, a[i], 1);
			}
		}
		
		int[][] g = makeBuckets(a, n+1);
		SegmentTreeArray[] sts = new SegmentTreeArray[n+1];
		long ret = 0;
		for(int i = 0;i <= n;i++){
			if(g[i].length > 0){
				sts[i] = new SegmentTreeArray(g[i], rb, lb);
				ret += sts[i].node[1][2];
			}
		}
		ret %= mod;
		
		for(int Q = ni();Q > 0;Q--){
			int t = ni();
			int x = ni()-1;
			if(t == 1){
				ret -= sts[a[x]].node[1][2];
				sts[a[x]].off(Arrays.binarySearch(g[a[x]], x));
				ret += sts[a[x]].node[1][2];
			}else{
				ret -= sts[a[x]].node[1][2];
				sts[a[x]].on(Arrays.binarySearch(g[a[x]], x), g[a[x]], rb, lb);
				ret += sts[a[x]].node[1][2];
			}
			if(ret < 0)ret += mod;
			if(ret >= mod)ret -= mod;
			out.println(ret);
		}
	}
	
	public static ResultExtraction extract(int[][] A, int mod)
	{
		int n = A.length;
		int[][] ids = new int[n*n][];
		int idgen = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(A[i][j] != 0){
					ids[idgen++] = new int[]{i, j};
				}
			}
		}
		
		// is operator?
		outer:
		for(int i = 0;i < idgen;i++){
			for(int j = 0;j < idgen;j++){
				if(ids[i][1] == ids[j][0]){
					for(int k = 0;k < idgen;k++){
						if(ids[i][0] == ids[k][0] && ids[j][1] == ids[k][1]){
							continue outer;
						}
					}
					throw new RuntimeException(String.format("((%d,%d),(%d,%d)) -> (%d,%d) is not closed", ids[i][0], ids[i][1], ids[j][0], ids[j][1], ids[i][0], ids[j][1]));
				}
			}
		}
	
		StringBuilder sb = new StringBuilder();
		long lim = Long.MAX_VALUE / mod / mod - 1;
		for(int k = 0;k < idgen;k++){
			StringBuilder lsb = new StringBuilder();
			int nadd = 0;
			for(int i = 0;i < idgen;i++){
				if(ids[i][0] != ids[k][0])continue;
				for(int j = 0;j < idgen;j++){
					if(ids[j][1] != ids[k][1])continue;
					if(ids[i][1] == ids[j][0]){
						if(nadd > 0)lsb.append("+");
						lsb.append(String.format("L[%d]*R[%d]", i, j));
						if(++nadd >= lim){
							nadd = 0;
							lsb.insert(0, "(");
							lsb.append(")%mod");
						}
					}
				}
			}
			sb.append(String.format("P[%d] = ", k));
			if(lsb.length() == 0){
				sb.append("0;\n");
			}else if(nadd == 0){
				sb.append(lsb).append(";\n");
			}else{
				sb.append("(").append(lsb).append(")%mod;\n");
			}
		}
		
		ResultExtraction ret = new ResultExtraction();
		ret.formulae = sb.toString();
		ret.ids = Arrays.copyOf(ids, idgen);
		return ret;
	}
	
	public static ResultExtraction extractWithDiag1(int[][] A, int mod)
	{
		int n = A.length;
		int[][] ids = new int[n*n][];
		int idgen = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(A[i][j] != 0){
					ids[idgen++] = new int[]{i, j};
				}
			}
		}
		
		int[] comediag = new int[n];
		// is operator?
		outer:
		for(int i = 0;i < idgen;i++){
			for(int j = 0;j < idgen;j++){
				if(ids[i][1] == ids[j][0]){
					for(int k = 0;k < idgen;k++){
						if(ids[i][0] == ids[k][0] && ids[j][1] == ids[k][1]){
							if(ids[k][0] == ids[k][1])comediag[ids[k][0]]++;
							continue outer;
						}
					}
					throw new RuntimeException(String.format("((%d,%d),(%d,%d)) -> (%d,%d) is not closed", ids[i][0], ids[i][1], ids[j][0], ids[j][1], ids[i][0], ids[j][1]));
				}
			}
		}
		int[] remap = new int[idgen];
		int p = 0;
		Arrays.fill(remap, -1);
		for(int i = 0;i < idgen;i++){
			if(ids[i][0] == ids[i][1] && A[ids[i][0]][ids[i][1]] == 1 && comediag[ids[i][0]] == 1){
				continue;
			}
			remap[i] = p++;
		}
	
		StringBuilder sb = new StringBuilder();
		long lim = Long.MAX_VALUE / mod / mod - 1;
		for(int k = 0;k < idgen;k++){
			if(remap[k] == -1)continue;
			StringBuilder lsb = new StringBuilder();
			int nadd = 0;
			for(int i = 0;i < idgen;i++){
				if(ids[i][0] != ids[k][0])continue;
				for(int j = 0;j < idgen;j++){
					if(ids[j][1] != ids[k][1])continue;
					if(ids[i][1] == ids[j][0]){
						if(nadd > 0)lsb.append("+");
						if(remap[i] == -1){
							if(remap[j] == -1){
								lsb.append("1");
							}else{
								lsb.append(String.format("R[%d]", remap[j]));
							}
						}else{
							if(remap[j] == -1){
								lsb.append(String.format("L[%d]", remap[i]));
							}else{
								lsb.append(String.format("L[%d]*R[%d]", remap[i], remap[j]));
							}
						}
						if(++nadd >= lim){
							nadd = 0;
							lsb.insert(0, "(");
							lsb.append(")%mod");
						}
					}
				}
			}
			sb.append(String.format("P[%d] = ", remap[k]));
			if(lsb.length() == 0){
				sb.append("0;\n");
			}else if(nadd == 0){
				sb.append(lsb).append(";\n");
			}else{
				sb.append("(").append(lsb).append(")%mod;\n");
			}
		}
		
		for(int i = 0;i < idgen;i++){
			if(remap[i] == -1)continue;
			ids[remap[i]] = ids[i];
		}
		
		ResultExtraction ret = new ResultExtraction();
		ret.formulae = sb.toString();
		ret.ids = Arrays.copyOf(ids, p);
		return ret;
	}
	
	public static class ResultExtraction
	{
		String formulae;
		int[][] ids;
	}
	
	public static class SegmentTreeArray {
		public int M, H, N;
		public long[][] node;
		public int K = 6;
		
		public SegmentTreeArray(int[] h, int[] rb, int[] lb)
		{
			N = h.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new long[M][];
			for(int i = 0;i < N;i++){
				long[] item = new long[K];
				item[0] = lb[h[i]];
				item[3] = 1;
				item[5] = rb[h[i]];
				
				node[H+i] = item;
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void on(int pos, int[] h, int[] rb, int[] lb)
		{
			node[H+pos][0] = lb[h[pos]];
			node[H+pos][3] = 1;
			node[H+pos][5] = rb[h[pos]];
			
			for(int i = H+pos>>>1;i >= 1;i >>>= 1){
				prop2(node[2*i], node[2*i+1], node[i]);
			}
		}
		
		public void off(int pos)
		{
			node[H+pos][0] = node[H+pos][3] = node[H+pos][5] = 0;
			for(int i = H+pos>>>1;i >= 1;i >>>= 1){
				prop2(node[2*i], node[2*i+1], node[i]);
			}
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		static final int mod = 1000000007;
		
		private long[] prop2(long[] L, long[] R, long[] C)
		{
			if(L != null && R != null){
				if(C == null)C = new long[K];
				C[0] = (R[0]+L[0])%mod;
				C[1] = (R[1]+L[0]*R[3]+L[1])%mod;
				C[2] = (R[2]+L[0]*R[4]+L[1]*R[5]+L[2])%mod;
				C[3] = (R[3]+L[3])%mod;
				C[4] = (R[4]+L[3]*R[5]+L[4])%mod;
				C[5] = (R[5]+L[5])%mod;
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private long[] prop1(long[] L, long[] C)
		{
			if(C == null)C = new long[K];
			for(int i = 0;i < K;i++)C[i] = L[i];
			return C;
		}
	}	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
	}

	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	
	public static int[] shrink(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0)
				p++;
			ret[(int) b[i]] = p;
		}
		return ret;
	}

	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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