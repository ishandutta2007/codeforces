//package round90re;
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
		char[] A = ns(1000003);
		char[] B = ns(1000003);
		if(A.length != B.length){
			out.println("-1 -1");
			return;
		}
		// A=XYZ
		// B=Yr(Z)r(X)
		// rab:Yr(Z)r(X)r(Z)r(Y)r(X)r(Z)prefix
		// ba:XYZYr(Z)r(X)Ysuffix
		
		int n = A.length;
		char[] rab = new char[2*n+1];
		char[] ba = new char[2*n+1];
		System.arraycopy(A, 0, rab, 0, n);
		System.arraycopy(A, 0, ba, n+1, n);
		System.arraycopy(B, 0, rab, n+1, n);
		System.arraycopy(B, 0, ba, 0, n);
		for(int i = 0, j = n-1;i < j;i++,j--){
			char d = rab[i]; rab[i] = rab[j]; rab[j] = d;
		}
		
		int[] kmp = kmpTable(rab);
		int[] z = Z(ba);
		int opti = -1, optj = -1;
		for(int i = 0;i < n-1;i++){
			if(A[i] != B[n-1-i])break;
			
			// |X|=i+1
			int zmax = kmp[2*n+1-(i+1)];
			// |Z|<=zmax
			int jmin = n-1-zmax+1;
			int ymax = z[n+1+(i+1)];
			// |Y|=j-i-1
//			tr(i,jmin,jmin-i-1,ymax);
			if(jmin-i-1 <= ymax){
				opti = i;
				optj = jmin;
			}
		}
		out.println(opti + " " + optj);
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
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
				int k = i-l;
				if(z[k] < r-i+1){
					z[i] = z[k];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
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
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b) && b != ' '); return b; }
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b) && b != ' ')){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}