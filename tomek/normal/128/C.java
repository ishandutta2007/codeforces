import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new C().go();
  }

  static MyReader reader;
  static PrintStream writer;

  private static final long MOD = 1000000007;
  
  void go() {
    long n = reader.readInt();
    long m = reader.readInt();
    long k = reader.readInt();
    long res = choose(n-1, 2*k) * choose(m-1, 2*k) % MOD;
    System.out.println(res);
  }
  
  
  
  private long choose(long n, long k) {
    if (k<0 || k>n) return 0;
    long a = factorial(n);
    long b = factorial(k) * factorial(n-k) % MOD;
    return a * inverse(b) % MOD;
  }
  
  private long inverse(long a) {
    return powmod(a, MOD-2);
  }
  
  private long powmod(long a, long b) {
    if(b==0) return 1;
    else if(b%2==0) return powmod(a*a%MOD, b/2);
    else return powmod(a*a%MOD, b/2) * a % MOD;
  }


  private long factorial(long n) {
    long res = 1;
    for (long i = 1; i <= n; i++) {
      res = res * i % MOD;
    }
    return res;
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
      while(nextChar >= '0' && nextChar <= '9') {
        res = 10*res + (nextChar-'0');
        move();
      }
      return res;
    }
  
    public long readLong() {
      skipWhitespace();
      long res = 0;
      while(nextChar >= '0' && nextChar <= '9') {
        res = 10*res + (nextChar-'0');
        move();
      }
      return res;
    }
  
    public void skipWhitespace() {
      while(nextChar==' ' || nextChar=='\n' || nextChar=='\t' || nextChar=='\r') move();
    }
  }

}