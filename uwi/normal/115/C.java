//package round87;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class C5 {
//	InputStream is;
	BufferedReader br;
	PrintWriter out;
//	String INPUT = "2 2 13 ..";
//	String INPUT = "2 2 3. .1";
//	String INPUT = "3 3 ... ... ...";
//	String INPUT = "3 1 1 4 .";
	String INPUT = "";
	
	void solve() throws Exception
	{
		String line = br.readLine();
		String[] sp = line.split(" ");
		int n = Integer.parseInt(sp[0]);
		int m = Integer.parseInt(sp[1]);
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = br.readLine().toCharArray();
		}
		
		int mod = 1000003;
		int ret = 1;
		for(int i = 0;i < n;i++){
			int f = 3;
			for(int j = 0;j < m;j++){
				if(b[i][j] != '.'){
					if(j % 2 == 0){
						if(b[i][j] == '1' || b[i][j] == '2'){
							f &= 1;
						}else{
							f &= 2;
						}
					}else{
						if(b[i][j] == '1' || b[i][j] == '2'){
							f &= 2;
						}else{
							f &= 1;
						}
					}
				}
			}
			if(f == 3){
				ret = ret * 2 % mod;
			}else if(f == 0){
				ret = 0;
				break;
			}
		}
		
		for(int i = 0;i < m;i++){
			int f = 3;
			for(int j = 0;j < n;j++){
				if(b[j][i] != '.'){
					if(j % 2 == 0){
						if(b[j][i] == '1' || b[j][i] == '4'){
							f &= 1;
						}else{
							f &= 2;
						}
					}else{
						if(b[j][i] == '1' || b[j][i] == '4'){
							f &= 2;
						}else{
							f &= 1;
						}
					}
				}
			}
			if(f == 3){
				ret = ret * 2 % mod;
			}else if(f == 0){
				ret = 0;
				break;
			}
		}
		out.println(ret);
	}
	
	void run() throws Exception
	{
//		int n = 500000;
//		StringBuilder sb = new StringBuilder(n + " 1 ");
//		for(int i = 0;i < n;i++){
//			sb.append(". ");
//		}
//		INPUT = sb.toString();
//		int n = 500;
//		int m = 1000;
//		StringBuilder sb = new StringBuilder(n + " " + m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				sb.append(".");
//			}
//			sb.append("\r\n");
//		}
//		INPUT = sb.toString();
		
		br = new BufferedReader(new InputStreamReader(System.in));
//		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C5().run();
	}
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}