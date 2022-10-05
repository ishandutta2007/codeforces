import java.util.Scanner;

public class CompressWords2 {
    static final long MOD = 1000000007;
    static final long P = 67;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < n; i++) {
            add(builder, in.next());
        }
        System.out.println(builder);
    }

    static void add(StringBuilder s1, String s2) {
        int n = Math.min(s1.length(), s2.length());
        boolean[] hashEquals = new boolean[n + 1];
        hashEquals[0] = true;
        long hash1 = 0;
        long hash2 = 0;
        long coef = 1;
        for (int i = 1; i <= n; i++, coef = (coef * P) % MOD) {
            hash1 = (choi(s1.charAt(s1.length() - i)) + (P * hash1)) % MOD;
            hash2 = (hash2 + (coef * choi(s2.charAt(i - 1)))) % MOD;
            //System.out.println("s2 = " + s2 + ", i = " + i + ", hash1 = " + hash1 + ", hash2 = " + hash2);
            if (hash1 == hash2) {
                hashEquals[i] = true;
            }
        }
        for (int i = n; i >= 0; i--) {
            //System.out.println("s2 = " + s2 + ", hashEquals[" + i + "] = " + hashEquals[i]);
            if (hashEquals[i] && s1.substring(s1.length() - i).equals(s2.substring(0, i))) {
                s1.append(s2.substring(i));
                return;
            }
        }
        throw new IllegalStateException();
    }

    static long choi(char chara) {
        if (chara <= '9') {
            return chara - '0';
        } else if (chara <= 'Z') {
            return chara - 'A' + 10;
        } else {
            return chara - 'a' + 36;
        }
    }
}