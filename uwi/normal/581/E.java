//package round322;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int S;
	
	void solve()
	{
		int e = ni(), s = ni(), n = ni(), m = ni();
		S = s;
		int[][] es = new int[n+m][];
		for(int i = 0;i < n;i++){
			int t = ni(), x = ni();
			es[i] = new int[]{x, t, -1, -1, -1};
		}
		for(int i = 0;i < m;i++){
			int x = ni();
			es[i+n] = new int[]{x, -1, i, -1};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return -(a[2] - b[2]);
			}
		});
		int[][] last = new int[4][];
		last[3] = new int[]{e, 3, -1, n+m, 0};
		
		int[][] stack = new int[n+3][];
		int[][] typelens = new int[n+3][4];
		int sp = 0;
		int[][] ret = new int[m][];
		// stype
		// 
		stack[sp++] = last[3];
		for(int i = n+m-1;i >= 0;i--){
			if(es[i][0] > e)continue;
			es[i][3] = i;
			int[] next = null;
			int curtype = es[i][1];
			if(curtype == -1)curtype = 3;
			for(int j = 1;j <= 3;j++){
				if(last[j] != null && last[j][0] > es[i][0] + s)last[j] = null;
				if(last[j] != null){
					if(next != null){
						if(next[1] < curtype && last[j][1] >= curtype){
						}else if(next[1] < curtype){
							if(!(last[j][1] > next[1] || last[j][1] == next[1] && last[j][0] > next[0])){
								continue;
							}
						}else{
							if(next[0] < last[j][0]){
								continue;
							}
						}
					}
					next = last[j];
				}
			}
			
			if(next != null){
				if(es[i][1] != -1){
					sp = next[4] + 1;
					stack[sp] = es[i];
					if(next[1] >= es[i][1]){
						for(int j = 1;j <= 3;j++)typelens[sp][j] = typelens[sp-1][j];
						typelens[sp][es[i][1]] += stack[sp-1][0] - stack[sp][0];
					}else{
						int ev = s - (stack[sp-1][0] - stack[sp][0]);
						next[0] += ev;
						typelens[sp-1][next[1]] -= ev;
						for(int j = 1;j <= 3;j++)typelens[sp][j] = typelens[sp-1][j];
						typelens[sp][es[i][1]] += s;
					}
					es[i][4] = sp;
					sp++;
					last[es[i][1]] = es[i];
				}else{
					int[] ltl = Arrays.copyOf(typelens[next[4]], 4);
					int ev = s - (next[0] - es[i][0]);
					ltl[next[1]] -= ev;
					ltl[3] += s;
					ret[es[i][2]] = new int[]{ltl[1], ltl[2]};
				}
			}else{
				if(es[i][1] == -1){
					ret[es[i][2]] = new int[]{-1, -1};
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			out.println(ret[i][0] + " " + ret[i][1]);
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