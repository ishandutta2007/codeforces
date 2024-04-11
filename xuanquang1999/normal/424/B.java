import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), s = sc.nextInt();

        City[] c = new City[n];
        for(int i = 0; i < n; ++i) {
            int x = sc.nextInt(), y = sc.nextInt(), pop = sc.nextInt();
            c[i] = new City((long)x*x +(long)y*y, pop);
        }

        Arrays.sort(c, (o1, o2) -> {
            if (o1.dist < o2.dist) return -1;
            if (o1.dist > o2.dist) return 1;
            return 0;
        });

        for(int i = 0; i < n; ++i) {
            s += c[i].pop;
            if (s >= 1000000) {
                System.out.printf("%.9g\n", Math.sqrt(c[i].dist));
                return;
            }
        }

        System.out.println(-1);


    }
}

class City {
    long dist;
    int pop;

    public City(long dist, int pop) {
        this.dist = dist;
        this.pop = pop;
    }
}