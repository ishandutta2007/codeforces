//package memsql2014.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		List<int[]> list = new ArrayList<int[]>();
		for(int i = 0;i < 3 && i <= n;i++){
			for(int j = 0;j < 3 && j <= m;j++){
				list.add(new int[]{i, j});
				list.add(new int[]{n-i, j});
				list.add(new int[]{n-i, m-j});
				list.add(new int[]{i, m-j});
			}
		}
		
		List<int[]> go = new ArrayList<int[]>();
		outer:
		for(int i = 0;i < list.size();i++){
			for(int[] u : go){
				if(list.get(i)[0] == u[0] && list.get(i)[1] == u[1])continue outer;
			}
			go.add(list.get(i));
		}
		
		int z = go.size();
		double max = -1;
		int maxi = -1;
		int maxj = -1;
		int maxk = -1;
		int maxl = -1;
		for(int i = 0;i < z;i++){
			for(int j = 0;j < z;j++){
				if(i == j)continue;
				for(int k = 0;k < z;k++){
					if(k == i || k == j)continue;
					for(int l = 0;l < z;l++){
						if(l == i || l == j || l == k)continue;
						double len = 0;
						len += d(go.get(i), go.get(j));
						len += d(go.get(j), go.get(k));
						len += d(go.get(k), go.get(l));
						if(len > max){
							max = len;
							maxi = i;
							maxj = j;
							maxk = k;
							maxl = l;
						}
					}
				}
			}
		}
		out.println(go.get(maxi)[0] + " " + go.get(maxi)[1]);
		out.println(go.get(maxj)[0] + " " + go.get(maxj)[1]);
		out.println(go.get(maxk)[0] + " " + go.get(maxk)[1]);
		out.println(go.get(maxl)[0] + " " + go.get(maxl)[1]);
	}
	
	double d(int[] a, int[] b){
		return Math.sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
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