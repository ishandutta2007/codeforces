//package round566;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Datum[] ds = new Datum[n];
		String V = "aeoui";
		for(int i = 0;i < n;i++) {
			char[] s = ns().toCharArray();
			char lv = 0;
			int nv = 0;
			for(int j = 0;j < s.length;j++) {
				if(V.indexOf(s[j]) >= 0) {
					lv = s[j];
					nv++;
				}
			}
			ds[i] = new Datum(s, nv, lv);
		}
		
		Arrays.sort(ds, new Comparator<Datum>() {
			public int compare(Datum a, Datum b) {
				if(a.nv != b.nv)return a.nv - b.nv;
				return a.lv - b.lv;
			}
		});
		
		int fmat2 = 0;
		int fmat = 0;
		for(int i = 0;i < n;) {
			int j = i;
			while(j < n && ds[i].nv == ds[j].nv) {
				j++;
			}
			
			int mat2 = 0;
			for(int k = i;k < j;) {
				int l = k;
				while(l < j && ds[k].lv == ds[l].lv) {
					l++;
				}
				mat2 += (l-k)/2;
				
				k = l;
			}
			fmat2 += mat2;
			fmat += (j-i-2*mat2)/2;
			
			i = j;
		}
		int ret = 0;
		if(fmat >= fmat2) {
			ret = fmat2;
		}else {
			ret = (fmat+fmat2)/2;
		}
		
		out.println(ret);
		
		Queue<Datum[]> ps2 = new ArrayDeque<>();
		Queue<Datum[]> ps = new ArrayDeque<>();
		for(int i = 0;i < n;) {
			int j = i;
			while(j < n && ds[i].nv == ds[j].nv) {
				j++;
			}
			
			Datum temp = null;
			for(int k = i;k < j;) {
				int l = k;
				while(l < j && ds[k].lv == ds[l].lv) {
					l++;
				}
				for(int m = k;m < l;m++) {
					if(m+1 < l) {
						ps2.add(new Datum[] {ds[m], ds[m+1]});
						m++;
					}else if(temp == null) {
						temp = ds[m];
					}else {
						ps.add(new Datum[] {temp, ds[m]});
						temp = null;
					}
				}
				k = l;
			}
			
			i = j;
		}
		while(ps2.size() > ps.size()) {
			ps.add(ps2.poll());
		}
		
		while(ps.size() > 0 && ps2.size() > 0) {
			Datum[] p = ps.poll();
			Datum[] p2 = ps2.poll();
			out.println(new String(p[0].s) + " " + new String(p2[0].s));
			out.println(new String(p[1].s) + " " + new String(p2[1].s));
		}
		
	}
	
	static class Datum
	{
		char[] s;
		int nv;
		char lv;
		public Datum(char[] s, int nv, char lv) {
			super();
			this.s = s;
			this.nv = nv;
			this.lv = lv;
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