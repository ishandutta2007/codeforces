#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,a[5050],b[5050];

// Stock Price = a_i*t + b_i
#define maxv 13232
namespace MaxFlow{
#define pb push_back
#define inf 0x3f3f3f3f
	int m,n,s,t,u,v,ca,co;
	int mm,mf;
	int dist[maxv],inq[maxv],prevv[maxv],preve[maxv];
	struct edge{int to,ca,cost,rev;};
	vector<edge> G[maxv];
	void add_edge(int u,int v,int ca,int co){
		G[u].pb((edge){v,ca,co,(int)G[v].size()});
		G[v].pb((edge){u,0,-co,(int)G[u].size()-1});
	}
	void run(){
		while(1){
			deque<int> que;
			memset(dist, inf , sizeof(dist));
			memset(inq,0,sizeof(inq));
			dist[s] = 0;
			que.push_back(s);
			inq[s] = 1;
			while(!que.empty() && dist[t] >1){
				int cur = que.front();
				que.pop_front();
				inq[cur] = 0;
				for(int i=0;i<G[cur].size();i++){
					edge cw = G[cur][i];
					if(cw.ca<=0)continue;
					if(dist[cw.to]>cw.cost+dist[cur]){
						dist[cw.to] = cw.cost+dist[cur];
						prevv[cw.to] = cur;
						preve[cw.to] = i;
						if(!inq[cw.to]){
							if(que.empty() || dist[cw.to]>dist[que.front()]){
								que.push_back(cw.to);
							}else{
								que.push_front(cw.to);
							}
							if(que.size()>2 && dist[que.front()]>dist[que.back()]){
								int cc = que.front(),dd = que.back();
								que.pop_front();
								que.pop_back();
								que.push_front(dd);
								que.push_back(cc);
							}
							inq[cw.to] = 1;
						}
					}
				}
			}
			if(dist[t]==inf)break;
			int md = inf,di = 0;
			for(int p = t;p!=s;p = prevv[p]){
				md = min(md,G[prevv[p]][preve[p]].ca);
				di += G[prevv[p]][preve[p]].cost;
			}
			mm+=di*md;
			mf+=md;
			for(int p = t;p!=s;p = prevv[p]){
				G[prevv[p]][preve[p]].ca-=md;
				G[G[prevv[p]][preve[p]].to][G[prevv[p]][preve[p]].rev].ca+=md;
			}
		}
	}
	void clear(){
		mm = mf = 0;
		for(int i=0;i<maxv;i++)G[i].clear();
	}
	int id(int layer,int x){
		if(layer == 1)return x;
		return (layer-1)*2*n-n+x;
	}
	
	bool ok(int T){
		clear();
		s = 13230;
		t = 13231;
		n = ::n;
		for(int i=0;i<n;i++)
			add_edge(s,id(1,i),1,0);
		for(int i=0;i<n;i++)
			add_edge(id(4,i),t,1,0);
		vector<pii> V2,V3;
		for(int i=0;i<2*n;i++){
			V2.push_back(make_pair(b[i],i));
			V3.push_back(make_pair(1ll*a[i]*T+b[i],i));
		}
		sort(V2.begin(),V2.end());
		sort(V3.begin(),V3.end());
		for(int i=1;i<n*2;i++){
			add_edge(id(2,V2[i].second),id(2,V2[i-1].second),30000,0);
			add_edge(id(3,V3[i].second),id(3,V3[i-1].second),30000,0);
		}
		for(int i=0;i<n;i++){
			int cp = lower_bound(V2.begin(),V2.end(),make_pair(b[i]+1ll,-1ll))-V2.begin()-1;
			cp = V2[cp].second;
			add_edge(id(1,i),id(2,cp),1,1);
			cp = lower_bound(V3.begin(),V3.end(),make_pair(1ll*a[i]*T+b[i]+1,-1ll))-V3.begin()-1;
			cp = V3[cp].second;
			add_edge(id(1,i),id(3,cp),1,1);
		}
		for(int i=0;i<2*n;i++){
			int cp = lower_bound(V3.begin(),V3.end(),make_pair(1ll*a[i]*T+b[i]+1,-1ll))-V3.begin()-1;
			cp = V3[cp].second;
			add_edge(id(2,i),id(3,cp),30000,1);
		}
		for(int i=0;i<n;i++){
			add_edge(id(2,n+i),id(4,i),1,0);
			add_edge(id(3,n+i),id(4,i),1,0);
		}
		run();
		return mf == n;
	}
}

namespace MaxFlowez{
	int cnt[5050] = {0};
	bool ok(int T){
		memset(cnt,0,sizeof(cnt));
		vector<pii> V,V2;
		for(int i=0;i<2*n;i++){
			V.push_back(make_pair(1ll*a[i]*T+b[i],i));
			V2.push_back(make_pair(b[i],1ll*a[i]*T+b[i]));
		}
		sort(V.begin(),V.end());
		sort(V2.begin(),V2.end());
		for(int i=1;i<n*2;i++){
			V2[i].second = max(V2[i].second,V2[i-1].second);
		}
		for(int i=0;i<n;i++){
			ll cmx = V2[lower_bound(V2.begin(),V2.end(),make_pair(b[i]+1ll,-1ll))-V2.begin()-1].second;
			int cp = lower_bound(V.begin(),V.end(),make_pair(cmx+1ll,-1ll))-V.begin()-1;
			cnt[cp]+=1;
		}
		for(int i=n*2-1;i>=0;i--){
			if(V[i].second>=n){
				cnt[i]-=1;
				if(cnt[i]<0)return 0;
			}
			if(i)cnt[i-1]+=cnt[i];
		}
		return 1;
	}
}


int main() {
	read(n);
	for(int i=0;i<n*2;i++){
		read(a[i]);read(b[i]);
	}
	int l = -1,r = 1e9+7;
	while(l+1!=r){
		int mid = (l+r)/2;
		if(MaxFlowez::ok(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	if(r == 1e9+7){
		cout<<"-1"<<endl;
		return 0;
	}
	MaxFlow::ok(r);
	cout<<r<<' '<<MaxFlow::mm<<endl;
	return 0;
}