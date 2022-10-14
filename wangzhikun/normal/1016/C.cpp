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

ll n,a[300010],b[300010],c[300010],d[300010],togrow[300010];
char s1[1010],s2[1010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		togrow[0]+=a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		togrow[0]+=b[i];
	}
	ll cnt = 0;
	for(int i=0;i<n;i++){
		c[0]+=a[i]*cnt;
		d[0]+=b[i]*cnt;
		cnt+=1;
	}
	for(int i=n-1;i>=0;i--){
		c[0]+=b[i]*cnt;
		d[0]+=a[i]*cnt;
		cnt+=1;
	}
	ll ans = c[0];
	//cout<<c[0]<<endl;
	for(int i=1;i<=n;i++){
		togrow[i] = togrow[i-1]-a[i-1]-b[i-1];
		c[i] = c[i-1]-(n*2-1)*b[i-1]-((i-1)*2)*a[i-1]+togrow[i];
		d[i] = d[i-1]-(n*2-1)*a[i-1]-((i-1)*2)*b[i-1]+togrow[i];
		//cout<<c[i]<<' '<<d[i]<<endl;
	}
	ll scc =0;
	for(int i=0;i<n;i++){
		ll cans;
		if(i%2){
			scc+=i*2*b[i]+(i*2+1)*a[i];
			cans = scc+c[i+1];
		}else{
			scc+=i*2*a[i]+(i*2+1)*b[i];
			cans = scc+d[i+1];
		}
		ans = max(ans,cans);
	}
	cout<<ans<<endl;
	return 0;
}