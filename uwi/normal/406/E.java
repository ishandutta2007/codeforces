//package round238;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long count(int[] o)
	{
		int no = o.length;
		if(o[0] == o[no-1]){
			return (long)no*(no-1)*(no-2)/6;
		}else{
			long down = 0, up = 0;
			for(int i = 0;i < no;i++){
				if(o[i] == o[0])down++;
				if(o[i] == o[no-1])up++;
			}
			long rem = no-down-up;
			return down*rem*up+down*(down-1)/2*up+down*up*(up-1)/2;
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] z = new int[m];
		int[] o = new int[m];
		int nz = 0, no = 0;
		for(int i = 0;i < m;i++){
			int t = ni();
			if(t == 0){
				z[nz++] = ni();
			}else{
				o[no++] = ni();
			}
		}
		z = radixSort(Arrays.copyOf(z, nz));
		o = radixSort(Arrays.copyOf(o, no));
		int maxz = nz >= 3 ? z[nz-1] - z[0] : -1;
		int maxo = no >= 3 ? o[no-1] - o[0] : -1;
		long lm = m;
		if(no == 0){
			out.println(count(z));
			return;
		}
		if(nz == 0){
			out.println(count(o));
			return;
		}
		if(z[nz-1] < o[0]){
			int maxx = 2*n-(o[0]-z[nz-1]);
			int max = Math.max(Math.max(maxx, maxz), maxo);
			long ret = 0;
			if(max == maxx){
				long nno = 0, nnz = 0;
				for(int i = 0;i < no;i++){
					if(o[i] == o[0])nno++;
				}
				for(int i = 0;i < nz;i++){
					if(z[i] == z[nz-1])nnz++;
				}
				ret += nnz*(nnz-1)/2*nno + nno*(nno-1)/2*nnz + nno*nnz*(no-nno+nz-nnz);
			}
			if(max == maxz){
				ret += count(z);
			}
			if(max == maxo){
				ret += count(o);
			}
			out.println(ret);
		}else if(o[no-1] < z[0]){
			int maxx = 2*n-(z[0]-o[no-1]);
			int max = Math.max(Math.max(maxx, maxz), maxo);
			long ret = 0;
			if(max == maxx){
				long nno = 0, nnz = 0;
				for(int i = 0;i < no;i++){
					if(o[i] == o[no-1])nno++;
				}
				for(int i = 0;i < nz;i++){
					if(z[i] == z[0])nnz++;
				}
				ret += nnz*(nnz-1)/2*nno + nno*(nno-1)/2*nnz + nno*nnz*(no-nno+nz-nnz);
			}
			if(max == maxz){
				ret += count(z);
			}
			if(max == maxo){
				ret += count(o);
			}
			out.println(ret);
		}else{
			long ret = 0;
			// 2n
			{
				int p = 0;
				for(int i = 0;i < nz;){
					int j = i;
					for(;j < nz && z[i] == z[j];j++);
					while(p < no && o[p] < z[i])p++;
					long below = p;
					while(p < no && o[p] <= z[i])p++;
					long same = p-below;
					long above = no-(below+same);
					ret += below*above*(j-i) + below*(j-i)*same + same*(j-i)*above + same*(same-1)/2*(j-i);
					i = j;
				}
			}
			{
				int p = 0;
				for(int i = 0;i < no;){
					int j = i;
					for(;j < no && o[i] == o[j];j++);
					while(p < nz && z[p] < o[i])p++;
					long below = p;
					while(p < nz && z[p] <= o[i])p++;
					long same = p-below;
					long above = nz-(below+same);
					ret += below*above*(j-i) + below*(j-i)*same + same*(j-i)*above + same*(same-1)/2*(j-i);
					i = j;
				}
			}
			out.println(ret);
		}
	}
	
	public static int[] radixSort(int[] f)
	{
		if(f.length == 0)return f;
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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