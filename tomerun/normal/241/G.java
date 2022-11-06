import java.util.ArrayList;
import java.util.Scanner;


public class Main {

    static Scanner sc = new Scanner(System.in);
    static int N;
    static ArrayList<Integer> s = new ArrayList<Integer>();
    static ArrayList<Double> r = new ArrayList<Double>();
    static ArrayList<Integer> x = new ArrayList<Integer>();
    static ArrayList<Integer> p = new ArrayList<Integer>();

    static double sq(double v) {
        return v * v;
    }

    static void relax(int i, int j) {
        r.set(i, Math.min(r.get(i), sq(x.get(i) - x.get(j)) / 4 / r.get(s.get(j))));
    }

    static double solve(int n) {
        s.clear();
        r.clear();
        double ans = 0;
        for (int i = 0; i < x.size(); ++i) {
            r.add(1.0 * p.get(i));
            for (int j = 0; j < Math.min(s.size(), n); ++j) {
                relax(i, s.size() - 1 - j);
            }
            while (!s.isEmpty() && r.get(s.get(s.size() - 1)) <= r.get(i)) {
                s.remove(s.size() - 1);
            }
            s.add(i);
            ans += r.get(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        x.add(0);
        p.add(1000000);
        for (int i = 1; i < 499; ++i) {
            double nx = 0;
            int np = 500 - i;
            p.add(np);
            for (int j = 0; j < i; ++j) {
                nx = Math.max(nx, x.get(j) + 2 * Math.sqrt(p.get(i) * np));
            }
            x.add((int) Math.ceil(nx));
        }
        p.add(1000000);
        double nx = 0;
        for (int i = 1; i < x.size(); ++i) {
            nx = Math.max(nx, x.get(i) + 2 * Math.sqrt(p.get(i) * 1000000));
        }
        x.add((int) Math.ceil(nx));

        System.out.println(x.size());
        for (int i = 0; i < x.size(); ++i) {
            System.out.println(x.get(i) + " " + p.get(i));
        }

//      System.out.println(solve(500));
//      System.out.println(solve(300));
    }

}