#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200005
#define W 20

int n,k,a[N];

int m,sum[N];

int val[N],tot;

std::vector<int> ver[N],b[N];

int f[N][W],g[N][W];

int ans,id;

int d[N];
inline void wr(int L,int R){
	printf("%d ",L%n);
	for(int i=L;i<=R;i++)
		printf("%d ",a[i]);
	puts("");
}
inline void sol(int L,int R){
//	printf("&%d %d\n",L,R);
//	for(int i=0;i<n+n;i++)
//		printf("%d ",d[i]);
//	puts("");
//	for(int i=0;i<n+n;i++)
//		printf("%d ",a[i]);
//	puts("");
	if(R-L+1<=k){
		for(int i=L;i<=R;i++){
			a[i]+=0-d[i];
			d[i]=0;
		}
		wr(R-k+1,R);
		return;
	}
	int s=0;
	for(int i=L;i<=L+k-1;i++)
		s+=d[i];
	if(s>=0){
		for(int i=L;i<L+k-1;i++){
			a[i]+=0-d[i];
			d[i]=0;
		}
		a[L+k-1]+=s-d[L+k-1];
		d[L+k-1]=s;
		wr(L,L+k-1);
		sol(L+k-1,R);
	}
	else{
		std::vector<int> e(k);
		for(int i=L;i<L+k-1;i++){
			e[i-L]=0-d[i];
			d[i]=0;
		}
		e[k-1]=s-d[L+k-1];
		d[L+k-1]=s;
		sol(L+k-1,R);
		for(int i=L;i<=L+k-1;i++)
			a[i]+=e[i-L];
		wr(L,L+k-1);
	}
//	printf("^%d %d\n",L,R);
//	for(int i=0;i<n+n;i++)
//		printf("%d ",a[i]);
//	puts("");
//	for(int i=0;i<n+n;i++)
//		printf("%d ",d[i]);
//	puts("");
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[n+i]=a[i];
		m+=a[i];
	}
	m/=n;
	for(int i=1;i<n+n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=0;i<n+n;i++){
		sum[i]-=i*m;
		val[++tot]=sum[i];
	}
//	for(int i=0;i<n+n;i++)
//		printf("%d ",sum[i]);
//	puts("");
	std::sort(val+1,val+tot+1);
	tot=std::unique(val+1,val+tot+1)-val-1;
	for(int i=0;i<n+n;i++){
		sum[i]=std::lower_bound(val+1,val+tot+1,sum[i])-val;
		ver[sum[i]].push_back(i);
	}
	for(int i=0;i<W;i++)
		for(int j=0;j<=n+n;j++)
			f[j][i]=n+n;
	ans=n;
	for(int o=1;o<=tot;o++){
		for(auto u:ver[o]){
			for(auto v:b[(u+k-2)%(k-1)]){
//				printf("$%d %d\n",v,u);
				f[v][0]=u;
				g[v][0]=(u-v-1)/(k-1);
			}
			b[(u+k-2)%(k-1)].clear();
			b[u%(k-1)].push_back(u);
		}
		for(auto u:ver[o])
			b[u%(k-1)].clear();
		for(int i=1;i<W;i++)
			for(auto u:ver[o]){
				f[u][i]=f[f[u][i-1]][i-1];
				g[u][i]=g[u][i-1]+g[f[u][i-1]][i-1];
			}
		for(auto u:ver[o]){
			if(u>=n)
				break;
			int r=u+n,tmp=0;
			for(int i=W-1;i>=0;i--)
				if(f[u][i]<=r){
					tmp+=g[u][i];
					u=f[u][i];
				}
//			printf("$%d %d %d %d\n",r-n,u,f[r-n][0],tmp);
			int len=r-u;
			if(len)
				tmp+=len<=k?1:(len-2)/(k-1)+1;
			if(tmp<=ans){
				ans=tmp;
				id=r-n;
			}
		}
	}
	printf("%d\n",ans);
//	printf("^%d\n",id);
	for(int i=0;i<n+n;i++)
		d[i]=a[i]-m;
	int u=id,r=u+n;
	while(f[u][0]<=r){
		if(u+1!=f[u][0])
			sol(u+1,f[u][0]);
		u=f[u][0];
	}
	if(u<r)
		sol(u+1,r);
}