//package round55;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class D {
	IntReader in;
	PrintWriter out;
//	String INPUT = "2\r\n" +
//			"4 1 3 2 5 6\r\n" +
//			"4 6 5\r\n" +
//			"1 2 3\r\n" +
//			"4";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] tps = new int[3*n];
		for(int i = 0;i < 3*n;i++){
			tps[i] = ni() - 1;
		}
		int[][] team = new int[n][3];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				team[i][j] = ni() - 1;
			}
		}
		int k = ni() - 1;
		BitSet used = new BitSet();
		for(int i = 0;i < n;i++){
			boolean end = false;
			for(int j = 0;j < 3;j++){
				if(team[i][j] == k){
					end = true;
				}
				used.set(team[i][j]);
			}
			if(end){
				for(int v = 0;v < 3*n;v++){
					for(int l = 0;l < 3;l++){
						if(team[i][l] == tps[v]){
							if(k == tps[v]){
								int max = 0;
								for(int f = 0;f < 3;f++){
									if(team[i][f] != k){
										max = Math.max(max, team[i][f]);
									}
								}
								used.clear(max+1, 3*n);
								
								for(int j = used.nextSetBit(0);j != -1;j = used.nextSetBit(j + 1)){
									if(j != k)out.print(j+1+" ");
								}
								for(int j = used.nextClearBit(0);j < 3*n;j = used.nextClearBit(j + 1)){
									if(j != k)out.print(j+1+" ");
								}
								out.println();
								return;
							}else{
								for(int j = 0;j < 3*n;j++){
									if(j != k)out.print(j+1+" ");
								}
								out.println();
								return;
							}
						}
					}
				}
			}
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) != -1 && (num < '0' || num > '9'));
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b == -1)return num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
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
					if(b == -1)return minus ? -num : num;
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
		
		public String nl()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
	}
	
	int ni() { return in.ni(); }
	int nui() { return in.nui(); }
	String nl() { return in.nl(); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}