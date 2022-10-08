import java.io.*;
import java.util.*;

public class B {

  public static void main(String[] args) throws Exception {
    reader = new MyReader(System.in);
    writer = System.out;
    new B().go();
  }

  static MyReader reader;
  static PrintStream writer;

  void go() {
    text = reader.readString();
    int k = reader.readInt();
    String result = calc(k);
    if(result == null) writer.println("No such line.");
    else writer.println(result);
  }
  
  private String text;
  
  private String calc(int nr) {
    ArrayList<Pos> poss = new ArrayList<Pos>();
    for(int st=0;st<text.length();st++) poss.add(new Pos(st));
    StringBuilder res = new StringBuilder();
    --nr;
    for(;;) {
//      System.out.println("nr=" + nr);
//      for (Pos pos : poss) System.out.println(pos.start + " " + pos.len);
//      System.out.println("==");
      Collections.sort(poss);
      int nr2 = nr;
      char last = '?';
      for (Pos pos : poss) {
        int hm = pos.howMany();
        if(nr2 < hm) { last = pos.last; break; }
        nr2 -= hm;
      }
      if (last=='?') return null;
      res.append(last);
      int cnt = 0;
      ArrayList<Pos> poss2 = new ArrayList<Pos>();
      for (Pos pos : poss) {
        if(pos.last == last) {
          cnt++;
          if(pos.extend()) poss2.add(pos);
        } else if (pos.last < last) {
          nr -= pos.howMany();
        }
      }
      if(nr < cnt) break;
      nr -= cnt;
      poss = poss2;
    }
    return res.toString();
  }
  
  private class Pos implements Comparable<Pos> {
    int start, len;
    char last;
    Pos(int st) {
      start = st; len=1; last = text.charAt(start);
    }
    public boolean extend() {
      if (start+len >= text.length()) return false;
      ++len;
      last = text.charAt(start+len-1);
      return true;
    }
    public int howMany() { return text.length() - start - len + 1; }
    public int compareTo(Pos o) {
      return (int)last - (int)o.last;
    }
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
  
    public String readString() {
      StringBuilder b = new StringBuilder();
      skipWhitespace();
      while(nextChar >= 33) {
        b.append((char)nextChar);
        move();
      }
      return b.toString();
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