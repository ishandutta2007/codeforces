#include<bits/stdc++.h>
#define ll long long
#define N 300005

int n,a[N];

ll t[2][N];
inline int lb(int x){
	return x&-x;
}
inline void add(int tp,int x,int d){
	for(;x<=(int)3e5;x+=lb(x))
		t[tp][x]+=d;
}
inline ll sum(int tp,int x){
	ll res=0;
	for(;x;x-=lb(x))
		res+=t[tp][x];
	return res;
}

ll ans,s;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=s+1ll*a[i]*(i-1)-sum(1,a[i]);
		for(int j=1;j*a[i]<=(int)3e5;j++){
			ans-=1ll*a[i]*(i-1-sum(0,j*a[i]-1));
			add(1,j*a[i],a[i]);
		}
		s+=a[i];
		add(0,a[i],1);
		printf("%lld ",ans);
	}
	puts("");
}