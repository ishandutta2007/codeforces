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
int a[55],f[55],d,m;
void solve(){
	scanf("%d%d",&d,&m);
	For(i,0,30) a[i]=min((1<<i)-1,d);
	Rep(i,30,1) a[i]-=a[i-1];
	For(i,1,30){
		int s=1;
		For(j,0,i-1) s=(s+f[j])%m;
		f[i]=1ll*a[i]*s%m;
		//if (i<=3) cout<<f[i]<<' ';
	}
	int ans=0;
	For(i,1,30) ans=(ans+f[i])%m;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}