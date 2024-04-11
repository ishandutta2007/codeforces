// Author : WangZhikun
// Date   : 2018.08.03

#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll gmin(ll a,ll b){return a<b?a:b;}
ll gmax(ll a,ll b){return a>b?a:b;}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x,ll &y){ll d = a;if(b!=0){d = exgcd(b,a%b,y,x);y-=(a/b)*x;}else{x = 1; y = 0;}return d;}
ll inv(ll a){ll d,x,y;d = exgcd(a,mod,x,y);return d==1 ? (x+mod)%mod : -1;}

ll n,m,a[200010],qzh[200010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i] = qzh[i-1]+a[i];
		cout<<(qzh[i]/m)-(qzh[i-1]/m)<<' ';
	}
	cout<<endl;
	return 0;
}