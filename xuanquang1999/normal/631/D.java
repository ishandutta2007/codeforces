import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static void readString(Scanner in, int n, ArrayList<Block> s) {
        for (int i = 0; i < n; ++i) {
            String buff[] = in.next().split("-");
            Block bl = new Block(Integer.parseInt(buff[0]), buff[1].charAt(0));

            if (s.isEmpty() || s.get(s.size() - 1).c != bl.c)
                s.add(bl);
            else
                s.get(s.size() - 1).l += bl.l;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), m = in.nextInt();
        ArrayList<Block> t = new ArrayList<>(), p = new ArrayList<>();
        readString(in, n, t);
        readString(in, m, p);
        n = t.size();
        m = p.size();

        long ans = 0;
        if (m == 1) {
            for (Block bl : t)
                if (bl.c == p.get(0).c)
                    ans += Math.max(0, bl.l - p.get(0).l + 1);
        } else {
            ArrayList<Integer> cand = new ArrayList<>();
            if (m == 2) {
                for(int i = 1; i < n; ++i)
                    cand.add(i);
            } else {
                int pref[] = new int[m - 2];
                pref[0] = 0;
                int j = 0;
                for (int i = 2; i < m - 1; ++i) {
                    while (j > 0 && !p.get(i).equals(p.get(j + 1)))
                        j = pref[j - 1];
                    if (p.get(i).equals(p.get(j + 1)))
                        ++j;
                    pref[i - 1] = j;
                }

                int i = 0;
                j = 0;
                while (i < n) {
                    if (t.get(i).equals(p.get(j + 1))) {
                        ++i;
                        ++j;
                        if (j == m - 2) {
                            cand.add(i - j);
                            j = pref[j - 1];
                        }
                    } else {
                        if (j == 0)
                            ++i;
                        else
                            j = pref[j - 1];
                    }
                }
            }


            for(int x: cand) {
                if (x == 0 || x+m-2 >= n) continue;
                if (t.get(x - 1).c == p.get(0).c && t.get(x - 1).l >= p.get(0).l && t.get(x + m - 2).c == p.get(m - 1).c && t.get(x + m - 2).l >= p.get(m - 1).l)
                    ++ans;
            }
        }

        System.out.println(ans);
    }

    static class Block {
        long l;
        char c;

        public Block(long l, char c) {
            this.l = l;
            this.c = c;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Block block = (Block) o;
            return l == block.l &&
                    c == block.c;
        }
    }
}