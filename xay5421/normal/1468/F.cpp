#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
map<pair<int,int>,int> mp;
int n,a[N],b[N],T;
ll Solve(){
	mp.clear();
	ll ans=0;
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),u=read(),v=read();
		a[i]=u-x,b[i]=v-y;
		int g=__gcd(abs(a[i]),abs(b[i]));
		a[i]/=g,b[i]/=g;
		++mp[make_pair(a[i],b[i])];
	}
	for(int i=1;i<=n;++i){
		ans+=mp[make_pair(-a[i],-b[i])];
	}
	return ans>>1;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}