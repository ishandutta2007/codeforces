#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,T,ans;
int a[maxn],cnt[maxn],mx[maxn][maxn],f[maxn];
vector<int>w[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			w[i].push_back(0);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),w[a[i]].push_back(i);
		for(int i=1;i<=n;i++){
			int now=0;
			for(int j=i;j<=n;j++)
				cnt[a[j]]++,now=max(now,cnt[a[j]]),mx[i][j]=now;
			for(int j=i;j<=n;j++)
				cnt[a[j]]--;
		}
		for(int v=1;v<=n;v++){
			if(w[v].size()>1){
				w[v].push_back(n+1);
				for(int i=1;i<w[v].size();i++){
					int p=w[v][i];
					f[i]=-1e9;
					for(int j=0;j<i;j++){
						int q=w[v][j];
						f[i]=max(f[i],f[j]+1-((q-p-1)&1)-max(0,mx[q+1][p-1]-(p-q-1-mx[q+1][p-1])));
					}
				}
				ans=max(ans,f[w[v].size()-1]-1);
			}
			w[v].clear();
		}
		printf("%d\n",ans);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				mx[i][j]=0;
	}
	return 0;
}
//