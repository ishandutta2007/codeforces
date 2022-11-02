//CF 13B
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long x1[4], y1[4], x2[4], y2[4];
bool flag;

bool f(int a, int b, int c) {
  //a b common end point
  if (x2[a] != x2[b] || y2[a] != y2[b]) return false;
  //c on a
  if ((y1[a] - y2[a]) * (x1[c] - x1[a]) != (x1[a] - x2[a]) * (y1[c] - y1[a]) || 
      !(x1[c] >= min(x1[a], x2[a]) && x1[c] <= max(x1[a], x2[a])) || 
      !(y1[c] >= min(y1[a], y2[a]) && y1[c] <= max(y1[a], y2[a]))) return false;
  //c on b
  if ((y1[b] - y2[b]) * (x2[c] - x1[b]) != (x1[b] - x2[b]) * (y2[c] - y1[b]) || 
      !(x2[c] >= min(x1[b], x2[b]) && x2[c] <= max(x1[b], x2[b])) || 
      !(y2[c] >= min(y1[b], y2[b]) && y2[c] <= max(y1[b], y2[b]))) return false;
  if (x1[c] == x2[a] && y1[c] == y2[a]) return false;
  if (x2[c] == x2[a] && y2[c] == y2[a]) return false;
      
  //angle between
  long long tx1 = x1[a] - x2[a], ty1 = y1[a] - y2[a],
            tx2 = x1[b] - x2[b], ty2 = y1[b] - y2[b];
  long long t1 = tx1 * tx2 + ty1 * ty2;
  if (t1 < 0 ||  (y1[a] - y2[a]) * (x1[b] - x1[a]) == (x1[a] - x2[a]) * (y1[b] - y1[a])) return false;
  //divide a
  tx1 = x1[a] - x1[c];
  tx2 = x1[c] - x2[a];
  if (tx1 < 0) tx1 = -tx1;
  if (tx2 < 0) tx2 = -tx2;
  if (tx1 * 4 < tx2 || tx2 * 4 < tx1) return false;
  ty1 = y1[a] - y1[c];
  ty2 = y1[c] - y2[a];
  if (ty1 < 0) ty1 = -ty1;
  if (ty2 < 0) ty2 = -ty2;
  if (ty1 * 4 < ty2 || ty2 * 4 < ty1) return false;
  
  //divide b;
  tx1 = x1[b] - x2[c];
  tx2 = x2[c] - x2[b];
  if (tx1 < 0) tx1 = -tx1;
  if (tx2 < 0) tx2 = -tx2;
  if (tx1 * 4 < tx2 || tx2 * 4 < tx1) return false;  
  ty1 = y1[b] - y2[c];
  ty2 = y2[c] - y2[b];
  if (ty1 < 0) ty1 = -ty1;
  if (ty2 < 0) ty2 = -ty2;
  if (ty1 * 4 < ty2 || ty2 * 4 < ty1) return false;  
  
  return true;
}

int main() {
  scanf("%d", &n);
  for (; n; n--) {
    for (int i = 1; i <= 3; i++) {
      scanf("%I64d %I64d %I64d %I64d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }
    flag = false;
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[1], x2[1]); swap(y1[1], y2[1]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[2], x2[2]); swap(y1[2], y2[2]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[1], x2[1]); swap(y1[1], y2[1]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[3], x2[3]); swap(y1[3], y2[3]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[1], x2[1]); swap(y1[1], y2[1]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[2], x2[2]); swap(y1[2], y2[2]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    swap(x1[1], x2[1]); swap(y1[1], y2[1]);
    flag = flag || f(1, 2, 3) || f(1, 3, 2) || f(2, 1, 3) || f(2, 3, 1) || f(3, 1, 2) || f(3, 2, 1);
    if (flag) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}