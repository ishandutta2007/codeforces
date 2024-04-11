//package round183;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		int N = 1000000;
		int[] e = new int[N+2];
		int[] esp = new int[N+2];
		int[][] es = new int[N+2][];
		a = radixSort(a);
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				int d = a[j]-a[i];
				e[d]++;
				esp[d]++;
			}
		}
		for(int i = 1;i <= N;i++){
			for(int j = i*2;j <= N;j += i){
				e[i] += e[j];
			}
			if(e[i] > K && e[i] <= K*(K+1)/2){
				for(int j = i;j <= N;j += i){
					if(esp[j] > 0 && es[j] == null){
						es[j] = new int[esp[j]];
					}
				}
			}
		}
		Arrays.fill(esp, 0);
		
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				int d = a[j] - a[i];
				if(es[d] != null){
					es[d][esp[d]++] = i<<16|j;
				}
			}
		}
		
		
		for(int i = 1;;i++){
			if(e[i] <= K){
				out.println(i);
				return;
			}
			if(e[i] > K*(K+1)/2){
				continue;
			}
			int[] ess = new int[e[i]*2];
			int ep = 0;
			for(int j = i;j <= N;j+=i){
				for(int k = 0;k < esp[j];k++){
					ess[ep++] = es[j][k]>>>16;
					ess[ep++] = es[j][k]&65535;
				}
			}
			Arrays.sort(ess);
			int[] dims = new int[5];
			int prev = 0;
			for(int j = 0;j < e[i]*2;j++){
				if(j == e[i]*2-1 || ess[j+1] != ess[j]){
					dims[j-prev+1]++;
					prev = j+1;
				}
			}
			int need = 0;
			for(int k = 1;k <= 4;k++){
				need += dims[k]/(k+1)*k;
			}
			if(need <= K){
				out.println(i);
				return;
			}
		}
	}
	
	public static int[] radixSort(int[] f)
	{
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}