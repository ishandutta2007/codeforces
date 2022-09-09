#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int inf=1e9+7;
vector<int> dist;
vector<bool> good;
int main(){
	dist.pb(0);
	good.pb(false);
	queue<int> q;
	q.push(0);
	int cnt=0,mxd=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		bool ok=true;
		for(int i=u-49;i>=0;i-=49)if(dist[i]<=dist[u])ok=false;
		if(!ok)continue;
		cnt++;
		good[u]=true;
		mxd=max(mxd,dist[u]);
		for(int d:{4,9}){
			int v=u+d;
			while(dist.size()<=v){
				dist.pb(inf);
				good.pb(false);
			}
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	//printf("%i %i %i\n",dist.size(),cnt,mxd);
	int n;scanf("%i",&n);
	ll ans=(ll)max(0,n-12+1)*cnt;
	for(int i=max(0,n-11);i<=n;i++){
		for(int j=0;j<dist.size();j++){
			if(good[j]){
				if(dist[j]<=n-i)ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}