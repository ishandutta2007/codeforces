import java.io.*;
import java.util.*;

public class B {

    class Bug implements Comparable<Bug> {
        int id, val;

        public Bug(int id, int val) {
            super();
            this.id = id;
            this.val = val;
        }
        
        @Override
        public int compareTo(Bug o) {
            return val - o.val;
        }

        @Override
        public String toString() {
            return "Bug [id=" + id + ", val=" + val + "]";
        }
        
    }
    
    class Student implements Comparable<Student> {
        int id, val, cost;

        public Student(int id, int val, int cost) {
            super();
            this.id = id;
            this.val = val;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Student o) {
            return val - o.val;
        }

        @Override
        public String toString() {
            return "Student [id=" + id + ", val=" + val + ", cost=" + cost + "]";
        }
        
    }
    
    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), s = in.nextInt();
        int[] a = new int[m], b = new int[n], c = new int[n];

        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        Bug[] bugs = new Bug[m];
        Student[] studs = new Student[n];
        for (int i =0 ; i < m; i++) {
            bugs[i] = new Bug(i, a[i]);
        }
        for (int i = 0; i < n; i++) {
            studs[i] = new Student(i, b[i], c[i]);
        }
        Arrays.sort(bugs);
        Arrays.sort(studs);
        
        PriorityQueue<Student> pq = new PriorityQueue<>(n, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.cost - o2.cost;
            }
        });
        
        int left = 0, right = m + 1;
        while (left < right - 1) {
            int mid = (left + right) >> 1;
            pq.clear();
            
            int j = n - 1;
            long sum = 0;
            long cost = 0;
            boolean ok = true;
            for (int i = m - 1; i >= 0; i--) {
                while (j >= 0 && studs[j].val >= bugs[i].val) {
                    pq.add(studs[j]);
                    j--;
                }
                if (sum == 0) {
                    sum += mid;
                    Student stud = pq.poll();
                    
                    if (stud == null) {
                        ok = false;
                        break;
                    }
                    cost += stud.cost;
                }
                sum--;
            }
            
            
            if (cost <= s && ok) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        if (right == m + 1) {
            out.println("NO");
            return;
        }
        
        int res = right;
        int j = n - 1;
        int[] ans = new int[m];
        Student curStud = null;
        int lastSolved = 0;
        
        pq.clear();
        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && studs[j].val >= bugs[i].val) {
                pq.add(studs[j]);
                j--;
            }
            if (lastSolved == 0) {
                lastSolved = res;
                curStud = pq.poll();
            }
            ans[bugs[i].id] = curStud.id;
            lastSolved--;
        }
        
        
        out.println("YES");
        for (int i = 0; i < m; i++) {
            out.print((ans[i] + 1) + " ");
        }
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}