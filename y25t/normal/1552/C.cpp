#include<bits/stdc++.h>
#define N 105

int T;

int n,k;

bool b[N<<1];

std::vector<int> a;

int e[N][2];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n+n;i++)
			b[i]=0;
		a.clear();
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u>v)
				std::swap(u,v);
			e[i][0]=u,e[i][1]=v;
			b[u]=b[v]=1;
		}
		for(int i=1;i<=n+n;i++)
			if(!b[i])
				a.push_back(i);
		for(int i=k+1;i<=n;i++)
			e[i][0]=a[i-k-1],e[i][1]=a[i-k-1+n-k];
//		for(int i=1;i<=n;i++)
//			printf("&%d %d\n",e[i][0],e[i][1]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(!(e[i][1]<e[j][0]||e[j][1]<e[i][0])&&(e[i][0]-e[j][0])*(e[i][1]-e[j][1])>0)
//					printf("#%d %d %d %d\n",e[i][0],e[i][1],e[j][0],e[j][1]),
					ans++;
		printf("%d\n",ans);
	}
}