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

ll n,m,q,a[1010],qzh[1010] = {0};
char s1[1010],s2[1010];
int main(){
	cin>>n>>m>>q;
	cin>>(s1+1)>>s2;
	for(int i=1;i<=n-m+1;i++){
		a[i] = 1;
		for(int j=0;j<m;j++){
			if(s1[i+j] != s2[j])a[i] = 0;
		}
		qzh[i] = qzh[i-1]+a[i];
	}
	int l,r;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		if(r-l<m-1){
			cout<<0<<endl;
		}else{
			cout<<qzh[r-m+1]-qzh[l-1]<<endl;
		}
	}
	return 0;
}