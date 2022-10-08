import java.io.*;
import java.util.*;

public class A {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new A().go();
  }

  static MyReader reader;
  static PrintStream writer;
  private boolean[][] statues;

  void go() {
    statues = new boolean[8][8];
    for(int y=0;y<8;y++) {
      reader.skipWhitespace();
      for(int x=0;x<8;x++) {
        char c = reader.readChar();
        statues[y][x] = c=='S';
      }
    }
    boolean[][] poss = new boolean[8][8];
    poss[7][0] = true;
    for(int t=0;t<10;t++) {
      boolean[][] poss2 = new boolean[8][8];
      for(int y=0;y<8;++y) for(int x=0;x<8;++x) if(poss[y][x]) {
        for(int y2=y-1;y2<=y+1;y2++) for(int x2=x-1;x2<=x+1;x2++) {
          if(y2>=0 && y2<8 && x2>=0 && x2<8) {
            if(!isStatue(t, y2, x2) && !isStatue(t+1, y2, x2)) {
              poss2[y2][x2]=true;
            }
          }
        }
      }
      poss = poss2;
    }
    boolean ok = false;
    for(int y=0;y<8;++y) for(int x=0;x<8;++x) if(poss[y][x]) {
      ok = true;
    }
    if (ok) writer.println("WIN"); else writer.println("LOSE");
  }
  
  
  
  private boolean isStatue(int t, int y, int x) {
    y -= t;
    return y>=0 && statues[y][x];
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
    
    public char readChar() {
      char res = (char)nextChar;
      move();
      return res;
    }
  }

}