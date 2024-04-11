import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        TreeSet<Element> s = new TreeSet<Element>((lhs, rhs) -> {
            if (lhs.val < rhs.val) return -1;
            if (lhs.val > rhs.val) return 1;
            if (lhs.index < rhs.index) return -1;
            if (lhs.index > rhs.index) return 1;
            return 0;
        });

        int l = 0, ans = 0;

        for(int r = 0; r < n; ++r) {
            s.add(new Element(a[r], r));
            while (s.last().val - s.first().val > 1) {
                s.remove(new Element(a[l], l));
                ++l;
            }
            ans = Math.max(ans, r-l+1);
        }

        System.out.println(ans);
    }

    public static class Element {
        int val, index;

        public Element(int val, int index) {
            this.val = val;
            this.index = index;
        }
    }
}