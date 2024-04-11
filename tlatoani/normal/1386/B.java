import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Mixture {
    
    static long[] favorite = new long[3];
    static long[][] matrix = new long[3][3];
    
    static void add(int to, int from) {
        for (int j = 0; j <= 2; j++) {
            matrix[to][j] += matrix[from][j];
        }
    }

    static void subtract(int to, int from) {
        for (int j = 0; j <= 2; j++) {
            matrix[to][j] -= matrix[from][j];
        }
    }
    
    static void reduce(int a, int b) {
        while (favorite[a] != 0L && favorite[b] != 0L) {
            if (favorite[a] >= favorite[b]) {
                favorite[a] -= favorite[b];
                subtract(a, b);
            } else {
                favorite[b] -= favorite[a];
                subtract(b, a);
            }
        }
        if (favorite[a] != 0L) {
            favorite[b] += favorite[a];
            add(b, a);
            favorite[a] -= favorite[b];
            subtract(a, b);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        for (int j = 0; j <= 2; j++) {
            favorite[j] = Long.parseLong(tokenizer.nextToken());
            matrix[j][j] = 1L;
        }
        reduce(0, 1);
        reduce(1, 2);
        /*for (int y = 0; y <= 2; y++) {
            for (int x = 0; x <= 2; x++) {
                System.out.print(matrix[y][x] + " ");
            }
            System.out.println();
        }*/
        int amt00 = 0;
        int amtPosInfty = 0;
        int amtNegInfty = 0;
        int amtMatch = 0;
        TreeMap<Rational, Integer> positive = new TreeMap<>();
        TreeMap<Rational, Integer> negative = new TreeMap<>();
        int j = 0;
        int n = Integer.parseInt(in.readLine());
        long[] xs = new long[n + 1];
        long[] ys = new long[n + 1];
        StringBuilder out = new StringBuilder();
        for (; n > 0; n--) {
            tokenizer = new StringTokenizer(in.readLine());
            if (tokenizer.nextToken().charAt(0) == 'A') {
                j++;
                for (int a = 0; a <= 2; a++) {
                    long k = Long.parseLong(tokenizer.nextToken());
                    xs[j] += matrix[0][a] * k;
                    ys[j] += matrix[1][a] * k;
                }
                if (xs[j] == 0L) {
                    if (ys[j] == 0L) {
                        amt00++;
                    } else if (ys[j] > 0L) {
                        amtPosInfty++;
                    } else {
                        amtNegInfty++;
                    }
                } else {
                    Rational q = new Rational(ys[j], xs[j]);
                    if (xs[j] > 0L) {
                        if (positive.compute(q, (__, prev) -> prev == null ? 1 : (prev + 1)) == 1 && negative.containsKey(q)) {
                            amtMatch++;
                        }
                    } else {
                        if (negative.compute(q, (__, prev) -> prev == null ? 1 : (prev + 1)) == 1 && positive.containsKey(q)) {
                            amtMatch++;
                        }
                    }
                }
            } else {
                int j2 = j;
                j = Integer.parseInt(tokenizer.nextToken());
                if (xs[j] == 0L) {
                    if (ys[j] == 0L) {
                        amt00--;
                    } else if (ys[j] > 0L) {
                        amtPosInfty--;
                    } else {
                        amtNegInfty--;
                    }
                } else {
                    Rational q = new Rational(ys[j], xs[j]);
                    if (xs[j] > 0L) {
                        if (positive.compute(q, (__, prev) -> prev == 1 ? null : (prev - 1)) == null && negative.containsKey(q)) {
                            amtMatch--;
                        }
                    } else {
                        if (negative.compute(q, (__, prev) -> prev == 1 ? null : (prev - 1)) == null && positive.containsKey(q)) {
                            amtMatch--;
                        }
                    }
                }
                j = j2;
            }
            if (amt00 > 0) {
                out.append(1);
            } else if (amtMatch > 0 || (amtPosInfty > 0 && amtNegInfty > 0)) {
                out.append(2);
            } else {
                boolean exists = false;
                if (positive.size() >= 2) {
                    Rational q = negative.ceilingKey(positive.firstKey());
                    if (q != null && q.compareTo(positive.lastKey()) <= 0) {
                        exists = true;
                    }
                }
                if (!exists && negative.size() >= 2) {
                    Rational q = positive.ceilingKey(negative.firstKey());
                    if (q != null && q.compareTo(negative.lastKey()) <= 0) {
                        exists = true;
                    }
                }
                if (!exists && amtPosInfty > 0 && !positive.isEmpty() && !negative.isEmpty()) {
                    Rational q = positive.firstKey();
                    Rational r = negative.lastKey();
                    if (q.compareTo(r) < 0) {
                        exists = true;
                    }
                }
                if (!exists && amtNegInfty > 0 && !positive.isEmpty() && !negative.isEmpty()) {
                    Rational q = positive.lastKey();
                    Rational r = negative.firstKey();
                    if (q.compareTo(r) > 0) {
                        exists = true;
                    }
                }
                if (exists) {
                    out.append(3);
                } else {
                    out.append(0);
                }
            }
            out.append('\n');
        }
        System.out.print(out);
    }

    static class Rational implements Comparable<Rational> {
        final long num;
        final long denom;

        Rational(long num, long denom) {
            if (denom > 0L) {
                this.num = num;
                this.denom = denom;
            } else {
                this.num = -num;
                this.denom = -denom;
            }
        }

        @Override
        public int compareTo(Rational other) {
            long d = (num * other.denom) - (other.num * denom);
            if (d > 0L) {
                return 1;
            } else if (d == 0L) {
                return 0;
            } else {
                return -1;
            }
        }
    }
}