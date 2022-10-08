#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

const int N=400005,G=20;
const ll inf=1e15+1;

ll ans,dep[N],val[N];
int fa[N][G+1],Q,o,n=1;
ll x,y;

int main(){
	scanf("%d",&Q);
	val[0]=val[1]=dep[1]=inf;
	while(Q--){
		scanf("%d%lld%lld",&o,&x,&y);
		x^=ans;y^=ans;
		if(o==1){
			val[++n]=y;
			int p=x;
			fd(i,G,0)if(val[fa[p][i]]<y)p=fa[p][i];
			if(val[p]<y)p=fa[p][0];
			fa[n][0]=p;dep[n]=dep[p]+val[n];
			fo(i,1,G)fa[n][i]=fa[fa[n][i-1]][i-1];
		}else{
			ans=0;
			if(x==1){
				ans=1;
				printf("%lld\n",ans);
				continue;
			}
			if(val[x]>y){
				printf("%lld\n",ans);
				continue;
			}
			int q=x;
			fd(i,G,0)if(dep[x]-dep[fa[q][i]]<=y)q=fa[q][i],ans+=1<<i;
			if(dep[x]==inf)ans++;
			printf("%lld\n",ans);
		}
	}
	return 0;
}