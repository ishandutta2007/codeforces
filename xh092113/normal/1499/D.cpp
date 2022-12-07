#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int W = 2e7;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int pri[W/5],pn;
bool isp[W+5];
ll f[W+5];
ll p2[10];

void Eular(){
	f[1] = 0;
	for(rg int i = 2;i <= W;i++)isp[i] = 1;
	for(rg int i = 2;i <= W;i++){
		if(isp[i])pri[++pn] = i,f[i] = 1;
		for(rg int j = 1;pri[j] * i <= W;j++){
			int p = pri[j];
			isp[i*p] = 0;
			if(i % p == 0){
				f[i*p] = f[i];
				break;		
			}
			else{
				f[i*p] = f[i] + 1;
			}
		}
	}
}

ll c,d,x;
vector<int> fac;

ll gcd(ll a,ll b){
	return b ? gcd(b,a % b) : a;
}
ll solve(){
	c = read(),d = read(),x = read();
	ll g = gcd(c,d);
	if(x % g != 0)return 0;
	c /= g,d /= g,x /= g;
	fac.resize(0);
	for(rg int i = 1;i * i <= x;i++)if(x % i == 0){
		int j = x / i;
		fac.push_back(i);
		if(i != j)fac.push_back(j);
	}
	ll ans = 0;
	for(rg int i = 0;i < fac.size();i++){
		ll e = fac[i];
//cout<<"e="<<e<<endl;
		ll ed = e + d;	
		if(ed % c == 0)ans += f[ed/c];
	}
	return ans;
}

int main(){
	//freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	int Tc = read();
	Eular();
	p2[0] = 1;for(rg int i = 1;i < 10;i++)p2[i] = p2[i-1] * 2;
//for(rg int i = 1;i <= 100;i++)cout<<f[i]<<" ";cout<<endl;
	for(rg int i = 1;i <= W;i++)f[i] = p2[f[i]];
	while(Tc--)write(solve()),putchar('\n');
	return 0;
}