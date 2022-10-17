#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=200005;
int n,T,ps,qs;
int col[maxn],tot[2],now[maxn],lg[maxn],mx[maxn];
vector<int>v[maxn],p,q;
void dfs(int x,int last){
	col[x]=col[last]^1,tot[col[x]]++;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last)
			dfs(v[x][i],x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			puts("1");
			continue;
		}
		for(int i=1,x,y;i<n;i++)
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		tot[0]=tot[1]=0,dfs(1,0);
		for(int i=1;i<=n;i++){
			lg[i]=lg[i>>1]+1,mx[lg[i]]=i;
			if(now[lg[i]]==0)
				now[lg[i]]=i;
		}
		if(tot[0]>tot[1]){
			for(int i=1;i<=n;i++)
				col[i]^=1;
			swap(tot[0],tot[1]);
		}
		for(int i=1;i<=lg[n];i++){
			if((tot[0]>>(i-1))&1)
				p.push_back(i);
			else q.push_back(i);
		}
		ps=qs=0;
		for(int i=1;i<=n;i++){
			int w;
			if(col[i]==0){
				w=now[p[ps]],now[p[ps]]++;
				if(now[p[ps]]>mx[p[ps]])
					ps++;
			}
			else{
				w=now[q[qs]],now[q[qs]]++;
				if(now[q[qs]]>mx[q[qs]])
					qs++;
			}
			printf("%d%c",w,i==n? '\n':' ');
		}
		p.clear(),q.clear();
		for(int i=1;i<=n;i++)
			v[i].clear(),now[i]=mx[i]=0;
	}
	return 0;
}