import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringJoiner;

public class LetThemSlide {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int w = in.nextInt();
        long[] diffs = new long[w + 1];
        for (; n > 0; n--) {
            int l = in.nextInt();
            LinkedList<Long> elems = new LinkedList<>();
            LinkedList<Integer> ixs = new LinkedList<>();
            long prev = 0;
            for (int i = 1; i <= l; i++) {
                long a = in.nextLong();
                while (!elems.isEmpty() && elems.getLast() <= a) {
                    elems.removeLast();
                    ixs.removeLast();
                }
                elems.addLast(a);
                ixs.addLast(i);
                if (i - ixs.getFirst() + l > w) {
                    elems.removeFirst();
                    ixs.removeFirst();
                }
                long next = elems.getFirst();
                if (next < 0 && i + l <= w) {
                    next = 0;
                }
                diffs[i] += next - prev;
                //System.out.println("n = " + n + ", i = " + i + ", adding " + (next - prev));
                prev = next;
            }
            for (int i = w - Math.min(l - 1, w - l) + 1; i <= w; i++) {
                if (i - ixs.getFirst() + l > w) {
                    elems.removeFirst();
                    ixs.removeFirst();
                }
                long next = elems.getFirst();
                if (next < 0 && i > l) {
                    next = 0;
                }
                diffs[i] += next - prev;
                //System.out.println("n = " + n + ", i = " + i + ", adding " + (next - prev));
                prev = next;
            }
        }
        long curr = 0;
        StringJoiner joiner = new StringJoiner(" ");
        for (int i = 1; i <= w; i++) {
            curr += diffs[i];
            joiner.add(curr + "");
        }
        System.out.println(joiner);
    }
}