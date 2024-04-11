#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,m,p[N],x[N];

int val[N],tot;

ll a[N],b[N];

ll f[N],g[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i],&x[i]),val[++tot]=p[i];
		std::sort(val+1,val+tot+1),tot=std::unique(val+1,val+tot+1)-val-1;
		for(int i=0;i<=tot;i++)
			a[i]=b[i]=0;
		for(int i=1;i<=n;i++){
			p[i]=std::lower_bound(val+1,val+tot+1,p[i])-val;
			int l=std::lower_bound(val+1,val+tot+1,val[p[i]]-x[i])-val;
			int r=std::upper_bound(val+1,val+tot+1,val[p[i]]+x[i])-val-1;
			a[l]++,a[p[i]+1]--,b[l]+=x[i]-val[p[i]],b[p[i]+1]-=x[i]-val[p[i]];
			a[p[i]+1]--,a[r+1]++,b[p[i]+1]+=x[i]+val[p[i]],b[r+1]-=x[i]+val[p[i]];
		}
		for(int i=1;i<=tot;i++)
			a[i]+=a[i-1],b[i]+=b[i-1];
		for(int i=1;i<=tot;i++)
			f[i]=g[i]=-1e18;
		for(int i=1;i<=tot;i++){
			ll t=a[i]*val[i]+b[i];
			if(t<=m)
				continue;
			t-=m;
			f[i]=t+val[i],g[i]=t-val[i];
		}
		for(int i=tot-1;i;i--)
			f[i]=std::max(f[i],f[i+1]);
		for(int i=2;i<=tot;i++)
			g[i]=std::max(g[i],g[i-1]);
		for(int i=1;i<=n;i++)
			putchar(x[i]+val[p[i]]>=f[p[i]]&&x[i]-val[p[i]]>=g[p[i]]?'1':'0');
		puts("");
	}
}