#include<bits/stdc++.h>
#define N 200005

int n;

int b[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x;x-=lb(x))
		t[x]=std::max(t[x],d);
}
inline int sum(int x){
	int res=-0x3f3f3f3f;
	for(;x<=n;x+=lb(x))
		res=std::max(res,t[x]);
	return res;
}

int f[N];

int main(){
	scanf("%d",&n);
	memset(t,~0x3f,sizeof(t));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		f[i]=f[i-1];
		if(!b[x])
			b[x]=i;
		else{
			f[i]=std::max(f[i],i-b[x]-1+f[b[x]]);
			f[i]=std::max(f[i],i+sum(b[x]+1)-1);
			add(i,f[i]-i);
		}
	}
	printf("%d\n",f[n]);
}