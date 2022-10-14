// Author : WangZhikun
// Date   : 2018-10-18
// ?o??r???I?????u?

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch))ch = getchar();if(ch == '-')f*=-1;
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}
ll mod = 998244353,n,a[200020],m,s,inv2 = (998244354)/2;
ll pow(ll a,ll b){
	ll r = 1;
	while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod;b>>=1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	read(n);read(m);read(s);a[0] = 0;
	for(int i=1;i<=m;i++)read(a[i]);
	ll ans = pow(s,n-a[m]*2);
	for(int i=1;i<=m;i++){
		ll cl = a[i]-a[i-1];
		ll cu = (((pow(s,cl*2)-pow(s,cl)+mod)%mod)*inv2+pow(s,cl)+mod)%mod;
		ans = ans*cu%mod;
	}
	
	cout<<ans<<endl;
	return 0;
}