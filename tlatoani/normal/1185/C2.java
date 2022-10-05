import java.util.*;

public class ExamInBerSU {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] times = new int[n];
        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            times[i] = scanner.nextInt();
            students[i] = new Student(i, times[i]);
        }
        Arrays.sort(students);
        int[] poses = new int[n];
        for (int i = 0; i < n; i++) {
            poses[students[i].ix] = i + 1;
        }
        System.out.print(0);
        SegmentTree segTree1 = new SegmentTree(n);
        SegmentTree segTreeTime = new SegmentTree(n);
        for (int i = 1; i < n; i++) {
            segTree1.update(poses[i - 1], 1);
            segTreeTime.update(poses[i - 1], times[i - 1]);
            int lower = 0;
            int upper = n;
            while (upper > lower) {
                int mid = (lower + upper + 1) / 2;
                if (segTreeTime.query(1, mid) <= m - times[i]) {
                    lower = mid;
                } else {
                    upper = mid - 1;
                }
            }
            System.out.print(" " + segTree1.query(upper + 1, n));
        }
    }

    static class Student implements Comparable<Student> {
        final int ix;
        final int time;

        Student(int ix, int time) {
            this.ix = ix;
            this.time = time;
        }

        @Override
        public int compareTo(Student o) {
            return time - o.time;
        }
    }

    static class SegmentTree {
        final int n;
        final int[] array;

        SegmentTree(int n) {
            this.n = n;
            array = new int[550000];
        }

        int query(int from, int to) {
            if (to < 1 || from > n) {
                return 0;
            }
            return query(from, to, 1, n, 1);
        }

        int query(int from, int to, int segFrom, int segTo, int node) {
            int result = 0;
            if (from == segFrom && to == segTo) {
                result += array[node];
            } else {
                int midLower = (segFrom + segTo) / 2;
                int midUpper = midLower + 1;
                if (from <= midLower) {
                    result += query(from, Math.min(midLower, to), segFrom, midLower, node << 1);
                }
                if (to >= midUpper) {
                    result += query(Math.max(midUpper, from), to, midUpper, segTo, (node << 1) + 1);
                }
            }
            return result;
        }

        void update(int i, int dist) {
            update(i, dist, 1, n, 1);
        }

        int update(int i, int dist, int segFrom, int segTo, int node) {
            int change;
            if (segFrom == segTo) {
                change = dist - array[node];
            } else {
                int midLower = (segFrom + segTo) / 2;
                if (i <= midLower) {
                    change = update(i, dist, segFrom, midLower, node << 1);
                } else {
                    change = update(i, dist, midLower + 1, segTo, (node << 1) + 1);
                }
            }
            array[node] += change;
            return change;
        }
    }
}