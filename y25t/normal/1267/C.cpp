#include<bits/stdc++.h>
#define N 2005

int n,m,d[N];

int a[N],b[N];
std::vector<std::pair<int,int>> E;
std::vector<int> V[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]),m+=d[i];
	m=m/2-n+1;
	if(m<0||m>(n-1)/2)
		return puts("-1"),0;
	E.clear();
	for(int i=1;i<=m;i++)
		a[i]=2,b[i]=0,V[i].clear();
	while(1){
		int o=0;
		for(int i=1;i<=n;i++)
			if(d[i]==2)
				o=i;
		if(o){
			int x=0;
			for(int i=1;i<=m;i++)
				if(!b[i]&&a[i]>0&&(!x||a[i]<a[x]))
					x=i;
			if(!x)
				for(int i=1;i<=m;i++)
					if(!b[i]&&(!x||a[i]>a[x]))
						x=i;
			if(x){
				d[o]-=2,a[x]--,V[x].push_back(o);
				continue;
			}
		}
		for(int i=1;i<=n;i++)
			if(d[i]==1)
				o=i;
		if(o){
			int x=0;
			for(int i=1;i<=n;i++)
				if(d[i]>2&&(d[i]&1)&&(!x||d[i]<d[x]))
					x=i;
			if(!x)
				for(int i=1;i<=n;i++)
					if(d[i]>1&&(!x||d[i]<d[x]))
						x=i;
			if(!x)
				for(int i=1;i<=n;i++)
					if(i!=o&&d[i]==1)
						x=i;
			if(x){
				d[o]--,d[x]--,E.emplace_back(o,x);
				continue;
			}
		}
		for(int i=1;i<=m;i++)
			if(!b[i]&&a[i]<=0&&(!o||a[i]>a[o]))
				o=i;
		if(!o)
			break;
		int x=0;
		for(int i=1;i<=n;i++)
			if(d[i]>2&&(!x||d[i]<d[x]))
				x=i;
		if(!x)
			for(int i=1;i<=n;i++)
				if(d[i]==2)
					x=i;
		if(x)
			b[o]=1,d[x]-=2,V[o].push_back(x);
		else
			break;
	}
	for(int i=1;i<=n;i++)
		if(d[i])
			return puts("-1"),0;
	for(int i=1;i<=m;i++)
		if(a[i]>0||(a[i]==0&&!b[i]))
			return puts("-1"),0;
	printf("%d\n",(int)E.size()+m);
	for(auto [x,y]:E)
		printf("2 %d %d\n",x,y);
	for(int i=1;i<=m;i++){
		printf("%d %d ",(int)V[i].size()+1,V[i].back());
		for(auto x:V[i])
			printf("%d ",x);
		puts("");
	}
}