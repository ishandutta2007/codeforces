//package croc2013.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "";
//	String INPUT = "4 1000000 -1000000 1000000 1000000 -1000000 1000000 -1000000 -1000000\r\n";
//	String INPUT = "4 0 0 4 0 4 1 0 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		for(int j = 0;j < n-2;j++){
			int a = j, b = (j+1)%n, c = (j+2)%n;
			long s = (long)(co[b][1]-co[a][1])*(co[c][0]-co[a][0])-(long)(co[c][1]-co[a][1])*(co[b][0]-co[a][0]);
			if(s > 0){
				for(int i = 0;i < n;i++){
					co[i][1] = -co[i][1];
				}
				break;
			}else if(s < 0){
				break;
			}
		}
		
		double SX = go(co);
		for(int i = 0;i < n;i++){
			int d = co[i][0]; co[i][0] = co[i][1]; co[i][1] = d;
			co[i][0] = -co[i][0];
		}
		double SY = go(co);
		out.printf("%.12f\n", (SX+SY)/num/(num-1)*2/2/2);
	}
	
	double go(int[][] co)
	{
		int n = co.length;
		int I = 100000000;
		// cc
		int minx = I;
		int minxiup = -1;
		int minxilo = -1;
		int upy = -I;
		int loy = I;
		
		int maxx = -I;
		for(int i = 0;i < n;i++){
			if(co[i][0] <= minx){
				if(co[i][0] < minx){
					upy = -I;
					loy = I;
				}
				minx = co[i][0];
				if(co[i][1] > upy){
					upy = co[i][1];
					minxiup = i;
				}
				if(co[i][1] < loy){
					loy = co[i][1];
					minxilo = i;
				}
			}
			if(co[i][0] > maxx){
				maxx = co[i][0];
			}
		}
		
		int upper = minxiup;
		int lower = minxilo;
		long[] f = new long[maxx-minx+1];
		num = 0;
		for(int x = minx;x <= maxx;x++){
			while(co[upper][0] < x){
				upper--;
				if(upper < 0)upper += n;
			}
			while(co[lower][0] < x){
				lower++;
				if(lower >= n)lower -= n;
			}
			
			if(x == minx){
				f[0] = upy-loy+1;
			}else if(x == maxx){
				f[maxx-minx] = co[upper][1]-co[lower][1]+1;
			}else{
				long uy, ly;
				{
					int upnx = upper+1;
					if(upnx >= n)upnx -= n;
					long a = co[upnx][0], b = co[upnx][1];
					long c = co[upper][0], d = co[upper][1];
					uy = (d-b)*(x-a) >= 0 ? (d-b)*(x-a)/(c-a)+b : ((d-b)*(x-a)-(c-a-1))/(c-a)+b;
				}
				{
					int lonx = lower-1;
					if(lonx < 0)lonx += n;
					long a = co[lonx][0], b = co[lonx][1];
					long c = co[lower][0], d = co[lower][1];
					ly = (d-b)*(x-a) >= 0 ? ((d-b)*(x-a)+(c-a-1))/(c-a)+b : (d-b)*(x-a)/(c-a)+b;
				}
//				tr(ly, uy, x);
				f[x-minx] = uy-ly+1;
			}
//			if(f[x-minx] < 0)f[x-minx] = 0;
			num += f[x-minx];
		}
		
		double total = 0;
		{
			double[] g = new double[f.length];
			for(int i = 0;i < f.length;i++)g[i] = f[i];
			double sum = 0;
			for(int i = 0;i < maxx-minx+1;i++){
				g[i] += sum;
				sum += 2*f[i];
			}
			for(int i = 1;i < maxx-minx+1;i++){
				g[i] += g[i-1];
			}
			for(int i = 1;i < maxx-minx+1;i++){
				g[i] += g[i-1];
			}
			
			for(int i = maxx-minx-1;i >= 0;i--){
//			for(int i = 0;i < maxx-minx;i++){
				total += (double)g[i] * f[i+1];
			}
		}
		{
			for(int i = 0, j = f.length-1;i < j;i++,j--){
				long u = f[i]; f[i] = f[j]; f[j] = u;
			}
			double[] g = new double[f.length];
			for(int i = 0;i < f.length;i++)g[i] = f[i];
			double sum = 0;
			for(int i = 0;i < maxx-minx+1;i++){
				g[i] += sum;
				sum += 2*f[i];
			}
			for(int i = 1;i < maxx-minx+1;i++){
				g[i] += g[i-1];
			}
			for(int i = 1;i < maxx-minx+1;i++){
				g[i] += g[i-1];
			}
			
			for(int i = maxx-minx-1;i >= 0;i--){
//			for(int i = 0;i < maxx-minx;i++){
				total += (double)g[i] * f[i+1];
			}
		}
		return total;
	}
	
	long num;
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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