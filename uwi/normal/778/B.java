//package round402;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Formula
	{
		int subs;
		char[] val;
		int left, right;
		int ope;
		public Formula(int subs, char[] val) {
			this.subs = subs;
			this.val = val;
		}
		public Formula(int subs, int left, int right, int ope) {
			this.subs = subs;
			this.left = left;
			this.right = right;
			this.ope = ope;
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		int id = 0;
		Map<String, Integer> map = new HashMap<>();
		Formula[] fs = new Formula[n];
		for(int i = 0;i < n;i++){
			String subs = ns();
			map.put(subs, id++);
			ns();
			String x = ns();
			if(x.startsWith("0") || x.startsWith("1")){
				fs[i] = new Formula(i, x.toCharArray());
			}else{
				String ope = ns();
				String y = ns();
				int opev = 0;
				if(ope.equals("AND")){
					opev = 0;
				}else if(ope.equals("OR")){
					opev = 1;
				}else if(ope.equals("XOR")){
					opev = 2;
				}else{
					throw new RuntimeException();
				}
				int xv = map.containsKey(x) ? map.get(x) : -1;
				int yv = map.containsKey(y) ? map.get(y) : -1;
				fs[i] = new Formula(i, xv, yv, opev);
			}
		}
		
		char[] argmin = new char[m];
		char[] argmax = new char[m];
		for(int i = 0;i < m;i++){
			int[] sums = new int[2];
			for(int d = 0;d < 2;d++){
				int[] vals = new int[n];
				for(int j = 0;j < n;j++){
					if(fs[j].val != null){
						vals[j] = fs[j].val[i]-'0';
					}else{
						int lv = fs[j].left == -1 ? d : vals[fs[j].left];
						int rv = fs[j].right == -1 ? d : vals[fs[j].right];
						if(fs[j].ope == 0){
							vals[j] = lv & rv;
						}else if(fs[j].ope == 1){
							vals[j] = lv | rv;
						}else if(fs[j].ope == 2){
							vals[j] = lv ^ rv;
						}
					}
				}
				sums[d] = Arrays.stream(vals).sum();
			}
			if(sums[0] < sums[1]){
				argmin[i] = '0';
				argmax[i] = '1';
			}else if(sums[0] > sums[1]){
				argmin[i] = '1';
				argmax[i] = '0';
			}else{
				argmin[i] = '0';
				argmax[i] = '0';
			}
		}
		out.println(new String(argmin));
		out.println(new String(argmax));
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