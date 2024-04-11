#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int deg[N],dep[N];
vector<int> E[N];
bool was[N];
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		for(int i=1;i<=n;i++)E[i].clear(),deg[i]=0,dep[i]=1,was[i]=false;
		for(int i=1;i<=n;i++){
			scanf("%i",&deg[i]);
			for(int j=1;j<=deg[i];j++){
				int a;scanf("%i",&a);
				E[a].push_back(i);

			}
		}
		deque<int> que;
		for(int i=1;i<=n;i++)if(deg[i]==0)que.push_back(i);
		while(!que.empty()){
			int i=que[0];
			was[i]=true;
			for(int j:E[i]){
				dep[j]=max(dep[j],dep[i]+(j<i?1:0));
				deg[j]--;
				if(deg[j]==0)que.push_back(j);
			}
			que.pop_front();
		}
		int mx=1;
		bool valid=true;
		for(int i=1;i<=n;i++){
			mx=max(mx,dep[i]);
			if(!was[i])valid=false;
		}
		printf("%i\n",(valid?mx:-1));
	}
	return 0;
}