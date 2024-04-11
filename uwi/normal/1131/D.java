//package round541;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Row
	{
		int[] a;
		int oid;
		public Row(int[] a, int oid) {
			this.a = a;
			this.oid = oid;
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		Row[] rows = new Row[n];
		for(int i = 0;i < n;i++){
			int[] a = new int[m];
			for(int j = 0;j < m;j++){
				a[j] = "<=>".indexOf(map[i][j])-1;
			}
			rows[i] = new Row(a, i);
		}
		Arrays.sort(rows, new Comparator<Row>() {
			public int compare(Row a, Row b) {
				for(int i = 0;i < a.a.length;i++){
					if(a.a[i] != b.a[i]){
						return a.a[i] - b.a[i];
					}
				}
				return 0;
			}
		});
		
		Row[] cols = new Row[m];
		for(int j = 0;j < m;j++){
			int[] b = new int[n];
			for(int i = 0;i < n;i++){
				b[i] = rows[i].a[j];
			}
			cols[j] = new Row(b, j);
		}
		
		Arrays.sort(cols, new Comparator<Row>() {
			public int compare(Row a, Row b) {
				for(int i = 0;i < a.a.length;i++){
					if(a.a[i] != b.a[i]){
						return -(a.a[i] - b.a[i]);
					}
				}
				return 0;
			}
		});
		
		int[] cnums = new int[m];
		int[] rnums = new int[n];
		
		int gen = 0;
		int p = 0;
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && Arrays.equals(rows[i].a, rows[j].a))j++;
			
			int oop = p;
			while(p < m && map[rows[i].oid][cols[p].oid] == '>'){
				if(oop < p && Arrays.equals(cols[p].a, cols[p-1].a)){
				}else{
					gen++;
				}
				cnums[cols[p].oid] = gen;
				p++;
			}
			
			gen++;
			int op = p;
			while(p < m && map[rows[i].oid][cols[p].oid] == '=')p++;
			for(int k = i;k < j;k++){
				rnums[rows[k].oid] = gen;
			}
			for(int k = op;k < p;k++){
				cnums[cols[k].oid] = gen;
			}
			
			i = j;
		}
		
		gen++;
		while(p < m){
			cnums[cols[p].oid] = gen;
			p++;
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '<'){
					if(rnums[i] < cnums[j]){
					}else{
						out.println("No");
						return;
					}
				}else if(map[i][j] == '>'){
					if(rnums[i] > cnums[j]){
					}else{
						out.println("No");
						return;
					}
				}else{
					if(rnums[i] == cnums[j]){
					}else{
						out.println("No");
						return;
					}
				}
			}
		}
		out.println("Yes");
		
		for(int w : rnums){
			out.print(w + " ");
		}
		out.println();
		for(int w : cnums){
			out.print(w + " ");
		}
		out.println();
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