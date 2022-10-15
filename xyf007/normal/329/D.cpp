#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, x;
int main(int argc, char const *argv[]) {
  Read(n, x);
  if (n == 5) {
    std::printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1");
    return 0;
  }
  if (n == 3) {
    std::printf(">vv\n^<.\n^.<\n1 3");
    return 0;
  }
  std::printf(
      "v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<"
      "<<<<<<<<<<<<<<<<<<<<<<<<<<<<\nv>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>"
      "v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v^\n");
  for (int i = 1; i <= 24; i++)
    std::printf(
        "v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v."
        "v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.\nv^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"
        "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^\n");
  for (int i = 1; i <= 24; i++)
    std::printf(
        "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"
        "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^\n.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^"
        ".^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^\n");
  std::printf(
      ">^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^"
      ">^>^>^>^>^>^>^>^>^>^>^>^>^>^\n.........................................."
      "..........................................................\n1 1");
  return 0;
}