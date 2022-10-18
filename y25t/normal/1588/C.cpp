#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define N 300005

int T;

int n,a[N];

ll s[N];

#define W 19
ll lg[N],f[W][N],g[W][N];
inline void init(){
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int j=1;j<W;j++)
		for(int i=0;i<=n-(1<<j)+1;i++){
			f[j][i]=std::min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
			g[j][i]=std::max(g[j-1][i],g[j-1][i+(1<<(j-1))]);
		}
}
inline ll mn(int l,int r){
	int k=lg[r-l+1];
	return std::min(f[k][l],f[k][r-(1<<k)+1]);
}
inline ll mx(int l,int r){
	int k=lg[r-l+1];
	return std::max(g[k][l],g[k][r-(1<<k)+1]);
}

std::unordered_map<ll,std::vector<int>> V;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		V.clear();
		V[0].push_back(0);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i&1){
				s[i]=s[i-1]+a[i];
				f[0][i]=s[i],g[0][i]=-inf;
			}
			else{
				s[i]=s[i-1]-a[i];
				g[0][i]=s[i],f[0][i]=inf;
			}
			V[s[i]].push_back(i);
		}
		init();
		ll ans=0;
		for(auto [x,v]:V){
			int m=v.size();
			for(int i=1,j=0;i<m;i++){
				while(j<i&&!(mx(v[j]+1,v[i])<=x&&x<=mn(v[j]+1,v[i])))
					j++;
				ans+=i-j;
			}
		}
		printf("%lld\n",ans);
	}
}