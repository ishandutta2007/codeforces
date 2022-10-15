import java.io.ByteArrayInputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

  static boolean LOCAL = System.getProperty("ONLINE_JUDGE") == null;
  public static void main(String[] args) throws Exception {
    new A().go();
  }

  Scanner in;
  String INPUT = "3\n" +
      "5 1 4";

  void go() {
    if (LOCAL) {
      System.setIn(new ByteArrayInputStream(INPUT.getBytes()));
    }
    in = new Scanner(System.in);
    long startTime = System.currentTimeMillis();
    solve();
    if (LOCAL) {
      System.out.printf("[%dms]\n", System.currentTimeMillis()-startTime);
    }
    in.close();
  }


  PrintWriter out = new PrintWriter(System.out);
  StringBuffer sb = new StringBuffer();


  class Sub {
    int l;
    int r;
    int[] aCount;
    int sum = 0;
    Sub(int[] aCount, int l) {
      this.aCount = aCount;
      this.l=l;
      this.r=l;
    }

    void process() {
      if (aCount[l-1] == 1) {
        l--;
      }
      if (aCount[r+1] == 1) {
        r++;
      }
      for (int i = l; i <= r; i++) {
        sum += aCount[i];
      }
    }

    @Override
    public String toString() {
      StringBuffer answer = new StringBuffer();
      for (int i = l; i <= r; i++) {
        answer.append(" "+i);
        aCount[i]--;
        while(aCount[i] > 1) {
          answer.append(" "+i);
          aCount[i]--;
        }
      }
      for (int i = r; i >= l; i--) {
        if (aCount[i] >= 1) {
          answer.append(" "+i);
        }
      }
      return answer.toString();
    }
  }


  void solve() {

    int n = in.nextInt();
    final int[] aCount = new int[200002]; // begins and ends with zero
    for (int i = 0; i < n; i++) {
      aCount[in.nextInt()]++;
    }

    List<Sub> subs = new ArrayList<>();
    boolean needSub = true;
    Sub nextSub = null;

    for (int i = 1; i < aCount.length; i++) {
      if (aCount[i] >= 2) {
        if (needSub) {
          nextSub = new Sub(aCount, i);
          needSub = false;
          subs.add(nextSub);
        } else {
          nextSub.r = i;
        }
      } else {
        needSub = true;
      }
    }

    if (subs.size() == 0) {
      for (int i = 2; i < aCount.length; i++) {
        if (aCount[i] == 1 && aCount[i-1] == 1) {
          System.out.println(2);
          System.out.printf("%d %d\n", i-1, i);
          return;
        }
      }
      for (int i = 1; i < aCount.length; i++) {
        if (aCount[i] == 1) {
          System.out.println(1);
          System.out.println(i);
          return;
        }
      }
    }


    for (Sub sub : subs) {
      sub.process();
    }

    Sub maxSub = subs.get(0);
    for (Sub sub : subs) {
      if (sub.sum > maxSub.sum) maxSub = sub;
    }

    System.out.println(maxSub.sum);
    System.out.println(maxSub);


  } // end of solve


}