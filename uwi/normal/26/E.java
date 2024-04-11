//package round26;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class E {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "1 10 10";
//	private String INPUT = "2 3 5 5";
//	private String INPUT = "3 1 1 2 3";
//	private String INPUT = "3 2 5 1 2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int w = ni();
		int[] t = new int[n];
		int min = 99999;
		int mini = -1;
		int sum = 0;
		for(int i = 0;i < n;i++){
			t[i] = ni();
			sum += t[i];
			if(t[i] < min){
				min = t[i];
				mini = i;
			}
		}
		
		if(w <= 0 || w > sum){
			out.println("No");
			return;
		}
		if(n == 1){
			if(w == t[0]){
				out.println("Yes");
				for(int i = 0;i < 2 * t[0];i++){
					out.print("1 ");
				}
				out.println();
			}else{
				out.println("No");
			}
		}else{
			if(w == 1){
				if(min == 1){
					out.println("Yes");
					out.printf("%d ", mini + 1);
					for(int i = 0;i < n;i++){
						if(i == mini)continue;
						for(int u = 0;u < t[i];u++){
							out.printf("%d %d ", i + 1, i + 1);
						}
					}
					out.println(mini + 1);
				}else{
					out.println("No");
				}
			}else{
				out.println("Yes");
				if(t[0] < w){
					int pos = 0;
					List<Integer> ord = new ArrayList<Integer>();
					List<Integer> ord0 = new ArrayList<Integer>();
					for(int i = 0;i < n;i++){
						for(int u = 0;u < t[i];u++){
							if(pos < w){
								ord.add(i + 1);
								ord.add(i + 1);
							}else{
								ord0.add(i + 1);
								ord0.add(i + 1);
							}
							pos++;
						}
					}
					
					ord.addAll(1, ord0);
					for(int o : ord){
						out.printf("%d ", o);
					}
					out.println();
				}else{
					List<Integer> in0 = new ArrayList<Integer>();
					List<Integer> in1 = new ArrayList<Integer>();
					for(int i = 1;i < n;i++){
						in0.addAll(Collections.nCopies((t[i] - (i == 1 ? 1 : 0)) * 2, i + 1));
//						for(int u = i == 1 ? 1 : 0;u < t[i];u++){
//							in0.add(i + 1);
//							in0.add(i + 1);
//						}
					}
					
					in1 = Collections.nCopies((t[0] - (w - 1)) * 2, 1);
//					for(int u = w - 1;u < t[0];u++){
//						in1.add(1);
//						in1.add(1);
//					}
					
					List<Integer> ord = new ArrayList<Integer>();
					for(int i = 0;i < w - 1;i++){
						ord.add(1);
						if(i == 0)ord.addAll(in0);
						ord.add(1);
					}
					ord.add(2);
					ord.addAll(in1);
					ord.add(2);
					
					for(int o : ord){
						out.printf("%d ", o);
					}
					out.println();
				}
			}
		}
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
		new E().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}