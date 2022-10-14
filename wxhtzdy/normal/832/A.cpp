#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, K;
  scanf("%lld%lld", &N, &K);
  long long X=N/K;
  if(X%2==1) {
    printf("YES");
  } else {
    printf("NO");
  }
}