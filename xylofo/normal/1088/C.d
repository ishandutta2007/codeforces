import std.algorithm, std.conv, std.range, std.stdio, std.string;

void main() {
  int n = readln.strip.to!int;
  auto v = readln.splitter.map!(to!long).array;
  v.reverse;
  long md = 5000;
  writeln(n+1);
  //make v[i] = -i mod md.
  foreach(i,x;v) {
    //x + i + delta = k*md
    long target = (x+i+md)/md*md;
    long d = target - (x+i+1);
    v[i..$] += d;
    writefln!"1 %d %d" (n-i, d);
    debug {writeln(v);}
  }
  v.reverse;
  v[] %= md;
  debug {writeln(v);}
  writefln!"2 %d %d" (n, md);
}