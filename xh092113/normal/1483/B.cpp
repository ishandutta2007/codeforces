#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

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

ll a[N+5];
ll n,pre[N+5],nxt[N+5],vis[N+5];

In ll gcd(ll a,ll b){
	if(!b)return a;
	else return gcd(b,a % b);
}
set<ll> S;
vector<ll> vc;
void solve1(ll x){
	x = (x - 1) % n + 1;
//cout<<"solve1: x="<<x<<" a="<<a[x]<<endl;
	if(a[x] == 1)vc.push_back(x);
	else return;
}
void print(){
	write(vc.size());
	for(auto x : vc)putchar(' '),write(x);
	putchar('\n');
}
void solve(){
	n = read();
	S.clear();
	vc.resize(0);
	for(rg int i = 1;i <= n;i++)vis[i] = 0;
	for(rg int i = 1;i <= n;i++)a[i] = read();
	if(n == 1){solve1(1);print();return;}
	for(rg int i = 1;i <= n;i++){
		pre[i] = i == 1 ? n : i - 1;
		nxt[i] = i == n ? 1 : i + 1;
	}
	for(rg int i = 2;i <= n;i++)if(gcd(a[i],a[i-1]) == 1)S.insert(i),vis[i] = i;
	if(gcd(a[n],a[1]) == 1)S.insert(n + 1),vis[1] = n + 1;
	int cnt = n;
	while(1){
		if(!S.size())break;
		if(cnt == 1){
			solve1(*S.begin());
			break;
		}
		set<ll> :: iterator it = S.begin();
		ll t = *it;
//cout<<"t="<<t<<endl;
		S.erase(it);
		ll i = (t - 1) % n + 1;
		ll x = pre[i],y = nxt[i];
//cout<<"x="<<x<<" y="<<y<<endl;
		pre[y] = x,nxt[x] = y;
		cnt--;vc.push_back(i);
		if(gcd(a[i],a[y]) == 1)S.erase(vis[y]),vis[y] = 0; // **
		if(gcd(a[x],a[y]) == 1){
			ll D = t - i;
			if(i < y)S.insert(D + y + n),vis[y] = D + y + n;
			else S.insert(D + y + 2 * n),vis[y] = D + y + n * 2; // **
		}
//cout<<"S:"<<endl;
//for(auto x : S)cout<<x<<endl;
	}	
	print();
}


int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--){
		solve();
	}
	return 0;
}