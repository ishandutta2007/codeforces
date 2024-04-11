import java.util.Scanner;

public class F {
  static Scanner sc = new Scanner(System.in);
  static final double logE = Math.log(Math.E);

  public static void main(String[] args) {
    int V = sc.nextInt();
    double[] factLog = new double[1500001];
    for (int i = 1; i < factLog.length; i++) {
      factLog[i] = Math.log(i) + factLog[i - 1];
    }
    for (int i = 0; i < V; i++) {
      int[] K = new int[250];
      int min = 0;
      int max = 0;
      long sum = 0;
      long sum2 = 0;
      for (int j = 0; j < K.length; j++) {
        K[j] = sc.nextInt();
        min = Math.min(min, K[j]);
        max = Math.max(max, K[j]);
        sum += K[j];
        sum2 += K[j] * K[j];
      }
      double ave = 1.0 * sum / K.length;
      double ave2 = 1.0 * sum2 / K.length;
      double var = ave2 - ave * ave;
      System.err.println("var:" + var);
      double uniform = -Math.log(2 * Math.max(1, Math.max(-min, max)) + 1) * K.length;
      double poisson = -Double.MAX_VALUE;
      for (int j = Math.max(1, Math.max(-min, (int) var - 100)); j <= Math.min(2000, (int) var + 300); j++) {
        double likelyhood = 0;
        for (int k = 0; k < K.length; k++) {
          likelyhood += (K[k] + j) * Math.log(j) - j * logE - factLog[K[k] + j];
        }
        if (likelyhood > poisson) {
          poisson = likelyhood;
        }
      }
      System.err.println(uniform + " " + poisson);
      System.out.println(uniform < poisson ? "poisson" : "uniform");
    }
  }

}