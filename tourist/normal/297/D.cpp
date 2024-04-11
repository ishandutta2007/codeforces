#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

int a[4444][4444];
char hor[4444][4444], ver[4444][4444];

int main() {
  int h, w, k;
  scanf("%d %d %d", &h, &w, &k);
  for (int i=0;i<2*h-1;i++)
    if (i % 2 == 0) {
      scanf("%s", hor[i / 2]);
    } else {
      scanf("%s", ver[i / 2]);
    }
  if (k == 1) {
    int cnt = 0;
    for (int i=0;i<h;i++)
      for (int j=0;j<w-1;j++)
        if (hor[i][j] == 'E') cnt++;
    for (int i=0;i<h-1;i++)
      for (int j=0;j<w;j++)
        if (ver[i][j] == 'E') cnt++;
    int total = h*(w-1) + (h-1)*w;
    if (4*cnt >= 3*total) {
      printf("YES\n");
      for (int i=0;i<h;i++) {
        for (int j=0;j<w-1;j++) printf("%d ", 1);
        printf("%d\n", 1);
      }
    }
    else printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if (h*(w-1) >= (h-1)*w) {
    for (int i=0;i<h;i++) {
      a[i][0] = 1;
      for (int j=0;j<w-1;j++)
        if (hor[i][j] == 'E') a[i][j+1] = a[i][j];
        else a[i][j+1] = 3-a[i][j];
      if (i > 0) {
        int good = 0, bad = 0;
        for (int j=0;j<w;j++)
          if ((ver[i-1][j] == 'E') != (a[i-1][j] == a[i][j])) bad++;
          else good++;
        if (bad > good) {
          for (int j=0;j<w;j++) a[i][j] = 3-a[i][j];
        }
      }
    }
  } else {
    for (int j=0;j<w;j++) {
      a[0][j] = 1;
      for (int i=0;i<h-1;i++)
        if (ver[i][j] == 'E') a[i+1][j] = a[i][j];
        else a[i+1][j] = 3-a[i][j];
      if (j > 0) {
        int good = 0, bad = 0;
        for (int i=0;i<h;i++)
          if ((hor[i][j-1] == 'E') != (a[i][j-1] == a[i][j])) bad++;
          else good++;
        if (bad > good) {
          for (int i=0;i<h;i++) a[i][j] = 3-a[i][j];
        }
      }
    }
  }
  for (int i=0;i<h;i++) {
    for (int j=0;j<w-1;j++) printf("%d ", a[i][j]);
    printf("%d\n", a[i][w-1]);
  }
  return 0;
}