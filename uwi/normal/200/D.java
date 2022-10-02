//package round126;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class D {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		int n = Integer.parseInt(br.readLine());
		String[][] args = new String[n][];
		String[] func = new String[n];
		for(int i = 0;i < n;i++){
			String line = br.readLine();
			int vo = line.indexOf("void");
			int ks = line.indexOf("(");
			int ke = line.lastIndexOf(")");
			func[i] = line.substring(vo + 4, ks).trim();
			args[i] = line.substring(ks+1, ke).split(",");
			for(int j = 0;j < args[i].length;j++){
				args[i][j] = args[i][j].trim();
			}
		}
		
		int m = Integer.parseInt(br.readLine());
		// <name, type>
		Map<String, String> map = new HashMap<String, String>();
		for(int i = 0;i < m;i++){
			String line = br.readLine().trim();
			int sp = line.indexOf(" ");
			String ty = line.substring(0, sp).trim();
			String name = line.substring(sp + 1).trim();
			map.put(name, ty);
		}
		
		int Q = Integer.parseInt(br.readLine());
		for(int i = 0;i < Q;i++){
			String line = br.readLine().trim();
			int ks = line.indexOf("(");
			int ke = line.lastIndexOf(")");
			String fname = line.substring(0, ks).trim();
			String[] as = line.substring(ks+1, ke).split(",");
			for(int j = 0;j < as.length;j++){
				as[j] = map.get(as[j].trim());
			}
			int res = 0;
			inner:
			for(int j = 0;j < n;j++){
				if(fname.equals(func[j]) && args[j].length == as.length){
					for(int k = 0;k < as.length;k++){
						if(args[j][k].equals("T") || args[j][k].equals(as[k])){
						}else{
							continue inner;
						}
					}
					res++;
				}
			}
			out.println(res);
		}
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
		new D().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}