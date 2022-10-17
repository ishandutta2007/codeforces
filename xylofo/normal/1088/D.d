import std.algorithm, std.conv, std.range, std.stdio, std.string;

void main() {
  int a = 0, b = 0;
  int less = -2;
  foreach(i; iota(29,-1,-1)) {
    debug {writeln(i);}
    int query(int x, int y) {
      x <<= i; y <<= i;
      x ^= a; y ^= b;
      writefln!"? %d %d" (x,y);
      stdout.flush;
      return readln.strip.to!int;
    }
    void set(int x, int y) {
      x <<= i; y <<= i;
      a ^= x; b ^= y;
    }
    if(less == -2) less = query(0,0);
    int k = query(1,1);
    if(less != k) {
      set(less > 0, less < 0);
      less = -2;
      continue;
    }
    k = query(0,1);
    set(k > 0, k > 0);
  }
  writefln!"! %d %d" (a,b);
}