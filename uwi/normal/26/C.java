//package round26;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 6 2 2 1";
//	private String INPUT = "11 10 15 15 15";
//	private String INPUT = "10 11 15 15 15";
	private String INPUT = "";
	private String IMP = "IMPOSSIBLE";
	
	public void solve()
	{
		int n = ni(), m = ni(), a = ni(), b = ni(), c = ni();
		if(n % 2 == 1 && m % 2 == 1){
			out.println(IMP);
			return;
		}
		if(n % 2 == 1 && a < m / 2){
			out.println(IMP);
			return;
		}
		if(m % 2 == 1 && b < n / 2){
			out.println(IMP);
			return;
		}
		if(n * m > a * 2 + b * 2 + c * 4){
			out.println(IMP);
			return;
		}
		
		if(n % 2 == 1){
			a -= m / 2;
		}
		if(m % 2 == 1){
			b -= n / 2;
		}
		
		char[][] col = new char[n][m];
		for(int y = 0;y < n - 1;y += 2){
			for(int x = 0;x < m - 1;x += 2){
				if(c > 0){
					c--;
					int used = 0;
					if(x >= 2){
						used |= 1 << (col[y][x-1] - 'a');
						used |= 1 << (col[y+1][x-1] - 'a');
					}
					if(y >= 2){
						used |= 1 << (col[y-1][x] - 'a');
						used |= 1 << (col[y-1][x+1] - 'a');
					}
					char ca;
					for(ca = 'a';(used & (1 << (ca - 'a'))) != 0;ca++);
					
					col[y][x] = ca;
					col[y][x+1] = ca;
					col[y+1][x] = ca;
					col[y+1][x+1] = ca;
				}else if(a >= 2){
					a-=2;
					int used1 = 0;
					int used2 = 0;
					if(x >= 2){
						used1 |= 1 << (col[y][x-1] - 'a');
						used2 |= 1 << (col[y+1][x-1] - 'a');
					}
					if(y >= 2){
						used1 |= 1 << (col[y-1][x] - 'a');
						used1 |= 1 << (col[y-1][x+1] - 'a');
					}
					
					char ca1, ca2;
					for(ca1 = 'a';(used1 & (1 << (ca1 - 'a'))) != 0;ca1++);
					used2 |= 1 << (ca1 - 'a');
					for(ca2 = 'a';(used2 & (1 << (ca2 - 'a'))) != 0;ca2++);
					col[y][x] = ca1;
					col[y][x+1] = ca1;
					col[y+1][x] = ca2;
					col[y+1][x+1] = ca2;
				}else if(b >= 2){
					b-=2;
					int used1 = 0;
					int used2 = 0;
					if(x >= 2){
						used1 |= 1 << (col[y][x-1] - 'a');
						used1 |= 1 << (col[y+1][x-1] - 'a');
					}
					if(y >= 2){
						used1 |= 1 << (col[y-1][x] - 'a');
						used2 |= 1 << (col[y-1][x+1] - 'a');
					}
					
					char ca1, ca2;
					for(ca1 = 'a';(used1 & (1 << (ca1 - 'a'))) != 0;ca1++);
					used2 |= 1 << (ca1 - 'a');
					for(ca2 = 'a';(used2 & (1 << (ca2 - 'a'))) != 0;ca2++);
					col[y][x] = ca1;
					col[y][x+1] = ca2;
					col[y+1][x] = ca1;
					col[y+1][x+1] = ca2;
				}else{
					out.println(IMP);
					return;
				}
			}
		}
		
		
		if(n % 2 == 1){
			for(int x = 0;x < m;x+=2){
				int used = 0;
				if(x >= 2){
					used |= 1 << (col[n-1][x-1] - 'a');
				}
				if(n-1 >= 2){
					used |= 1 << (col[n-2][x] - 'a');
					used |= 1 << (col[n-2][x+1] - 'a');
				}
				
				char ca;
				for(ca = 'a';(used & (1 << (ca - 'a'))) != 0;ca++);
				col[n-1][x] = ca;
				col[n-1][x+1] = ca;
			}
		}
		
		if(m % 2 == 1){
			for(int y = 0;y < n;y+=2){
				int used = 0;
				if(y >= 2){
					used |= 1 << (col[y-1][m-1] - 'a');
				}
				if(m-1 >= 2){
					used |= 1 << (col[y][m-2] - 'a');
					used |= 1 << (col[y+1][m-2] - 'a');
				}
				
				char ca;
				for(ca = 'a';(used & (1 << (ca - 'a'))) != 0;ca++);
				col[y][m-1] = ca;
				col[y+1][m-1] = ca;
			}
		}
		
		for(char[] row : col){
			out.println(new String(row));
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
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}