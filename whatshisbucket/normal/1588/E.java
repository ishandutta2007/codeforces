import java.util.*;
import java.io.*;
import java.lang.*;

public class cf {
	static FastReader in = new FastReader();
	
	static double angle(Pair a, Pair b) {
		if (b.i == a.i) {
			if (b.j >= a.j) {
				return Math.PI/2;
			} else { return 3 * Math.PI/2; }
		}
		double tan = Math.atan((double)(b.j - a.j) / (double)(b.i - a.i));
		if (b.i < a.i) {
			return tan + Math.PI;
		} else if (b.j < a.j) {
			return tan + 2 * Math.PI;
		} else { return tan; }
	}
	
	static double dist(Pair a, Pair b) {
		return Math.pow(Math.pow(b.j - a.j, 2) + Math.pow(b.i - a.i, 2), 0.5);
	}
	
	public static void main(String[] args) throws IOException {
		int n = i();
		int R = i();
		List<Pair> points = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int x = i();
			int y = i();
			points.add(new Pair(x, y));
		}
		int[][] goodrays = new int[n][n];
		
		double tau = 2 * Math.PI;
		for (int i = 0; i < n; i++) {
			List<Double> angles = new ArrayList<>();
			List<Double> interval = new ArrayList<>(List.of(-1000., -1000.));
			boolean fail = false;
			for (int j = 0; j < n; j++) {
				if (j == i) {
					angles.add(-1000.);
				} else {
					double d = dist(points.get(i), points.get(j));
					double a = angle(points.get(i), points.get(j));
					angles.add(a);
					if (d > R) {
						double diff = Math.asin((double)R / d);
						double sml = (a - diff) % tau;
						if (sml < 0) {
							sml += tau;
						}
						double big = (a + diff) % tau;
						if (interval.get(0) < -500.) {
							interval.set(0, sml);
							interval.set(1, big);
						} else {
							double left = interval.get(0);
							double right = interval.get(1);
							if (left <= right) {
								if (left < big && big < right) {
									interval.set(1, big);
								}
								if (left < sml && sml < right) {
									interval.set(0, sml);
								}
								left = interval.get(0);
								if (! ((sml <= left && left <= big) || (left <= big && big <= sml) || (big <= sml && sml <= left))) {
									fail = true;
									break;
								}
							} else {
								boolean change = false;
								if (sml > left || right > sml) {
									interval.set(0, sml);
									change = true;
								}
								if (big > left || right > big) {
									interval.set(1, big);
									change = true;
								}
								if (! change && sml < big) {
									fail = true;
									break;
								}
							}
						}
					}
				}
			}
			if (! fail) {
				if (interval.get(0) < -500.) {
					for (int j = 0; j < n; j++) {
						if (j != i) {
							goodrays[i][j] = 1;
						}
					}
				} else if (interval.get(0) <= interval.get(1)) {
					for (int j = 0; j < n; j++) {
						double ang = angles.get(j);
						if (ang > -500. && interval.get(0) <= ang && ang <= interval.get(1)) {
							goodrays[i][j] = 1;
						}
					}
				} else {
					for (int j = 0; j < n; j++) {
						double ang = angles.get(j);
						if (ang > -500. && (interval.get(0) <= ang || ang <= interval.get(1))) {
							goodrays[i][j] = 1;
						}
					}
				}
			}
		}
		//System.out.println(Arrays.deepToString(goodrays));
		int tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (goodrays[i][j] == 1 && goodrays[j][i] == 1)  {
					tot += 1;
				}
			}
		}
		System.out.println(tot);
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