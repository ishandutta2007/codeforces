#include<bits/stdc++.h>

using namespace std;

const int maxn=1027;

int n,m;
int u[maxn],c[maxn],d[maxn],idx[maxn],idx_t[maxn];

int get_val(){
	int val=0,k;
	scanf("%d",&k);
	for (int j=1;j<=k;++j){
		int u;
		scanf("%d",&u);
		val+=(1<<u-1); 
	}
	return val;	
}
int main(){
	memset(u,0,sizeof(u));
	scanf("%d%d",&n,&m);
	for (int i=0;i<maxn;++i){
		c[i]=-1;
		d[i]=-1;
	}
	for (int i=1;i<=n;++i){
		int val=get_val();
		u[val]++;
	}
	for (int i=1;i<=m;++i){
		int cost;
		scanf("%d",&cost);
		int val=get_val();
		if (c[val]==-1){
			c[val]=cost;
			idx[val]=i;
		}
		else{
			if (c[val]>cost){
				d[val]=c[val];
				idx_t[val]=idx[val];
				c[val]=cost;
				idx[val]=i;
			}
			else{
				if (d[val]==-1||d[val]>cost){
					d[val]=cost;
					idx_t[val]=i;
				}
			}
		}
	}
	int ans=-1,cost=2e9,x=-1,y=-1;
	for (int i=1;i<(1<<9);++i){
		for (int j=1;j<=i;++j){
			if (i==j){
				if (d[i]==-1) continue;
				int val=i,ret=0;
				for (int k=1;k<(1<<9);++k){
					if ((val|k)==val){
						ret+=u[k];
					}
				}
				if (ret>ans||(ret==ans&&c[i]+d[j]<cost)){
					cost=c[i]+d[j];
					ans=ret;
					x=idx[i],y=idx_t[j];
				}
				continue; 
			} 
			if (c[i]==-1||c[j]==-1) continue;
			int val=i|j,ret=0;
			for (int k=1;k<(1<<9);++k){
				if ((val|k)==val){
					ret+=u[k];
				}
			}
			if (ret>ans||(ret==ans&&c[i]+c[j]<cost)){
				cost=c[i]+c[j];
				ans=ret;
				x=idx[i],y=idx[j];
			} 
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}