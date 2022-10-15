// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=998244353;
const double EPS=1e-9;
// const double pi=acos(-1);
const int INF=1e18;
const int N=500007;
const int M=1000007;
mt19937 rng(1234);
typedef bitset<1000> bs1;
typedef bitset<3000> bs2;
using S=pii;
using F=int;

int n,q;
int a[N];


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout.precision(15);
  int _;
  cin>>_;
  while (_--){
    cin>>n>>q;
    int qq=q;
    rep(i,n) cin>>a[i];
    rep(i,n) if (a[i]>q) q--;
    if (q>0) {
      rep(i,n) cout<<"1";
      cout<<"\n";
      continue;
    }
    q=0;
    vi lst;
    reverse(a,a+n);
    rep(i,n) {
      if (a[i]>q){
        if (q==qq) lst.pb(0);
        else lst.pb(1), q++;
      }
      else lst.pb(1);
    }
    reverse(range(lst));
    for (auto c:lst) cout<<c;
    cout<<"\n";
  }
  return 0;
}
/*
5 3
1 2
1 3
4 5
1 4
1 5
2 3

01100
10000
10000
00001
00010

00101
00100
11000
00001
10010
*/