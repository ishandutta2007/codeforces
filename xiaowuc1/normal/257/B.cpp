#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  int n,m;
  scanf("%d%d", &n, &m);
  if(n > m){
    n ^= m;
    m ^= n;
    n ^= m;
  }
  printf("%d %d\n", m-1, n);
}