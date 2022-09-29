//package educational.round24;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		ni(); ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni() ,ni(), ni(), ni(), 1, i};
		}
		clean(co);
		int[] need = na(4);
		go(co, need[0]);
		for(int i = 0;i < n;i++){
			co[i][0] = -co[i][0]; co[i][2] = -co[i][2];
		}
		clean(co);
		go(co, need[1]);
		for(int i = 0;i < n;i++){
			co[i][0] = co[i][1]; co[i][2] = co[i][3];
		}
		clean(co);
		go(co, need[2]);
		for(int i = 0;i < n;i++){
			co[i][0] = -co[i][0]; co[i][2] = -co[i][2];
		}
		clean(co);
		go(co, need[3]);
		
		int ret = -1;
		for(int[] c : co){
			if(c[4] == 1){
				ret = c[5]+1;
			}
		}
		out.println(ret);
	}
	
	void clean(int[][] co)
	{
		int n = co.length;
		for(int i = 0;i < n;i++){
			if(co[i][0] > co[i][2]){
				int z = co[i][0]; co[i][0] = co[i][2]; co[i][2] = z;
			}
			if(co[i][1] > co[i][3]){
				int z = co[i][1]; co[i][1] = co[i][3]; co[i][3] = z;
			}
		}
	}
	
	void go(int[][] co, int ne)
	{
		int n = co.length;
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[2] - b[2];
			}
		});
		
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && co[j][0] == co[i][0] && co[j][2] == co[i][2])j++;
			if(co[i][0] == co[i][2]){
				for(int k = i;k < j;k++){
					if(ne != i)co[k][4] = 0;
				}
			}else{
				for(int k = i;k < j;k++){
					if(ne != j-1)co[k][4] = 0;
				}
			}
			i = j;
		}
//		tr(co, ne);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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