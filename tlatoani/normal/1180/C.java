import java.util.LinkedList;
import java.util.Scanner;

public class ValeriyAndDeque {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        LinkedList<Integer> deque = new LinkedList<>();
        int max = 0;
        for (int i = 1; i <= n; i++) {
            deque.addLast(scanner.nextInt());
            max = Math.max(max, deque.getLast());
        }
        int i = 1;
        int[][] res = new int[n + 1][2];
        for (; deque.getFirst() != max; i++) {
            res[i][0] = deque.removeFirst();
            res[i][1] = deque.removeFirst();
            deque.addFirst(Math.max(res[i][0], res[i][1]));
            deque.addLast(Math.min(res[i][0], res[i][1]));
        }
        deque.removeFirst();
        Integer[] beyond = deque.toArray(new Integer[0]);
        long offset = i;
        long amt = (long) beyond.length;
        for (int j = 1; j <= q; j++) {
            long query = scanner.nextLong();
            if (query < offset) {
                System.out.println(res[(int) query][0] + " " + res[(int) query][1]);
            } else {
                query = (query - offset) % amt;
                System.out.println(max + " " + beyond[(int) query]);
            }
        }
    }
}