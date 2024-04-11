#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

pair<int,int> f[100005];

int n,m,t[205],y[205];
ll x[205];
long long F(int i,int j){
	long long nv;
	if (t[j]==1) nv=100000ll*i+x[j];
	else nv=1ll*i*x[j];
	return (nv+99999)/100000;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		f[i]=pii(1<<30,0);
	f[0]=pii(1,0);
	for (int i=1;i<=n;i++)
		scanf("%d%lld%d",&t[i],&x[i],&y[i]);
	for (int i=0;i<m;i++){
		//cout<<i<<' '<<f[i].first<<' '<<f[i].second<<endl;
		if (f[i].first!=1<<30)
			if (y[f[i].first]!=f[i].second){
				pii nv=f[i];
				nv.second++;
				long long nj=F(i,f[i].first);
				if (nj<=m) f[nj]=min(f[nj],nv);
			}
		for (int j=f[i].first+1;j<=n;j++){
			long long nj=F(i,j);
			if (nj<=m) f[nj]=min(f[nj],pii(j,1));
		}
	}
	for (int i=1;i<=m;i++)
		if (f[i].first==1<<30)
			printf("-1 ");
		else printf("%d ",f[i].first);
}