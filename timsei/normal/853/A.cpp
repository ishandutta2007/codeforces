#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

priority_queue < int > q;

long long ans, Sum;
int n, k, C[N], T[N];

map <int, vector <int> > Map;

vector <int> All;

int main() {
  cin >> n >> k;
  for(int i = 1; i <= n + k; ++ i) {
    ans += Sum;
    if(i <= n) {
      scanf("%d", &C[i]);
      Map[C[i]].push_back(i);
      Sum += C[i];
      q.push(C[i]);
    }
    if(i > k) {
      Sum -= q.top();
      T[(Map[q.top()].back())] = i;
      Map[q.top()].pop_back();
      q.pop();
    }
  }
  cout << ans << endl;
  for(int i = 1; i <= n; ++ i) printf("%d ", T[i]);
}