//package round567;
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
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni(), ni(), ni(), -1};
		}
		if(splitable(co) == 1){
			out.println("YES");
		}else{
			out.println("NO");
		}
	}
	
	int splitable(int[][] co)
	{
		int res = splitable(co, 0);
		if(res == 0){
			res = splitable(co, 1);
		}
		return res;
	}
	
	int splitable(int[][] co, int ind)
	{
		if(co.length <= 1)return 1;
//		tr(co.length, ind);
		int n = co.length;
		for(int i = 0;i < n;i++){
			co[i][4] = i;
		}
		int[][] cob = Arrays.copyOf(co, n);
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[ind] - b[ind];
			}
		});
		Arrays.sort(cob, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[ind+2] - b[ind+2];
			}
		});
		boolean[] done = new boolean[n];
		int lreach = co[0][ind+2], rreach = cob[n-1][ind];
		for(int i = 0, j = n-1;;i++,j--){
			if(co[i][ind] >= lreach){
				assert i > 0;
				return splitable(Arrays.copyOf(co, i)) == 1 &&
						splitable(Arrays.copyOfRange(co, i, n)) == 1 ? 1 : -1;
			}else{
				lreach = Math.max(co[i][ind+2], lreach);
			}
			if(done[co[i][4]])break;
			done[co[i][4]] = true;
			if(cob[j][ind+2] <= rreach){
				assert j < n-1;
				return splitable(Arrays.copyOf(cob, j+1)) == 1 &&
						splitable(Arrays.copyOfRange(cob, j+1, n)) == 1 ? 1 : -1;
			}else{
				rreach = Math.min(rreach, cob[j][ind]);
			}
			if(done[cob[j][4]])break;
			done[cob[j][4]] = true;
		}
		return 0;
	}
	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			int x = gen.nextInt(1000000000);
//			int y = gen.nextInt(1000000000);
//			sb.append(x + " " + y + " ");
//			x += gen.nextInt(10000);
//			y += gen.nextInt(10000);
//			sb.append(x + " " + y + "\n");
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