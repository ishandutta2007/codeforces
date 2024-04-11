#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll h(pair<ll,ll> r){return(r.first*1e10)+r.second;}
unordered_set<ll> s;
struct it{ll x, y;};
it pr(ll x, ll y){it i={x,y}; return i;}
ll n, m, r, k, i, ex;
ll val(ll x, ll y){
	ll up1 = min(x, n-r+1), up2 = min(y, m-r+1);
	ll lo1 = max(1LL, x-r+1), lo2 = max(1LL, y-r+1);
	return (up1-lo1+1)*(up2-lo2+1);
}
struct pq{bool operator()(const it&i,const it&j){
	return(val(i.x,i.y)<val(j.x,j.y));
}};
priority_queue<it,vector<it>,pq> q;

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&r,&k);
	q.push(pr(ceil(n/2.0),ceil(m/2.0)));
	s.insert(h({ceil(n/2.0),ceil(m/2.0)}));
	while(q.size() && k){
		it c = q.top(); q.pop(); k--;
		ex += val(c.x,c.y); 
		if(c.x != 1 && s.find(h({c.x-1,c.y}))==s.end()){
			q.push(pr(c.x-1,c.y));
			s.insert(h({c.x-1,c.y}));
		}
		if(c.x != n && s.find(h({c.x+1,c.y}))==s.end()){
			q.push(pr(c.x+1,c.y));
			s.insert(h({c.x+1,c.y}));
		}
		if(c.y != 1 && s.find(h({c.x,c.y-1}))==s.end()){
			q.push(pr(c.x,c.y-1));
			s.insert(h({c.x,c.y-1}));
		}
		if(c.y != m && s.find(h({c.x,c.y+1}))==s.end()){
			q.push(pr(c.x,c.y+1));
			s.insert(h({c.x,c.y+1}));
		}
	}
	printf("%.10lf\n",ex/(double)((n-r+1)*(m-r+1)));
	return 0;
}