//package round269;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = new int[]{ni(), i+1};
		}
		Arrays.sort(a, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		long all = 1;
		List<int[]> ok = new ArrayList<int[]>();
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && a[j][0] == a[i][0])j++;
			all *= j-i;
			if(j-i > 1)ok.add(new int[]{i, j});
			if(all >= 3){
				out.println("YES");
				if(ok.size() == 2){
					if(ok.get(0).length == 2 && ok.get(1).length == 2){
						for(int k = 0;k < n;k++){
							if(k > 0)out.print(" ");
							out.print(a[k][1]);
						}
						out.println();
						{
							int l = ok.get(0)[0], r = ok.get(0)[0]+1;
							int d = a[l][1]; a[l][1] = a[r][1]; a[r][1] = d;
						}
						for(int k = 0;k < n;k++){
							if(k > 0)out.print(" ");
							out.print(a[k][1]);
						}
						out.println();
						{
							int l = ok.get(1)[0], r = ok.get(1)[0]+1;
							int d = a[l][1]; a[l][1] = a[r][1]; a[r][1] = d;
						}
						for(int k = 0;k < n;k++){
							if(k > 0)out.print(" ");
							out.print(a[k][1]);
						}
						out.println();
					}else{
						for(int u = 0;u < 3;u++){
							for(int k = 0;k < n;k++){
								if(k > 0)out.print(" ");
								out.print(a[k][1]);
							}
							out.println();
							int l = ok.get(1)[0], r = ok.get(1)[0]+1, x = ok.get(1)[0]+2;
							int d = a[l][1]; a[l][1] = a[r][1]; a[r][1] = a[x][1]; a[x][1] = d;
						}
					}
				}else{
					for(int u = 0;u < 3;u++){
						for(int k = 0;k < n;k++){
							if(k > 0)out.print(" ");
							out.print(a[k][1]);
						}
						out.println();
						int l = ok.get(0)[0], r = ok.get(0)[0]+1, x = ok.get(0)[0]+2;
						int d = a[l][1]; a[l][1] = a[r][1]; a[r][1] = a[x][1]; a[x][1] = d;
					}
				}
				return;
			}
			
			i = j;
		}
		out.println("NO");
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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