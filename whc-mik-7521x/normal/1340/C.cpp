#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],f[10005][1005],r,g;
void dfs(int x,int t,int tot){
	if(f[x][t]>tot)f[x][t]=tot;
	else return;
	if(t==0){
		dfs(x,g,tot+r);
		return;
	}
	if(x>1){
		if(a[x]-a[x-1]<=t)dfs(x-1,t-a[x]+a[x-1],tot+a[x]-a[x-1]);
	}
	if(x<m){
		if(a[x+1]-a[x]<=t)dfs(x+1,t-a[x+1]+a[x],tot+a[x+1]-a[x]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&g,&r);
	sort(a+1,a+m+1);
	memset(f,127,sizeof f);
	f[1][0]=0;
	deque<pair<int,int> >q;
	q.push_front(make_pair(1,0));
	while(q.size()){
		int u=q.front().first;
		int t=q.front().second;
		q.pop_front();
		if(t==0){
			f[u][g]=f[u][t]+1;
			q.push_back(make_pair(u,g));
			continue;
		}
		if(u>1){
			int tn=t-a[u]+a[u-1];
			if(tn>=0){
				if(f[u][t]<f[u-1][tn]){
					f[u-1][tn]=f[u][t];
					q.push_front(make_pair(u-1,tn));
				}
			}
		}
		if(u<m){
			int tn=t-a[u+1]+a[u];
			if(tn>=0){
				if(f[u][t]<f[u+1][tn]){
					f[u+1][tn]=f[u][t];
					q.push_front(make_pair(u+1,tn));
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<=g;i++)if(f[m][i]>0&&f[m][i]<(int)1e9)ans=min(ans,(f[m][i]-1)*(r+g)+(g-i));
	printf("%d",ans==1e9?-1:ans);
	return 0;
}