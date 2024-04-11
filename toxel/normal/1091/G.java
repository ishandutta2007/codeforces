import java.lang.*;
import java.math.BigInteger;
import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        BigInteger n = scan.nextBigInteger();
        final int TIME = 30;
        HashSet <BigInteger> set = new HashSet<>();
        for (int i = 0; i < TIME; ++ i) {
            Random random = new Random();
            char[] s = new char[500];
            for (int j = 0; j < 500; ++ j) {
                s[j] = (char) ('0' + Math.abs(random.nextInt()) % 10);
            }
            BigInteger x = new BigInteger(new String(s));
            BigInteger y = x.multiply(x).mod(n);
            System.out.print("sqrt ");
            System.out.print(y);
            System.out.println();
            System.out.flush();
            BigInteger z = (scan.nextBigInteger().subtract(x).mod(n).add(n)).mod(n);
            if (z.compareTo(BigInteger.ZERO) == 0) {
                continue;
            }
            z = z.gcd(n);
            Vector <BigInteger> vec = new Vector<>();
            vec.add(z);
            while (!vec.isEmpty()){
                Vector <BigInteger> tmp = new Vector<>();
                for (BigInteger u : vec) {
                    for (BigInteger v : set) {
                        BigInteger w = u.gcd(v);
                        if (!set.contains(w)) {
                            tmp.add(w);
                        }
                    }
                }
                for (BigInteger u : vec) {
                    set.add(u);
                }
                vec = tmp;
            }
        }
        Vector <BigInteger> ans = new Vector<>();
        for (BigInteger u : set) {
            if (u.isProbablePrime(20)) {
                ans.add(u);
            }
        }
        System.out.printf("! %d", ans.size());
        for (BigInteger u : ans) {
            System.out.print(' ');
            System.out.print(u);
        }
        System.out.println();
    }
}