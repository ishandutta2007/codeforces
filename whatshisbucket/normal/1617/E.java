import java.util.*;
import java.io.*;
import java.lang.*;

public class cf {
	static FastReader in = new FastReader();
	static void print(Object o) {
		System.out.println(o);
	}
	static void prin(Object o) {
		System.out.print(o);
	}
	
	static int bits(int x) {
		return 32-Integer.numberOfLeadingZeros(x);
	}
	
	static int[] far(Map<Integer, List<Integer>> graph, int start) {
		if (!graph.containsKey(start)) {
			int[] out = {start, 0, start, start, 0};
			return out;
		}
		int deep1 = start;
		int depth1 = 0;
		int deep2 = start;
		int depth2 = 0;
		int x = 0;
		int y = 0;
		int dist = 0;
		for (int child : new HashSet<>(graph.get(start))) {
			int[] a = far(graph, child);
			if (a[1] + 1 > depth1) {
				deep2 = deep1;
				depth2 = depth1;
				deep1 = a[0];
				depth1 = a[1] + 1;
			} else if (a[1] + 1 > depth2) {
				deep2 = a[0];
				depth2 = a[1] + 1;
			}
			if (a[4] > dist) {
				x = a[2];
				y = a[3];
				dist = a[4];
			}
		}
		if (depth1 + depth2 > dist) {
			int[] out = {deep1, depth1, deep1, deep2, depth1 + depth2};
			return out;
		} else {
			int[] out = {deep1, depth1, x, y, dist};
			return out;
		}
	}
	
	public static void main(String[] args) throws IOException, InterruptedException {
		int n = i();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i();
			//a[i] = rand.nextInt(1000000001);
		}
		if (n > 200000) {
			System.out.println(System.currentTimeMillis());
		}
		int curr;
		Map<Integer, List<Integer>> graph = new HashMap<>();
		int[] pow = new int[32];
		for (int i = 0; i < 31; i++) {
			pow[i] = 1 << (30 - i);
		}
		for (int i = 0; i < n; i++) {
			curr = a[i];
			for (int val : pow) {
				if (2 * curr > val) {
					int ne = val - curr;
					if (graph.containsKey(ne)) {
						graph.get(ne).add(curr);
						break;
					} else {
						List<Integer> add = new ArrayList<>();
						add.add(curr);
						graph.put(ne, add);
						curr = ne;
					}
				}
			}
		}
		//System.out.println(graph);
		if (n > 200000) {
			System.out.println(System.currentTimeMillis());
		}
		HashSet<Integer> values = new HashSet<>();
		for (int x : a) {
			values.add(x);
		}
		curr = 0;
		while (!values.contains(curr)) {
			List<Integer> l = graph.get(curr);
			if (l.size() == 0) {
				break;
			}
			int num = l.get(0);
			boolean good = true;
			for (int val : l) {
				if (val != num) {
					good = false;
					break;
				}
			}
			if (good) { curr = num; }
			else { break; }
		}
		//System.out.println(System.currentTimeMillis());
		int[] x = far(graph, curr);
		//System.out.println(Arrays.toString(x));
		if (n > 200000) {
			System.out.println(System.currentTimeMillis());
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == x[2]) {
				System.out.print(i + 1);
			}
		}
		System.out.print(' ');
		for (int i = 0; i < n; i++) {
			if (a[i] == x[3]) {
				System.out.print(i + 1);
			}
		}
		System.out.print(' ');
		System.out.print(x[4]);
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

class CPair {
	public char c;
	public int n;
	
	public CPair(int n, char c) {
		this.c = c;
		this.n = n;
	}

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        CPair pair = (CPair) o;
        return n == pair.n && c == pair.c;
    }
    
    @Override
    public int hashCode() {
    	return Objects.hash(n, c);
    }
    
    @Override
    public String toString() {
    	return "(" + c + ", " + Integer.toString(n) + ")";
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
    
    @Override
    public String toString() {
    	return "(" + Integer.toString(i) + ", " + Integer.toString(j) + ")";
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