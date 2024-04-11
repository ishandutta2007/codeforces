import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static ArrayList<Integer> ps = primes(100000);

    public static ArrayList<Integer> primes(int max) {
        if (max < 2) {
            return new ArrayList<Integer>();
        }
        BitSet primeSet = new BitSet(max / 2);
        primeSet.set(1, max / 2);
        int limit = (int) Math.sqrt(max);
        for (int i = 3; i <= limit; i += 2) {
            if (!primeSet.get(i / 2)) {
                continue;
            }
            for (int j = i * i; j < max; j += i * 2) {
                primeSet.clear(j / 2);
            }
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(2);
        for (int i = primeSet.nextSetBit(0); i >= 0; i = primeSet.nextSetBit(i + 1)) {
            list.add(i * 2 + 1);
        }
        return list;
    }

    static ArrayList<Integer> factorize(int v) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        if (v == 1) {
            ret.add(1);
            return ret;
        }
        for (int i = 0; i < ps.size(); ++i) {
            int p = ps.get(i);
            if (p * p > v) break;
            if (v % p == 0) {
                ret.add(p);
                do {
                    v /= p;
                } while (v % p == 0);
            }
        }
        if (v > 1) ret.add(v);
        return ret;
    }

    public static void main(String[] args) throws Exception {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] room = new int[100001];
        OUT: for (int i = 0; i < M; ++i) {
            String str = sc.next();
            int v = Integer.parseInt(sc.next());
            ArrayList<Integer> f = factorize(v);
            if (str.equals("+")) {
                for (int p : f) {
                    if (room[p] != 0) {
                        if (room[p] == v) {
                            System.out.println("Already on");
                        } else {
                            System.out.println("Conflict with " + room[p]);
                        }
                        continue OUT;
                    }
                }
                for (int p : f) {
                    room[p] = v;
                }
                System.out.println("Success");
            } else {
                if (room[f.get(0)] == v) {
                    for (int p : f) {
                        room[p] = 0;
                    }
                    System.out.println("Success");
                } else {
                    System.out.println("Already off");
                }
            }
        }

    }
}