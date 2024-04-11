#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr std::pair<int, int> kLose[] = {
    {0, 0},     {1, 2},     {3, 5},     {4, 7},     {6, 10},    {8, 13},
    {9, 15},    {11, 18},   {12, 20},   {14, 23},   {16, 26},   {17, 28},
    {19, 31},   {21, 34},   {22, 36},   {24, 39},   {25, 41},   {27, 44},
    {29, 47},   {30, 49},   {32, 52},   {33, 54},   {35, 57},   {37, 60},
    {38, 62},   {40, 65},   {42, 68},   {43, 70},   {45, 73},   {46, 75},
    {48, 78},   {50, 81},   {51, 83},   {53, 86},   {55, 89},   {56, 91},
    {58, 94},   {59, 96},   {61, 99},   {63, 102},  {64, 104},  {66, 107},
    {67, 109},  {69, 112},  {71, 115},  {72, 117},  {74, 120},  {76, 123},
    {77, 125},  {79, 128},  {80, 130},  {82, 133},  {84, 136},  {85, 138},
    {87, 141},  {88, 143},  {90, 146},  {92, 149},  {93, 151},  {95, 154},
    {97, 157},  {98, 159},  {100, 162}, {101, 164}, {103, 167}, {105, 170},
    {106, 172}, {108, 175}, {110, 178}, {111, 180}, {113, 183}, {114, 185},
    {116, 188}, {118, 191}, {119, 193}, {121, 196}, {122, 198}, {124, 201},
    {126, 204}, {127, 206}, {129, 209}, {131, 212}, {132, 214}, {134, 217},
    {135, 219}, {137, 222}, {139, 225}, {140, 227}, {142, 230}, {144, 233},
    {145, 235}, {147, 238}, {148, 240}, {150, 243}, {152, 246}, {153, 248},
    {155, 251}, {156, 253}, {158, 256}, {160, 259}, {161, 261}, {163, 264},
    {165, 267}, {166, 269}, {168, 272}, {169, 274}, {171, 277}, {173, 280},
    {174, 282}, {176, 285}, {177, 287}, {179, 290}, {181, 293}, {182, 295},
    {184, 298}};
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
int n, a[4];
bool vis[301];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  if (n == 1) {
    if (a[1])
      std::printf("BitLGM");
    else
      std::printf("BitAryo");
  } else if (n == 2) {
    if (a[1] > a[2]) std::swap(a[1], a[2]);
    if (std::find(kLose, kLose + 115, std::make_pair(a[1], a[2])) - kLose !=
        115)
      std::printf("BitAryo");
    else
      std::printf("BitLGM");
  } else {
    if (a[1] ^ a[2] ^ a[3])
      std::printf("BitLGM");
    else
      std::printf("BitAryo");
  }
  return 0;
}