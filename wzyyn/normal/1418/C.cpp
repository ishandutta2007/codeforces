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
const int N=500005;
int n,a[N],f[N][2];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	a[n+1]=0;
	f[n+2][0]=f[n+2][1]=0;
	f[n+1][0]=f[n+1][1]=0;
	Rep(i,n,1){
		f[i][0]=min(f[i+1][1],f[i+2][1]);
		f[i][1]=min(f[i+1][0],f[i+2][0]+a[i+1])+a[i];
	}
	cout<<f[1][1]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}