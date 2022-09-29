//package round499;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.TreeMap;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	// 9 10
	// 7 2
	// 7 8
	
	void solve()
	{
		ni(); ni(); ni();
		
		int n = ni(), m = ni(), Q = ni();
		int[][] coin = new int[n][];
		for(int i = 0;i < n;i++){
			coin[i] = na(3);
		}
		int[][] coout = new int[m][];
		for(int i = 0;i < m;i++){
			coout[i] = na(3);
		}
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni(), ni(), ni(), i};
		}
		
		int[] anss = new int[Q];
		// 1:open
		// -1:closed
		Arrays.fill(anss, -2);
		
		int[] mx = mm(coin, 0);
		int[] my = mm(coin, 1);
		int[] mz = mm(coin, 2);
		for(int[] o : coout){
			if(
					mx[0] <= o[0] && o[0] <= mx[1] &&
					my[0] <= o[1] && o[1] <= my[1] &&
					mz[0] <= o[2] && o[2] <= mz[1]){
				out.println("INCORRECT");
				return;
			}
		}
		out.println("CORRECT");
		
		for(int i = 0;i < Q;i++){
			int[] q = qs[i];
			if(
					mx[0] <= q[0] && q[0] <= mx[1] &&
					my[0] <= q[1] && q[1] <= my[1] &&
					mz[0] <= q[2] && q[2] <= mz[1]){
				anss[i] = 1;
			}
		}
		
		go(qs, anss, 0, 1, 2, mx, my, mz, coout);
		{
			for(int[] q : qs)q[0] = -q[0];
			for(int[] c : coout)c[0] = -c[0];
			{int d = -mx[0]; mx[0] = -mx[1]; mx[1] = d;}
		}
		go(qs, anss, 0, 1, 2, mx, my, mz, coout);
		{
			for(int[] q : qs)q[0] = -q[0];
			for(int[] c : coout)c[0] = -c[0];
			{int d = -mx[0]; mx[0] = -mx[1]; mx[1] = d;}
		}
		go(qs, anss, 1, 0, 2, my, mx, mz, coout);
		{
			for(int[] q : qs)q[1] = -q[1];
			for(int[] c : coout)c[1] = -c[1];
			{int d = -my[0]; my[0] = -my[1]; my[1] = d;}
		}
		go(qs, anss, 1, 0, 2, my, mx, mz, coout);
		{
			for(int[] q : qs)q[1] = -q[1];
			for(int[] c : coout)c[1] = -c[1];
			{int d = -my[0]; my[0] = -my[1]; my[1] = d;}
		}
		go(qs, anss, 2, 0, 1, mz, mx, my, coout);
		{
			for(int[] q : qs)q[2] = -q[2];
			for(int[] c : coout)c[2] = -c[2];
			{int d = -mz[0]; mz[0] = -mz[1]; mz[1] = d;}
		}
		go(qs, anss, 2, 0, 1, mz, mx, my, coout);
		{
			for(int[] q : qs)q[2] = -q[2];
			for(int[] c : coout)c[2] = -c[2];
			{int d = -mz[0]; mz[0] = -mz[1]; mz[1] = d;}
		}
		for(int v : anss){
			if(v == 1){
				out.println("OPEN");
			}else if(v == 0){
				out.println("UNKNOWN");
			}else{
				out.println("CLOSED");
			}
		}
	}
	
	void go(int[][] qs, int[] anss, 
			int aind, int bind, int cind,
			int[] ma, int[] mb, int[] mc, int[][] co)
	{
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return (a[aind] - b[aind]);
			}
		});
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return (a[aind] - b[aind]);
			}
		});
		int p = 0;
		int minb = Integer.MIN_VALUE / 2,
				maxb = Integer.MAX_VALUE / 2;
		int minc = Integer.MIN_VALUE / 2,
				maxc = Integer.MAX_VALUE / 2;
		TreeMap<Integer, Integer> lu = new TreeMap<>();
		TreeMap<Integer, Integer> ru = new TreeMap<>();
		TreeMap<Integer, Integer> ld = new TreeMap<>();
		TreeMap<Integer, Integer> rd = new TreeMap<>();
		for(int[] q : qs){
			while(p < co.length && co[p][aind] <= q[aind]){
				if(co[p][aind] < ma[0]){
					p++;
					continue;
				}
				if(
						mb[0] <= co[p][bind] && co[p][bind] <= mb[1] &&
						mc[0] <= co[p][cind] && co[p][cind] <= mc[1]
								){
					return;
				}
				if(co[p][bind] < mb[0] && co[p][cind] > mc[1]){
					int x = co[p][bind], y = co[p][cind];
					TreeMap<Integer, Integer> tar = lu;
					while(true){
						Integer f = tar.floorKey(x);
						if(f != null && tar.get(f) >= y){
							tar.remove(f);
						}else{
							break;
						}
					}
					Integer c = tar.ceilingKey(x);
					if(c == null || tar.get(c) > y){
						tar.put(x, y);
					}
					p++;
					continue;
				}
				if(co[p][bind] < mb[0] && co[p][cind] < mc[0]){
					int x = co[p][bind], y = co[p][cind];
					TreeMap<Integer, Integer> tar = ld;
					while(true){
						Integer f = tar.floorKey(x);
						if(f != null && tar.get(f) <= y){
							tar.remove(f);
						}else{
							break;
						}
					}
					Integer c = tar.ceilingKey(x);
					if(c == null || tar.get(c) < y){
						tar.put(x, y);
					}
					p++;
					continue;
				}
				if(co[p][bind] > mb[1] && co[p][cind] < mc[0]){
					int x = co[p][bind], y = co[p][cind];
					TreeMap<Integer, Integer> tar = rd;
					while(true){
						Integer f = tar.ceilingKey(x);
						if(f != null && tar.get(f) <= y){
							tar.remove(f);
						}else{
							break;
						}
					}
					Integer c = tar.floorKey(x);
					if(c == null || tar.get(c) < y){
						tar.put(x, y);
					}
					p++;
					continue;
				}
				if(co[p][bind] > mb[1] && co[p][cind] > mc[1]){
					int x = co[p][bind], y = co[p][cind];
					TreeMap<Integer, Integer> tar = ru;
					while(true){
						Integer f = tar.ceilingKey(x);
						if(f != null && tar.get(f) >= y){
							tar.remove(f);
						}else{
							break;
						}
					}
					Integer c = tar.floorKey(x);
					if(c == null || tar.get(c) > y){
						tar.put(x, y);
					}
					p++;
					continue;
				}
				if(co[p][bind] < mb[0]){
					minb = Math.max(minb, co[p][bind]);
				}
				if(co[p][bind] > mb[1]){
					maxb = Math.min(maxb, co[p][bind]);
				}
				if(co[p][cind] < mc[0]){
					minc = Math.max(minc, co[p][cind]);
				}
				if(co[p][cind] > mc[1]){
					maxc = Math.min(maxc, co[p][cind]);
				}
				p++;
			}
			if(q[aind] > ma[1]){
				if(mb[0] <= q[bind] && q[bind] <= mb[1] &&
						mc[0] <= q[cind] && q[cind] <= mc[1]){
					anss[q[3]] = 0;
				}else if(minb < q[bind] && q[bind] < maxb &&
						minc < q[cind] && q[cind] < maxc){
					if(q[bind] < mb[0] && q[cind] > mc[1]){
						Integer f = lu.ceilingKey(q[bind]);
						if(f == null || q[cind] < lu.get(f)){
							anss[q[3]] = 0;
						}
						continue;
					}
					if(q[bind] < mb[0] && q[cind] < mc[0]){
						Integer f = ld.ceilingKey(q[bind]);
						if(f == null || q[cind] > ld.get(f)){
							anss[q[3]] = 0;
						}
						continue;
					}
					if(q[bind] > mb[1] && q[cind] > mc[1]){
						Integer f = ru.floorKey(q[bind]);
						if(f == null || q[cind] < ru.get(f)){
							anss[q[3]] = 0;
						}
						continue;
					}
					if(q[bind] > mb[1] && q[cind] < mc[0]){
						Integer f = rd.floorKey(q[bind]);
						if(f == null || q[cind] > rd.get(f)){
							anss[q[3]] = 0;
						}
						continue;
					}
					anss[q[3]] = 0;
				}
			}
		}
	}
	
	int[] mm(int[][] co, int ind)
	{
		int min = Integer.MAX_VALUE / 2, max = Integer.MIN_VALUE / 2;
		for(int[] c : co){
			min = Math.min(min, c[ind]);
			max = Math.max(max, c[ind]);
		}
		return new int[]{min, max};
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