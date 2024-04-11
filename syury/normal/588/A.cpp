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
int p, a;
int cmin = 1e9;
long long int ans = 0ll;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &a, &p);
    cmin = min(cmin, p);
    ans += a * cmin;
  }
  printf("%lld", ans);
  return 0;
}