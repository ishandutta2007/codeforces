#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
typedef long long lli;
typedef unsigned long long llu;
typedef pair<lli,lli> pll;
const lli inf=1e15;

struct data{
	lli t;
	int ad;
	data() {}
	data(lli t,int ad):t(t),ad(ad) {}
	bool operator<(const data &rhs)const {
		return t!=rhs.t ? t>rhs.t : ad<rhs.ad;
	}
};

int n,m;
lli bnd,inc,dmg,mh[100000],sh[100000],rg[100000];
vector<pll> arr[100000];

lli get(int i,lli s,lli ad) {
	if(rg[i]==0 || mh[i]<=dmg) return inf;
	else return (dmg-s)/rg[i]+ad;
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%lld%lld%lld",&bnd,&inc,&dmg);
	for(int i=0;i<n;i++) scanf("%lld%lld%lld",mh+i,sh+i,rg+i);

	for(int i=0;i<m;i++) {
		lli t,val;
		int ei;
		scanf("%lld%d%lld",&t,&ei,&val);
		arr[--ei].push_back(pll(t,val));
	}

	priority_queue<data> que;
	for(int i=0;i<n;i++) {
		int s=0;
		lli lt=0;
		if(sh[i]<=dmg) {
			lt = get(i,sh[i],0);
			que.push(data(0,1));
			s=1;
		}
		
		sort(arr[i].begin(),arr[i].end());
		for(auto &it:arr[i]) {
			if(lt < it.first && s==1) {
				que.push(data(lt,-1));
				s=0;
			}
			if(it.second<=dmg) {
				if(s==0) {
					que.push(data(it.first,1));
					s=1;
				}
				lt=get(i,it.second,it.first);
			}
			else if(s==1) {
				lt=it.first-1;
				que.push(data(lt,-1));
				s=0;
			}
		}
		if(s==1 && lt<inf) {
			que.push(data(lt,-1));
		}
	}

	int c=0;
	lli mx=0;
	while(!que.empty()) {
		data cur=que.top(); que.pop();
		if(cur.t>=inf) break;

		mx=max(mx,c*(bnd+inc*cur.t));
		c+=cur.ad;
	}
	
	if(inc==0) mx=max(mx, c*bnd);
	if(c!=0 && inc!=0) puts("-1");
	else printf("%lld\n",mx);

	return 0;
}