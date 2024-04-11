//package gb2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), h = ni(), w = ni();
		char[] s = ns(n);
		String S = "DRUL";
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int r = 0, c = 0;
		int maxr = 0, maxc = 0;
		int minr = 0, minc = 0;
		int Z = 1000005;
		int o = Z/2;
		long[] whenr = new long[Z];
		long[] whenc = new long[Z];
		long I = 1000000000000000L;
		Arrays.fill(whenr, I);
		Arrays.fill(whenc, I);
		whenr[o] = whenc[o] = 0;
		for(int i = 0;i < n;i++){
			int k = S.indexOf(s[i]);
			r += dr[k]; c += dc[k];
			if(r > maxr)maxr = r;
			if(c > maxc)maxc = c;
			if(r < minr)minr = r;
			if(c < minc)minc = c;
			if(whenr[r+o] == I)whenr[r+o] = i+1;
			if(whenc[c+o] == I)whenc[c+o] = i+1;
		}
		if(r == 0 && c == 0 && maxr-minr+1 <= h && maxc-minc+1 <= w){
			out.println(-1);
			return;
		}
		
		int mod = 1000000007;
		long ret = 0;
		if(r < 0){
			r = -r;
			for(int i = o+1, j =o-1;i < Z && j >= 0;i++,j--){
				long d = whenr[i]; whenr[i] = whenr[j]; whenr[j] = d;
			}
			int d = maxr; maxr = minr; minr = d;
			maxr = -maxr; minr = -minr;
		}
		if(c < 0){
			c = -c;
			for(int i = o+1, j =o-1;i < Z && j >= 0;i++,j--){
				long d = whenc[i]; whenc[i] = whenc[j]; whenc[j] = d;
			}
			int d = maxc; maxc = minc; minc = d;
			maxc = -maxc; minc = -minc;
		}
		
		if(r > 0){
			for(int i = o+1;i < Z;i++){
				if(whenr[i] == I){
					whenr[i] = whenr[i-r] + n;
				}
			}
		}
		if(c > 0){
			for(int i = o+1;i < Z;i++){
				if(whenc[i] == I){
					whenc[i] = whenc[i-c] + n;
				}
			}
		}
		
		long big = 8L*mod*mod;
		int rowd = 0, rowu = h-1;
		int cold = 0, colu = w-1;
		while(rowd <= rowu && cold <= colu){
			long trd = whenr[-rowd-1+o];
			long tru = whenr[h-1-rowu+1+o];
			long tcd = whenc[-cold-1+o];
			long tcu = whenc[w-1-colu+1+o];
			if(trd < tru && trd < tcd && trd < tcu){
				ret += (long)trd%mod*(colu-cold+1);
				rowd++;
			}else if(tru < trd && tru < tcd && tru < tcu){
				ret += (long)tru%mod*(colu-cold+1);
				rowu--;
			}else if(tcd < tcu && tcd < trd && tcd < tru){
				ret += (long)tcd%mod*(rowu-rowd+1);
				cold++;
			}else if(tcu < tcd && tcu < trd && tcu < tru){
				ret += (long)tcu%mod*(rowu-rowd+1);
				colu--;
			}else{
				throw new RuntimeException();
			}
			if(ret >= big)ret -= big;
		}
		out.println(ret%mod);
		
//		// [-minr-1+1, h-1-(maxr-1)-1]
//		// [-minc-1+1, w-1-(maxc-1)-1]
//		long minh = -minr-1+1, maxh = h-1-(maxr-1)-1;
//		long minw = -minc-1+1, maxw = w-1-(maxc-1)-1;
//		
//		long cornerlu = 0;
//		{
//			int rowd = 0, rowu = -minr-1;
//			int cold = 0, colu = -minc-1;
//			while(rowd <= rowu && cold <= colu){
//				int tr = whenr[-rowd-1+o];
//				int tc = whenc[-cold-1+o];
//				if(tr < tc){
//					cornerlu += (long)tr*(colu-cold+1);
//					rowd++;
//				}else if(tc < tr){
//					cornerlu += (long)tc*(rowu-rowd+1);
//					cold++;
//				}else{
//					throw new RuntimeException();
//				}
//			}
//		}
//		long cornerru = 0;
//		{
//			int rowd = 0, rowu = -minr-1;
//			int cold = 0, colu = maxc-1;
//			while(rowd <= rowu && cold <= colu){
//				int tr = whenr[-rowd-1+o];
//				int tc = whenc[maxc-1-colu+1+o];
//				if(tr < tc){
//					cornerru += (long)tr*(colu-cold+1);
//					rowd++;
//				}else if(tc < tr){
//					cornerru += (long)tc*(rowu-rowd+1);
//					colu--;
//				}else{
//					throw new RuntimeException();
//				}
//			}
//		}
//		long cornerrd = 0;
//		{
//			int rowd = 0, rowu = maxr-1;
//			int cold = 0, colu = maxc-1;
//			while(rowd <= rowu && cold <= colu){
//				int tr = whenr[maxr-1-rowu+1+o];
//				int tc = whenc[maxc-1-colu+1+o];
//				if(tr < tc){
//					cornerrd += (long)tr*(colu-cold+1);
//					rowu--;
//				}else if(tc < tr){
//					cornerrd += (long)tc*(rowu-rowd+1);
//					colu--;
//				}else{
//					throw new RuntimeException();
//				}
//			}
//		}
//		long cornerld = 0;
//		{
//			int rowd = 0, rowu = maxr-1;
//			int cold = 0, colu = -minc-1;
//			while(rowd <= rowu && cold <= colu){
//				int tr = whenr[maxr-1-rowu+1+o];
//				int tc = whenc[-cold-1+o];
//				if(tr < tc){
//					cornerld += (long)tr*(colu-cold+1);
//					rowu--;
//				}else if(tc < tr){
//					cornerld += (long)tc*(rowu-rowd+1);
//					cold++;
//				}else{
//					throw new RuntimeException();
//				}
//			}
//		}
		
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