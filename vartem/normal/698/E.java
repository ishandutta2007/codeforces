import java.io.*;
import java.time.Instant;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.*;

public class E {

    int[] time = new int[6];

    final int DAY = 60 * 60 * 24;
    final ZoneId UTC = ZoneId.of("UTC");

    int curDayOfMonth, curMonth, curYear, curDayOfWeek;

    int[] month = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    boolean isLeapYear(int year) {
        if (year % 400 == 0) {
            return true;
        }
        if (year % 100 == 0) {
            return false;
        }
        return year % 4 == 0;
    }

    void addDay() {
        curDayOfWeek++;
        if (curDayOfWeek == 8) {
            curDayOfWeek = 1;
        }

        curDayOfMonth++;
        int maxMonth = month[curMonth - 1] + (curMonth == 2 && isLeapYear(curYear) ? 1 : 0);
        if (curDayOfMonth > maxMonth) {
            curDayOfMonth = 1;
            curMonth++;
        }
        if (curMonth == 13) {
            curMonth = 1;
            curYear++;
        }
    }

    public void solve() {
        for (int i = 0; i < 6; i++) {
            time[i] = in.nextInt();
        }

        Map<Long, Long> cache = new HashMap<>();

        int q = in.nextInt();
        outer: while (q-- > 0) {
            long init = in.nextLong();
            if (cache.containsKey(init)) {
                out.println(cache.get(init));
                continue;
            }
            long unixTime = init + 1;
            ZonedDateTime zdt = Instant.ofEpochSecond(unixTime).atZone(UTC);
            this.curDayOfMonth = zdt.getDayOfMonth();
            this.curDayOfWeek = zdt.getDayOfWeek().getValue();
            this.curMonth = zdt.getMonth().getValue();
            this.curYear = zdt.getYear();
            if (checkDay()) {
                for (long i = unixTime; i / DAY == unixTime / DAY; i++) {
                    if (checkTime(i)) {
                        out.println(i);
                        cache.put(init, i);
                        continue outer;
                    }
                }
            }

            addDay();
            unixTime = (unixTime + DAY - 1) / DAY * DAY;
            while (!checkDay()) {
                unixTime += DAY;
                addDay();
            }

//            System.err.println(Instant.ofEpochSecond(unixTime).atZone(ZoneId.of("UTC")));

            unixTime += (time[0] == -1 ? 0 : time[0]);
            unixTime += (time[1] == -1 ? 0 : time[1]) * 60;
            unixTime += (time[2] == -1 ? 0 : time[2]) * 60 * 60;
            out.println(unixTime);
            cache.put(init, unixTime);
        }
    }

    boolean checkDay() {
        if (time[3] != -1 && time[4] != -1) {
            return (time[3] == curDayOfWeek || time[4] == curDayOfMonth) && (time[5] == -1 || time[5] == curMonth);
        } else {
            return (time[3] == -1 || time[3] == curDayOfWeek) && (time[4] == -1 || time[4] == curDayOfMonth) && (time[5] == -1 || time[5] == curMonth);
        }
    }

    boolean checkTime(long i) {
        long sec = i % 60;
        i /= 60;
        long min = i % 60;
        i /= 60;
        i %= 24;
        return (time[0] == -1 || time[0] == sec) && (time[1] == -1 || time[1] == min) && (time[2] == -1 || time[2] == i);
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new E().run();
    }
}