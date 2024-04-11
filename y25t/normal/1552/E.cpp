#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 105

int n,k;

int lst[N];
std::vector<pii> a[N];

int b[N];

bool vis[N];

pii ans[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++){
		int x;
		scanf("%d",&x);
		if(lst[x])
			a[x].push_back(mp(i,lst[x]));
		lst[x]=i;
	}
	int m=(n+k-2)/(k-1);
	for(int i=0;i<k-1;i++){
		for(int j=1;j<=n;j++)
			b[j]=j;
		std::sort(b+1,b+n+1,[&](int x,int y){
			return mp(vis[x],a[x][i])<mp(vis[y],a[y][i]);
		});
		for(int j=1;j<=m;j++){
			if(vis[b[j]])
				continue;
			vis[b[j]]=1;
			ans[b[j]]=mp(a[b[j]][i].sec,a[b[j]][i].fir);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ans[i].fir,ans[i].sec);
}