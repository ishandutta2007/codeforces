//package round27;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "4 2 1 3 2 4"; // io
//	private String INPUT = "6 4 1 3 3 5 5 1 2 4"; // iiio
//	private String INPUT = "6 5 1 3 3 5 1 4 2 5 2 3"; // ioioi
//	private String INPUT = "5 5 1 2 1 2 1 2 1 3 4 2"; // iiiio
//	private String INPUT = "5 5 1 3 1 3 1 3 2 4 4 2"; // iiioo
//	private String INPUT = "100 3 1 4 2 5 3 6"; // impossible
//	private String INPUT = "100 7 1 3 1 4 1 5 2 4 3 5 3 6 5 1";
//	private String INPUT = "8 3 1 3 3 5 4 6"; // iio
//	private String INPUT = "8 5 1 3 1 3 2 5 2 5 1 4"; // iiooi
//	private String INPUT = "8 5 1 3 3 5 3 6 5 7 6 2"; // iioio
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		R[] r = new R[m];
		for(int i = 0;i < m;i++){
			r[i] = new R();
			r[i].from = ni();
			r[i].to = ni();
			if(r[i].to < r[i].from){
				int d = r[i].from;
				r[i].from = r[i].to;
				r[i].to = d;
			}
		}
		
		int[][] imap = new int[m][m];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < i;j++){
				imap[i][j] = intersect(r, i, j) ? 1 : 0;
				imap[j][i] = imap[i][j];
			}
		}
		
		while(true){
			boolean nl = false;
			for(int i = 0;i < m;i++){
				for(int j = 0;j < i;j++){
					if(imap[i][j] == 0){
						for(int k = 0;k < m;k++){
							if(imap[i][k] > 0 && imap[k][j] > 0){
								imap[i][j] = imap[i][k] + imap[k][j];
								imap[j][i] = imap[i][j];
								nl = true;
								break;
							}
						}
					}
				}
			}
			if(!nl)break;
		}
		
		for(int[] row : imap){
			tr(Arrays.toString(row));
		}
		
		int[] f = new int[m];
		Arrays.fill(f, 3);
		
		BitSet cled = new BitSet();
		for(int i = 0;i < m;i++){
			if(!cled.get(i)){
				f[i] = 1;
				for(int j = i;j < m;j++){
					if(imap[i][j] > 0)cled.set(j);
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			for(int j = 0;j < i;j++){
				if(imap[i][j] > 0){
					if(imap[i][j] % 2 == 1){
						if(f[i] != 3)f[j] &= 3 - f[i];
						if(f[j] != 3)f[i] &= 3 - f[j];
						if(f[i] != 3)f[j] &= 3 - f[i];
						if(f[j] != 3)f[i] &= 3 - f[j];
					}else{
						f[j] &= f[i];
						f[i] &= f[j];
					}
				}
			}
		}
		tr(Arrays.toString(f));
		
		for(int i = 0;i < m;i++){
			if(f[i] == 0){
				out.println("Impossible");
				return;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < m;i++){
			if(f[i] == 1){
				sb.append('i');
			}else{
				sb.append('o');
			}
		}
		out.println(sb.toString());
	}
	
	public boolean intersect(R[] r, int a, int b)
	{
		if(r[a].from < r[b].from && r[b].from < r[a].to && r[a].to < r[b].to)return true;
		if(r[b].from < r[a].from && r[a].from < r[b].to && r[b].to < r[a].to)return true;
		return false;
	}
	
	public static class R
	{
		public int from;
		public int to;
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}