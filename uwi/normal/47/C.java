//package round44;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String[] ss = new String[6];
		for(int i = 0;i < 6;i++){
			ss[i] = in.next();
		}
		int[] ord = new int[6];
		for(int i = 0;i < 6;i++)ord[i] = i;
		
		char[][] opt = null;
		String[] x = new String[6];
		outer:
		do{
			for(int i = 0;i < 6;i++){
				x[i] = ss[ord[i]];
			}
			
			if(x[0].length() + x[4].length() - 1 == x[2].length()){
				if(x[1].length() + x[5].length() - 1 == x[3].length()){
					if(x[0].charAt(0) == x[1].charAt(0)){
						if(x[0].charAt(x[0].length() - 1) == x[3].charAt(0)){
							if(x[1].charAt(x[1].length() - 1) == x[2].charAt(0)){
								if(x[2].charAt(x[2].length() - 1) == x[5].charAt(0)){
									if(x[3].charAt(x[3].length() - 1) == x[4].charAt(0)){
										if(x[4].charAt(x[4].length() - 1) == x[5].charAt(x[5].length() - 1)){
											if(x[2].charAt(x[0].length() - 1) == x[3].charAt(x[1].length() - 1)){
												int s = x[1].length() + x[5].length() - 1;
												int t = x[0].length() + x[4].length() - 1;
												char[][] pz = new char[s][t];
												for(int i = 0;i < s;i++){
													Arrays.fill(pz[i], '.');
												}
												for(int i = 0;i < x[0].length();i++)pz[0][i] = x[0].charAt(i);
												for(int i = 0;i < x[1].length();i++)pz[i][0] = x[1].charAt(i);
												for(int i = 0;i < x[2].length();i++)pz[x[1].length() - 1][i] = x[2].charAt(i);
												for(int i = 0;i < x[3].length();i++)pz[i][x[0].length() - 1] = x[3].charAt(i);
												for(int i = 0;i < x[4].length();i++)pz[s - 1][x[0].length() - 1 + i] = x[4].charAt(i);
												for(int i = 0;i < x[5].length();i++)pz[x[1].length() - 1 + i][t - 1] = x[5].charAt(i);
												
												if(opt == null){
													opt = pz;
												}else{
													for(int i = 0;i < opt.length && i < pz.length;i++){
														for(int j = 0;j < opt[i].length && j < pz[i].length;j++){
															if(opt[i][j] > pz[i][j]){
																opt = pz;
																continue outer;
															}else if(opt[i][j] < pz[i][j]){
																continue outer;
															}
														}
														if(opt[i].length > pz[i].length){
															opt = pz;
															continue outer;
														}else if(opt[i].length < pz[i].length){
															continue outer;
														}
													}
													if(opt.length > pz.length){
														opt = pz;
														continue outer;
													}else if(opt.length < pz.length){
														continue outer;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}while(nextPermutation(ord));
		
		if(opt == null){
			out.println("Impossible");
		}else{
			for(char[] r : opt){
				out.println(new String(r));
			}
		}
	}
	
	public static boolean nextPermutation(int[] src)
	{
		int i;
		for(i = src.length - 2;i >= 0 && src[i] > src[i+1];i--);
		if(i == -1)return false;
		int j;
		for(j = i + 1;j < src.length && src[i] < src[j];j++);
		int d = src[i]; src[i] = src[j - 1]; src[j - 1] = d;
		for(int p = i + 1, q = src.length - 1;p < q;p++,q--){
			d = src[p]; src[p] = src[q]; src[q] = d;
		}
		return true;
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}