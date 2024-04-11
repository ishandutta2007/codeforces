#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int x[105];
int y[105];
bool seen[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    seen[i] = false;
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(!seen[i]) {
      seen[i] = true;
      ret++;
      queue<int> q;
      q.push(i);
      while(!q.empty()) {
	int curr = q.front();
	q.pop();
	for(int k = 0; k < n; k++) {
	  if((x[k] == x[curr] || y[k] == y[curr]) && !seen[k]) {
	    seen[k] = true;
	    q.push(k);
	  }
	}
      }
    }
  }
  printf("%d\n", ret-1);
  return 0;
}