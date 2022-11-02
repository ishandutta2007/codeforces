#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define fi first
#define se second

const ll mod=998244353;
ll god;
int n,q;
ll p[200001];
set<int>s;
ll d[200001];
vector<pair<int,int>> qr1[200001], qr2[200001];

ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}

const int ts=524288;
ll gm[ts],tc[ts];

void pass(int p,int c){
	gm[c]=gm[p]*gm[c]%mod;
	tc[c]=(gm[p]*tc[c]+tc[p])%mod;
}

void push(int id){
	pass(id,id*2);
	pass(id,id*2+1);
	gm[id]=1,tc[id]=0;
}

void upd(int id,int l,int r,int ql,int qr,ll x,ll y){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		gm[id]=(gm[id]*x)%mod;
		tc[id]=(tc[id]*x+y)%mod;
		return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr,x,y);
	upd(id*2+1,mid+1,r,ql,qr,x,y);
}

ll qry(int id,int l,int r,int p){
	if(l==r) return tc[id];
	push(id);
	int mid=(l+r)/2;
	if(p<=mid) return qry(id*2,l,mid,p);
	else return qry(id*2+1,mid+1,r,p);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	god=pw(100,mod-2);
	for(int i=1; i<=n ;i++)
		cin >> p[i];
	s.insert(1);s.insert(n+1);
	qr1[n].push_back({1,0});
	for(int i=1; i<=q ;i++){
		int x;
		cin >> x;
		if(s.find(x)==s.end()){
			auto it=s.lower_bound(x);
			auto it2=it;
			--it;
			qr2[*it2-1].push_back({*it,i});
			qr1[*it2-1].push_back({x,i});
			qr1[x-1].push_back({*it,i});
			s.insert(x);
		}
		else{
			s.erase(x);
			auto it=s.lower_bound(x);
			auto it2=it;
			--it;
			qr1[*it2-1].push_back({*it,i});
			qr2[*it2-1].push_back({x,i});
			qr2[x-1].push_back({*it,i});
		}
	}
	for(int i=1; i<=n ;i++){
		ll y=pw(p[i]*god%mod,mod-2);
		upd(1,1,n,1,i,y,y);
		for(auto cur:qr1[i])
			d[cur.se]=(d[cur.se]+qry(1,1,n,cur.fi))%mod;
		for(auto cur:qr2[i])
			d[cur.se]=(d[cur.se]+mod-qry(1,1,n,cur.fi))%mod;
	}
	ll ans=d[0];
	for(int i=1; i<=q ;i++){
		ans=(ans+d[i])%mod;
		cout << ans << "\n";
	}
}