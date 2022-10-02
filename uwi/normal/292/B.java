//package corc2013.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		boolean isb = isBus(g, n, m);
		boolean isr = isRing(g, n, m);
		boolean iss = isStar(g, n, m);
		if(isb && !isr && !iss){
			out.println("bus topology");
		}else if(isr && !isb && !iss){
			out.println("ring topology");
		}else if(iss && !isb && !isr){
			out.println("star topology");
		}else{
			out.println("unknown topology");
		}
	}
	
	boolean isBus(int[][] g, int n, int m)
	{
		if(m != n-1)return false;
		for(int i = 0;i < n;i++){
			if(g[i].length == 1){
				BitSet ved = new BitSet();
				int cur = i;
				ved.set(cur);
				outer:
				while(true){
					for(int e : g[cur]){
						if(!ved.get(e)){
							ved.set(e);
							cur = e;
							continue outer;
						}
					}
					break;
				}
				if(ved.cardinality() == n){
					return true;
				}
				return false;
			}
		}
		return false;
	}
	
	boolean isRing(int[][] g, int n, int m)
	{
		if(m != n)return false;
		for(int i = 0;i < n;i++){
			if(g[i].length != 2){
				return false;
			}
		}
		
		BitSet ved = new BitSet();
		int cur = 0;
		ved.set(cur);
		outer:
		while(true){
			for(int e : g[cur]){
				if(!ved.get(e)){
					ved.set(e);
					cur = e;
					continue outer;
				}
			}
			break;
		}
		if(ved.cardinality() == n){
			return true;
		}
		return false;
	}
	
	boolean isStar(int[][] g, int n, int m)
	{
		if(m != n-1)return false;
		int cent = -1;
		for(int i = 0;i < n;i++){
			if(g[i].length == n-1){
				cent = i;
			}else if(g[i].length != 1){
				return false;
			}
		}
		if(cent != -1)return true;
		return false;
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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