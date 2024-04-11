#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

int grid[50000][5];
int last[5];

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  for(int i = 0; i < r; i++) {
    int curr = 0;
    for(int j = 0; j < 5; j++) {
      curr = max(curr, last[j]);
      curr += grid[i][j];
      last[j] = curr;
    }
    printf("%d ", curr);
  }
  return 0;  
}