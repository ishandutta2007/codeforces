//package round322;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] a = new int[3][];
		int S = 0;
		for(int i = 0;i < 3;i++){
			a[i] = na(2);
			S += a[i][0]*a[i][1];
		}
		int SS = (int)Math.sqrt(S);
		if(SS * SS != S){
			out.println(-1);
			return;
		}
		int[] ord = new int[3];
		for(int i = 0;i < 3;i++)ord[i] = i;
		do{
			int[] rot = new int[3];
			do{
				if(abc(a, ord, rot))return;
				if(a_bc(a, ord, rot))return;
			}while(inc(rot, 2));
		}while(nextPermutation(ord));
		out.println(-1);
	}
	
	boolean abc(int[][] a, int[] ord, int[] rot)
	{
		int[] x = Arrays.copyOf(a[ord[0]], 2);
		int[] y = Arrays.copyOf(a[ord[1]], 2);
		int[] z = Arrays.copyOf(a[ord[2]], 2);
		if(rot[0] == 1){ int d = x[0]; x[0] = x[1]; x[1] = d; }
		if(rot[1] == 1){ int d = y[0]; y[0] = y[1]; y[1] = d; }
		if(rot[2] == 1){ int d = z[0]; z[0] = z[1]; z[1] = d; }
		if(x[1] == y[1] && y[1] == z[1] && x[0] + y[0] + z[0] == x[1]){
			int n = x[1];
			out.println(n);
			char[][] ret = new char[n][n];
			for(int i = 0;i < x[0];i++)Arrays.fill(ret[i], (char)('A'+ord[0]));
			for(int i = 0;i < y[0];i++)Arrays.fill(ret[i+x[0]], (char)('A'+ord[1]));
			for(int i = 0;i < z[0];i++)Arrays.fill(ret[i+x[0]+y[0]], (char)('A'+ord[2]));
			for(int i = 0;i < n;i++){
				out.println(new String(ret[i]));
			}
			return true;
		}
		return false;
	}
	
	boolean a_bc(int[][] a, int[] ord, int[] rot)
	{
		int[] x = Arrays.copyOf(a[ord[0]], 2);
		int[] y = Arrays.copyOf(a[ord[1]], 2);
		int[] z = Arrays.copyOf(a[ord[2]], 2);
		if(rot[0] == 1){ int d = x[0]; x[0] = x[1]; x[1] = d; }
		if(rot[1] == 1){ int d = y[0]; y[0] = y[1]; y[1] = d; }
		if(rot[2] == 1){ int d = z[0]; z[0] = z[1]; z[1] = d; }
		if(x[1] == y[1] + z[1] && y[0] == z[0] && x[0] + y[0] == x[1]){
			int n = x[1];
			out.println(n);
			char[][] ret = new char[n][n];
			for(int i = 0;i < x[0];i++)Arrays.fill(ret[i], (char)('A'+ord[0]));
			for(int i = 0;i < y[0];i++){
				for(int j = 0;j < y[1];j++)ret[i+x[0]][j] = (char)('A'+ord[1]);
				for(int j = y[1];j < x[1];j++)ret[i+x[0]][j] = (char)('A'+ord[2]);
			}
			for(int i = 0;i < n;i++){
				out.println(new String(ret[i]));
			}
			return true;
		}
		return false;
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}
	
	public static boolean nextPermutation(int[] a) {
		int n = a.length;
		int i;
		for (i = n - 2; i >= 0 && a[i] >= a[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < n && a[i] < a[j]; j++)
			;
		int d = a[i];
		a[i] = a[j - 1];
		a[j - 1] = d;
		for (int p = i + 1, q = n - 1; p < q; p++, q--) {
			d = a[p];
			a[p] = a[q];
			a[q] = d;
		}
		return true;
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