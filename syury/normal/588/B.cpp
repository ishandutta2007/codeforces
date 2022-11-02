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

lint n;
lint ans = 1;

int main(){
  scanf("%lld", &n);
  for(lint i = 2; i * i <= n; i++){
    if(n % i == 0){ans *= i; while(n % i == 0){n /= i;}}
  }
  ans *= n;
  printf("%lld", ans);
  return 0;
}