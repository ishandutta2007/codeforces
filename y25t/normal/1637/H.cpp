#include<bits/stdc++.h>
#define ll long long
#define N 500005

int T;

int n,a[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x){
	for(;x;x-=lb(x))
		t[x]++;
}
inline int sum(int x){
	int res=0;
	for(;x<=n;x+=lb(x))
		res+=t[x];
	return res;
}

int d[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ll res=0;
		for(int i=1;i<=n;i++)
			t[i]=0;
		for(int i=1;i<=n;i++){
			int x=sum(a[i]);
			d[i]=i-1-2*x;
			res+=x;
			add(a[i]);
		}
		for(int i=1;i<=n;i++)
			t[i]=0;
		for(int i=n;i;i--){
			d[i]+=2*(n-i-sum(a[i]));
			add(a[i]);
		}
		std::sort(d+1,d+n+1);
		printf("%lld ",res);
		for(int i=1;i<=n;i++){
			res+=d[i]-i+1;
			printf("%lld ",res);
		}
		puts("");
	}
}