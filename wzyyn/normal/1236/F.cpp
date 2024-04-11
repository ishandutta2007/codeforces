#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int inv2=(mo+1)/2;
const int inv4=(mo+1)/4;
const int N=500005;
int dep[N],fa[N],deg[N];
int sz[N],p[N],cnt[N],n,m,nd;
vector<int> e[N],vec[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x])
		if (i!=fa[x])
			if (!dep[i]){
				fa[i]=x;
				dfs(i);
			}
			else if (dep[x]>dep[i]){
				++nd;
				for (int y=x;;y=fa[y]){
					vec[nd].PB(y);
					if (y==i) break;
				}
				sz[nd]=vec[nd].size();
				p[nd]=power(inv2,sz[nd]);
			}
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) deg[i]=e[i].size();
	dfs(1);
	int E1=0,E2=0,E3=0;
	E1=1ll*n*inv2%mo;
	E2=1ll*m*inv4%mo;
	For(i,1,nd) E3=(E3+p[i])%mo;
	int E=(E1+mo-E2+1ll*E3)%mo; 
	//printf("%lld %d\n",E*8ll%mo,E3);
	int E11=0,E12=0,E13=0,E22=0,E23=0,E33=0;
	E11=(1ll*n*(n-1)%mo*inv4%mo+E1)%mo;
	For(i,1,n) E12=(E12+1ll*(m-deg[i])*inv4%mo*inv2+1ll*deg[i]*inv4)%mo;
	For(i,1,nd) E13=(E13+1ll*p[i]*(1ll*inv2*(n-sz[i])%mo+sz[i])%mo)%mo;
	E22=(1ll*m*(m-1)%mo*inv4%mo*inv4%mo+E2)%mo;
	For(i,1,n) E22=(E22+1ll*deg[i]*(deg[i]-1)%mo*inv4%mo*inv4)%mo;
	For(i,1,nd) E23=(E23+1ll*p[i]*(1ll*inv4*(m-sz[i])%mo+sz[i]))%mo;
	For(i,1,nd) for (auto j:vec[i]) E23=(E23+1ll*p[i]*inv4%mo*(deg[j]-2)%mo)%mo;
	For(i,1,nd) E33=(E33+1ll*p[i]*(E3+mo-p[i]+1))%mo;
	For(i,1,nd) for (auto j:vec[i]) cnt[j]=(cnt[j]+p[i])%mo;
	For(i,1,nd) for (auto j:vec[i]) E33=(E33+1ll*p[i]*(cnt[j]+mo-p[i]))%mo;
	int EF=(1ll*E11+E22+E33+2*E13+4ll*mo-2*E12-2*E23)%mo;
	printf("%lld\n",(EF+mo-1ll*E*E%mo)%mo);
}
//1: 2: 3: