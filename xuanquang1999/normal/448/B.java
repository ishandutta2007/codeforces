import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next(), t = sc.next();

        int cntS[] = new int[26];
        int cntT[] = new int[26];
        for(int i = 0; i < s.length(); ++i)
            ++cntS[s.charAt(i)-'a'];
        for(int i = 0; i < t.length(); ++i)
            ++cntT[t.charAt(i)-'a'];

        for(int i = 0; i < 26; ++i) {
            if (cntS[i] < cntT[i]) {
                System.out.println("need tree");
                return;
            }
        }

        boolean needArray = false;
        int j = 0;
        for(int i = 0; i < t.length(); ++i) {
            while (j < s.length() && s.charAt(j) != t.charAt(i)) ++j;
            if (j == s.length()) {needArray = true; break;}
            ++j;
        }

        boolean needAutomaton = (s.length() > t.length());
        if (needArray && needAutomaton)
            System.out.println("both");
        else if (needArray)
            System.out.println("array");
        else if (needAutomaton)
            System.out.println("automaton");


    }
}