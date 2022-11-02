#include<bits/stdc++.h>
using namespace std;
const int N=1000005,ycl[7]={2,3,5,7,11,13,17},MX=10,JJ=300,JB=900;
int y1[N],y2[N],f[N],id[N],t1,t2,dist[JJ][JB],g[JJ][JJ];
map<int,int> M;
vector<int> v[N];
void dfs(int p,int cs,int s,int t,int m1,int m2){
	if(!y1[s])y1[s]=++t1; if(!y2[t])y2[t]=++t2;
	if(dist[y1[s]][y2[t]]<=cs)return;
	if(p==7){
		s=y1[s]; t=y2[t]; dist[s][t]=min(dist[s][t],cs);
		return;
	}
	for(int i=0;i<=m1;i++)if(s<=1000000){
		for(int j=0;j<=MX-cs+i&&j<=m2;j++)if(cs+abs(i-j)<=MX){
			dfs(p+1,cs+abs(j-i),s,t*(j+1),i,j);
		}
		s=s*ycl[p];
	}
}
signed main(){
	for(int i=0;i<JJ;i++)for(int j=0;j<JB;j++)dist[i][j]=100;
	for(int i=2;i<N;i++)f[i]=i; id[1]=1;
	for(int i=2;i<N;i++){
		if(f[i]>1)for(int j=i;j<N;j+=i)if(f[j]%i==0){
			int s=1;
			while(f[j]%i==0){
				f[j]/=i; s++;
			}
			v[j].push_back(s);
		}
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
		id[i]=1; 
		for(unsigned j=0;j<v[i].size();j++){
			for(int k=1;k<v[i][j];k++)id[i]*=ycl[j];
		}
	}
	dfs(0,0,1,1,100,100);
	int T; scanf("%d",&T);
	memset(g,-1,sizeof(g));
	while(T--){
		int a,b,ans=100;  scanf("%d%d",&a,&b);
		a=y1[id[a]]; b=y1[id[b]]; if(a>b)swap(a,b);
		if(g[a][b]!=-1){
			printf("%d\n",g[a][b]); continue;
		}
		for(int i=1;i<=t2;i++)ans=min(dist[a][i]+dist[b][i],ans);
		printf("%d\n",g[a][b]=ans);//(g[a][b]=ans);
	}
}