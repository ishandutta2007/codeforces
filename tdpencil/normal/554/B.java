    import java.io.PrintWriter;
    import java.util.Scanner;
     
     
    public class LightMatrix {
      public static void main (String[] args) {
        Scanner in = new Scanner (System.in);
        PrintWriter out = new PrintWriter (System.out, true);
        
        int N = in.nextInt();
        String[] board = new String[N];
        for (int i = 0; i < N; i++) board[i] = in.next();
        int res = 0;
        for (int i = 0; i < N; i++) {
          int count = 0;
          for (int j = 0; j < N; j++) if (board[j].equals(board[i])) count++;
          res = Math.max(res, count);
        }
        out.println(res);
        out.close();
        System.exit(0);
      }
    }