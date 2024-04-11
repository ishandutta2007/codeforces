import java.io.*;
import java.util.*;

public class Test {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new Test().go();
  }

  static MyReader reader;
  static PrintStream writer;

  void go() {
    long n = reader.readInt();
    long m = reader.readInt();
    long a = reader.readInt();
    long res = ((n+a-1)/a) * ((m+a-1)/a);
    writer.println(res);
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