#include <bits/stdc++.h>
using namespace std;
 
const int MaxN = 100000 + 5;
 
int N;
long long A[MaxN];
 
int main() {
  cin >> N;
  long long mx = 0, sum = 0;
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]), sum += A[i], mx = max(mx, A[i]);
  puts(sum % 2 == 0 && mx <= sum / 2 ? "Yes" : "No");
  return 0;
}