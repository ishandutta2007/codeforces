#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> G[100100];
int req[100100];
int cnt[100100];
int N,M;
vector<int> vs;
int K;

vector<int> res;

queue<int> que;
bool flg[100100];

bool check(double r){
	for(int i=0;i<N;i++){
		req[i]=G[i].size()*(1.0-r);
		flg[i]=false;
		cnt[i]=0;
	}
	while(!que.empty()) que.pop();
	for(int i=0;i<vs.size();i++){
		que.push(vs[i]);
		flg[vs[i]]=true;
	}
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i];
			if(flg[u]) continue;
			cnt[u]++;
			if(cnt[u]>req[u]){
				flg[u]=true;
				que.push(u);
			}
		}
	}
	bool ok=false;
	for(int i=0;i<N;i++) if(!flg[i]) ok=true;
	return ok;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<K;i++){
		int v;
		scanf("%d",&v);
		vs.push_back(v-1);
	}
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	double lb=0,ub=1;
	for(int stage=0;stage<100;stage++){
		double mid=(ub+lb)/2;
		bool ok=check(mid);
		if(ok){
			lb=mid;
			res.clear();
			for(int i=0;i<N;i++){
				if(!flg[i]) res.push_back(i);
			}
		}else{
			ub=mid;
		}
	}
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++){
		printf("%d%c",res[i]+1,i+1==res.size()?'\n':' ');
	}
	return 0;
}