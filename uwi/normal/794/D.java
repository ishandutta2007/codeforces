//package round414;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D {
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
		Random gen = new Random();
		int[][] g = packU(n, from, to);
		for(int[] row : g){
			Arrays.sort(shuffle(row, gen));
		}
		
		int[] label = new int[n];
		boolean[] ved = new boolean[n];
		
		int labelBase = 1;
		int I = 99999999;
		Arrays.fill(label, I);
		int[] hist = new int[20000000];
		int hp = 0;
		
		outer:
		for(int i = 0;i < n;i++){
			if(ved[i] || label[i] != I)continue;
			hp = 0;
			
			int deg = g[i].length;
			int gter = -1;
			for(int e : g[i]){
				if(g[e].length == deg)continue;
				if(g[e].length < deg)continue outer;
				if(gter == -1){
					gter = g[e].length;
				}else if(gter != g[e].length)continue outer;
			}
			
			for(int e : g[i]){
				for(int f : g[i]){
					if(e == f)continue;
					if(Arrays.binarySearch(g[e], f) < 0)continue outer;
				}
			}
			
			ved[i] = true;
			for(int e : g[i]){
				if(deg == g[e].length)ved[e] = true;
			}
			
			int cur = -1;
			hist[hp++] = i;
			label[i] = labelBase;
			for(int e : g[i]){
				if(deg == g[e].length){
					hist[hp++] = e;
					label[e] = labelBase;
				}else{
					hist[hp++] = e;
					label[e] = labelBase+1;
					cur = e;
				}
			}
			labelBase++;

			while(cur != -1){
				int phase = labelBase;
				gter = -1;
				for(int e : g[cur]){
					if(label[e] <= phase)continue;
					if(gter == -1){
						gter = g[e].length;
					}else if(gter != g[e].length){
						while(hp > 0)label[hist[--hp]] = I;
						continue outer;
					}
				}
				
				for(int e : g[cur]){
					if(label[e] < phase)continue;
					for(int f : g[cur]){
						if(label[f] < phase)continue;
						if(e == f)continue;
						if(Arrays.binarySearch(g[e], f) < 0){
							while(hp > 0)label[hist[--hp]] = I;
							continue outer;
						}
					}
				}
				
				int nex = -1;
				for(int e : g[cur]){
					if(label[e] <= phase)continue;
					hist[hp++] = e;
					label[e] = labelBase+1;
					nex = e;
				}
				cur = nex;
				labelBase++;
			}
			labelBase+=2;
		}
		for(int v : label){
			if(v >= I){
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for(int v : label)out.print(v + " " );
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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