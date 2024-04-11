import java.util.Scanner;

public class E {
  static Scanner sc = new Scanner(System.in);
  static final double logE = Math.log(Math.E);

  public static void main(String[] args) {
    int V = sc.nextInt();
    double[] factLog = new double[3001];
    for (int i = 1; i < factLog.length; i++) {
      factLog[i] = Math.log(i) + factLog[i - 1];
    }
    for (int i = 0; i < V; i++) {
      int[] K = new int[250];
      long sum = 0;
      for (int j = 0; j < K.length; j++) {
        K[j] = sc.nextInt();
        sum += K[j];
      }
      double P = sum * 1.0 / K.length;
      double uniform = -Math.log(2 * P + 1) * K.length;
      double poisson = 0;
      for (int j = 0; j < K.length; j++) {
        poisson += K[j] * Math.log(P) - P * logE - factLog[K[j]];
      }
//      System.err.println(uniform + " " + poisson);
      int bestI = 0;
      if (uniform < poisson) {
        double bestLikelyhood = -Double.MAX_VALUE;
        for (int j = Math.max(10, (int) P - 10); j <= (int) P + 10; j++) {
          double likelyhood = 0;
          for (int k = 0; k < K.length; k++) {
            likelyhood += K[k] * Math.log(j) - j * logE;
          }
          if (likelyhood > bestLikelyhood) {
            bestLikelyhood = likelyhood;
            bestI = j;
          }
        }
      } else {
        int max = 0;
        for (int j = 0; j < K.length; j++) {
          max = Math.max(max, K[j]);
        }
        bestI = max / 2 + 1;
      }
      System.out.println(bestI);
    }
  }

}