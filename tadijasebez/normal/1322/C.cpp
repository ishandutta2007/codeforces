#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=1000050;
const int mod=998244353;
const int base=7954789;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
int n,m;
ll sum[N];
vector<int> my[N];
map<int,int> go[N];
ll all[N];
int tsz;
ll gcd(ll x,ll y){return x==0?y:gcd(y%x,x);}
void Solve(){
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)my[i].clear();
	for(int i=1;i<=n;i++)scanf("%lld",&sum[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		my[v].pb(u);
	}
	tsz=0;
	for(int i=1;i<=n;i++){
		int hsh=0;
		int root=0;
		sort(my[i].begin(),my[i].end());
		for(int j=0;j<my[i].size();j++){
			if(!go[root][my[i][j]])go[root][my[i][j]]=++tsz,all[tsz]=0;
			root=go[root][my[i][j]];
		}
		all[root]+=sum[i];
	}
	ll g=0;
	for(int i=1;i<=tsz;i++)g=gcd(g,all[i]);//,printf("%lld ",all[i]);
	printf("%lld\n",g);
	for(int i=0;i<=tsz;i++)go[i].clear();
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--)Solve();
	return 0;
}