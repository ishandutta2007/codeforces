import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C2SbalansirovannieUdaleniyaPoslozhnee solver = new C2SbalansirovannieUdaleniyaPoslozhnee();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2SbalansirovannieUdaleniyaPoslozhnee {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            List<Point> a = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                a.add(new Point(in.nextInt(), in.nextInt(), in.nextInt(), i + 1));
            }

            {
                Map<Long, List<Point>> map = new HashMap<>();
                List<Point> newA = new ArrayList<>();
                for (Point p : a) {
                    long hash = p.x * (long) 1e9 + p.y;
                    if (!map.containsKey(hash)) {
                        map.put(hash, new ArrayList<>());
                    }
                    map.get(hash).add(p);
                }
                for (Map.Entry<Long, List<Point>> entry : map.entrySet()) {
                    List<Point> list = entry.getValue();
                    Collections.sort(list, Comparator.comparing(point -> point.z));
                    for (int i = 1; i < list.size(); i += 2) {
                        out.println(list.get(i - 1).id + " " + list.get(i).id);
                    }
                    if (list.size() % 2 != 0) {
                        newA.add(list.get(list.size() - 1));
                    }
                }
                a = newA;
            }

            {
                Map<Long, List<Point>> map = new HashMap<>();
                List<Point> newA = new ArrayList<>();
                for (Point p : a) {
                    long hash = p.x;
                    if (!map.containsKey(hash)) {
                        map.put(hash, new ArrayList<>());
                    }
                    map.get(hash).add(p);
                }
                for (Map.Entry<Long, List<Point>> entry : map.entrySet()) {
                    List<Point> list = entry.getValue();
                    Collections.sort(list, Comparator.comparing(point -> point.y));
                    for (int i = 1; i < list.size(); i += 2) {
                        out.println(list.get(i - 1).id + " " + list.get(i).id);
                    }
                    if (list.size() % 2 != 0) {
                        newA.add(list.get(list.size() - 1));
                    }
                }
                a = newA;
            }
            Collections.sort(a, Comparator.comparing(point -> point.x));
            for (int i = 1; i < a.size(); i += 2) {
                out.println(a.get(i - 1).id + " " + a.get(i).id);
            }
        }

        class Point {
            int x;
            int y;
            int z;
            int id;

            public Point(int x, int y, int z, int id) {
                this.x = x;
                this.y = y;
                this.z = z;
                this.id = id;
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}