#include<bits/stdc++.h>
#define N 200005

int T;

int n,x,p[N],q[N];

int d[N];

bool vis[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			d[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			d[u]++,d[v]++;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]),q[p[i]]=i,cnt+=p[i]!=i;
		if(!cnt||(cnt==2&&p[x]==x)){
			puts("Alice");
			continue;
		}
		int y=0;
		for(int i=1;i<=n;i++) if(d[i]>1)
			y=y?-1:i;
		if(y==-1){
			puts("Alice");
			continue;
		}
		if(p[y]!=y&&(x==y||x==p[y])){
			puts("Bob");
			continue;
		}
		int t=n&1;
		if(p[y]!=y)
			std::swap(p[q[y]],p[y]);
		else if(x!=y)
			t^=1;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++) if(i!=y&&!vis[i]){
			t^=1;
			for(int j=i;!vis[j];j=p[j])
				vis[j]=1;
		}
		puts(t?"Bob":"Alice");
	}
}