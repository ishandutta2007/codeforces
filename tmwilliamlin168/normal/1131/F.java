import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

public class F {
        public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] s = reader.readLine().split("\\s+");
        int n = Integer.parseInt(s[0]);
      
        Deque<Integer>[] ans = new LinkedList[n + 1];
        for (int i = 0; i < n + 1; i++) {
            ans[i] = new LinkedList<Integer>();
        }
        int[] col = new int[n + 1];
        int curcol = 1;
        for (int i = 0; i < n - 1; i++) {
            s = reader.readLine().split("\\s+");
            int x = Integer.parseInt(s[0]);
            int y = Integer.parseInt(s[1]);
            if (col[x] == 0 && col[y] == 0) {
                ans[curcol].addFirst(x);
                ans[curcol].addFirst(y);
                col[x] = curcol;
                col[y] = curcol;
                curcol++;
            } else if (col[x] == 0) {
                col[x] = col[y];
                ans[col[y]].addFirst(x);
            } else if (col[y] == 0) {
                col[y] = col[x];
                ans[col[x]].addFirst(y);
            } else  {
                int mi = Math.min(col[x], col[y]);
                int ma = Math.max(col[x], col[y]);
                for (int q : ans[ma]){
                    ans[mi].addFirst(q);
                    col[q] = mi;
                }
            }
        }
        for (int i : ans[1]) {
            System.out.print(i + " ");
        }
    }
}