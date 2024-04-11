#include<bits/stdc++.h>
#define ll long long
#define N 305

int T;

int n,m;
std::pair<int,int> a[N*N];

int b[N][N];

int t[N*N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=n*m;x+=lb(x))
		t[x]+=d;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res+=t[x];
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		std::sort(a+1,a+n*m+1);
		for(int i=1,lst=1;i<=n*m+1;i++)
			if(i==n*m+1||(i>1&&a[i].first!=a[i-1].first)){
				std::vector<std::pair<int,int>> v;
				for(int j=lst;j<i;j++)
					v.push_back({(j-1)/m+1,-((j-1)%m+1)});
				std::sort(v.begin(),v.end());
				int tmp=lst;
				for(auto [x,y]:v)
					b[x][-y]=a[tmp++].second;
				lst=i;
			}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=sum(b[i][j]);
				add(b[i][j],1);
			}
			for(int j=1;j<=m;j++)
				add(b[i][j],-1);
		}
		printf("%lld\n",ans);
	}
}