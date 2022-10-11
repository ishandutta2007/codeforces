#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

map<int, vector<int> > prices;

int have;

int temp[100000];

int solve(int need) {
  int own = have;
  int extra = 0;
  int cost = 0;
  for(map<int, vector<int> >::iterator it = prices.begin(); it != prices.end(); it++) {
    vector<int> now = it->second;
    for(int i = 0; i < now.size(); i++) {
      if(now.size() - i >= need) {
        own++;
        cost += now[i];
      }
      else {
        temp[extra++] = now[i];
      }
    }
  }
  if(own < need) {
    sort(temp, temp+extra);
  }
  for(int i = 0; own < need; i++, own++) {
    cost += temp[i];
  }
  return cost;
}

int main() {
  int n;
  scanf("%d", &n);
  have = 0;
  for(int i = 0; i < n; i++) {
    int curr, price;
    scanf("%d%d", &curr, &price);
    if(curr == 0) {
      have++;
    }
    else {
      prices[curr].push_back(price);
    }
  }
  for(map<int, vector<int> >::iterator it = prices.begin(); it != prices.end(); it++) {
    sort(it->second.begin(), it->second.end());
  }
  int left = 1;
  int right = n;
  while(right - left > 3) {
    int aa = (2*left+right)/3;
    int bb = (2*right+left)/3;
    if(solve(aa) < solve(bb)) {
      right = bb;
    }
    else {
      left = aa;
    }
  }
  int ret = 1000000000;
  for(int a = left; a <= right; a++) {
    ret = min(ret, solve(a));
  }
  printf("%d\n", ret);
  return 0;
}