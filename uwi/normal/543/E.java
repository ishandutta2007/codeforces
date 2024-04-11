//package round302;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2FF {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] a = na(n);
		long[] as = new long[n];
		for(int i = 0;i < n;i++){
			as[i] = (long)a[i]<<32|i;
		}
		Arrays.sort(as);
		
		int s = (int)Math.sqrt(n);
		// time split
		int[][] minblock = new int[n/s+1][];
		int[] imos = new int[n/s+2];
		for(int i = 0;i <= n;i++){
			if(i % s == 0){
				minblock[i/s] = Arrays.copyOf(imos, n/s+2);
				for(int j = 1;j <= n/s;j++){
					minblock[i/s][j] += minblock[i/s][j-1];
				}
			}
			
			if(i == n)break;
			if(0 > (int)as[i]-m+1){
				int l = Math.max(0, (int)as[i]-m+1);
				int r = (int)as[i];
				if(l/s <= r/s){
					imos[l/s]++;
					imos[r/s]--;
				}
			}else{
				int l = Math.max(0, (int)as[i]-m+1);
				int r = (int)as[i];
				if(l/s+1 <= r/s){
					imos[l/s+1]++;
					imos[r/s]--;
				}
			}
		}
		
		int[][] mininblock = new int[n/s+1][];
		int[][] wheninblock = new int[n/s+1][];
		for(int i = 0;i < n/s+1;i++){
			mininblock[i] = new int[2*s+1];
			wheninblock[i] = new int[2*s+1];
		}
		
		int[] map = new int[n];
		int[] ps = new int[n/s+1];
		for(int i = 0;i < n;i++){
			int l = Math.max(0, (int)as[i]-m+1);
			int r = (int)as[i];
			if(l/s == r/s){
				for(int j = l;j <= r;j++)map[j]++;
				
				int lmin = Integer.MAX_VALUE;
				for(int j = l/s*s;j < l/s*s+s && j < n;j++){
					if(map[j] < lmin){
						lmin = map[j];
					}
				}
				int clus = l/s;
				mininblock[clus][ps[clus]] = lmin;
				wheninblock[clus][ps[clus]] = i;
				ps[clus]++;
			}else{
				{
					for(int j = r/s*s;j <= r;j++)map[j]++;
					
					int lmin = Integer.MAX_VALUE;
					for(int j = r/s*s;j < r/s*s+s && j < n;j++){
						if(map[j] < lmin){
							lmin = map[j];
						}
					}
					int clus = r/s;
					mininblock[clus][ps[clus]] = lmin;
					wheninblock[clus][ps[clus]] = i;
					ps[clus]++;
				}
				if(0 <= (int)as[i]-m+1){
					for(int j = l;j < l/s*s+s;j++)map[j]++;
					
					int lmin = Integer.MAX_VALUE;
					for(int j = l/s*s;j < l/s*s+s && j < n;j++){
						if(map[j] < lmin){
							lmin = map[j];
						}
					}
					int clus = l/s;
					mininblock[clus][ps[clus]] = lmin;
					wheninblock[clus][ps[clus]] = i;
					ps[clus]++;
				}
			}
		}
		for(int i = 0;i <= n/s;i++){
			wheninblock[i] = Arrays.copyOf(wheninblock[i], ps[i]);
		}
		int[][][] bb = prepareFractionalCascading(wheninblock);
		
//		for(int i = 0;i < n/s+1;i++){
//			tr(i);
//			tr(Arrays.copyOf(mininblock[i], ps[i]));
//			tr(Arrays.copyOf(wheninblock[i], ps[i]));
//		}
		
		int ans = 0;
		int[] llimos = new int[s+1];
		int[] limos = new int[n/s+2];
		for(int Q = ni(); Q >= 1;Q--){
			int ql = ni()-1, qr = ni()-1, qx = ni()^ans;
			int time = -Arrays.binarySearch(as, ((long)qx<<32)-1)-1;
			Arrays.fill(limos, 0);
			for(int i = time/s*s;i < time;i++){
				if(0 > (int)as[i]-m+1){
					int l = Math.max(0, (int)as[i]-m+1);
					int r = (int)as[i];
					if(l/s <= r/s){
						limos[l/s]++;
						limos[r/s]--;
					}
				}else{
					int l = Math.max(0, (int)as[i]-m+1);
					int r = (int)as[i];
					if(l/s+1 <= r/s){
						limos[l/s+1]++;
						limos[r/s]--;
					}
				}
			}
			for(int i = 1;i < n/s+1;i++){
				limos[i] += limos[i-1];
			}
			for(int i = 0;i < n/s+1;i++){
				limos[i] += minblock[time/s][i];
			}
			ans = 999999999;
			
			if(ql/s == qr/s){
				Arrays.fill(llimos, 0);
				int clus = ql/s;
				for(int j = 0;j < ps[clus] && wheninblock[clus][j] < time;j++){
					int l = Math.max((int)as[wheninblock[clus][j]]-m+1-clus*s, 0);
					int r = Math.min(s-1, (int)as[wheninblock[clus][j]]-clus*s);
					llimos[l]++;
					llimos[r+1]--;
				}
				for(int j = 1;j <= s;j++){
					llimos[j] += llimos[j-1];
				}
				for(int j = ql-clus*s;j <= qr-clus*s;j++){
					ans = Math.min(ans, limos[clus] + llimos[j]);
				}
			}else{
//				int[] mins = doFractionalCascading(bb[0], bb[1], ql/s+1, qr/s-1, time-1);
				
//				if(l > r)return new int[0];
//				int[] inds = new int[r-l+1];
//				int ub = upperBound(b[l], v);
//				inds[0] = ub == -1 ? -1 : bind[l][ub];
//				for(int i = l+1;i <= r;i++){
//					int ind = ub == -1 ? -1 : 2*(ub-bind[i-1][ub])-1;
//					ub = ind+1 < b[i].length && v >= b[i][ind+1] ? ind+1 : ind;
//					inds[i-l] = ub == -1 ? -1 : bind[i][ub];
//				}
//				return inds;
				if(ql/s+1 <= qr/s-1){
					int ub = upperBound(bb[0][ql/s+1], time-1);
					for(int i = ql/s+1;i < qr/s;i++){
	//					int xind = Arrays.binarySearch(wheninblock[i], time-1);
	//					if(xind < 0)xind = -xind-2;
						int lind = ub == -1 ? -1 : bb[1][i][ub];
						int xind = 2*(ub-lind)-1;
						ub = xind+1 < bb[0][i+1].length && time-1 >= bb[0][i+1][xind+1] ? xind+1 : xind;
//						int lind = mins[j];
						if(lind >= 0){
							ans = Math.min(ans, limos[i] + mininblock[i][lind]);
						}else{
							ans = Math.min(ans, limos[i]);
						}
					}
				}
				
				{
					int clus = ql/s;
					Arrays.fill(llimos, 0);
					for(int j = 0;j < ps[clus] && wheninblock[clus][j] < time;j++){
						int l = Math.max((int)as[wheninblock[clus][j]]-m+1-clus*s, 0);
						int r = Math.min((int)as[wheninblock[clus][j]]-clus*s, s-1);
						llimos[l]++;
						llimos[r+1]--;
					}
					for(int j = 1;j <= s;j++){
						llimos[j] += llimos[j-1];
					}
					for(int j = ql-clus*s;j < s && j < n-clus*s;j++){
						ans = Math.min(ans, limos[clus] + llimos[j]);
					}
				}
				{
					int clus = qr/s;
					Arrays.fill(llimos, 0);
					for(int j = 0;j < ps[clus] && wheninblock[clus][j] < time;j++){
						int l = Math.max((int)as[wheninblock[clus][j]]-m+1-clus*s, 0);
						int r = Math.min((int)as[wheninblock[clus][j]]-clus*s, s-1);
						llimos[l]++;
						llimos[r+1]--;
					}
					for(int j = 1;j <= s;j++){
						llimos[j] += llimos[j-1];
					}
					for(int j = 0;j <= qr-clus*s;j++){
						ans = Math.min(ans, limos[clus] + llimos[j]);
					}
				}
			}
			
			out.println(ans);
		}
	}
	
	int[] doFractionalCascading(int[][] b, int[][] bind, int l, int r, int v)
	{
		if(l > r)return new int[0];
		int[] inds = new int[r-l+1];
		int ub = upperBound(b[l], v);
		inds[0] = ub == -1 ? -1 : bind[l][ub];
		for(int i = l+1;i <= r;i++){
			int ind = ub == -1 ? -1 : 2*(ub-bind[i-1][ub])-1;
			ub = ind+1 < b[i].length && v >= b[i][ind+1] ? ind+1 : ind;
			inds[i-l] = ub == -1 ? -1 : bind[i][ub];
		}
		return inds;
	}
	
	
	public static int upperBound(int[] a, int v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] <= v){
				low = h;
			}else{
				high = h;
			}
		}
		return low;
	}
	
	public int[][][] prepareFractionalCascading(int[][] a)
	{
		int n = a.length;
		int[][] b = new int[n][];
		int[][] bind = new int[n][];
		b[n-1] = a[n-1];
		bind[n-1] = new int[a[n-1].length];
		for(int i = 0;i < bind[n-1].length;i++)bind[n-1][i] = i;
		for(int i = n-2;i >= 0;i--){
			b[i] = new int[a[i].length + b[i+1].length/2];
			bind[i] = new int[a[i].length + b[i+1].length/2];
			int q = 1, r = 0;
			for(int p = 0;p < a[i].length;p++){
				while(q < b[i+1].length && b[i+1][q] < a[i][p]){
					b[i][r] = b[i+1][q];
					bind[i][r] = r-1 >= 0 ? bind[i][r-1] : -1;
					r++; q+=2;
				}
				b[i][r] = a[i][p];
				bind[i][r] = p;
				r++;
			}
			while(q < b[i+1].length){
				b[i][r] = b[i+1][q];
				bind[i][r] = r-1 >= 0 ? bind[i][r-1] : -1;
				r++; q+=2;
			}
			assert r == b[i].length;
		}
		return new int[][][]{b, bind};
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
	
	public static void main(String[] args) throws Exception { new E2FF().run(); }
	
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