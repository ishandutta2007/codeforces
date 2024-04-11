import java.util.Arrays;
import java.util.Scanner;

public class ExtraElement {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Term[] sequence = new Term[n];
        for (int i = 1; i <= n; i++) {
            sequence[i - 1] = new Term(i, scanner.nextLong());
        }
        if (n < 4) {
            System.out.println(1);
            return;
        }
        Arrays.sort(sequence);
        int res = -1;
        for (int i = 1; i <= 3; i++) {
            res = test(n, sequence, sequence[i].value - sequence[i - 1].value);
            if (res != -1) {
                System.out.println(res);
                return;
            }
        }
        System.out.println(-1);
    }

    static int test(int n, Term[] sequence, long d) {
        if (sequence[1].value - sequence[0].value != d && sequence[2].value - sequence[1].value == d) {
            for (int i = 2; i < n; i++) {
                if (sequence[i].value - sequence[i - 1].value != d) {
                    return -1;
                }
            }
            return sequence[0].index;
        } else {
            int res = -2;
            for (int i = 1; i < n; i++) {
                if (sequence[i].value - sequence[i - 1].value != d) {
                    if (res != -2) {
                        return -1;
                    }
                    res = sequence[i].index;
                    if (i < n - 1 && sequence[i + 1].value - sequence[i - 1].value != d) {
                        return -1;
                    }
                    i++;
                }
            }
            if (res == -2) {
                res = sequence[0].index;
            }
            return res;
        }
    }

    static class Term implements Comparable<Term> {
        final int index;
        final long value;

        Term(int index, long value) {
            this.index = index;
            this.value = value;
        }

        @Override
        public int compareTo(Term o) {
            return Long.compare(value, o.value);
        }
    }
}