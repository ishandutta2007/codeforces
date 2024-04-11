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
int x[5],y[5],d[25];
int vi[5],px[5],py[5];
ll ans,f[16];
void solve(){
	For(i,0,3) scanf("%d%d",&x[i],&y[i]);
	ans=1ll<<50;
	For(cx,0,3) For(cy,0,3){
		*d=0;
		For(nx,0,3) if (nx!=cx) d[++*d]=abs(x[nx]-x[cx]);
		For(ny,0,3) if (ny!=cy) d[++*d]=abs(y[ny]-y[cy]);
		For(i,1,*d) For(dx,0,1) For(dy,0,1){
			int x1=x[cx],x2=x1+(dx?-d[i]:d[i]);
			int y1=y[cy],y2=y1+(dy?-d[i]:d[i]);
			px[0]=px[2]=x1; px[1]=px[3]=x2;
			py[0]=py[1]=y1; py[2]=py[3]=y2;
			memset(f,1,sizeof(f));
			f[0]=0;
			For(S,0,14){
				int p=0;
				For(j,0,3) if (S&(1<<j)) p++;
				For(j,0,3) if (!(S&(1<<j)))
					f[S|(1<<j)]=min(f[S|(1<<j)],f[S]+abs(x[p]-px[j])+abs(y[p]-py[j]));
			}
			ans=min(ans,f[15]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}