import java.util.*;
import java.io.*;
import java.lang.*;

public class cf {
	static FastReader in = new FastReader();
	
	public static void main(String[] args) throws IOException {
		int t = i();
		while (t-- > 0) {
            s();
            int n = i(), m = i();
            String[] mat = new String[n];
            for (int i = 0; i < n; i++) {
            	mat[i] = s();
            }
            int[][] visited = new int[n][m];
            int[][] vals = new int[n][m];
            int big = 0;
            Pair loc = null;
            for (int i = 0; i < n; i++) {
            	for (int j = 0; j < m; j++) {
            		if (visited[i][j] == 0) {
            			List<Pair> path = new ArrayList<>();
            			int r = i;
            			int c = j;
            			while (0 <= r && r < n && 0 <= c && c < m && visited[r][c] == 0) {
            				visited[r][c] = 1;
            				path.add(new Pair(r, c));
            				char dir = mat[r].charAt(c);
            				if (dir == 'U') { r -= 1;
            				} else if (dir == 'D') { r += 1;
            				} else if (dir == 'L') { c -= 1;
            				} else { c += 1; }
            			}
            			if (r < 0 || r >= n || c < 0 || c >= m) {
            				int k = 0;
            				if (path.size() > big) {
            					big = path.size();
            					loc = path.get(0);
            				}
            				for (Pair p : path) {
            					vals[p.i][p.j] = path.size() - k;
            					k++;
            				}
            			} else if (vals[r][c] == 0) {
            				int k = 0;
            				int l = 0;
            				if (path.size() > big) {
            					big = path.size();
            					loc = path.get(0);
            				}
            				for (Pair p : path) {
            					if (p.i == r && p.j == c) {
            						l = path.size() - k;
            					}
            					vals[p.i][p.j] = Math.max(l, path.size() - k);
            					k++;
            				}
            			} else {
            				int v = vals[r][c];
            				int k = 0;
            				if (v + path.size() > big) {
            					big = v + path.size();
            					loc = path.get(0);
            				}
            				for (Pair p : path) {
            					vals[p.i][p.j] = v + path.size() - k;
            					k++;
            				}
            			}
            		}
            	}
            }
            String out = Integer.toString(loc.i + 1);
            out += " ";
            out += loc.j + 1;
            out += " ";
            out += big;
            System.out.println(out);
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