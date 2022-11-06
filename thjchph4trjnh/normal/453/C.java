import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	static double EPS = 1e-9;
	static int INF = (int) 1e9;
	static long LINF = (long) 1e18;
	static int MOD = (int) 1e9 + 7;
	static double PI = 2 * Math.acos(0);
	
	static int maxn = 100010;
	static int n, m;
	static ArrayList<Integer> adj[] = new ArrayList[maxn];
	static int a[] = new int[maxn];
	static int vis[] = new int[maxn];
	static ArrayList<Integer> ans = new ArrayList<Integer>();
	
	public static void dfs(int u, int p) {
		vis[u] = 1; ans.add(u); a[u] ^= 1;
		for (int v : adj[u]) {
			if (vis[v] == 0) {
				dfs(v, u);
			}
		}
		if (p != -1) {
			if (a[u] == 1) {
				ans.add(p); a[p] ^= 1;
				ans.add(u); a[u] ^= 1;
			}
			ans.add(p); a[p] ^= 1;
		}
	}
	
	public static void solve() {
		n = Input.nextInt();
    	m = Input.nextInt();
    	for (int i = 0; i < n; i++) {
    		adj[i] = new ArrayList<Integer>();
    	}
    	for (int i = 0; i < m; i++) {
    		int u = Input.nextInt() - 1;
    		int v = Input.nextInt() - 1;
    		adj[u].add(v); adj[v].add(u);
    	}
    	int r = -1;
    	for (int i = 0; i < n; i++) {
    		a[i] = Input.nextInt();
    		if (a[i] == 1) r = i;
    	}
    	if (r != -1) {
    		dfs(r, -1);
    		if (a[r] == 1) {
    			ans.remove(ans.size() - 1);
    			a[r] ^= 1;
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		if (a[i] == 1) {
    			out.print("-1");
    			return;
    		}
    	}
    	out.println(ans.size());
    	for (int u : ans) {
    		out.print((u + 1) + " ");
    	}
	}
	
    public static void main(String[] args) {
    	out = new PrintWriter(System.out);
    	solve();
    	out.close();
    }
    
    private static class Input {
    	private static StringTokenizer token = null;
    	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//    	private static BufferedReader in;
//    	static {
//    		try {
//                in = new BufferedReader(new FileReader("in.txt"));
//            } catch (IOException e) {
//            }
//    	}
        
        public static final int nextInt() {
            return Integer.parseInt(nextString());
        }

        public static final long nextLong() {
            return Long.parseLong(nextString());
        }

        public static final double nextDouble() {
            return Double.parseDouble(nextString());
        }

        public static final String nextString() {
            try {
                while (token == null || !token.hasMoreTokens()) {
                    token = new StringTokenizer(in.readLine());
                }
            } catch (IOException e) {
            }
            return token.nextToken();
        }
    }
}