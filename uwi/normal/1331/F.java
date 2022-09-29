//package afc2020;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	String[] ES = {
			"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na",
			"Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
			"Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb",
			"Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
			"Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu",
			"Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os",
			"Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac",
			"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No",
			"Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc",
			"Lv", "Ts", "Og"
	};
	
	void solve()
	{
		char[] s = in.next().toCharArray();
		int n = s.length;
		boolean[] dp = new boolean[n+1];
		dp[0] = true;
		for(int i = 0;i < n;i++) {
			if(dp[i]) {
				inner:
				for(String e : ES) {
					char[] h = e.toUpperCase().toCharArray();
					if(i+h.length > n)continue;
					for(int j = 0;j < h.length;j++) {
						if(s[i+j] != h[j])continue inner;
					}
					dp[i+h.length] = true;
				}
			}
		}
		out.println(dp[n] ? "YES" : "NO");
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
		new F().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}