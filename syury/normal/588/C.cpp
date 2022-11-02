#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<iostream>

#define sz(x) (x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ins insert
#define del delete

using namespace std;

typedef long long int lint;
typedef long double ldb;

int n;
vector<int> p(2000001, 0);

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int w;
    scanf("%d", &w);
    p[w]++;
  }
  int inc = 0;
  int ans = 0;
  for(int i = 0; i < 2000001; i++){
    p[i] += inc;
    inc = p[i] / 2;
    p[i] = p[i] % 2;
    ans += p[i];
  }
  printf("%d", ans);
  return 0;
}