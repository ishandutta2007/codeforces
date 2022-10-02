//package round162;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class CRe2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), q = ni();
		int[] v = na(n);
		int[] c = na(n);
		long[] maxs = new long[n+1]; // h
		long I = Long.MIN_VALUE / 2;
		maxs[n] = I;
		for(int i = 0;i < q;i++){
			long a = ni(), b = ni();
			Arrays.fill(maxs, I);
			int[] rank = {n, n}; // ranking
			long ret = 0;
			outer:
			for(int j = 0;j < n;j++){
//				tr(maxs, rank);
				long nex = I;
				// same
				nex = maxs[c[j]] + v[j]*a;
				
				// diff
				for(int k = 0;k < 2;k++){
					if(rank[k] != c[j]){
						nex = Math.max(nex, maxs[rank[k]] + v[j]*b);
						break;
					}
				}
				
				// first
				nex = Math.max(nex, v[j]*b);
				ret = Math.max(ret, nex);
				
				// update dp
				if(nex > maxs[c[j]]){
					maxs[c[j]] = nex;
					
					// update rank
					for(int k = 0;k < 2;k++){
						if(rank[k] == c[j]){
							for(int l = k;l >= 1 && maxs[rank[l-1]] < maxs[rank[l]];l--){
								int dum;
								dum = rank[l-1]; rank[l-1] = rank[l]; rank[l] = dum;
							}
							continue outer;
						}
					}
					for(int k = 0;k < 2;k++){
						if(nex > maxs[rank[k]]){
							for(int l = 2-1;l > k;l--){
								rank[l] = rank[l-1];
							}
							rank[k] = c[j];
							break;
						}
					}
				}
			}
			out.println(ret);
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
	
	public static void main(String[] args) throws Exception { new CRe2().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}