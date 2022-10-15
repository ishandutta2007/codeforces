// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define fir first
#define sec second

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
const int mod=1e9+7;
int main() {
  int n,x,pos,ans=1;
  cin>>n>>x>>pos;
  int num=0,qaq=0;
  int l=0,r=n,tot=0,tot2=0;
  while(l<r){
    num++;
    int mid=l+r>>1;
    if(mid<=pos){
      if(mid<pos)ans=1ll*ans*(x-1-tot++)%mod;
      l=mid+1;
    }
    else {
      ans=1ll*ans*(n-x-tot2++)%mod;
      r=mid;
    }
  } 
  for(int i=n-num;i>=1;i--)ans=1ll*ans*i%mod;
  cout<<ans<<'\n';
}