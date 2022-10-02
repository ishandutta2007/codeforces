//package round125;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		double xp = ni(), yp = ni(), vp = ni();
		double x = ni(), y = ni(), v = ni(), r = ni();
		double theta = Math.atan2(y, x);
		double R = Math.sqrt(x*x+y*y);
		double rp = Math.sqrt(xp*xp+yp*yp);
		double thp = Math.atan2(yp, xp) - theta;
		while(thp < 0)thp += Math.PI*2;
		// (R,0)->(nxp,nyp)
		double z = Math.acos(r / R);
		double lim = z + Math.acos(r / rp);
		double low = thp;
		double high = 99999.;
		for(int i = 0;i < 100;i++){
			double t = (high + low) / 2;
			if(f(t, R, rp, r, lim, v) - (t - thp) / (vp/rp) < 0){
				high = t;
			}else{
				low = t;
			}
		}
		double ret = (low - thp)/(vp/rp);
		if(ret < 0)ret = 0;
		out.printf("%.9f\n", ret);
		return;
	}
	
	double f(double tt, double R, double rp, double r, double lim, double v)
	{
		tt %= 2*Math.PI;
		if(tt >= Math.PI){
			tt = 2*Math.PI-tt;
		}
		if(tt <= lim){
			double x = Math.cos(tt) * rp;
			double y = Math.sin(tt) * rp;
			return Math.sqrt((x-R)*(x-R)+y*y)/v;
		}else{
			return (Math.sqrt(R*R-r*r) + Math.sqrt(rp*rp-r*r) + r*(tt - lim)) / v;
		}
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