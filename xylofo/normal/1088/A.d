import std.conv, std.stdio, std.string;

void main() {
  int x = readln.strip.to!(int);
  foreach(a; 1..x+1) foreach(b; 1..x+1) {
    if(a % b == 0 && a*b>x && b*x > a) {
      writeln(a," ",b);
      return;
    }
  }
  writeln(-1);
}