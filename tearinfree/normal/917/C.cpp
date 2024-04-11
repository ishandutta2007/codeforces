#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli inf=2e18;

int n,m,l,t;
lli ma[10],ta[30],tca[30];
pll tt[30];

lli dist[30][1<<8][1<<8];
vector<int> cs;

void getDist() {
	for(int i=0;i<1<<m;i++) {
		int c=0;
		for(int j=0;j<m;j++) if(i>>j&1) c++;
		if(c==n) cs.push_back(i);
	}

	for(int d=0;d<30;d++) for(int i=0;i<1<<m;i++) for(int j=0;j<1<<m;j++) dist[d][i][j]=inf;

	for(auto i:cs) {
		int nx,mp=0;
		for(;;mp++) {
			if(i>>mp&1) break;
		}
		nx = (i ^ (1<<mp))>>1;
		for(int j=0;j<m-mp;j++) if(!(nx & 1<<(j+mp))) {
			int tmp=nx | 1<<(j+mp);
			dist[0][i][tmp]=min(dist[0][i][tmp],ma[j]);
		}
		if(mp!=0) dist[0][i][i>>1]=min(dist[0][i][1>>i],0ll);
	}

	for(int d=1;d<30;d++) for(auto i:cs) for(auto j:cs) for(auto k:cs) {
		dist[d][i][k]=min(dist[d][i][k],dist[d-1][i][j]+dist[d-1][j][k]);
	}
}

lli cur[1<<8];
set<int> tr,co;
map<int,lli> vtr;

void moX(lli d,int b) {
	lli tmp[1<<8];

	for(int di=0;d>>di;di++) {
		if(d>>di&1) {
			for(int i=0;i<1<<m;i++) tmp[i]=inf;
			for(auto i:cs) for(auto j:cs) {
				lli cost=cur[i]+dist[di][i][j];
				if(d==1 && di==0) {
					for(int k=0;k<m;k++) {
						if( (j>>k&1) && !(i>>(k+1)&1) && co.find(b+k)!=co.end() ) {
							cost += vtr[b+k];
						}
					}
				}
				tmp[j]=min(tmp[j],cost);
			}
			for(int i=0;i<1<<m;i++) cur[i]=tmp[i];
		}
	}
}
void solve() {
	for(int i=0;i<1<<m;i++) cur[i]=inf;
	cur[(1<<n)-1]=0;

	for(int i=0;i<t;i++) {
		co.insert(ta[i]); vtr[ta[i]]=tca[i];
		for(int j=max(1ll,ta[i]-m);j<=ta[i];j++) tr.insert(j);
	}
	tr.insert(l-n+1);

	int cp=1;
	for(auto &np:tr) {
		if(cp==np) continue;
		if(np>l-n+1) break;
		moX(np-cp,np);
		cp=np;
		
//		printf("#%d\n",np);
//		for(auto i:cs) {
//			printf("%d : %lld\n",i,cur[i]);
//		}
//		puts("");
	}
}

int main() {
	scanf("%d%d%d%d",&n,&m,&l,&t);
	for(int i=0;i<m;i++) scanf("%lld",ma+i);
	for(int i=0;i<t;i++) scanf("%lld%lld",ta+i,tca+i);
	for(int i=0;i<t;i++) tt[i]=pll(ta[i],tca[i]);
	sort(tt,tt+t);
	for(int i=0;i<t;i++) ta[i]=tt[i].first,tca[i]=tt[i].second;

	getDist();
	solve();
	printf("%lld\n",cur[(1<<n)-1]);

	return 0;
}