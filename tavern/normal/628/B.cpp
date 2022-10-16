#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;


const int maxn = 3e5 + 5;

int n;
ll ans = 0;
char s[maxn];

inline bool check1(int i){
  return !(s[i] % 4);
}

inline bool check2(int i){
  if(!i)
    return 0;
  return !((s[i - 1] * 10 + s[i]) % 4);
}

inline bool check3(int i){
  if(i <= 1)
    return 0;
  return !((s[i - 2] * 100 + s[i - 1] * 10 + s[i]) % 4);
}

int main(){
  scanf("%s", s);
  n = strlen(s);
  FOR(i, 0, n)
    s[i] -= '0';
  FOR(i, 0, n){
    ans += check1(i);
    ans += check2(i);
    ans += check3(i) * (i - 1);
    //    printf("%lld\n", ans);
  }
  printf("%lld\n", ans);
}