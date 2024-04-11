#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = N * 2;
const int mod = 998244353;
#define int long long
int n , m , x , y , fir[N] , ne[M] , to[M] , cnt, S[N] , now , ans[N] , tot , P[N] , H[N];
void add(int x , int y) {
    ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}
#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
#define C(x) (x * x % mod * x % mod)
map<int,int> p;
void dance(int x , int f) {S[x] = 1; H[x] = 123123;Foreachson(i , x) {int V = to[i];if(V==f) continue;dance(V,x);S[x]+=S[V];H[x]=H[x]+C(H[V]);H[x]%=mod;}++p[H[x]];}
void solve(int x , int f , int F) {if(x!=1) if(-- p[H[x]]==0) p.erase(H[x]);if(x!=1) ans[x] = p.size();Foreachson(i,x) {int V = to[i]; if(V == f) continue;int F2 = C(F)+H[x]-C(H[V])+mod;F2%=mod;++ p[F2];solve(V,x ,F2);if(--p[F2]==0)p.erase(F2);}++p[H[x]];}
main(void) {
    cin>>n;for(int i=1;i<n;++i)cin>>x>>y,add(x,y),add(y,x);dance(1,0);now=1;ans[1]=p.size();solve(1,0,0);for(int i=1;i<=n;++i)if(ans[i]>ans[now])now=i;cout<<now;
}