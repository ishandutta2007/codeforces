import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner sc, PrintWriter out) {
            int n = sc.nextInt(), m = sc.nextInt();
            HashMap<String, String> mp = new HashMap<>();
            while (n-- > 0) {
                String name = sc.next();
                mp.put(sc.next() + ";", name);
            }
            while (m-- > 0) {
                String com = sc.next(), ip = sc.next();
                out.println(com + " " + ip + " #" + mp.get(ip));
            }
        }
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                }
                ;
            }
            return st.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}