#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

int retX[90000];
int retY[90000];

int main() {
  int r, c, k;
  scanf("%d%d%d", &r, &c, &k);
  int counter = 0;
  for(int i = 1; i <= r; i++) {
    if(i % 2 == 1) {
      for(int j = 1; j <= c; j++) {
        retX[counter] = i;
        retY[counter] = j;
        counter++;
      }
    }
    else {
      for(int j = c; j >= 1; j--) {
        retX[counter] = i;
        retY[counter] = j;
        counter++;
      } 
    }
  }
  int start = 0;
  while(k-- > 1) {
    printf("2");
    for(int i = start; i < start + 2; i++) {
      printf(" %d %d", retX[i], retY[i]);
    }
    printf("\n");
    start += 2;
  }
  printf("%d", counter - start);
  for(int i = start; i < counter; i++) {
    printf(" %d %d", retX[i], retY[i]);
  }
  printf("\n");
  return 0;  
}