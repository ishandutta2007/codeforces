//package round150;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), h = ni(), t = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		for(int i = 0;i < g.length;i++){
			Arrays.sort(g[i]);
		}
		
		for(int i = 0;i < m;i++){
			int a = from[i], b = to[i];
			if(check(a, b, g, h, t)){
				construct(a, b, g, h, t);
				return;
			}
			if(check(b, a, g, h, t)){
				construct(b, a, g, h, t);
				return;
			}
		}
		out.println("NO");
	}
	
	void construct(int a, int b, int[][] g, int h, int t)
	{
		out.println("YES");
		out.println((a+1) + " " + (b+1));
		int p = 0;
		int head = 0;
		StringBuilder shead = new StringBuilder();
		StringBuilder stail = new StringBuilder();
		BitSet common = new BitSet();
		for(int e : g[a]){
			if(e == b)continue;
			while(p < g[b].length && g[b][p] < e)p++;
			if(p < g[b].length && g[b][p] == e){
				common.set(e);
			}else{
				shead.append(" " + (e+1));
				head++;
				if(head == h){
					int q = 0;
					for(int f : g[b]){
						if(f == a)continue;
						if(q++ == t)break;
						stail.append(" " + (f+1));
					}
					out.println(shead.substring(1));
					out.println(stail.substring(1));
					return;
				}
			}
		}
		int left = h - head;
		BitSet proh = new BitSet();
		for(int e : g[a]){
			if(e == b)continue;
			if(common.get(e)){
				proh.set(e);
				shead.append(" " + (e+1));
				left--;
				if(left == 0){
					break;
				}
			}
		}
		int q = 0;
		for(int f : g[b]){
			if(f == a)continue;
			if(proh.get(f))continue;
			if(q++ == t)break;
			stail.append(" " + (f+1));
		}
		out.println(shead.substring(1));
		out.println(stail.substring(1));
	}
	
	static boolean check(int a, int b, int[][] g, int h, int t){
		if(g[a].length >= h+1 && g[b].length >= t+1){
		}else{
			return false;
		}
		
		int p = 0;
		int head = 0;
		int common = 0;
		for(int e : g[a]){
			if(e == b)continue;
			while(p < g[b].length && g[b][p] < e)p++;
			if(p < g[b].length && g[b][p] == e){
				common++;
			}else{
				head++;
				if(head == h){
					return true;
				}
			}
			if(head+common == h+t)return true;
		}
		if(g[b].length-1 - (h-head) >= t)return true;
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
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}