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
const int N=52;
ll op[N][N][5],c[N];
int n,k;
void divide(ll l,ll r,ll x,ll y,ll d,int id){
	if (x<=l&&r<=y){
		if ((l^x)<=(r^y))
			op[id][d][2]=l;
		else
			op[id][d][3]=r;
		return;
	}
	ll mid=(l+r)/2;
	if (x<=mid) divide(l,mid,x,y,d-1,id);
	if (y>mid) divide(mid+1,r,x,y,d-1,id);
}
void getrange(int id,ll l,ll r){
	divide(0,(1ll<<k)-1,l,r,k,id);
	For(i,0,k) op[id][i][0]=(l>>i)<<i;
	For(i,0,k) op[id][i][1]=(r>>i)<<i;
	//For(i,0,k) cout<<id<<' '<<i<<' '<<op[id][i][0]<<' '<<op[id][i][1]<<' '<<op[id][i][2]<<' '<<op[id][i][3]<<endl;
}
ll f[N][N][N][4][4];
int main(){
	memset(op,-1ll,sizeof(op));
	scanf("%d%d",&n,&k);
	For(i,1,n){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		getrange(i,l,r);
	}
	getrange(0,0,0);
	getrange(n+1,0,0);
	For(i,0,k-1) scanf("%lld",&c[i]);
	memset(f,30,sizeof(f));
	For(i,0,n) For(s1,0,1) For(s2,0,1)
		f[k+1][i][i+1][s1][s2]=0;
	Rep(d,k,0){
		For(l,0,n+1) For(s1,0,1) For(S1,0,1)
			For(r,l+1,n+1) For(s2,0,1) For(S2,0,1){
				int ns1=s1+S1*2,ns2=s2+S2*2;
				if (op[l][d][ns1]<0||op[r][d][ns2]<0) continue;
				f[d][l][r][ns1][ns2]=f[d+1][l][r][s1][s2];
				if (l!=0&&r!=n+1)
					if ((op[l][d][ns1]^op[r][d][ns2])&(1ll<<d))
						f[d][l][r][ns1][ns2]+=c[d];
			}
		Rep(m,n,1) For(l,0,m-1) For(r,m+1,n+1)
			For(d1,0,3) For(d2,2,3) For(d3,0,1)
				f[d][l][r][d1][d3]=min(f[d][l][r][d1][d3],f[d][l][m][d1][d2]+f[d][m][r][d2][d3]);
		/*For(l,1,n) For(s1,0,1)
			For(r,l+1,n) For(s2,0,1)
				if (f[d][l][r][s1][s2]<=1ll<<60)
					cout<<f[d][l][r][s1][s2]<<' '<<d<<' '<<l<<' '<<r<<' '<<s1<<' '<<s2<<endl;*/
	}
	ll ans=1ll<<60;
	For(d,0,k) For(s1,0,1) For(s2,0,1)
		ans=min(ans,f[d][0][n+1][s1][s2]);
	cout<<ans<<endl;
}