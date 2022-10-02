//package round265;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[][] th;
	
	void solve()
	{
		th = new int[100][];
		int p = 0;
		for(int i = 1;i < 8;i++){
			for(int j = i+1;j < 8;j++){
				for(int k = j+1;k < 8;k++){
					th[p++] = new int[]{i, j, k};
				}
			}
		}
		th = Arrays.copyOf(th, p);
		
		long[][] co = new long[8][];
		for(int i = 0;i < 8;i++){
			co[i] = new long[]{ni(), ni(), ni()};
		}
		long[][] xco = new long[8][3];
		xco[0] = Arrays.copyOf(co[0], 3);
		if(!dfs(1, co, xco)){
			out.println("NO");
		}
	}
	
	boolean dfs(int pos, long[][] co, long[][] xco)
	{
		if(pos == 8){
			outer:
			for(int[] t : th){
				long vax = xco[t[0]][0]-xco[0][0];
				long vay = xco[t[0]][1]-xco[0][1];
				long vaz = xco[t[0]][2]-xco[0][2];
				long vbx = xco[t[1]][0]-xco[0][0];
				long vby = xco[t[1]][1]-xco[0][1];
				long vbz = xco[t[1]][2]-xco[0][2];
				long vcx = xco[t[2]][0]-xco[0][0];
				long vcy = xco[t[2]][1]-xco[0][1];
				long vcz = xco[t[2]][2]-xco[0][2];
				if(
						(vax != 0 || vay != 0 || vaz != 0) &&
						(vbx != 0 || vby != 0 || vbz != 0) &&
						(vcx != 0 || vcy != 0 || vcz != 0) &&
						vax*vbx+vay*vby+vaz*vbz == 0 && 
						vax*vcx+vay*vcy+vaz*vcz == 0 && 
						vcx*vbx+vcy*vby+vcz*vbz == 0 &&
						vax*vax+vay*vay+vaz*vaz == vbx*vbx+vby*vby+vbz*vbz &&
						vax*vax+vay*vay+vaz*vaz == vcx*vcx+vcy*vcy+vcz*vcz
						){
					long[][] rem = new long[4][];
					rem[0] = new long[]{
							xco[0][0] + vax + vbx, 
							xco[0][1] + vay + vby, 
							xco[0][2] + vaz + vbz
					};
					rem[1] = new long[]{
							xco[0][0] + vcx + vbx, 
							xco[0][1] + vcy + vby, 
							xco[0][2] + vcz + vbz
					};
					rem[2] = new long[]{
							xco[0][0] + vax + vcx, 
							xco[0][1] + vay + vcy, 
							xco[0][2] + vaz + vcz
					};
					rem[3] = new long[]{
							xco[0][0] + vax + vbx + vcx,
							xco[0][1] + vay + vby + vcy,
							xco[0][2] + vaz + vbz + vcz
					};
					Arrays.sort(rem, new Comparator<long[]>() {
						public int compare(long[] a, long[] b) {
							if(a[0] != b[0])return Long.compare(a[0], b[0]);
							if(a[1] != b[1])return Long.compare(a[1], b[1]);
							if(a[2] != b[2])return Long.compare(a[2], b[2]);
							return 0;
						}
					});
					
					long[][] as = new long[4][];
					int p = 0;
					for(int i = 1;i < 8;i++){
						if(i != t[0] && i != t[1] && i != t[2]){
							as[p++] = xco[i];
						}
					}
					Arrays.sort(as, new Comparator<long[]>() {
						public int compare(long[] a, long[] b) {
							if(a[0] != b[0])return Long.compare(a[0], b[0]);
							if(a[1] != b[1])return Long.compare(a[1], b[1]);
							if(a[2] != b[2])return Long.compare(a[2], b[2]);
							return 0;
						}
					});
					
					if(!Arrays.deepEquals(rem, as)){
						continue;
					}
					
					out.println("YES");
					for(int k = 0;k < 8;k++){
						out.print(xco[k][0] + " ");
						out.print(xco[k][1] + " ");
						out.println(xco[k][2] + " ");
					}
					return true;
				}
			}
		}else{
			int[] ord = new int[3];
			for(int i = 0;i < 3;i++)ord[i] = i;
			do{
				for(int j = 0;j < 3;j++){
					xco[pos][ord[j]] = co[pos][j];
				}
				if(dfs(pos+1, co, xco))return true;
			}while(nextPermutation(ord));
		}
		return false;
	}
	
	static boolean nextPermutation(int[] src) {
		int i;
		for (i = src.length - 2; i >= 0 && src[i] > src[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < src.length && src[i] < src[j]; j++)
			;
		int d = src[i];
		src[i] = src[j - 1];
		src[j - 1] = d;
		for (int p = i + 1, q = src.length - 1; p < q; p++, q--) {
			d = src[p];
			src[p] = src[q];
			src[q] = d;
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