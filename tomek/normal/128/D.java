import java.io.*;
import java.util.*;

public class D {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new D().go();
  }

  static MyReader reader;
  static PrintStream writer;

  void go() {
    int n = reader.readInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = reader.readInt();      
    }
    try {
      solve(arr);
      writer.println("YES");
    } catch (ImpossibleException e) {
      writer.println("NO");
    }
  }


  private void solve(int[] arr) {
    Arrays.sort(arr);
    int edgesIn = 0;
    
    int p = 0;
    while (p < arr.length) {
      if (p != 0 && arr[p-1]+1 != arr[p]) throw new ImpossibleException();
      if (p != 0 && edgesIn==0) throw new ImpossibleException();
      int q = p;
      while(q < arr.length && arr[q] == arr[p]) ++q;
      int cnt = q-p;
      if (edgesIn > cnt) throw new ImpossibleException();
      cnt -= edgesIn;
      edgesIn = cnt;
      p = q;      
    }
    if (edgesIn != 0) throw new ImpossibleException();
  }
  
  private static class ImpossibleException extends RuntimeException {
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