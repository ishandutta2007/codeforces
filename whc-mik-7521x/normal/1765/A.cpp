#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int n,m,pd[N],vis[N],deg[N],num[N],res[N],val[N][N],bel[N];
vector<int>g[N];
bitset<N>a[N];
bool dfs(int v){
	if(vis[v])return 0;
	vis[v]=1;
	for(int x:g[v]){
		if(pd[x]==-1||dfs(pd[x])){
			pd[x]=v;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		string S;
		cin>>S;
		for(int o=0;o<m;o++)a[o][i]=(S[o]=='1');
	}
	for(int i=0;i<m;i++)bel[i]=1e6;
	for(int i=0;i<m;i++){
		for(int o=0;o<m;o++){
			if(a[i]==a[o]){
				int k=min(i,o);
				bel[i]=min(bel[i],k);
				bel[o]=min(bel[o],k);
				continue;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int o=0;o<m;o++){
			if(bel[i]==i&&bel[o]==o&&i!=o&&(a[i]&a[o])==a[o]){
				g[i].push_back(o);
			}
		}
	}
	int ans=0,cnt=0;
	for(int i=0;i<m;i++)pd[i]=-1;
	for(int i=0;i<m;i++)if(bel[i]==i){
		ans+=dfs(i);
		++cnt;
		for(int o=0;o<m;o++)vis[o]=0;
	}
	int k=cnt-ans;
	for(int i=0;i<m;i++)if(bel[i]==i&&pd[i]!=-1)deg[pd[i]]++;
	int sum=0;
	for(int i=0;i<m;i++)if(bel[i]==i&&!deg[i]){
		int x=i;
		vector<int>v;
		while(x!=-1){
			v.push_back(x);
			x=pd[x];
		}
		++sum;
		for(int x:v)num[x]=sum;
		bitset<N>t;
		int c=0;
		for(int x:v){
			a[x]^=t;res[x]=1e6-c+1;
			for(int o=0;o<n;o++)if(a[x][o])val[o][sum]=1e6-c;
			++c;t|=a[x];
		}
	}
	printf("%d\n",k);
	for(int i=0;i<m;i++)printf("%d ",num[bel[i]]);puts("");
	for(int i=0;i<m;i++)printf("%d ",res[bel[i]]);puts("");
	for(int i=0;i<n;i++){for(int o=1;o<=k;o++)printf("%d ",val[i][o]+1);puts("");}
}