//package round460;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	List<int[]> all = new ArrayList<>();
	
	long h(int[] a)
	{
		long h = 0;
		for(int v : a){
			h = h * 1000000009 + v;
		}
		return h;
	}
	
	void solve()
	{
		dfs(0, 8, new int[5]);
		
		Map<Long, Integer> map = new HashMap<>();
		for(int i = 0;i < all.size();i++){
			map.put(h(all.get(i)), i);
		}
		
		int[][] win = new int[495][495];
		for(int i = 0;i < 495;i++){
			win[0][i] = 1;
		}
		
		int[][][] nexs = new int[495][495][];
		int[] ns = new int[16];
		for(int i = 0;i < 495;i++){
			for(int j = 0;j < 495;j++){
				int[] a = all.get(i);
				int[] b = all.get(j);
				int p = 0;
				for(int k = 1;k <= 4;k++){
					if(a[k] == 0)continue;
					for(int l = 1;l <= 4;l++){
						if(b[l] == 0)continue;
						int[] na = Arrays.copyOf(a, 5);
						na[k]--;
						na[(k+l)%5]++;
						ns[p++] = map.get(h(na));
					}
				}
				nexs[i][j] = Arrays.copyOf(ns, p);
			}
		}
		
		while(true){
			int ch = 0;
			
			for(int i = 0;i < 495;i++){
				inner:
				for(int j = 0;j < 495;j++){
					if(win[i][j] != 0)continue;
					int z = 0;
					for(int nex : nexs[i][j]){
						if(win[j][nex] == -1){
							win[i][j] = 1;
							ch++;
							continue inner;
						}
						if(win[j][nex] == 0)z = 1;
					}
					if(z == 0){
						win[i][j] = -1;
						ch++;
					}
				}
			}
			if(ch == 0)break;
		}
		
		for(int Q = ni();Q > 0;Q--){
			int turn = ni();
			if(turn == 0){
				int[] a = nf(8);
				int[] b = nf(8);
				int res = win[map.get(h(a))][map.get(h(b))];
				if(res == 1){
					out.println("Alice");
				}else if(res == -1){
					out.println("Bob");
				}else{
					out.println("Deal");
				}
			}else{
				int[] a = nf(8);
				int[] b = nf(8);
				int res = win[map.get(h(b))][map.get(h(a))];
				if(res == 1){
					out.println("Bob");
				}else if(res == -1){
					out.println("Alice");
				}else{
					out.println("Deal");
				}
			}
		}
	}
	
	int[] nf(int n)
	{
		int[] ret = new int[5];
		for(int i = 0;i < n;i++){
			ret[ni()]++;
		}
		return ret;
	}
	
	void dfs(int num, int rem, int[] a)
	{
		if(num == a.length){
			if(rem == 0){
				all.add(Arrays.copyOf(a, 5));
			}
			return;
		}
		
		for(int i = rem;i >= 0;i--){
			a[num] = i;
			dfs(num+1, rem-i, a);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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