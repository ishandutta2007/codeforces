import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    class Host {
        String hostName;
        TreeSet<String> paths;
        String concatenated;

        public Host(String hostName) {
            this.hostName = hostName;
            paths = new TreeSet<>();
        }

        void concat() {
            StringBuilder sb = new StringBuilder();
            for (String path : paths) {
                sb.append(path).append("$");
            }
            this.concatenated = sb.toString();
        }
    }

    void solve() {
        int n = in.nextInt();
        String[] strings = new String[n];
        Map<String, Host> hosts = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            strings[i] = in.next().substring(7);
            int slashPos = strings[i].indexOf('/');
            if (slashPos == -1) {
                slashPos = strings[i].length();
            }
            String hostName = strings[i].substring(0, slashPos);
            if (!hosts.containsKey(hostName)) {
                hosts.put(hostName, new Host(hostName));
            }

            hosts.get(hostName).paths.add(strings[i].substring(slashPos));
        }

        List<Host> allHosts = new ArrayList<>(hosts.values());
        for (Host host : allHosts) {
            host.concat();
        }
        Comparator<Host> comp = (o1, o2) -> o1.concatenated.compareTo(o2.concatenated);
        Collections.sort(allHosts, comp);

        List<String> output = new ArrayList<>();

        for (int i = 0; i < allHosts.size(); ) {
            int j = i;
            while (j < allHosts.size() && comp.compare(allHosts.get(i), allHosts.get(j)) == 0) {
                j++;
            }

            if (j - i > 1) {
                StringBuilder line = new StringBuilder();
                for (int t = i; t < j; t++) {
                    line.append("http://").append(allHosts.get(t).hostName);
                    if (t + 1 < j) {
                        line.append(' ');
                    }
                }
                output.add(line.toString());
            }
            i = j;
        }
        out.println(output.size());
        for (String line : output) {
            out.println(line);
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
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
    }

    public static void main(String[] args) {
        new C().runIO();
    }
}