#include<bits/stdc++.h>
#define N 200005

int T;

int n;

std::vector<int> V[N];

int a[N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline bool mrg(int u,int v){
	u=fnd(u),v=fnd(v);
	return u!=v?f[u]=v,1:0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			V[i].clear();
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			V[x].push_back(i);
		}
		for(int i=1;i<=n;i++)
			a[i]=0;
		bool flg=1;
		for(int i=1,t=0;i<=n;i++){
			int o=0;
			while(V[i].size()>1)
				a[o=++t]=V[i].back(),V[i].pop_back(),a[n-t+1]=V[i].back(),V[i].pop_back();
			if(V[i].size()){
				int mid=(n+1)>>1;
				if(!(n&1)||a[mid])
					flg=0;
				a[mid]=V[i].back();
				if(a[mid]==mid){
					if(!o)
						flg=0;
					std::swap(a[mid],a[o]);
				}
			}
		}
		puts(flg?"YES":"NO");
		if(!flg)
			continue;
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<=n;i++)
			mrg(i,a[i]);
		for(int i=1,j=n;i<j;i++,j--)
			if(mrg(i,j))
				std::swap(a[i],a[j]);
		for(int i=1,j=n;i<j;i++,j--)
			if(mrg(1,i))
				std::swap(a[i],a[j]),std::swap(a[1],a[i]),std::swap(a[j],a[n]);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
	}
}