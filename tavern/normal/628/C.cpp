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

const int maxn = 1e5 + 5;

int n, k;
char s[maxn];

int main(){
  scanf("%d%d%s", &n, &k, s);
  FOR(i, 0, n){
    int mx = 0, nj = -1;
    FOR(j, 0, 26) if(abs(j - (s[i] - 'a')) <= k){
      mx = max(mx, abs(j - (s[i] - 'a')));
      if(mx == abs(j - (s[i] - 'a')))
	nj = j;
    }
    k -= mx;
    s[i] = nj + 'a';
  }
  if(k){
    puts("-1");
    return 0;
  }
  puts(s);
  return 0;
}