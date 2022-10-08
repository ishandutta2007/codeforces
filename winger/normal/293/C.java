import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class CF293C {

    static long f(long a, long b, long c) {
        return (a*a*b+a*a*c+a*b*b+b*b*c+a*c*c+b*c*c) + 2 * a * b * c;
    }

    static long solve(long n, long d, long u, long v, long w) {
        if (d * d > n) {
            if (n > 1) {
                return solve(1, d, u * n, v, w) + solve(1, d, u, v * n, w) + solve(1, d, u, v, w * n);
            }
            return (u + v + w) % 2 == 0 && u + v > w && u + w > v && v + w > u ? 1 : 0;
        }
        if (n % d == 0) {
            int count = 0;
            while (n % d == 0) {
                count++;
                n /= d;
            }
            long r = 0;
            long u1 = u;
            for (int i = 0; i <= count; ++i) {
                long v1 = v;
                for (int j = 0; i + j <= count; ++j) {
                    long w1 = w;
                    for (int k = 0; i + j + k < count; ++k) {
                        w1 *= d;
                    }
                    r += solve(n, d, u1, v1, w1);
                    v1 *= d;
                }
                u1 *= d;
            }
            return r;
        } else {
            return solve(n, d + 1, u, v, w);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
//        long ans = 0;
        long n = in.nextLong();
        if (n % 3 != 0) {
            out.println(0);
            return;
        }
        n /= 3;
        long t0 = System.currentTimeMillis();
//        ArrayList<Long> divsL = new ArrayList<Long>();
//        for (long d = 2; d * d <= n; ++d) {
//            if (n % d == 0) {
//                divsL.add(d);
//                if (d * d < n) {
//                    divsL.add(n / d);
//                }
//            }
//        }
//        long[] divs = new long[divsL.size()];
//        for (int i = 0; i < divs.length; ++i) {
//            divs[i] = divsL.get(i);
//        }
//        Arrays.sort(divs);
//        for (int u = 0; u < divs.length; ++u) {
//            int w = divs.length - 1;
//            for (int v = u; v < divs.length; ++v) {
//                while (w >= v && divs[u] * divs[v] > n / divs[w]) {
//                    --w;
//                }
//                if (w < v) {
//                    break;
//                }
//                if ((divs[u] + divs[v] + divs[w]) % 2 == 0 && divs[u] + divs[v] > divs[w] && divs[u] * divs[v] * divs[w] == n) {
////                    System.out.println(divs[u] + " " + divs[v] + " " + divs[w]);
////                    long a = (+ divs[u] + divs[v] - divs[w]) / 2;
////                    long b = (+ divs[u] - divs[v] + divs[w]) / 2;
////                    long c = (- divs[u] + divs[v] + divs[w]) / 2;
////                    System.out.println(a + " " + b + " " + c);
//                    if (u == v && v == w) {
//                        ans++;
//                    } else if (u == v || u == w || v == w) {
//                        ans += 3;
//                    } else {
//                        ans += 6;
//                    }
//                }
//            }
//        }
        out.println(solve(n, 2, 1, 1, 1));
//        for (long a = 1; f(a, a, a) <= n; ++a) {
////            System.out.println(a);
//            for (long b = a; f(a, b, b) <= n; ++b) {
//                long det = (a + b) * (a * a * a - a * a * b - a * b * b + b * b * b + 4 * n);
//                if (det >= 0) {
//                    long d = (long)Math.sqrt(det);
//                    while ((d + 1) * (d + 1) <= det) {
//                        ++d;
//                    }
//                    while (d * d > det) {
//                        --d;
//                    }
//                    if (d * d == det) {
//                        long c = (d - a * a - 2 * a * b - b * b);
//                        if (c >= 0 && c % (2 * (a + b)) == 0) {
//                            c /= 2 * (a + b);
////                            if (f(a, b, c) != n) {
////                                throw new AssertionError();
////                            }
//                            System.out.println(a + " " + b + " " + c);
//                            if (a == b && b == c) {
//                                ans++;
//                            } else if (a == b || a == c || b == c) {
//                                ans += 3;
//                            } else {
//                                ans += 6;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        System.out.println(maxb + " " + count);
//        System.out.println(System.currentTimeMillis() - t0);
//        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}