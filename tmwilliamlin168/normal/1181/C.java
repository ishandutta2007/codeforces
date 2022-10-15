import java.io.*;
import java.util.*;

public class Main {
  private static void execute(ContestReader reader, PrintWriter out) {
    int n = reader.nextInt();
    int m = reader.nextInt();
    char[][] map = new char[n][];
    for (int i = 0; i < n; i++) {
      map[i] = reader.next().toCharArray();
    }
    out.println(new Solver().solve(n, m, map));
    
  }
  
  public static void main(String[] args) {
    ContestReader reader = new ContestReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    execute(reader, out);
    out.flush();
  }
}

class Solver {
  int n;
  int m;
  char[][] map;
  int[][] rightSameColor;
  int[][] downSameColor;
  
  public long solve(int n, int m, char[][] map) {
    this.n = n;
    this.m = m;
    this.map = map;
    
    rightSameColor = new int[n][m];
    downSameColor = new int[n][m];
    for (int i = n-1; i >= 0; i-- ) {
      for (int j = m-1; j >= 0; j--) {
        if (j == m-1 || map[i][j] != map[i][j+1]) {
          rightSameColor[i][j] = 1;
        } else {
          rightSameColor[i][j] = rightSameColor[i][j + 1] + 1;
        }
        
        if (i == n-1 || map[i][j] != map[i+1][j]) {
          downSameColor[i][j] = 1;
        } else {
          downSameColor[i][j] = downSameColor[i+1][j] + 1;
        }
      }
    }
    
    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.err.printf("%d, ", downSameColor[i][j]);
      }
      System.err.println();
    }
    */
    long answer = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + 3 * downSameColor[i][j] <= n &&
            downSameColor[i][j] == downSameColor[i + downSameColor[i][j]][j] &&
            downSameColor[i][j] <= downSameColor[i + 2 * downSameColor[i][j]][j]) {
          int minWidth = Integer.MAX_VALUE;
          for (int t = 0; t < 3 * downSameColor[i][j]; t++) {
            minWidth = Math.min(minWidth, rightSameColor[i+t][j]);
          }
//          System.err.printf("%d %d\n", i, j);
          answer += minWidth;
        }
      }
    }
    return answer;
  }
}

class ContestReader {
  private BufferedReader reader;
  private StringTokenizer tokenizer;
  
  ContestReader(InputStream in) {
    reader = new BufferedReader(new InputStreamReader(in));
  }
  
  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }
  
  public int nextInt() {
    return Integer.parseInt(next());
  }
  
  public long nextLong() {
    return Long.parseLong(next());
  }
  
  public double nextDouble() {
    return Double.parseDouble(next());
  }
  
  public int[] nextIntArray(int n) {
    int[] array = new int[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextInt();
    }
    return array;
  }
  
  public long[] nextLongArray(int n) {
    long[] array = new long[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextLong();
    }
    return array;
  }
}

class Algorithm {
  private static void swap(Object[] list, int a, int b) {
    Object tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
  }
  
  public static <T extends Comparable<? super T>> boolean nextPermutation(T[] ts) {
    int rightMostAscendingOrderIndex = ts.length - 2;
    while (rightMostAscendingOrderIndex >= 0 &&
        ts[rightMostAscendingOrderIndex].compareTo(ts[rightMostAscendingOrderIndex + 1]) >= 0) {
      rightMostAscendingOrderIndex--;
    }
    if (rightMostAscendingOrderIndex < 0) {
      return false;
    }
    
    int rightMostGreatorIndex = ts.length - 1;
    while (ts[rightMostAscendingOrderIndex].compareTo(ts[rightMostGreatorIndex]) >= 0) {
      rightMostGreatorIndex--;
    }
    
    swap(ts, rightMostAscendingOrderIndex, rightMostGreatorIndex);
    for (int i = 0; i < (ts.length - rightMostAscendingOrderIndex - 1) / 2; i++) {
      swap(ts, rightMostAscendingOrderIndex + 1 + i, ts.length - 1 - i);
    }
    return true;
  }
  
  public static void shuffle(int[] array) {
    Random random = new Random();
    int n = array.length;
    for (int i = 0; i < n; i++) {
      int randomIndex = i + random.nextInt(n - i);
      
      int temp = array[i];
      array[i] = array[randomIndex];
      array[randomIndex] = temp;
    }
  }
  
  public static void shuffle(long[] array) {
    Random random = new Random();
    int n = array.length;
    for (int i = 0; i < n; i++) {
      int randomIndex = i + random.nextInt(n - i);
      
      long temp = array[i];
      array[i] = array[randomIndex];
      array[randomIndex] = temp;
    }
  }
  
  public static void sort(int[] array) {
    shuffle(array);
    Arrays.sort(array);
  }
  
  public static void sort(long[] array) {
    shuffle(array);
    Arrays.sort(array);
  }
}