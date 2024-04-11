import java.util.Scanner;

public class YouAreGivenAWASDString {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = Integer.parseInt(in.nextLine()); t > 0; t--) {
            String s = in.nextLine();
            long x = 0;
            long y = 0;
            long minX = 0;
            boolean xDown = false;
            long minY = 0;
            boolean yDown = false;
            long maxX = 0;
            boolean xUp = false;
            long maxY = 0;
            boolean yUp = false;
            for (int i = 0; i < s.length(); i++) {
                switch (s.charAt(i)) {
                    case 'W': {
                        y++;
                        if (y >= maxY) {
                            yUp = true;
                        }
                        if (y > maxY) {
                            maxY = y;
                            yDown = false;
                        }
                    } break;
                    case 'A': {
                        x--;
                        if (x <= minX) {
                            xDown = true;
                        }
                        if (x < minX) {
                            minX = x;
                            xUp = false;
                        }
                    } break;
                    case 'S': {
                        y--;
                        if (y <= minY) {
                            yDown = true;
                        }
                        if (y < minY) {
                            minY = y;
                            yUp = false;
                        }
                    } break;
                    case 'D': {
                        x++;
                        if (x >= maxX) {
                            xUp = true;
                        }
                        if (x > maxX) {
                            maxX = x;
                            xDown = false;
                        }
                    }
                }
            }
            long dx = maxX - minX;
            long dy = maxY - minY;
            boolean canReduceX = dx > 1 && !(xDown && xUp);
            boolean canReduceY = dy > 1 && !(yDown && yUp);
            if (canReduceX && (!canReduceY || dx <= dy)) {
                System.out.println(dx * (dy + 1));
            } else if (canReduceY) {
                System.out.println((dx + 1) * dy);
            } else {
                System.out.println((dx + 1) * (dy + 1));
            }
        }
    }
}