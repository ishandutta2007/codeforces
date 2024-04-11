import java.io.InputStreamReader;
import java.util.Scanner;

public class _1348C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int[] count = new int[26];

            String str = scanner.nextLine();
            str = scanner.nextLine();
            // System.out.println(str);
            for (int j = 0; j < n; j++) {
                count[str.charAt(j) - 'a']++;
            }

            int used = 0;
            int j = 0;
            while (count[j] == 0)
                j++;

            if (count[j] < k) {
                used += count[j];
                while (used < k) {
                    used += count[++j];
                }
                System.out.println((char) (j + 'a'));
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append((char) ('a' + j));
                count[j] -= k;

                int first = j;
                int kindsOfLetters = 0;
                boolean flag = true;
                for (int p = j; p < 26; p++) {
                    if (count[p] != 0)
                        kindsOfLetters++;
                    if (kindsOfLetters == 1 && flag) {
                        first = p;
                        flag = false;
                    }
                    if (kindsOfLetters >= 2)
                        break;
                }

                // System.out.printf("kinds: %d   ", kindsOfLetters);

                switch (kindsOfLetters) {
                    case 2: {
                        for (int p = j; p < 26; p++) {
                            while (count[p] > 0) {
                                sb.append((char) ('a' + p));
                                count[p]--;
                            }
                        }
                        break;
                    }
                    case 1: {
                        while (count[first] > 0) {
                            sb.append((char) ('a' + first));
                            count[first] -= k;
                        }
                        break;
                    }
                }

                System.out.println(sb.toString());
            }

        }
    }
}