import java.util.*;
import java.io.*;
import java.lang.*;

public class cf {
	static FastReader in = new FastReader();
	public static void main(String[] args) throws IOException {
		int t = i();
		while (t-- > 0) {
            int n = i(), m = i();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
            	for (int j = 0; j < m; j++) {
            		a[i][j] = i();
            	}
            }
            int[][][] left = new int[n][m][2];
            int[][][] right = new int[n][m][2];
            for (int i = 0; i < n; i++) {
            	int big = a[i][0], sml = a[i][0];
            	left[i][0][0] = sml;
            	left[i][0][1] = big;
            	for (int j = 1; j < m; j++) {
            		big = Math.max(big, a[i][j]);
            		sml = Math.min(sml, a[i][j]);
            		left[i][j][0] = sml;
            		left[i][j][1] = big;
            	}
            }
            //System.out.print(Arrays.deepToString(left));
            //System.out.print(Arrays.deepToString(right));
            for (int i = 0; i < n; i++) {
            	int big = a[i][m-1], sml = a[i][m - 1];
            	right[i][m-1][0] = sml;
            	right[i][m-1][1] = big;
            	for (int j = 1; j < m; j++) {
            		big = Math.max(big, a[i][m - j - 1]);
            		sml = Math.min(sml, a[i][m - j - 1]);
            		right[i][m - j - 1][0] = sml;
            		right[i][m - j - 1][1] = big;
            	}
            }
            boolean found = false;
            for (int i = 1; i < m; i++) {
            	List<Pair> lpairs = new ArrayList<>();
            	List<Pair> rpairs = new ArrayList<>();
            	for (int j = 0; j < n; j++) {
            		lpairs.add(new Pair(left[j][i-1][0], j));
            		lpairs.add(new Pair(left[j][i-1][1], j));
            		rpairs.add(new Pair(right[j][i][0], j));
            		rpairs.add(new Pair(right[j][i][1], j));
            	}
            	Collections.sort(rpairs);
            	Collections.sort(lpairs, Collections.reverseOrder());
            	int[] llocs = new int[n];
            	int[] rlocs = new int[n];
            	for (int j = 0; j < 2 * n; j++) {
            		llocs[lpairs.get(j).j] = j;
            		rlocs[rpairs.get(j).j] = j;
            	}
            	int[] included = new int[2 * n];
            	int bigl = 0;
            	int bigr = 0;
            	int pairs = 0;
            	found = false;
            	for (int j = 0; j < 2 * n; j++) {
            		if (included[j] == 0) {
            			pairs++;
            			if (pairs == n) {
            				break;
            			}
            			included[j] = 1;
            			int otherl = llocs[lpairs.get(j).j];
            			included[otherl] = 1;
            			bigl = Math.max(bigl, otherl);
            			bigr = Math.max(bigr, rlocs[lpairs.get(j).j]);
            			if (bigl == bigr && bigl == 2 * pairs - 1) {
            				if (rpairs.get(bigr).i != rpairs.get(bigr + 1).i && lpairs.get(bigl).i != lpairs.get(bigl + 1).i) {
            					found = true;
            					char[] colors = new char[n];
            					for (int k = 0; k < n; k++) {
            						colors[k] = 'B';
            					}
            					for (int k = 0; k < 2 * n; k++) {
            						if (included[k] == 1) {
            							colors[lpairs.get(k).j] = 'R';
            						}
            					}
            					System.out.println("YES");
            					for (int k = 0; k < n; k++) {
            						System.out.print(colors[k]);
            					}
            					System.out.print(' ');
            					System.out.print(i);
            					System.out.print('\n');
            					break;
            				}
            			}
            		}
            	}
            	if (found) {
            		break;
            	}
            }
            if (! found) {
            	System.out.println("NO");
            }
		}
	}
	static int i() {
        return in.nextInt();
    }
 
    static long l() {
        return in.nextLong();
    }
 
    static double d() {
        return in.nextDouble();
    }
 
    static String s() {
        return in.nextLine();
    }
}

class Pair implements Comparable<Pair> {
	 
    public int i, j;
 
    Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }
 
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Pair pair = (Pair) o;
        return i == pair.i && j == pair.j;
    }
 
    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }
    
    @Override
    public int compareTo(Pair p) {
    	if (this.i == p.i) {
    		return this.j - p.j;
    	}
    	return this.i - p.i;
    }
}

class FastReader {
	 
    BufferedReader br;
    StringTokenizer st;
 
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
 
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}