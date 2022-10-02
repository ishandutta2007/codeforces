//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class R86E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		for(int h = 0;h <= 1;h++){
//			for(int i = 0;i <= 100;i++){
//				tr(h, i, count(h, 12, i, 101));
//			}
//		}
//		tr(count(2, 12, 0, 60));
		
		int h = ni(), m = ni(), K = ni();
		int h1 = ni(), m1 = ni();
		int h2 = ni(), m2 = ni();
		if(h1 < h2 || (h1 == h2 && m1 <= m2)){
			out.println(count(h2, h, m2, m)[K] - count(h1, h, m1, m)[K]);
		}else{
//			tr(count(h-1, h, m-1, m));
//			tr(count(h, h, 0, m));
//			tr(count(h1, h, m1, m));
//			tr(count(h2, h, m2, m));
			out.println(count(h, h, 0, m)[K] - count(h1, h, m1, m)[K]
					 + count(h2, h, m2, m)[K]);
		}
	}
	
	long[] count(int h, int hlim, int m, int mlim)
	{
		long[] ret = new long[24];
		if(h == hlim){
			h--;
			m = mlim-1;
			int eh = 0;
			for(int u = hlim-1;u > 0;u/=10){
				if(u%10 != 0)eh++;
			}
			int ec = 0;
			for(int u = mlim-1;u > 0;u/=10){
				if(u%10 != 0)ec++;
			}
			ret[eh+ec]++;
		}
		long[] hdis = count(h, hlim);
		long[] mdis = count(m, mlim);
		long[] madis = count(mlim-1, mlim);
		
		int ec = 0;
		for(int u = mlim-1;u > 0;u/=10){
			if(u%10 != 0)ec++;
		}
		for(int i = 0;i < hdis.length;i++){
			ret[i+ec] += hdis[i];
		}
		for(int i = 0;i < mdis.length;i++){
			ret[i] += mdis[i] + madis[i] * h;
		}
		
		for(int i = ret.length-2;i >= 1;i--){
			ret[i] += ret[i+1];
		}
		
		return ret;
	}
	
	// 0->1, ..., m-1->m 
	long[] count(int m, int mlim)
	{
		long[] ret = new long[12];
		for(int i = 1, u = Math.min(m, mlim-1);i <= 10;i++, u/=10){
			ret[i] = u;
		}
		for(int i = 1;i <= 9;i++){
			ret[i] -= ret[i+1];
		}
		
		if(m == mlim){
			int ec = 0;
			for(int u = m;u > 0;u/=10){
				if(u%10 != 0)ec++;
			}
			ret[ec]++;
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new R86E().run(); }
	
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