//package round114;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;

public class Div2B {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		StringBuilder sb = null;
		while(true){
			String line = br.readLine();
			if(line == null)break;
			
			boolean amp = false;
			for(int i = 0;i < line.length();i++){
				if(line.charAt(i) != ' '){
					if(line.charAt(i) == '#'){
						amp = true;
					}
					break;
				}
			}
			if(amp){
				if(sb != null){
					out.println(sb);
					sb = null;
				}
				out.println(line);
			}else{
				if(sb == null){
					sb = new StringBuilder();
				}
				sb.append(line.replace(" ", ""));
			}
		}
		if(sb != null){
			out.println(sb);
			sb = null;
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
		new Div2B().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}