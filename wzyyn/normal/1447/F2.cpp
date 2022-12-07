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

const int N=200005,B=205;
int n,t,id,rk[N],q[N],a[N];
int vis[N],ans,c[N];
vector<int> v[N];
void solve1(int id2){
	For(i,0,n+1) vis[i]=-1;
	int S=t; vis[S]=0;
	For(i,1,n){
		if (a[i]==id) ++S;
		if (a[i]==id2) --S;
		if (vis[S]!=-1) ans=max(ans,i-vis[S]);
		else vis[S]=i;
	}
}
int su[N][B];
void solve2(){
	memset(su,1,sizeof(su));
	For(i,1,n)
		if (i!=id&c[i]<=B)
			For(j,0,v[i].size()-1)
				For(k,j,v[i].size()-1)
					su[v[i][j]][k-j+1]=min(su[v[i][j]][k-j+1],v[i][k]);
	Rep(i,n,1) For(j,1,B) su[i][j]=min(su[i][j],su[i+1][j]);
	For(i,0,t) For(j,1,B) if (i+j<=t)
		if (su[q[i]+1][j]<=q[i+j+1]) ans=max(ans,q[i+j+1]-q[i]-1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) ++c[a[i]];
	For(i,1,n) v[a[i]].PB(i);
	For(i,1,n) if (c[i]>c[id]) id=i;
	For(i,1,n) if (a[i]==id) q[++t]=i;
	q[t+1]=n+1;
	For(i,1,n) if (i!=id&&c[i]==c[id]) return printf("%d\n",n),0;
	For(i,1,n) rk[i]=rk[i-1]+(a[i]==id);
	For(i,1,n) if (c[i]>=B&&i!=id) solve1(i);
	solve2();
	cout<<ans<<endl;
}