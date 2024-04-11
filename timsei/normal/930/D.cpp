#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
const int Base = 1e5 + 2;

struct NODE {
  int x , y;
  void input(void) {
    scanf("%d%d" , &x , &y);
  }
  friend bool operator < (NODE a , NODE b) {
    return a.x < b.x;
  }
}now;

vector < NODE > Vec[2];

int n , u1[N] , u0[N] , d0[N] , d1[N];

long long solve(vector <NODE> A) {
  for(int i = 0;i < N;++ i) u0[i] = u1[i] = 0 , d0[i] = d1[i] = 2e9;
  for(int i = 0;i < (int) A.size();++ i) {
    int xx = A[i].x , yy = A[i].y;
    A[i].x = xx + yy , A[i].y = xx - yy;
    if(A[i].x & 1) ++ A[i].x , ++ A[i].y;
    A[i].x += Base * 2; A[i].y += Base * 2;
    u0[A[i].x + 1] = max(u0[A[i].x + 1] , A[i].y - 1);
    d0[A[i].x + 1] = min(d0[A[i].x + 1] , A[i].y + 1);
    u1[A[i].x - 1] = max(u1[A[i].x - 1] , A[i].y - 1);
    d1[A[i].x - 1] = min(d1[A[i].x - 1] , A[i].y + 1);
  }
  for(int i = 1;i < N;++ i)
    u0[i] = max(u0[i] , u0[i - 1]) ,
      d0[i] = min(d0[i] , d0[i - 1]);
  for(int i = N - 2;i >= 1;-- i)
    u1[i] = max(u1[i] , u1[i + 1]) ,
      d1[i] = min(d1[i] , d1[i + 1]);
  long long lsk = 0;
  for(int i = 1;i < N;i += 2) {
    int L = max(d1[i] , d0[i]) , R = min(u0[i] , u1[i]);
    if(L > R)
      continue;
    lsk += (R - L) / 2 + 1;
  }
  return lsk;
}

int main() {
  scanf("%d" , &n);
  if(n < 4) {
    puts("0");
    return 0;
  }
  for(int i = 1;i <= n;++ i) {
    now.input();
    Vec[(now.x + now.y + (int)1e8) & 1].push_back(now);
  }
  cout << solve(Vec[0]) + solve(Vec[1]) << endl;
}