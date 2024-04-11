import java.util.HashSet;
import java.util.Objects;
import java.util.Scanner;
import java.util.Set;

public class PlusFromPicture {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ");
        int h = Integer.parseInt(line[0]);
        int w = Integer.parseInt(line[1]);
        char[][] picture = new char[h][];
        for (int y = 0; y < h; y++) {
            picture[y] = scanner.nextLine().toCharArray();
        }
        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                if (picture[y][x] == '*' && picture[y + 1][x] == '*' && picture[y - 1][x] == '*' && picture[y][x + 1] == '*' && picture[y][x - 1] == '*') {
                    if (works(picture, h, w, y, x)) {
                        System.out.println("YES");
                    } else {
                        System.out.println("NO");
                    }
                    return;
                }
            }
        }
        System.out.println("NO");
    }

    static boolean works(char[][] picture, int h, int w, int y, int x) {
        Set<Point> plus = new HashSet<>();
        plus.add(new Point(y, x));
        for (int b = y; b >= 0 && picture[b][x] == '*'; b--) {
            plus.add(new Point(b, x));
        }
        for (int b = y; b < h && picture[b][x] == '*'; b++) {
            plus.add(new Point(b, x));
        }
        for (int a = x; a >= 0 && picture[y][a] == '*'; a--) {
            plus.add(new Point(y, a));
        }
        for (int a = x; a < w && picture[y][a] == '*'; a++) {
            plus.add(new Point(y, a));
        }
        for (int b = 0; b < h; b++) {
            for (int a = 0; a < w; a++) {
                if (!plus.contains(new Point(b, a)) && picture[b][a] == '*') {
                    return false;
                }
            }
        }
        return true;
    }

    static class Point {
        final int y;
        final int x;

        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return y == point.y &&
                    x == point.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }
    }
}