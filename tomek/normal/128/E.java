import java.awt.AWTPermission;
import java.io.*;
import java.util.*;

public class E {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new E().go();
  }

  static MyReader reader;
  static PrintStream writer;

  void go() {
    int n = reader.readInt();
    int k = reader.readInt();
    circles = new Circle[n];
    for(int i=0;i<n;++i) circles[i] = readCircle();
    long mc = maxCut();
    long res = n + k * (mc + mc + k - 1) / 2;
    System.out.println(res);
  }
  
  private int maxCut() {
    int res = 1;
    for(int i=0;i<circles.length;i++) res = Math.max(res, maxCut(i));
    return res;
  }

  private static final double EPSILON = 1e-10;
  
  private int maxCut(int a) {
    Circle A = circles[a];
    ArrayList<Angle> angles = new ArrayList<Angle>();
    int cnt = 1;
    int best = 1;
    for(int b=0;b<circles.length;b++) {
      if(b==a) continue;
      Circle B = circles[b];
      double alpha = Math.atan2(B.y - A.y, B.x - A.x);
      double beta = Math.asin((B.r - A.r) / Math.hypot(B.y-A.y, B.x-A.x)) - EPSILON;
      double gamma = Math.asin((B.r + A.r) / Math.hypot(B.y-A.y, B.x-A.x)) - EPSILON;
      double a1 = modulo(alpha-beta);
      double a2 = modulo(alpha+gamma);
      double b1 = modulo(alpha-gamma+Math.PI);
      double b2 = modulo(alpha+beta+Math.PI);     
      if(a1 > a2) ++cnt;
      if(b1 > b2) ++cnt;
      angles.add(new Angle(a1, 1));
      angles.add(new Angle(a2, -1));
      angles.add(new Angle(b1, 1));
      angles.add(new Angle(b2, -1));
    }
    Collections.sort(angles);
    for(Angle angle : angles) {
      cnt += angle.d;
      best = Math.max(best, cnt);
    }
    return best;
  }
  
  private static double modulo(double a) {
    while(a>2*Math.PI) a -= 2*Math.PI;
    while(a<0) a += 2*Math.PI;
    return a;
  }
  
  private static class Angle implements Comparable<Angle> {
    double a;
    int d;
    Angle(double a, int d) { this.a = a; this.d = d; }
    public int compareTo(Angle o) {
      if(a < o.a) return -1;
      else if(a > o.a) return 1;
      else return 0;
    }
  }

  private Circle readCircle() {
    Circle c = new Circle();
    c.x = reader.readInt();
    c.y = reader.readInt();
    c.r = reader.readInt();
    return c;
  }

  Circle[] circles;
  
  private static class Circle {
    int x,y,r;
  }
  
  
  private static class MyReader {
    private InputStream in;
    private byte[] buf;
    private int bufSize,bufPos;
    private int nextChar;
    
    public MyReader(InputStream in) {
      this.in = in;
      buf = new byte[16<<10];
      bufSize=0;
      bufPos=0;
      move();
    }
  
    private void move() {
      if (bufPos==bufSize) {
        try {
          bufSize = in.read(buf);
        } catch(IOException ex) {
          throw new RuntimeException(ex);
        }
        bufPos = 0;
        if (bufSize == -1) {
          nextChar = -1;
          return;
        }
      }
      nextChar = buf[bufPos++];
    }
  
    public int readInt() {
      skipWhitespace();
      int res = 0;
      boolean minus = false;
      if(nextChar=='-') { minus=true; move(); } 
      while(nextChar >= '0' && nextChar <= '9') {
        res = 10*res + (nextChar-'0');
        move();
      }
      if (minus) res = -res;
      return res;
    }
    public String readString() {
      StringBuilder b = new StringBuilder();
      skipWhitespace();
      while(nextChar >= 33) {
        b.append((char)nextChar);
        move();
      }
      return b.toString();
    }
  
    public void skipWhitespace() {
      while(nextChar==' ' || nextChar=='\n' || nextChar=='\t' || nextChar=='\r') move();
    }
  }

}