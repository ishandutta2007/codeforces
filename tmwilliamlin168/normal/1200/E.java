import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeSet;
 
public class Main {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
 
	void solve() 
	{
		char[] ans = new char[10000005];
		int p = 0;
		int n = ni();
		for(int i = 0; i < n; i++) {
			char[] s = ns().toCharArray();
			if(i == 0) {
				for(int j = 0; j < s.length; j++) {
					ans[p++] = s[j];
				}
			}
			else {
				int sn = s.length;
				int tn = Math.min(p, sn); tn++; tn += sn;
				char[] t = new char[tn];
				int curarg = 0;
				for(int j = 0; j < sn; j++) {
					t[curarg++] = s[j];
				}
				t[curarg++] = '$';
				for(int j = Math.max(0, p - sn); j < p; j++) {
					t[curarg++] = ans[j];
				}
				int[] z = Z(t);
				int zn = z.length;
				int offset = 0;
				for(int j = sn + 1; j < zn; j++) {
					if(j + z[j] == zn) {
						offset = Math.max(offset, z[j]);
					}
				}
				for(int j = offset; j < sn; j++) {
					ans[p++] = s[j];
				}
			}
		}
		ans = Arrays.copyOf(ans, p);
		out.println(new String(ans));
	}
	
	public static int[] Z(char[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
	}
		    
	void run() throws Exception {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
 
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if (!INPUT.isEmpty())
			tr(System.currentTimeMillis() - s + "ms");
	}
 
	public static void main(String[] args) throws Exception {
		new Main().run();
	}
 
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
 
	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}
 
	private boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}
 
	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}
 
	private double nd() {
		return Double.parseDouble(ns());
	}
 
	private float nf() {
		return Float.parseFloat(ns());
	}
 
	private char nc() {
		return (char) skip();
	}
 
	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
 
	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
 
	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}
 
	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
 
	private int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}
 
		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
 
	private long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}
 
		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
 
	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}