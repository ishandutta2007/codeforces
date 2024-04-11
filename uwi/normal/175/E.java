//package round115;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int nf, ne, ns, rf, re, rs, df, de;
	int[] fct;
	
	void solve()
	{
		nf = ni(); ne = ni(); ns = ni();
		rf = ni(); re = ni(); rs = ni();
		df = ni(); de = ni();
		fct = new int[13];
		
		sqs = Math.sqrt(rs*rs-1);
		sqf = Math.sqrt(rf*rf-1);
		sqe = Math.sqrt(re*re-1);

		rec(0, 0);
		out.printf("%.9f\n", gm);
	}
	
	double gm = 0;
	double sqs, sqf, sqe;
	
	void rec(int pos, int num)
	{
		if(pos == 13){
			if(num == ns)go();
		}else{
			for(int i = 0;i <= 2 && num+i <= ns;i++){
				fct[pos] = i;
				rec(pos+1, num+i);
			}
		}
	}
	
	boolean[] cache = new boolean[3*3*3*3*3*3*3*3*3*3*3*3*3];
	int gct = 0;
	
	void go()
	{
		int code =  0;
		for(int i = 0;i < 13;i++){
			code = code * 3 + fct[i];
		}
		if(cache[code])return;
		code = 0;
		for(int i = 12;i >= 0;i--){
			code = code * 3 + fct[i];
		}
		cache[code] = true;
		
		double I = -999999999;
		double[][] dp = new double[nf+1][ne+1];
		for(int j = 0;j <= nf;j++)Arrays.fill(dp[j], I);
		dp[0][0] = 0;
		
		for(int i = 0;i < 13;i++){
			double tdf = calc(i-sqf, i+sqf) * df;
			double tde = calc(i-sqe, i+sqe) * de;
			for(int j = nf;j >= 0;j--){
				for(int k = ne;k >= 0;k--){
					if(dp[j][k] != I){
						for(int l = 0;l <= 2-fct[i] && j+l <= nf;l++){
							for(int m = 0;l+m <= 2-fct[i] && k+m <= ne;m++){
								dp[j+l][k+m] = Math.max(dp[j+l][k+m], dp[j][k] + tdf*l + tde*m);
							}
						}
					}
				}
			}
		}
//		for(int i = 1;i <= 13;i++){
//			double tdf = calc(ev, i-1-sqf, i-1+sqf) * df;
//			double tde = calc(ev, i-1-sqe, i-1+sqe) * de;
//			for(int j = 0;j <= nf;j++){
//				for(int k = 0;k <= ne;k++){
//					double max = 0;
//					for(int l = 0;l <= 2-fct[i-1] && l <= j;l++){
//						for(int m = 0;l+m <= 2-fct[i-1] && m <= k;m++){
//							max = Math.max(max, dp[i-1][j-l][k-m] + tdf*l + tde*m);
//						}
//					}
//					dp[i][j][k] = max;
//				}
//			}
//		}
		gm = Math.max(gm, dp[nf][ne]);
	}
	
	double calc(double s, double t)
	{
		double dmg = 0;
		for(int i = 0;i < 13;i++){
			if(fct[i] > 0){
				double w = Math.min(t, i+sqs) - Math.max(s, i-sqs);
				if(w > 0)dmg += w * fct[i];
			}
		}
		return dmg + (t-s);
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
		new E().run();
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