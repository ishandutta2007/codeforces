#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define pli pair<long long,int>
#define N_ 201000

int n;
struct point{
	long long b, e, t;
	bool operator<(const point &p)const{
		return t<p.t;
	}
}w[N_];
struct AA{
	long long t;
	int num, ck;
	bool operator<(const AA &p)const{
		return t<p.t;
	}
};
vector<AA>V;
set<int>Set;
set<pli>Set2;
long long cur;
int PV;
void GoTo(long long T){
	int sz = V.size();
	while(PV < sz && V[PV].t <= T){
		if(V[PV].ck==1){
			int t = V[PV].num;
			Set2.erase({w[t].b+w[t].t,t});
			Set.insert(t);
		}
		else{
			Set.erase(V[PV].num);
		}
		PV++;
	}
	cur = T;
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&w[i].b,&w[i].e,&w[i].t);
	}
	sort(w+1,w+n+1);
	for(i=1;i<=n;i++){
		V.push_back({w[i].b, i, 1});
		V.push_back({w[i].e-w[i].t+1,i,-1});
	}
	sort(V.begin(),V.end());
	int pv = 0;
	cur = 0;
	for(i=1;i<=n;i++){
		Set2.insert({w[i].b+w[i].t, i});
	}
	long long res = 0;
	while(1){
		long long rr = 3e18;
		int pv = -1;
		if(!Set2.empty()){
			pli tp = *Set2.begin();
			rr = tp.first, pv = tp.second;
		}
		if(!Set.empty()){
			int t = *Set.begin();
			if(rr > cur + w[t].t){
				rr = cur+w[t].t;
				pv = t;
			}
		}
		if(pv==-1)break;
		if(cur < w[pv].b){
			GoTo(w[pv].b);
		}
		long long ed = cur+w[pv].t;
		if(PV!=V.size()){
			ed = max(ed, V[PV].t);
		}
		long long cc = (ed-cur)/w[pv].t;
		//printf("%lld %lld %d %lld\n",cur,cc,pv, w[pv].t);
		res += cc;
		GoTo(cur + cc*w[pv].t);
	}
	printf("%lld\n",res);
}