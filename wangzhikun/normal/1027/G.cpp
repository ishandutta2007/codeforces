//  Created by  on 2018/9/4.

#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair< ll, ll > pt;
vector<pt> merge(const vector<pt> &a, const vector<pt> &b) {
	vector<pt> ans;
	int u = 0, v = 0;
	while(u < a.size() && v < b.size()) {
		if(a[u].first < b[v].first)
			ans.push_back(a[u++]);
		else if(a[u].first > b[v].first)
			ans.push_back(b[v++]);
		else {
			ans.emplace_back(a[u].first, a[u].second + b[v].second);
			u++; v++;
		}
	}
	while(u < a.size())
		ans.push_back(a[u++]);
	while(v < b.size())
		ans.push_back(b[v++]);
	return ans;
}
template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll x,m,ans,cx,mod;
int apow[20];

ll mul2(ll a,ll b){
	ll c = a;a = 0;
	while(b){
		if(b&1)a = (a+c)%mod;
		c = (c+c)%mod;b>>=1;
	}
	return a;
}

ll mul(ll a, ll b) {
	ll m = (ll) ((long double) a *b/mod);
	ll rem = a * b - m * mod;
	while(rem < 0)
		rem += mod;
	while(rem >= mod)
		rem -= mod;
	return rem;
}
ll pow(ll a,ll b){
	ll c = a;a = 1;
	while(b){
		if(b&1)a = mul(a,c);
		c = mul(c,c);b>>=1;
	}
	return a;
}
vector< pair<ll , ll > > fac;
vector< pair<ll , ll > > facs[20];
vector< pair<ll , ll > > cur;
void ins(ll a,ll b,vector< pair<ll , ll > > &cur){
	for(int i=0;i<cur.size();i++){
		if(cur[i].first == a){
			cur[i].second+=b;
			return;
		}
	}
	cur.push_back(make_pair(a, b));
}
void cal(ll d){
	ll phi = d,ord = 1;
	mod = d;cx = x%d;
	cur = fac;
	for(int i=0;i<cur.size();i++){
		cur[i].second = max(apow[i]-1,0);
	}
	for(int i=0;i<cur.size();i++){
		if(apow[i]){
			//cout<<fac[i].first<<endl;
			phi = phi-phi/fac[i].first;
			cur = merge(cur,facs[i]);
		}
	}
	ord = phi;
	for(int i=0;i<cur.size();i++)
		while(ord%cur[i].first == 0 && pow(cx,ord/cur[i].first) == 1)
			ord/=cur[i].first;
	//cout<<mod<<' '<<phi<<endl;
	ans+=phi/ord;
}

void sol(ll cu,ll depth){
	if(depth == fac.size()){
		cal(cu);
		return;
	}
	for(int i=0;i<=fac[depth].second;i++){
		apow[depth] = i;
		sol(cu,depth+1);
		if(i!=fac[depth].second)cu*=fac[depth].first;
	}
}
void factorize(ll m,vector< pair <ll ,ll > > &fac){
	for(ll i=2;i*i<=m;i++){
		if(m%i == 0){
			fac.push_back(make_pair(i, 0));
			while(m%i == 0){
				m/=i;
				fac[fac.size()-1].second+=1;
			}
		}
	}
	if(m>1)fac.push_back(make_pair(m, 1));
}
int main() {
	read(m);read(x);
	factorize(m, fac);
	//cout<<"Posa"<<endl;
	//cout<<fac.size()<<endl;
	for(int i=0;i<fac.size();i++) factorize(fac[i].first-1, facs[i]);
	sol(1,0);
	cout<<ans<<endl;
	return 0;
}