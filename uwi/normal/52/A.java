

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class IntT {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = in.nui();
		int[] ct = new int[3];
		for(int i = 0;i < n;i++){
			ct[in.nui() - 1]++;
		}
		int min = 9999999;
		min = Math.min(min, ct[0] + ct[1]);
		min = Math.min(min, ct[1] + ct[2]);
		min = Math.min(min, ct[0] + ct[2]);
		out.println(min);
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
		new IntT().run();
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
	}
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}