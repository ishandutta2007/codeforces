//package croc2012.mbtu;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class F {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		String[] sp = br.readLine().split(" ");
		int n = Integer.parseInt(sp[0]);
		int m = Integer.parseInt(sp[1]);
		String line;
		List<Long> ts = new ArrayList<Long>();
		List<String> times = new ArrayList<String>();
		while((line = br.readLine()) != null){
			int Y = Integer.parseInt(line.substring(0, 4));
			int M = Integer.parseInt(line.substring(5, 7));
			int D = Integer.parseInt(line.substring(8, 10));
			int H = Integer.parseInt(line.substring(11, 13));
			int MI = Integer.parseInt(line.substring(14, 16));
			int S = Integer.parseInt(line.substring(17, 19));
			long t = (long)enc(Y, M, D)*86400+H*3600+MI*60+S;
			times.add(line.substring(0, 19));
			ts.add(t);
		}
		
		for(int i = m-1;i < ts.size();i++){
			if(ts.get(i)-ts.get(i-(m-1)) < n){
				out.println(times.get(i));
				return;
			}
		}
		out.println(-1);
	}
	
	public static int[] DOM = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public static int[] CUMDOM = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	
	public static int enc(int y, int m, int d)
	{
		int ret = 0;
		ret += (y-1) * 365;
		ret += (y-1) / 4;
		ret -= (y-1) / 100;
		ret += (y-1) / 400;
		ret += CUMDOM[m-1];
		if(m >= 3 && y % 4 == 0 && (y % 400 == 0 || y % 100 != 0)){
			ret++;
		}
		ret += d;
		return ret;
	}
	
	void run() throws Exception
	{
		long S = System.currentTimeMillis();
		br = new BufferedReader(INPUT.isEmpty() ? new InputStreamReader(System.in) : new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new F().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}