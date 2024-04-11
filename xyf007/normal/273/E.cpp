#include <iostream>
constexpr int kMod = 1e9 + 7, kInv2 = 500000004;
template <typename T>
T add(T a, T b) {
  return a + b >= kMod ? a + b - kMod : a + b;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return a - b < 0 ? a - b + kMod : a - b;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  if ((a += b) >= kMod) a -= kMod;
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  if ((a -= b) < 0) a += kMod;
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::pair<int, int> sg[] = {
    {1, 0},         {3, 1},         {4, 2},         {5, 1},
    {7, 2},         {9, 0},         {13, 1},        {15, 2},
    {19, 0},        {27, 1},        {39, 2},        {40, 0},
    {57, 2},        {58, 1},        {81, 2},        {85, 0},
    {120, 2},       {121, 1},       {174, 2},       {179, 0},
    {255, 2},       {260, 1},       {363, 2},       {382, 0},
    {537, 2},       {544, 1},       {780, 2},       {805, 0},
    {1146, 2},      {1169, 1},      {1632, 2},      {1718, 0},
    {2415, 2},      {2447, 1},      {3507, 2},      {3622, 0},
    {5154, 2},      {5260, 1},      {7341, 2},      {7730, 0},
    {10866, 2},     {11011, 1},     {15780, 2},     {16298, 0},
    {23190, 2},     {23669, 1},     {33033, 2},     {34784, 0},
    {48894, 2},     {49549, 1},     {71007, 2},     {73340, 0},
    {104352, 2},    {106510, 1},    {148647, 2},    {156527, 0},
    {220020, 2},    {222970, 1},    {319530, 2},    {330029, 0},
    {469581, 2},    {479294, 1},    {668910, 2},    {704371, 0},
    {990087, 2},    {1003364, 1},   {1437882, 2},   {1485130, 0},
    {2113113, 2},   {2156822, 1},   {3010092, 2},   {3169669, 0},
    {4455390, 2},   {4515137, 1},   {6470466, 2},   {6683084, 0},
    {9509007, 2},   {9705698, 1},   {13545411, 2},  {14263510, 0},
    {20049252, 2},  {20318116, 1},  {29117094, 2},  {30073877, 0},
    {42790530, 2},  {43675640, 1},  {60954348, 2},  {64185794, 0},
    {90221631, 2},  {91431521, 1},  {131026920, 2}, {135332446, 0},
    {192557382, 2}, {196540379, 1}, {274294563, 2}, {288836072, 0},
    {405997338, 2}, {411441844, 1}, {589621137, 2}, {608996006, 0},
    {866508216, 2}, {884431705, 1}, {1000000001, 0}};
int n, p, f[1001][4], g[3];
int Calc(int l, int r) { return mul(add(p - l, p - r), r - l + 1, kInv2); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> p;
  for (int i = 0; sg[i].first < p; i++) {
    int r = std::min(sg[i + 1].first, p) - 1;
    Add(g[sg[i].second], Calc(sg[i].first, r));
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      if (f[i][j])
        for (int k = 0; k < 3; k++) Add(f[i + 1][j ^ k], mul(f[i][j], g[k]));
  std::cout << add(f[n][1], f[n][2], f[n][3]);
  return 0;
}