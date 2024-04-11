import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int[] num = new int[3];
        for (int i = 0; i < 3; i++) num[i] = sc.nextInt();
        int[] wait = new int[3];
        long[] time = new long[3];
        for (int i = 0; i < 3; i++) time[i] = sc.nextLong();
        int n = sc.nextInt();
        long[] come = new long[n];
        for (int i = 0; i < n; i++) come[i] = sc.nextLong();
        PriorityQueue<Event> que = new PriorityQueue<Event>();
        for (int i = 0; i < n; i++) que.offer(new Event(come[i], 0));
        long res = 0;
        int m = 0;
        while (!que.isEmpty()) {
            Event e = que.poll();
            if (e.type == 0) {
                if (num[0] > 0) {
                    num[0]--;
                    que.offer(new Event(e.time + time[0], 1));
                } else {
                    wait[0]++;
                }
            } else if (e.type == 1) {
                if (wait[0] > 0) {
                    wait[0]--;
                    que.offer(new Event(e.time + time[0], 1));
                } else {
                    num[0]++;
                }
                if (num[1] > 0) {
                    num[1]--;
                    que.offer(new Event(e.time + time[1], 2));
                } else {
                    wait[1]++;
                }
            } else if (e.type == 2) {
                if (wait[1] > 0) {
                    wait[1]--;
                    que.offer(new Event(e.time + time[1], 2));
                } else {
                    num[1]++;
                }
                if (num[2] > 0) {
                    num[2]--;
                    que.offer(new Event(e.time + time[2], 3));
                } else {
                    wait[2]++;
                }
            } else {
                res = max(res, e.time - come[m++]);
                if (wait[2] > 0) {
                    wait[2]--;
                    que.offer(new Event(e.time + time[2], 3));
                } else {
                    num[2]++;
                }
            }
        }
        System.out.println(res);
    }
    
    class Event implements Comparable<Event> {
        long time;
        int type;
        Event(long time, int type) {
            this.time = time;
            this.type = type;
        }
        public int compareTo(Event o) {
            return Long.signum(time - o.time);
        }
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new B().run();
    }
}