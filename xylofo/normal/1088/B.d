import std.algorithm, std.conv, std.range, std.stdio, std.string;

void main() {
  int n,k,lst = 0;
  readf!"%d %d\n" (n, k);
  auto v = readln.splitter.map!(to!int).array.sort;
  foreach(x;v) {
    if(x>lst) {
      writeln(x-lst);
      if(--k == 0) break;
    }
    lst = x;
  }
  foreach(i;0..k) writeln(0);
}