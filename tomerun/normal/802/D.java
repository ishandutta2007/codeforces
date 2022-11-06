import java.util.Scanner;

public class D {
  static Scanner sc = new Scanner(System.in);


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
        poisson += K[j] * Math.log(P) - P * Math.log(Math.E) - factLog[K[j]];
      }
//      System.err.println(uniform + " " + poisson);
      System.out.println(uniform < poisson ? "poisson" : "uniform");
    }
  }

}