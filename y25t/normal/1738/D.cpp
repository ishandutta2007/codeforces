#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N],k;

int b[N],c[N];

std::vector<int> E[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		b[0]=n+1;
		for(int i=1;i<=n;i++)
			b[i]=std::min(b[i-1],a[i]);
		c[n+1]=0;
		for(int i=n;i;i--)
			c[i]=std::max(c[i+1],a[i]);
		for(k=0;k<=n;k++) if(b[k]>k&&c[k+1]<=k)
			break;
		for(int i=0;i<=n+1;i++)
			E[i].clear();
		for(int i=1;i<=n;i++)
			E[a[i]].emplace_back(i);
		std::vector<int> ans,V({0,n+1});
		while(V.size()){
			for(int i=0;i<(int)V.size();i++) if(E[V[i]].size())
				std::swap(V[i],V.back());
			for(auto i:V) if(i&&i<=n)
				ans.emplace_back(i);
			V=E[V.back()];
		}
		printf("%d\n",k);
		for(auto i:ans)
			printf("%d ",i);
		puts("");
	}
}