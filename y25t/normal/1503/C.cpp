#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define N 100005

ll n,a[N],c[N];

ll p[N],q[N];
inline bool cmp1(int x,int y){
	return a[x]<a[y];
}
inline bool cmp2(int x,int y){
	return c[x]<c[y];
}

ll f[N],g[N];

std::vector<int> v;

bool vis[N];

ll ans;

int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&c[i]);
		c[i]+=a[i];
		ans+=c[i];
		p[i]=q[i]=i;
	}
	std::sort(p+1,p+n+1,cmp1);
	std::sort(q+1,q+n+1,cmp2);
//	for(int i=1;i<=n;i++)
//		printf("^%d %d %d %d\n",p[i],q[i],a[p[i]],c[q[i]]);
//	for(int i=n;i;i--)
//		if(p[i]==q[i]){
//			if(i>1)
//				std::swap(q[i],q[i-1]);
//			else
//				std::swap(q[i],q[i+1]);
//		}
	for(int i=1;i<=n;i++){
		f[p[i]]=i;
		g[q[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		for(int j=g[q[i]];j!=i;j=g[q[j]])
			printf("*%d %d\n",i,j),
			vis[j]=1;
		v.push_back(i);
//		if(i<n)
//			std::swap(p[i+1],p[i]);
//		else
//			std::swap(p[i-1],p[i]);
	}
//	for(int i=1;i<=n;i++)
//		printf("&%d %d %d %d\n",p[i],q[i],a[p[i]],c[q[i]]);
	for(int i=0;i<v.size()-1;i++)
		std::swap(p[v[i]],p[v[i+1]]);
	for(int i=1;i<=n;i++)
		ans-=std::min(a[p[i]],c[q[i]]);
	printf("%lld\n",ans);
}