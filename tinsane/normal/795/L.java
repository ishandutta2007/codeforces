import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String abil = sc.nextLine();
        abil = sc.nextLine();
        ArrayList<Integer> pos = new ArrayList<>();
        for(int i = 1; i < abil.length(); ++i)
            if (abil.charAt(i) == '0')
                pos.add(i);
        int l = -1, r = n+1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            int last = 0;
            int left = k - 1;
            boolean ok = true;
            for(int i = 0; i < pos.size(); ++i)
                if (i == pos.size()-1 || last + m + 1 < pos.get(i+1))
                {
                    ok = ok && pos.get(i) - last <= m+1;
                    last = pos.get(i);
                    --left;
                }
            if (left < 0 || !ok)
                l = m;
            else
                r = m;
        }
        System.out.println(r);
    }
}