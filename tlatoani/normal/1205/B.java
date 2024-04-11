import java.util.*;

public class ShortestCycle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] first = new long[60];
        long[] second = new long[60];
        boolean trivial = false;
        for (int i = 0; i < n; i++) {
            long k = in.nextLong();
            long b = 1;
            for (int l = 0; l < 60; l++, b <<= 1) {
                if ((k & b) != 0) {
                    if (first[l] == 0) {
                        first[l] = k;
                    } else if (second[l] == 0) {
                        second[l] = k;
                    } else {
                        trivial = true;
                    }
                }
            }
        }
        if (trivial) {
            System.out.println(3);
            return;
        }
        Map<Long, Set<Long>> adj = new HashMap<>();
        for (int l = 0; l < 60; l++) {
            if (second[l] != 0 && first[l] != second[l]) {
                adj.putIfAbsent(first[l], new HashSet<>());
                adj.putIfAbsent(second[l], new HashSet<>());
                adj.get(first[l]).add(second[l]);
                adj.get(second[l]).add(first[l]);
            }
        }
        int answer = -1;
        for (long root : adj.keySet()) {
            //System.out.println(root + " -> " + adj.get(root));
            Map<Long, Integer> dist = new HashMap<>();
            dist.put(root, 0);
            Map<Long, Long> prev = new HashMap<>();
            prev.put(root, -1L);
            Queue<Long> q = new LinkedList<>();
            q.add(root);
            while (!q.isEmpty()) {
                long node = q.remove();
                //System.out.println("node = " + node);
                for (long next : adj.get(node)) {
                    //System.out.println("\tnext = " + next);
                    if (next != prev.get(node)) {
                        if (dist.containsKey(next)) {
                            int posAnswer = dist.get(node) + dist.get(next) + 1;
                            answer = answer == -1 ? posAnswer : Math.min(answer, posAnswer);
                        } else {
                            dist.put(next, dist.get(node) + 1);
                            prev.put(next, node);
                            q.add(next);
                        }
                    }
                }
            }
        }
        System.out.println(answer);
    }
}