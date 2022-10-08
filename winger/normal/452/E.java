import java.io.*;

public class ThreeStringsVI {


    static class SuffixAutomata {

        static class Vertex {
            Vertex suffixLink = null;
            Vertex[] edges;
            int log = 0;

            int[] terminals = new int[3];
            boolean visited;

            public Vertex(Vertex o, int log) {
                edges = o.edges.clone();
                terminals = o.terminals.clone();
                this.log = log;
            }

            public Vertex(int log) {
                edges = new Vertex[26];
                this.log = log;
            }

            void dp(long[] ans) {
                if (visited) {
                    return;
                }
                visited = true;
                for (Vertex v : edges) {
                    if (v != null) {
                        v.dp(ans);
                        for (int i = 0; i < terminals.length; ++i) {
                            terminals[i] += v.terminals[i];
                        }
                    }
                }
                if (suffixLink != null) {
                    long cnt = 1L;
                    for (int i = 0; i < terminals.length; ++i) {
                        cnt *= terminals[i];
                    }
                    if (suffixLink.log + 1 < ans.length) {
                        ans[suffixLink.log + 1] += cnt;
                    }
                    if (log + 1 < ans.length) {
                        ans[log + 1] -= cnt;
                    }
                }
            }
        }

        Vertex root, last;

        public SuffixAutomata(String[] strs) {
            last = root = new Vertex(0);
            for (int it = 0; it < strs.length; ++it) {
                String str = strs[it];
                for (int i = 0; i < str.length(); i++) {
                    addChar(str.charAt(i));
                }
                addTerm(it);
            }
        }

        private void addChar(char c) {
            Vertex cur = last;
            last = new Vertex(cur.log + 1);
            while (cur != null && cur.edges[c - 'a'] == null) {
                cur.edges[c - 'a'] = last;
                cur = cur.suffixLink;
            }
            if (cur != null) {
                Vertex q = cur.edges[c - 'a'];
                if (q.log == cur.log + 1) {
                    last.suffixLink = q;
                } else {
                    Vertex r = new Vertex(q, cur.log + 1);
                    r.suffixLink = q.suffixLink;
                    q.suffixLink = r;
                    last.suffixLink = r;
                    while (cur != null) {
                        if (cur.edges[c - 'a'] == q) {
                            cur.edges[c - 'a'] = r;
                        } else {
                            break;
                        }
                        cur = cur.suffixLink;
                    }
                }
            } else {
                last.suffixLink = root;
            }
        }

        private void addTerm(int i) {
            while (last != null) {
                last.terminals[i]++;
                last = last.suffixLink;
            }
            last = root;
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        String[] strs = new String[] {in.next(), in.next(), in.next()};
        SuffixAutomata sa = new SuffixAutomata(strs);
        long[] ans = new long[Math.min(strs[0].length(), Math.min(strs[1].length(), strs[2].length())) + 1];
        sa.root.dp(ans);
        long sum = 0;
        for (int i = 1; i < ans.length; ++i) {
            sum += ans[i];
            out.print(sum % 1000000007 + " ");
        }
        out.println();
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
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