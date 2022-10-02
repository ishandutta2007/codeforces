//package round290;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Triangle
	{
		int[] a;
		Triangle[] neis;
		
		public Triangle()
		{
			
		}

		@Override
		public String toString() {
			String s = "Triangle [a=" + Arrays.toString(a) + "]";
			for(Triangle t : neis){
				if(t == null){
					s += "[null]";
				}else{
					s += Arrays.toString(t.a);
				}
			}
			return s;
		}
	}
	
	void solve()
	{
		int n = ni();
		List<int[]> flipf = go(n);
		List<int[]> flipb = go(n);
		out.println(flipf.size() + flipb.size());
		for(int i = 0;i < flipf.size();i++){
			out.println((flipf.get(i)[0]+1) + " " + (flipf.get(i)[1]+1));
		}
		for(int i = flipb.size()-1;i >= 0;i--){
			out.println((flipb.get(i)[2]+1) + " " + (flipb.get(i)[3]+1));
		}
	}
	
	List<int[]> go(int n)
	{
		Triangle[] tris = new Triangle[n-2];
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < n-3;i++){
			int from = ni()-1, to = ni()-1;
			g[from][to] = g[to][from] = true;
		}
		for(int i = 0;i < n;i++){
			g[i][(i+1)%n] = g[(i+1)%n][i] = true;
		}
		int[] deg = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[i][j]){
					deg[i]++;
				}
			}
		}
		Triangle[][] tg = new Triangle[n][n];
		
		int q = 0;
		for(int rep = 0;rep < n-2;rep++){
			for(int i = 0;i < n;i++){
				if(deg[i] == 2){
					int[] tri = new int[3];
					int p = 0;
					tri[p++] = i;
					for(int j = 0;j < n;j++){
						if(g[i][j]){
							tri[p++] = j;
							g[i][j] = g[j][i] = false;
							deg[i]--; deg[j]--;
						}
					}
					assert p == 3;
					Arrays.sort(tri);
					Triangle[] nei = new Triangle[3]; 
					Triangle x = new Triangle();
					for(int j = 0;j < 3;j++){
						int k = (j+1)%3, l = (j+2)%3;
						nei[j] = tg[tri[k]][tri[l]];
						
						Triangle op = tg[tri[k]][tri[l]];
						if(op != null){
							for(int m = 0;m < 3;m++){
								if(Arrays.binarySearch(tri, op.a[m]) < 0){
									op.neis[m] = x;
									break;
								}
							}
						}
					}
					x.a = tri;
					x.neis = nei;
					tris[q++] = x;
					for(int j = 0;j < 3;j++){
						int k = (j+1)%3, l = (j+2)%3;
						if(tri[k] != i && tri[l] != i){
							tg[tri[k]][tri[l]] = tg[tri[l]][tri[k]] = tris[q-1];
						}
					}
					break;
				}
			}
		}
		
		List<int[]> flip = new ArrayList<int[]>();
		outer:
		while(true){
			for(int i = 0;i < n-2;i++){
				Triangle t = tris[i];
				for(int j = 0;j < 3;j++){
					if(t.a[j] == 0 && t.neis[j] != null){
						for(int k = 0;k < n-2;k++){
							if(tris[k] == t.neis[j]){
								// i,k flip
								int j1 = (j+1)%3, j2 = (j+2)%3;
								int rev = tris[k].a[0]+tris[k].a[1]+tris[k].a[2]-t.a[j1]-t.a[j2];
								flip.add(new int[]{t.a[j1], t.a[j2], t.a[j], rev});
								
								int[] ni = new int[]{t.a[j], t.a[j1], rev};
								int[] nk = new int[]{t.a[j], t.a[j2], rev};
								Arrays.sort(ni);
								Arrays.sort(nk);
								Triangle[] neii = new Triangle[3]; 
								Triangle[] neik = new Triangle[3]; 
								int indrev = -1;
								for(int l = 0;l < 3;l++){
									if(tris[k].a[l] == rev){
										indrev = l;
										break;
									}
								}
								
								Triangle newi = new Triangle();
								Triangle newk = new Triangle();
								for(int l = 0;l < 3;l++){
									if(ni[l] == rev){
										neii[l] = t.neis[j2];
									}else if(ni[l] == t.a[j]){
										neii[l] = tris[k].neis[(indrev+1)%3];
									}else if(ni[l] == t.a[j1]){
										neii[l] = newk;
									}
								}
								for(int l = 0;l < 3;l++){
									if(nk[l] == rev){
										neik[l] = t.neis[j1];
									}else if(nk[l] == t.a[j]){
										neik[l] = tris[k].neis[(indrev+2)%3];
									}else if(nk[l] == t.a[j2]){
										neik[l] = newi;
									}
								}
								newi.a = ni; newi.neis = neii;
								newk.a = nk; newk.neis = neik;
								tris[i] = newi;
								tris[k] = newk;
								continue outer;
							}
						}
						throw new RuntimeException();
					}
				}
			}
			break;
		}
		return flip;
	}
	
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
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n-3; i++) {
//			sb.append(1 + " ");
//			sb.append(i+3 + " ");
//		}
//		for (int i = 0; i < n-3; i++) {
//			sb.append(i+2 + " ");
//			sb.append(n + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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