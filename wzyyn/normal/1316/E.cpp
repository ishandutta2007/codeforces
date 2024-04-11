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
const int N=100005;
int n,p,k,a[N],id[N];
int S[128],v[N][8];
ll f[N][128];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d%d%d",&n,&p,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n) For(j,0,p-1) scanf("%d",&v[i][j]);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	For(i,0,(1<<p)-1) S[i]=S[i/2]+(i&1); 
	For(i,1,n) For(j,0,(1<<p)-1){
		f[i][j]=max(f[i][j],f[i-1][j]+(k+S[j]>=i?a[id[i]]:0));
		For(k,0,p-1) if (!(j&(1<<k)))
			f[i][j|(1<<k)]=max(f[i][j|(1<<k)],f[i-1][j]+v[id[i]][k]); 
	}
	ll ans=-(1ll<<60);
	For(j,0,(1<<p)-1) ans=max(ans,f[n][j]);
	printf("%lld\n",ans);
}