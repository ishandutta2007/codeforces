import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int HR, HL, N;
    static ArrayList<Mirror> ceil = new ArrayList<Mirror>();
    static ArrayList<Mirror> floor = new ArrayList<Mirror>();
    static final double EPS = 1e-6;

    public static void main(String[] args) {
        HL = sc.nextInt();
        HR = sc.nextInt();
        N = sc.nextInt();
        for (int i = 0; i < N; ++i) {
            int v = sc.nextInt();
            boolean c = sc.next().equals("T");
            int a = sc.nextInt();
            int b = sc.nextInt();
            (c ? ceil : floor).add(new Mirror(a, b, v));
        }
        int ans = 0;
        for (int i = 1; i < 200; ++i) {
            ans = Math.max(ans, solve(i));
        }
        ArrayList<Mirror> tmp = ceil;
        ceil = floor;
        floor = tmp;
        HL = 100 - HL;
        HR = 100 - HR;
        for (int i = 1; i < 200; ++i) {
            ans = Math.max(ans, solve(i));
        }
        System.out.println(ans);
    }

    static int solve(int rise) {
        int ans = 0;
        boolean[] usedC = new boolean[ceil.size()];
        boolean[] usedF = new boolean[floor.size()];
        double height = (100.0 * (rise - 1) + (100 - HL) + (rise % 2 == 0 ? HR : 100 - HR));
        for (int i = 1; i <= rise; ++i) {
            ArrayList<Mirror> mirrors = i % 2 == 0 ? floor : ceil;
            boolean[] used = i % 2 == 0 ? usedF : usedC;
            double x = 100000.0 * (100.0 * i - HL) / height;
            //          System.out.println(rise + " " + i + " " + x);
            boolean found = false;
            for (int j = 0; j < used.length; ++j) {
                Mirror m = mirrors.get(j);
                if (m.l <= x + EPS && x - EPS <= m.r) {
                    if (used[j]) return -1;
                    used[j] = true;
                    ans += m.v;
                    found = true;
                    break;
                }
            }
            if (!found) return -1;
        }
        //      System.out.println(rise + " " + ans);
        return ans;
    }

    static class Mirror {
        int l, r, v;

        Mirror(int l, int r, int v) {
            this.l = l;
            this.r = r;
            this.v = v;
        }
    }

}