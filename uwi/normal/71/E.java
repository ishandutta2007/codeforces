//package round65;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "17 17 H He Li Be B C N O F Ne Na Mg Al Si P S Cl H He Li Be B C N O F Ne Na Mg Al Si P S Ne";
//	String INPUT = "17 4 H H H H H H H H H H H H H H H H Be B B B B";
//	String INPUT = "2 1\r\n" +
//			"H H\r\n" +
//			"He";
	String INPUT = "";
	
	String[] PT = {null, "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
			"Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
			"K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
			"Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
			"Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
			"Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
			"Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es", "Fm"
			};
	
	void solve()
	{
		Map<String, Integer> map = new HashMap<String, Integer>();
		for(int j = 1;j < PT.length;j++){
			map.put(PT[j], j);
		}
		int n = ni();
		int k = ni();
		int[] from = new int[n];
		int[] to = new int[k];
		int oo = 0;
		for(int i = 0;i < n;i++){
			from[i] = map.get(in.next());
			oo += from[i];
		}
		int pp = 0;
		for(int i = 0;i < k;i++){
			to[i] = map.get(in.next());
			pp += to[i];
		}
		if(oo != pp){
			out.println("NO");
			return;
		}
		
		int[] psuml = new int[oo+1];
		int[] ss = new int[1<<n];
		for(int i = 0;i < 1<<n;i++){
			int sum = 0;
			for(int j = 0;j < n;j++){
				if((i&1<<j) != 0){
					sum += from[j];
				}
			}
			ss[i] = sum;
			psuml[sum]++;
		}
		int[][] suml = new int[oo+1][];
		for(int i = 0;i <= oo;i++){
			suml[i] = new int[psuml[i]];
		}
		for(int i = 0;i < 1<<n;i++){
			suml[ss[i]][--psuml[ss[i]]] = i;
		}
		
		BitSet[] bs = new BitSet[k+1];
		for(int i = 0;i <= k;i++){
			bs[i] = new BitSet();
		}
		bs[0].set(0);
		for(int i = 0;i < k;i++){
			for(int j = bs[i].nextSetBit(0);j != -1;j = bs[i].nextSetBit(j + 1)){
				if(suml.length <= to[i]){
					out.println("NO");
					return;
				}
				for(int u : suml[to[i]]){
					if((u&j) == 0){
						bs[i+1].set(u|j);
					}
				}
			}
		}
		if(bs[k].get((1<<n)-1)){
			out.println("YES");
			int cur = (1<<n)-1;
			outer:
			for(int i = k-1;i >= 0;i--){
				for(int u : suml[to[i]]){
					if((cur&u) == u && bs[i].get(cur^u)){
						StringBuilder sb = new StringBuilder();
						for(int j = 0;j < n;j++){
							if((u&1<<j) != 0){
								sb.append(PT[from[j]]);
								sb.append("+");
							}
						}
						sb.deleteCharAt(sb.length() - 1);
						sb.append("->");
						sb.append(PT[to[i]]);
						out.println(sb);
						
						cur ^= u;
						continue outer;
					}
				}
			}
		}else{
			out.println("NO");
		}
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
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}