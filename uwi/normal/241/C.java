//package bayan2012;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		double hl = ni(), hr = ni();
		int n = ni();
		double[][] top = new double[n][];
		double[][] flo = new double[n][];
		int p = 0, q = 0;
		for(int i = 0;i < n;i++){
			int sc = ni();
			char ft = nc();
			int l = ni(), r = ni();
			if(ft == 'F'){
				flo[q++] = new double[]{sc, l, r};
			}else{
				top[p++] = new double[]{sc, l, r};
			}
		}
		top = Arrays.copyOf(top, p);
		flo = Arrays.copyOf(flo, q);
		
		Arrays.sort(flo, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return Double.compare(a[1], b[1]);
			}
		});
		Arrays.sort(top, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return Double.compare(a[1], b[1]);
			}
		});
		double[] tx = new double[p];
		double[] fx = new double[q];
		for(int i = 0;i < p;i++)tx[i] = top[i][1];
		for(int i = 0;i < q;i++)fx[i] = flo[i][1];
		
		int max = 0;
		outer:
		for(int k = -150;k <= 150;k++){
			double ry = k % 2 == 0 ? hr + 100*k : -hr+100*(k+1);
			// (0,hl), (10^5,ry)
			BitSet bt = new BitSet();
			BitSet bf = new BitSet();
			int sc = 0;
			int inf, sup;
			if(k > 0){
				inf = 100;
				sup = k*100;
			}else{
				inf = (k+1)*100;
				sup = 0;
			}
			for(int h = inf;h <= sup;h+=100){
				double x = (h-hl) / (ry-hl) * 100000;
				if(h % 200 == 0){
					int ind = Arrays.binarySearch(fx, x+1E-10);
					if(ind < 0)ind = -ind-2;
					if(ind >= 0 && x <= flo[ind][2]+1E-9){
						if(bf.get(ind))continue outer;
						bf.set(ind);
						sc += (int)flo[ind][0];
					}else{
						continue outer;
					}
				}else{
					int ind = Arrays.binarySearch(tx, x+1E-10);
					if(ind < 0)ind = -ind-2;
					if(ind >= 0 && x <= top[ind][2]+1E-9){
						if(bt.get(ind))continue outer;
						bt.set(ind);
						sc += (int)top[ind][0];
					}else{
						continue outer;
					}
				}
			}
			max = Math.max(max, sc);
		}
		out.println(max);
	}
	
	char nc() {
		try{
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if(b == -1)
				return 0;
			return (char) b;
		}catch (IOException e){
		}
		return 0;
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
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
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