import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created by jedi
 */

public class Main {

    private void run() {
        int n = in.nextInt();
        Integer[] a = new Integer[n];

        for (int i = 0; i < n; i++) {
             a[i] = in.nextInt();
        }

        Arrays.sort(a);
        int ans = 0;

        for (int i = 0, j =0; i < n; i++) {

            while (j < n && a[j] - a[i] <6){
                j++;
            }
            if ((j-i) > ans) ans = (j-i);
        }

        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        new Main().prepare();
    }

    private PrintWriter out;
    private Scanner in;

    private void prepare() throws IOException {
        if ("true".equals(System.getProperty("ONLINE_JUDGE"))) {
            in = new Scanner(System.in);
        } else {
            in = new Scanner(new File("src/"+this.getClass().getPackage().getName().replace('.', '/')+"/input.txt"));
        }
        out = new PrintWriter(System.out);
        in.useLocale(new Locale("US"));
        run();
        out.flush();
    }
}