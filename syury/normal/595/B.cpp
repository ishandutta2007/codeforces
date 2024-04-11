#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int lint;

const lint M = 1000000007;

lint n, k, m, maxnum = 0, ans = 1ll;
vector<lint> a, b;

lint gen(lint i){
  lint res = 0;
  for(lint j = 0; j < i; j++){res = res * 10 + 9;}
  return res;
}

lint pow10(lint i){
  lint res = 1;
  for(lint j = 0; j < i; j++){res *= 10;}
  return res;
}

lint solve(lint ca, lint cb){
  lint d = maxnum/ca;
  lint c = pow10(k - 1);
  for(int i = k - 1; i < k; i++){
    lint cc = c * cb;
    lint mod = (ca - cc % ca)%ca;
    lint cnt = gen(i)/ca;
    if(gen(i)%ca >= mod){cnt++;}
    d -= cnt;
    //c *= 10;
  }
  //if(cb != 0){d++;}
  d++;
  return d;
}

int main(){
  scanf("%lld%lld", &n, &k);
  maxnum = gen(k);
  m = n/k;
  a.resize(m);
  b.resize(m);
  for(int i = 0; i < m; i++){
    scanf("%lld", &a[i]);
  }
  for(int i = 0; i < m; i++){
    scanf("%lld", &b[i]);
    lint curr = solve(a[i], b[i]);
    ans *= curr;
    ans %= M;
  }
  printf("%lld", ans);
  return 0;
}