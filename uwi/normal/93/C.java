//package round76;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "113";
	int[][] hist = new int[10][5];
	int[][] opt = new int[10][5];
	int hp = 1;
	
	void solve()
	{
		int n = ni();
		hist[0][0] = 1;
		
		if(n == 1){
			out.println(0);
			return;
		}
		rec(n);
		out.println(min-1);
		for(int i = 1;i < min;i++){
			if(opt[i][3] == 1){
				if(opt[i][4] > 1){
					out.println("lea e" + (char)('a'+i) + "x, [e" + (char)('a'+opt[i][1]) + "x + " + opt[i][4] + "*e" + (char)('a'+opt[i][2]) + "x]");
				}else{
					out.println("lea e" + (char)('a'+i) + "x, [e" + (char)('a'+opt[i][1]) + "x + e" + (char)('a'+opt[i][2]) + "x]");
				}
			}else{
				out.println("lea e" + (char)('a'+i) + "x, [" + opt[i][4] + "*e" + (char)('a'+opt[i][2]) + "x]");
			}
		}
	}
	
	int[] nya = {0,1,2,4,8};
	int min = 9;
	
	void rec(int n)
	{
		if(hp+1 >= min)return;
		for(int i = 0;i < hp;i++){
			for(int j = 0;j < hp;j++){
				outer:
				for(int k = 1;k < 5;k++){
					int v = hist[i][0]+nya[k]*hist[j][0];
					if(v > n)continue;
					for(int l = 0;l < hp;l++){
						if(v == hist[l][0])continue outer;
					}
					hist[hp][0] = v;
					hist[hp][1] = i;
					hist[hp][2] = j;
					hist[hp][3] = 1;
					hist[hp][4] = nya[k];
					hp++;
					if(v == n){
						min = Math.min(min, hp);
						if(min == hp){
							for(int q = 0;q < hp;q++){
								opt[q] = Arrays.copyOf(hist[q], 5);
							}
						}
					}else{
						rec(n);
					}
					hp--;
				}
			
				outer2:
				for(int k = 2;k < 5;k++){
					int v = nya[k]*hist[j][0];
					if(v > n)continue;
					for(int l = 0;l < hp;l++){
						if(v == hist[l][0])continue outer2;
					}
					hist[hp][0] = v;
					hist[hp][1] = i;
					hist[hp][2] = j;
					hist[hp][3] = 0;
					hist[hp][4] = nya[k];
					hp++;
					if(v == n){
						min = Math.min(min, hp);
						if(min == hp){
							for(int q = 0;q < hp;q++){
								opt[q] = Arrays.copyOf(hist[q], 5);
							}
						}
					}else{
						rec(n);
					}
					hp--;
				}
			}
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
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
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}