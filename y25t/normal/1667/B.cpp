#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define N 500005

int T;

int n,a[N];

ll s[N],val[N];
int tot;

int f[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=tot;x+=lb(x))
		t[x]=std::max(t[x],d);
}
inline int sum(int x){
	int res=-inf;
	for(;x;x-=lb(x))
		res=std::max(res,t[x]);
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s[i]=s[i-1]+a[i],val[i]=s[i];
		val[n+1]=0;
		std::sort(val+1,val+n+2),tot=std::unique(val+1,val+n+2)-val-1;
		for(int i=1;i<=tot;i++)
			t[i]=-inf;
		for(int i=0;i<=n;i++)
			s[i]=std::lower_bound(val+1,val+tot+1,s[i])-val;
		f[0]=0,add(s[0],f[0]);
		for(int i=1;i<=n;i++){
			f[i]=std::max(sum(s[i]-1)+i,f[i-1]-(a[i]<0));
			add(s[i],f[i]-i);
		}
		printf("%d\n",f[n]);
	}
}