import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

public class TreasureGeolocation {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = in.nextInt();
        Location[] obelisks = new Location[n];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            obelisks[i] = new Location(x, y);
        }
        Location[] clues = new Location[n];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            clues[i] = new Location(x, y);
        }
        Map<Location, Integer> map = new HashMap<>();
        Location treasure = null;
        int maxAmount = 0;
        for (Location obelisk : obelisks) {
            for (Location clue : clues) {
                Location posTreasure = new Location(obelisk.x + clue.x, obelisk.y + clue.y);
                Integer prevAmount = map.get(posTreasure);
                int nextAmount = prevAmount == null ? 1 : prevAmount + 1;
                if (nextAmount > maxAmount) {
                    treasure = posTreasure;
                    maxAmount = nextAmount;
                }
                map.put(posTreasure, nextAmount);
            }
        }
        out.println(treasure.x + " " + treasure.y);
    }

    static class Location {
        final int x;
        final int y;

        Location(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Location location = (Location) o;
            return x == location.x &&
                    y == location.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}