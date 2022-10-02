//package round84;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		int[][] b = new int[n][2];
		int L = -1;
		for(int i = 0;i < n;i++){
			b[i][0] = a[i] = ni();
			b[i][1] = i;
			if(isln(a[i]))L = i;
		}
		Arrays.sort(b, new Comparator<int[]>(){
			public int compare(int[] x, int[] y){
				return x[0] - y[0];
			}
		});
		
		if(L == -1){
			boolean cor = true;
			for(int i = 0;i < n;i++){
				if(b[i][1] != i){
					cor = false;
					break;
				}
			}
			if(cor){
				out.println(0);
			}else{
				out.println(-1);
			}
		}else{
			int[] f = new int[n];
			for(int i = 0;i < n;i++){
				f[b[i][1]] = i;
			}
			
			BitSet ved = new BitSet();
			StringBuilder sb = new StringBuilder();
			int swap = 0;
			for(int i = ved.nextClearBit(0);i < n;i = ved.nextClearBit(i+1)){
				int cy = 1;
				int M = isln(a[i]) ? i : -1;
				ved.set(i);
				boolean lin = i == L;
				for(int j = f[i];j != i;j = f[j], cy++){
					if(M == -1)M = isln(a[j]) ? j : -1;
					if(j == L)lin = true;
					ved.set(j);
				}
				if(cy > 1){
					if(M != -1){
						if(lin){
							L = f[M];
						}
						for(int j = b[M][1];j != M;j = b[j][1]){
							sb.append((j+1) + " " + (f[j]+1) + "\n");
//							int d = a[j]; a[j] = a[f[j]]; a[f[j]] = d;
//							if(!isln(a[j]) && !isln(a[f[j]])){
//								tr("DEAD");
//							}
							swap++;
						}
					}else{
						if(L == -1){
							out.println(-1);
							return;
						}
						sb.append((i+1) + " " + (L+1) + "\n");
//						int d = a[i]; a[i] = a[L]; a[L] = d;
//						if(!isln(a[i]) && !isln(a[L])){
//							tr("DEADA", a[i], a[L]);
//						}
						for(int j = b[i][1];j != i;j = b[j][1]){
							sb.append((j+1) + " " + (f[j]+1) + "\n");
//							int e = a[j]; a[j] = a[f[j]]; a[f[j]] = e;
//							if(!isln(a[j]) && !isln(a[f[j]])){
//								tr("DEADB");
//							}
							swap++;
						}
						sb.append((f[i]+1) + " " + (L+1) + "\n");
//						d = a[f[i]]; a[f[i]] = a[L]; a[L] = d;
//						if(!isln(a[f[i]]) && !isln(a[L])){
//							tr("DEADC");
//						}
						swap += 2;
					}
				}
			}
			if(swap >= 2*n){
				out.println(-1);
				return;
			}
//			for(int i = 0;i < n;i++){
//				if(a[i] != b[i][0]){
//					tr("DEAD");
////					tr(a);
//					return;
//				}
//			}
//			tr("OK");
			out.println(swap);
			out.print(sb);
		}
	}
	
	boolean isln(int n)
	{
		while(n > 0){
			if(!(n % 10 == 4 || n % 10 == 7))return false;
			n /= 10;
		}
		return true;
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(100000000)+1 + " ");
//		}
//		INPUT = sb.toString();
//		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
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
	
	public String nline()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
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
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}