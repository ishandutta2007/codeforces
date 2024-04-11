import java.io.*;
import java.util.*;

public class b {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		solve(in, out);
		out.close();
	}

	static private boolean valid(int[] a) {
		for(int i = 0; i + 1 < a.length; i++) {
			if(i % 2 == 0 && a[i] >= a[i + 1]) {
				return false;
			} else if(i % 2 == 1 && a[i] <= a[i + 1]) {
				return false;
			}
		}
		return true;
	}

	static private void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] bottom = new int[(n + 1) / 2];
		int[] upper = new int[n / 2];
		for(int i = 0; i < n; i += 2) {
			bottom[i / 2] = 200000;
			if(i + 1 < n) {
				bottom[i / 2] = a[i + 1];
			}
			if(i != 0 && a[i - 1] < bottom[i / 2]) {
				bottom[i / 2] = a[i - 1];
			}
			//out.print(bottom[i / 2] + " ");
		}
		//out.println();
		for(int i = 1; i < n; i += 2) {
			upper[i / 2] = a[i - 1];
			if(i + 1 < n && a[i + 1] > upper[i / 2]) {
				upper[i / 2] = a[i + 1];
			}
			//out.print(upper[i / 2] + " ");
		}
		//out.println();
		int l = 0, r = n - 1;
		while(l < n) {
			if(l % 2 == 0 && a[l] >= a[l + 1]) {
				break;
			} else if(l % 2 == 1 && a[l] <= a[l + 1]) {
				break;
			}
			l++;
		}
		while(r > 0) {
			r--;
			if(r % 2 == 0 && a[r] >= a[r + 1]) {
				break;
			} else if(r % 2 == 1 && a[r] <= a[r + 1]) {
				break;
			}
		}
		int ans = 0;
		int lul = 10;
		//out.println("got (" + l + ", " + r + ")");
		if(l == r) {
			if(l % 2 == 0) {
				if(l < n) {
					//out.println("is bottom, " + bottom[l / 2]);
					for(int i = 0; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] < bottom[l / 2] && a[l] < bottom[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
					for(int i = 1; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] < bottom[l / 2] && a[l] > upper[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
				}
				l++;
				if(l < n) {
					//out.println("is upper, " + bottom[l / 2]);
					for(int i = 0; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] > upper[l / 2] && a[l] < bottom[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
					for(int i = 1; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] > upper[l / 2] && a[l] > upper[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
				}
			} else {
				if(l < n) {
					//out.println("is upper, " + bottom[l / 2]);
					for(int i = 0; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] > upper[l / 2] && a[l] < bottom[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
					for(int i = 1; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] > upper[l / 2] && a[l] > upper[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
				}
				//out.println(ans);
				l++;
				if(l < n) {
					//out.println("is bottom, " + bottom[l / 2]);
					for(int i = 0; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] < bottom[l / 2] && a[l] < bottom[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
					for(int i = 1; i < n; i += 2) {
						if((r - lul <= i && i <= r + lul)) continue;
						if(a[i] < bottom[l / 2] && a[l] > upper[i / 2]) {
							//out.println("found answer swapping (" + l + ", " + i + ")");
							ans++;
						}
					}
				}
				//out.println(ans);
			}
			l--;
		} else if(l + 1 == r) {
			lul = 1;
			l++;
			if(r % 2 == 0) {
				for(int i = 0; i < n; i += 2) {
					if((r - lul <= i && i <= r + lul)) continue;
					if(a[i] < bottom[l / 2] && a[l] < bottom[i / 2]) {
						//out.println("found answer swapping (" + l + ", " + i + ")");
						ans++;
					}
				}
				for(int i = 1; i < n; i += 2) {
					if((r - lul <= i && i <= r + lul)) continue;
					if(a[i] < bottom[l / 2] && a[l] > upper[i / 2]) {
						//out.println("found answer swapping (" + l + ", " + i + ")");
						ans++;
					}
				}
			} else {
				for(int i = 0; i < n; i += 2) {
					if((r - lul <= i && i <= r + lul)) continue;
					if(a[i] > upper[l / 2] && a[l] < bottom[i / 2]) {
						//out.println("found answer swapping (" + l + ", " + i + ")");
						ans++;
					}
				}
				for(int i = 1; i < n; i += 2) {
					if((r - lul <= i && i <= r + lul)) continue;
					if(a[i] > upper[l / 2] && a[l] > upper[i / 2]) {
						//out.println("found answer swapping (" + l + ", " + i + ")");
						ans++;
					}
				}
			}
		}
		for(int i = -lul; i <= lul; i++) {
			for(int j = -lul; j <= lul; j++) {
				//out.println("testing (" + (i + l) + ", " + (j + r) + ")");
				if(i + l < 0 || j + r < 0 || l + i >= r + j || l + i >= n || r + j >= n) {
					continue;
				}
				//out.println("testing (" + (i + l) + ", " + (j + r) + ")");
				int t = a[l + i];
				a[l + i] = a[r + j];
				a[r + j] = t;
				if(valid(a)) {
					ans++;
				}
				a[r + j] = a[l + i];
				a[l + i] = t;
			}
		}
		out.println(ans);
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}