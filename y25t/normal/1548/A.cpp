#include<bits/stdc++.h>
#define N 200005

int n,m;

int cnt[N];

int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		cnt[std::min(u,v)]++;
	}
	for(int i=1;i<=n;i++)
		if(cnt[i])
			ans++;
	scanf("%d",&m);
	while(m--){
		int tp,u,v;
		scanf("%d",&tp);
		if(tp==3){
			printf("%d\n",n-ans);
			continue;
		}
		scanf("%d%d",&u,&v);
		int x=std::min(u,v);
		if(cnt[x])
			ans--;
		cnt[x]+=tp==1?1:-1;
		if(cnt[x])
			ans++;
	}
}