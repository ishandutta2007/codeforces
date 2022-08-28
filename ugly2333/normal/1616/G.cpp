//CF1616G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 555555;
int n,m,a[N],b[N],c[N],s[N],d[N][2],e[2][2];
vector<int> v1[N],v2[N];
void dfs1(int u,int o){
	if(d[u][o])
		return;
	d[u][o]=1;
	int i,x;
	for(i=0;i<v1[u].size();i++){
		x=v1[u][i];
		dfs1(x,o^1);
	}
}
void dfs2(int u,int o){
	if(d[u][o])
		return;
	d[u][o]=1;
	int i,x;
	for(i=0;i<v2[u].size();i++){
		x=v2[u][i];
		dfs2(x,o^1);
	}
}
int main()
{
	int T,i,j,k,x,y;
	LL ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",a+i,b+i);
		for(i=1;i<=n;i++)
			m++,a[m]=0,b[m]=i;
		for(i=1;i<=n;i++)
			m++,a[m]=i,b[m]=n+1;
		for(i=0;i<=n;i++)
			c[i]=1;
		for(i=1;i<=m;i++)
			if(a[i]==b[i]-1)
				c[a[i]]=0;
		s[0]=c[0];
		for(i=1;i<=n;i++)
			s[i]=s[i-1]+c[i];
		if(s[n]==0){
			printf("%lld\n",(LL)n*(n-1)/2);
			continue;
		}
		for(i=1;i<=m;i++){
			if(a[i]<b[i]-1&&s[a[i]]==s[b[i]-2]){//cout<<a[i]<<' '<<b[i]-1<<endl;
				v1[a[i]].push_back(b[i]-1);
				v2[b[i]-1].push_back(a[i]);
			}
		}
		x=n+1,y=0;
		for(i=1;i<=n;i++)
			if(c[i])
				x=min(x,i),y=max(y,i);//cout<<x<<' '<<y<<endl;
		dfs1(x,0);
		d[x][0]=0;
		dfs2(x,0);
		for(i=0;i<=x;i++)
			e[d[i][0]][d[i][1]]++;
		ans=0;
		for(i=y;i<=n;i++){
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
					if((j&&d[i][0])||(k&&d[i][1]))
						ans+=e[j][k];
		}
		if(x==y)
			ans--;
		printf("%lld\n",ans);
		for(i=0;i<=n+1;i++){
			v1[i].clear();
			v2[i].clear();
		}
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
	}
	return 0;
}