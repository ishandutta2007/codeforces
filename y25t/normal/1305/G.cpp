#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define fr first
#define sc second
#define ll long long
#define N 200005
#define W 18

int n,a[N];

int f[N];
inline int fnd(int u){
	return f[u]?f[u]=fnd(f[u]):u;
}

struct node{
	pii x,y;
	node(){
		x=y=pii(-1,0);
	}
	inline void ins(pii z){
		if(z.fr>x.fr)
			y=x,x=z;
		else if(z.fr>y.fr&&z.sc!=x.sc)
			y=z;
	}
	inline pii mx(int z=-1){
		return z==x.sc?y:x;
	}
}s[1<<W];

pii g[N];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans-=a[i];
	n++;
	while(1){
		int cnt=0;
		for(int i=1;i<=n;i++) if(!f[i])
			cnt++,g[i]=pii(-1,0);
		if(cnt==1)
			break;
		for(int i=0;i<(1<<W);i++)
			s[i]=node();
		for(int i=1;i<=n;i++)
			s[a[i]].ins(pii(a[i],fnd(i)));
		for(int k=1;k<(1<<W);k<<=1)
			for(int i=0;i<(1<<W);i+=k<<1)
				for(int j=0;j<k;j++)
					s[i+j+k].ins(s[i+j].x),s[i+j+k].ins(s[i+j].y);
		for(int i=1;i<=n;i++){
			int o=fnd(i);
			auto [x,j]=s[a[i]^((1<<W)-1)].mx(o);
			if(j)
				g[o]=std::max(g[o],pii(x+a[i],j));
		}
		for(int i=1;i<=n;i++) if(!f[i]){
			auto [x,j]=g[i];
			if(fnd(j)!=i)
				f[fnd(j)]=i,ans+=x;
		}
	}
	printf("%lld\n",ans);
}