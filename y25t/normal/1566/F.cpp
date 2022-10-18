#include<bits/stdc++.h>
#define int long long
#define ll long long
#define mp std::make_pair
#define fir first
#define sec second
#define N 200005

int T;

int n,m;

int c[N];
std::pair<int,int> a[N],b[N];
int tot;

ll f[N],g[N];

signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		c[0]=-1e18,c[++n]=1e18;
		std::sort(c,c+n+1);
		for(int i=1;i<=m;i++)
			scanf("%lld%lld",&a[i].fir,&a[i].sec);
		std::sort(a+1,a+m+1,[&](std::pair<int,int> x,std::pair<int,int> y){
			return x.sec==y.sec?x.fir>y.fir:x.sec<y.sec;
		});
		tot=0;
		for(int i=1,mx=-1e18;i<=m;i++){
			int x=std::lower_bound(c,c+n+1,a[i].fir)-c;
			if(a[i].fir>mx&&(x>n||c[x]>a[i].sec))
				b[++tot]=a[i];
			mx=std::max(mx,a[i].fir);
		}
		for(int i=0;i<n;i++){
			int l=std::upper_bound(b+1,b+tot+1,mp(c[i],0ll))-b;
			int r=std::upper_bound(b+1,b+tot+1,mp(c[i+1],0ll))-b-1;
			if(l>r){
				g[i+1]=f[i+1]=f[i];
				continue;
			}
			ll tmp=std::min(f[i]+2ll*(b[r].fir-c[i]),g[i]+b[r].fir-c[i]);
			f[i+1]=std::min(tmp,f[i]+c[i+1]-b[l].sec);
			g[i+1]=std::min(tmp,f[i]+2ll*(c[i+1]-b[l].sec));
			for(int j=l;j<r;j++){
				tmp=std::min(f[i]+2ll*(b[j].fir-c[i]),g[i]+b[j].fir-c[i]);
				f[i+1]=std::min(f[i+1],tmp+c[i+1]-b[j+1].sec);
				g[i+1]=std::min(g[i+1],tmp+2ll*(c[i+1]-b[j+1].sec));
			}
		}
		printf("%lld\n",f[n]);
	}
}