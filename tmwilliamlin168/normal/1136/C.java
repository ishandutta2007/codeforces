import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

  void solve() throws IOException {
    int n=nextInt();
    int m=nextInt();
    int[][] a=new int[n][m];
    int[][] b=new int[n][m];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)a[i][j]=nextInt();
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)b[i][j]=nextInt();
    int max = Math.max(n,m);
    boolean good=true;
    for (int i=0;i<n+m-1&&good;i++) {
      HashMap<Integer, Integer> c=new HashMap<>();
      int x=Math.min(n-1, i);
      int y= i>=n ? i-n+1 : 0;
      int l= Math.min(x + 1, m - y);
      for (int j=0;j<l;j++) {
        int q=a[x-j][y+j];
        c.compute(q, (key, value) -> {
          if (value == null) {
            return 1;
          } else {
            return value +1;
          }
        });
      }
      for (int j=0;j<l;j++) {
        int q=b[x-j][y+j];
        int newCount = c.getOrDefault(q, 0) - 1;
        if (newCount<0){
          good=false;
          break;
        }
        c.put(q,newCount);
      }
    }
    if (good) {
      out.println("YES");
    } else {
      out.println("NO");
    }
  }

  public static void main(String[] args) throws IOException {
    new C().run();
  }

  void run() throws IOException {
    reader = new BufferedReader(new InputStreamReader(System.in));
//		reader = new BufferedReader(new FileReader("input.txt"));
    tokenizer = null;
    out = new PrintWriter(new OutputStreamWriter(System.out));
//		out = new PrintWriter(new FileWriter("output.txt"));
    solve();
    reader.close();
    out.flush();

  }

  BufferedReader reader;
  StringTokenizer tokenizer;
  PrintWriter out;

  int nextInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  long nextLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  double nextDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  String nextToken() throws IOException {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      tokenizer = new StringTokenizer(reader.readLine());
    }
    return tokenizer.nextToken();
  }
}