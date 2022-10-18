#include<bits/stdc++.h>
#define N 200005

int T;

int n,m;

int f[N<<1];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline void mrg(int u,int v){
	u=fnd(u),v=fnd(v);
	if(u!=v)
		f[u]=v;
}

int a[N],b[N],c[N];

int d[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n+n;i++)
			f[i]=0;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(c[i]==-1)
				continue;
			if(__builtin_parity(c[i]))
				mrg(a[i],b[i]+n),mrg(a[i]+n,b[i]);
			else
				mrg(a[i],b[i]),mrg(a[i]+n,b[i]+n);
		}
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(__builtin_parity(w))
				mrg(u,v+n),mrg(u+n,v);
			else
				mrg(u,v),mrg(u+n,v+n);
		}
		bool flg=1;
		for(int i=1;i<=n;i++)
			if(fnd(i)==fnd(i+n)){
				flg=0;
				break;
			}
		if(!flg)
			puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)
				d[i]=fnd(i)<fnd(i+n);
			for(int i=1;i<n;i++)
				printf("%d %d %d\n",a[i],b[i],c[i]==-1?d[a[i]]^d[b[i]]:c[i]);
		}
	}
}