//package vkcup2012.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "3 1 2 3 1 17 1 3 3 1 2 3 5 1";
	
	void solve()
	{
		for(int t = ni();t >= 1;t--){
			int n = ni();
			long[][] F = new long[n][2];
			int m = 1;
			long V = 1;
			for(int i = 0;i < n;i++){
				F[i][0] = nl();
				F[i][1] = ni();
				m *= F[i][1]+1;
				for(int j = 0;j < F[i][1];j++)V *= F[i][0];
			}
			long S = (long)Math.sqrt(V);
			if(V >= 1000000000000000L){
				for(S-=3;S*S<=V;S++);
				S--;
			}
			int L = S*S==V?m/2+1:m/2;
			
			long[] D = new long[L];
			D[0] = 1;
			int p = 1;
			for(int i = 0;i < n;i++){
				for(int k = p-1;k >= 0;k--){
					long x = D[k];
					for(int j = 0;j < F[i][1];j++){
						x *= F[i][0];
						if(x <= S){
							D[p++] = x;
						}
					}
				}
			}
//			D = Arrays.copyOf(D, p);
			D = radixSort(D);
//			Arrays.sort(D, 0, p);
//			tr(D);
			
			long min = Long.MAX_VALUE;
			long mina = -1, minb = -1, minc = -1;
			
			int ind = Arrays.binarySearch(D, 0, p, (long)(Math.cbrt(V)+1));
			if(ind < 0)ind = -ind-1;
			if(ind >= p)ind = p-1;
//			tr(D);
			for(int u = ind;u >= 0;u--){
				long h = (long)Math.sqrt(V/D[u]);
				if(D[u]*(2*h)+V/D[u] > min)break;
				int indq = Arrays.binarySearch(D, 0, p, h);
				if(indq < 0)indq = -indq-2;
				for(int r = indq;r >= 0;r--){
					if(V/D[u]%D[r]==0){
						long a = D[u];
						long b = D[r];
						long c = V/a/b;
						long v = a*b+b*c+c*a;
						if(v > 0 && v < min){
							min = v;
							mina = a; minb = b; minc = c;
						}
						break;
					}
				}
				
			}
			out.println(2*min + " " + mina + " " + minb + " " + minc);
		}
	}
	
	public static long[] radixSort(long[] f)
	{
		{
			long[] to = new long[f.length];
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			f = to;
		}
		{
			long[] to = new long[f.length];
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			f = to;
		}
		{
			long[] to = new long[f.length];
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			f = to;
		}
		{
			long[] to = new long[f.length];
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			f = to;
		}
		return f;
	}
	
	
	void run() throws Exception
	{
//		int n = 500;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(12 + " ");
//			sb.append("2 8 ");
//			sb.append("3 4 ");
//			sb.append("5 2 ");
//			sb.append("7 2 ");
//			sb.append("11 1 ");
//			sb.append("13 1 ");
//			sb.append("17 1 ");
//			sb.append("19 1 ");
//			sb.append("23 1 ");
//			sb.append("29 1 ");
//			sb.append("31 1 ");
//			sb.append("37 1 ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}