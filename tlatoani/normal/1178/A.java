import java.util.Scanner;
import java.util.StringJoiner;

public class PrimeMinister {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        StringJoiner answer = new StringJoiner(" ");
        int aliceParty = in.nextInt();
        int coalition = aliceParty;
        int k = 1;
        int total = aliceParty;
        answer.add("1");
        for (int i = 2; i <= n; i++) {
            int party = in.nextInt();
            total += party;
            if ((party << 1) <= aliceParty) {
                answer.add(i + "");
                k++;
                coalition += party;
            }
        }
        if ((coalition << 1) > total) {
            System.out.println(k);
            System.out.println(answer);
        } else {
            System.out.println(0);
        }
    }
}