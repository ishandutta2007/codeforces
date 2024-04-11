import java.io.*;
import java.util.*;

public class E {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        List<Integer>[] lists = new List[k];
        
        for (int i = 0; i < n; i++) {
            if (lists[i % k] == null) {
                lists[i % k] = new ArrayList<>();
            }
            String cur = in.nextToken();
            if (cur.equals("?")) {
                lists[i % k].add(Integer.MAX_VALUE);
            } else {
                lists[i % k].add(Integer.parseInt(cur));
            }
        }
        
        
        for (int i = 0; i < k; i++) {
            lists[i] = solve(lists[i]);
            if (lists[i] == null) {
                out.println("Incorrect sequence");
                return;
            }
        }
        
        for (int i = 0; i < n; i++) {
            out.print(lists[i % k].get(i / k) + " ");
        }
    }

    private List<Integer> solve(List<Integer> list) {
        list.add(0, (int) -2e9);
        list.add((int) 2e9);
        
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < list.size() - 1; ) {
            int j = i + 1;
            while (j < list.size() && list.get(j) == Integer.MAX_VALUE) {
                j++;
            }
            
            int cnt = j - i - 1;
            if (list.get(i) + cnt >= list.get(j)) {
                return null;
            }
            
            int from = list.get(i), to = list.get(j);
            result.add(from);
            if (from >= 0 && to >= 0) {
                for (int t = 0; t < cnt; t++) {
                    result.add(from + t + 1);
                }
            } else if (from <= 0 && to <= 0) {
                for (int t = 0; t < cnt; t++) {
                    result.add(to - cnt + t);
                }
            } else {
                List<Integer> cur = new ArrayList<>();
                
                for (int x = 0; cnt > 0; x++) {
                    if (cnt > 0 && from < x && x < to) {
                        cur.add(x);
                        cnt--;
                    }
                    if (x == 0) {
                        continue;
                    }
                    if (cnt > 0 && from < -x && -x < to) {
                        cur.add(-x);
                        cnt--;
                    }
                }
                Collections.sort(cur);
                result.addAll(cur);
            }
            i = j;
        }
        
        result.remove(0);
        for (int i = 0; i < result.size() - 1; i++) {
            if (result.get(i) >= result.get(i + 1)) {
                return null;
            }
        }
        return result;
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
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
        new E().run();
    }
}