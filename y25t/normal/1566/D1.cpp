#include<bits/stdc++.h>
#define N 305

int T;

int n,m;
std::pair<int,int> a[N];

int b[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x){
	for(;x<=m;x+=lb(x))
		t[x]++;
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
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i].first);
			a[i].second=-i;
		}
		std::sort(a+1,a+m+1);
		for(int i=1;i<=m;i++)
			b[-a[i].second]=i;
		for(int i=1;i<=m;i++)
			t[i]=0;
		int ans=0;
		for(int i=1;i<=m;i++){
			ans+=sum(b[i]);
			add(b[i]);
		}
		printf("%d\n",ans);
	}
}