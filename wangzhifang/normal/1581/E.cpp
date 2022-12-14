#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
#define max_m 200000
#define max_lim 2000
int x[max_n+1],y[max_n+1],pos[max_n+1];
int tr[max_lim+1][max_lim+1];
int trr[max_m+1];
int vis[max_lim+1];
#define lowbit(x) ((x)&-(x))
void update(int*tr,int pos,ci val,ci siz){
//	printf("update %d %d\n",pos,val);
	for(; pos<=siz; pos+=lowbit(pos))
		tr[pos]+=val;
}
int query(int*tr,int pos){
//	printf("query %d\n",pos);
	int ret=0;
	for(; pos; pos&=pos-1)
		ret+=tr[pos];
	return ret;
}
il void test(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int lim=sqrt(m*log(m));
	for(int i=1; i<=n; ++i)
		scanf("%d%d",x+i,y+i);
	for(int i=1,op,k; i<=m; ++i){
		scanf("%d%d",&op,&k);
		int d=x[k]+y[k];
		if(op==1){
			pos[k]=i;
			if(d<=lim){
				++vis[d];
				int l=(i+x[k])%d+1,r=(i+x[k]+y[k]-1)%d+1;
				if(l>r){
					for(int i=1; i<=r; ++i)
						++tr[d][i];
					for(int i=l; i<=d; ++i)
						++tr[d][i];
				}
				else{
					for(int i=l; i<=r; ++i)
						++tr[d][i];
				}
			}
			else{
				for(int l=i+x[k]; l<=m; l+=d){
					int r=l+y[k];
					if(r<=i)
						continue;
					if(r>m){
						update(trr,l,1,m);
						break;
					}
					update(trr,l,1,m);
					update(trr,r,-1,m);
				}
			}
		}
		else{
			if(d<=lim){
				--vis[d];
				int i=pos[k];
				int l=(i+x[k])%d+1,r=(i+x[k]+y[k]-1)%d+1;
				if(l>r){
					for(int i=1; i<=r; ++i)
						--tr[d][i];
					for(int i=l; i<=d; ++i)
						--tr[d][i];
				}
				else{
					for(int i=l; i<=r; ++i)
						--tr[d][i];
				}
			}
			else{
				for(int l=pos[k]+x[k]; l<=m; l+=d){
					int r=l+y[k];
					if(r<=i)
						continue;
					if(r>m){
						update(trr,l,-1,m);
						break;
					}
					update(trr,l,-1,m);
					update(trr,r,1,m);
				}
			}
		}
		int ans=query(trr,i);
		for(int d=1; d<=lim; ++d)
			if(vis[d])
				ans+=tr[d][i%d+1];
		printf("%d\n",ans);
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}