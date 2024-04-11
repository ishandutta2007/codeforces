#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define pii std::pair<ll,ll>
#define fr first
#define sc second
#define N 60

inline ll fp(ll x,ll k,ll P){
	ll res=1;
	for(;k;k>>=1,x=(LL)x*x%P) if(k&1)
		res=(LL)res*x%P;
	return res;
}

const unsigned ll P[2]={9000000000000000041,9000000000000000053};
pii operator + (pii x,pii y){
	return {(x.fr+y.fr)%P[0],(x.sc+y.sc)%P[1]};
}
pii operator - (pii x,pii y){
	return {(x.fr-y.fr+P[0])%P[0],(x.sc-y.sc+P[1])%P[1]};
}
pii operator * (pii x,pii y){
	return {(LL)x.fr*y.fr%P[0],(LL)x.sc*y.sc%P[1]};
}
inline pii inv(pii x){
	return {fp(x.fr,P[0]-2,P[0]),fp(x.sc,P[1]-2,P[1])};
}

int n,e[N][2];

pii a[N][N<<1];
inline void gs(){
	for(int i=1;i<=n;i++)
		a[i][i+n]=pii(1,1);
	for(int i=1;i<=n;i++){
		if(!a[i][i].fr||!a[i][i].sc)
			for(int j=i+1;j<=n;j++) if(a[j][i].fr&&a[j][i].sc){
				std::swap(a[i],a[j]);
				break;
			}
		pii x=inv(a[i][i]);
		for(int j=n+n;j>=i;j--)
			a[i][j]=a[i][j]*x;
		for(int j=1;j<=n;j++) if(j!=i){
			pii y=a[j][i];
			for(int k=i;k<=n+n;k++)
				a[j][k]=a[j][k]-y*a[i][k];
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		a[i][j]=a[i][j+n];
}

int q,v;
char s[N];

pii b[N],c[N];

bool vis[N];
inline bool dfs(int u){
	if(u==v)
		return 1;
	if(vis[u])
		return 0;
	vis[u]=1;
	return dfs(e[u][s[u]=='R']);
}
inline ll sol(){
	for(int i=1;i<=n;i++)
		b[i]=pii(0,0);
	for(int i=1;i<=n;i++) if(s[i]=='R')
		b[i]=b[i]+pii(1,1),b[e[i][0]]=b[e[i][0]]-pii(1,1);
	b[1]=b[1]+pii(1,1),b[v]=b[v]-pii(1,1);
	for(int i=1;i<=n;i++)
		c[i]=pii(0,0);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		c[i]=c[i]+a[i][j]*b[j];
	ll res=0;
	for(int i=1;i<=n;i++){
		if(c[i].fr!=c[i].sc||c[i].fr-(s[i]=='R')<0)
			return -1;
		res+=c[i].fr+c[i].fr-(s[i]=='R');
		for(int j=1;j<=n;j++)
			vis[j]=0;
		if(c[i].fr&&!dfs(i))
			return -1;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	n--;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&e[i][0],&e[i][1]);
	for(int i=1;i<=n;i++)
		a[i][i]=pii(2,2);
	for(int i=1;i<=n;i++) for(int j=0;j<2;j++)
		a[e[i][j]][i]=a[e[i][j]][i]-pii(1,1);
	gs();
	scanf("%d",&q);
	while(q--){
		scanf("%d%s",&v,s+1);
		printf("%lld\n",sol());
	}
}