#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=(1<<16)|5;
vector<int> e[N];
int dis[N],tg[N],q[N];
int n,ans[N],p[N];
void solve(){
	scanf("%d",&n);
	for (int i=0;i<1<<n;i++)
		e[i].resize(0);
	for (int i=0;i<n*(1<<(n-1));i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i=0;i<1<<n;i++)
		dis[i]=0,tg[i]=0;
	int h=0,t=0;
	dis[0]=1;
	for (int i=0;i<e[0].size();i++){
		tg[e[0][i]]=1<<i;
		q[++t]=e[0][i];
		dis[e[0][i]]=1;
	}
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]){
			if (!dis[i]){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
			if (dis[i]==dis[x]+1)
				tg[i]|=tg[x];
		}
	}
	for (int i=0;i<1<<n;i++) p[tg[i]]=i;
	for (int i=0;i<1<<n;i++)
		printf("%d ",p[i]);
	puts("");
	if (n!=(n&(-n)))
		puts("-1");
	else{
		for (int i=0;i<1<<n;i++){
			int s=0;
			for (int j=0;j<n;j++)
				if (tg[i]&(1<<j)) s^=j;
			printf("%d ",s);
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1:0 0
2:0 0 1 1
4:0 0 1 1 1 

*/