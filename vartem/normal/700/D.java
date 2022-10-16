import java.io.*;
import java.util.*;

public class D {

    int MAX = 100000;
    int MAGIC = 321;

    int[] count = new int[MAX];
    int[] amount = new int[MAX + 1];
    int[] w1 = new int[MAX], w2 = new int[500000];
    int[] cnt1 = new int[MAX], cnt2 = new int[500000];

    int[] large = new int[400];
    int[] largePos = new int[MAX];
    int largeSize = 0;

    public void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }
        int q = in.nextInt();
        Query[] qs = new Query[q];
        for (int i = 0; i < q; i++) {
            qs[i] = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
        }
        Arrays.sort(qs);


        int L = 0, R = -1;
        int[] ans = new int[q];
        amount[0] = MAX;
        for (int i = 0; i < q; i++) {
            Query query = qs[i];
            while (L > query.l) {
                L--;
                amount[count[a[L]]]--;
                count[a[L]]++;
                amount[count[a[L]]]++;
                if (count[a[L]] == MAGIC) {
                    large[largeSize] = a[L];
                    largePos[a[L]] = largeSize;
                    largeSize++;
                }
            }
            while (R < query.r) {
                R++;
                amount[count[a[R]]]--;
                count[a[R]]++;
                amount[count[a[R]]]++;
                if (count[a[R]] == MAGIC) {
                    large[largeSize] = a[R];
                    largePos[a[R]] = largeSize;
                    largeSize++;
                }
            }
            while (L < query.l) {
                amount[count[a[L]]]--;
                count[a[L]]--;
                amount[count[a[L]]]++;
                if (count[a[L]] == MAGIC - 1) {
                    int ps = largePos[a[L]];
                    int val = large[largeSize - 1];
                    largePos[val] = ps;
                    large[ps] = val;
                    largeSize--;
                }
                L++;
            }
            while (R > query.r) {
                amount[count[a[R]]]--;
                count[a[R]]--;
                amount[count[a[R]]]++;
                if (count[a[R]] == MAGIC - 1) {
                    int ps = largePos[a[R]];
                    int val = large[largeSize - 1];
                    largePos[val] = ps;
                    large[ps] = val;
                    largeSize--;
                }
                R--;
            }

            ans[query.id] = answer();
        }
        for (int i = 0; i < q; i++) {
            out.println(ans[i]);
        }
    }

    int answer() {
        int head1 = 0, tail1 = 0, head2 = 0, tail2 = 0;
        for (int i = 1; i < MAGIC; i++) {
            if (amount[i] > 0) {
                w1[tail1] = i;
                cnt1[tail1] = amount[i];
                tail1++;
            }
        }
        int tmp = 0;
        for (int i = 0; i < largeSize; i++) {
            w1[tail1] = count[large[i]];
            cnt1[tail1] = 1;
            tail1++;
        }
        Arrays.sort(w1, tmp, tail1);

        int ans = 0;
        while (true) {
            if (head1 < tail1 && (head2 == tail2 || w1[head1] < w2[head2])) {
                if (cnt1[head1] > 1) {
                    int newW = 2 * w1[head1];
                    int newCnt = cnt1[head1] / 2;

                    ans += newW * newCnt;
                    w2[tail2] = newW;
                    cnt2[tail2] = newCnt;
                    tail2++;

                    if ((newCnt << 1) == cnt1[head1]) {
                        head1++;
                    } else {
                        cnt1[head1] = 1;
                    }
                } else {
                    int newW = w1[head1];
                    head1++;
                    if (head1 == tail1 && head2 == tail2) {
                        break;
                    }

                    if (head1 < tail1 && (head2 == tail2 || w1[head1] < w2[head2])) {
                        newW += w1[head1];
                        cnt1[head1]--;
                        if (cnt1[head1] == 0) {
                            head1++;
                        }

                        ans += newW;
                        w2[tail2] = newW;
                        cnt2[tail2] = 1;
                        tail2++;
                    } else {
                        newW += w2[head2];
                        cnt2[head2]--;
                        if (cnt2[head2] == 0) {
                            head2++;
                        }

                        ans += newW;
                        w2[tail2] = newW;
                        cnt2[tail2] = 1;
                        tail2++;
                    }
                }
            } else {
                if (cnt2[head2] > 1) {
                    int newW = 2 * w2[head2];
                    int newCnt = cnt2[head2] / 2;

                    ans += newW * newCnt;
                    w2[tail2] = newW;
                    cnt2[tail2] = newCnt;
                    tail2++;

                    if ((newCnt << 1) == cnt2[head2]) {
                        head2++;
                    } else {
                        cnt2[head2] = 1;
                    }
                } else {
                    int newW = w2[head2];
                    head2++;
                    if (head1 == tail1 && head2 == tail2) {
                        break;
                    }

                    if (head1 < tail1 && (head2 == tail2 || w1[head1] < w2[head2])) {
                        newW += w1[head1];
                        cnt1[head1]--;
                        if (cnt1[head1] == 0) {
                            head1++;
                        }

                        ans += newW;
                        w2[tail2] = newW;
                        cnt2[tail2] = 1;
                        tail2++;
                    } else {
                        newW += w2[head2];
                        cnt2[head2]--;
                        if (cnt2[head2] == 0) {
                            head2++;
                        }

                        ans += newW;
                        w2[tail2] = newW;
                        cnt2[tail2] = 1;
                        tail2++;
                    }
                }
            }
        }
        return ans;
    }

    class Query implements Comparable<Query> {
        int l, r, id;

        public Query(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
        }

        @Override
        public int compareTo(Query o) {
            if (l / MAGIC != o.l / MAGIC) {
                return Integer.compare(l / MAGIC, o.l / MAGIC);
            }
            return Integer.compare(r, o.r);
        }
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}