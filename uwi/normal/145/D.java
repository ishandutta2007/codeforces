//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.TreeSet;

public class P104D_2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		List<Integer> lns = new ArrayList<Integer>();
		enumLuckyNumbers(1000000001, 0, lns);
		Collections.sort(lns);
		
		int[][] lus = new int[1001][];
		int p = 0;
		int[] lp = new int[2000];
		for(int i = 0;i < n;i++){
			int ind = Collections.binarySearch(lns, a[i]);
			if(ind >= 0){
				lus[p++] = new int[]{i, ind};
				lp[ind]++;
			}
		}
		if(p == 0){
			long ret = 0;
			for(int i = 0;i < n;i++){
				ret += (long)(n-i)*i*(i+1)/2;
			}
			out.println(ret);
		}else{
			int[][] lg = new int[2000][];
			for(int i = 0;i < 2000;i++){
				lg[i] = new int[lp[i]];
			}
			for(int i = p-1;i >= 0;i--){
				lg[lus[i][1]][--lp[lus[i][1]]] = i;
			}
			
			long ret = 0;
			for(int i = 0;i < p;i++){
				TreeSet<Integer> ts = new TreeSet<Integer>();
				ts.add(-1);
				ts.add(i);
				int sp = lus[i][0]-(i == 0 ? -1 : lus[i-1][0]);
//				tr(i, sp);
				long count = (long)lus[i][0]*(lus[i][0]+1)/2;
				for(int j = i;j < p;j++){
					int nex = (j+1 < p ? lus[j+1][0] : n) - lus[j][0];
					for(int e : lg[lus[j][1]]){
						if(e >= i)break;
						if(ts.contains(e))break;
						int h = ts.higher(e);
						int l = ts.lower(e);
						ts.add(e);
						int xh = h == -1 ? -1 : lus[h][0];
						int xl = l == -1 ? -1 : lus[l][0];
						count -= (long)(xh-xl)*(xh-xl-1)/2;
						count += (long)(xh-lus[e][0])*(xh-lus[e][0]-1)/2;
						count += (long)(lus[e][0]-xl)*(lus[e][0]-xl-1)/2;
					}
//					tr(i,j,nex,count);
					int g = ts.lower(i);
					g = g == -1 ? -1 : lus[g][0];
					
					int last = lus[i][0] - g - 1;
					ret += (count*sp
							-(long)last*(last+1)/2*sp
							+(long)last*(last+1)*(last+2)/6
							-(long)(last-sp)*(last-sp+1)*(last-sp+2)/6
							)*nex;
				}
			}
			
			int nex = lus[0][0];
			int u = 0;
			for(int i = 0;i < n;i++){
				if(nex == i){
					u++;
					if(u < p){
						nex = lus[u][0];
					}else{
						nex = n;
					}
				}else{
					int q = nex-i;
					ret += (long)q*(nex-q+1)*(nex-q)/2;
				}
			}
			out.println(ret);
				// q, (nex-q)*(nex-q-1)/2
				// q*(s-q)*(s-q-1)/2
		}
	}
	
	void enumLuckyNumbers(long lim, long cur, List<Integer> lns)
	{
		if(cur > lim)return;
		if(cur != 0)lns.add((int)cur);
		enumLuckyNumbers(lim, cur*10+4, lns);
		enumLuckyNumbers(lim, cur*10+7, lns);
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
	
	public static void main(String[] args) throws Exception { new P104D_2().run(); }
	
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