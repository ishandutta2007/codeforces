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
#define all(v) v.begin(),v.end()
using namespace std;
int n,a[200005];
ll f[5];
void mian(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]); a[n+1]=0;
	f[0]=0; f[1]=f[2]=-(1ll<<60);
	For(i,1,n+1){
		if (i&1) f[1]=max(f[1],f[0]),f[2]=max(f[2],f[1]);
		if (i&1) f[0]+=a[i],f[2]+=a[i];
		else f[1]+=a[i];
	}
	ll ans=f[2];
	f[0]=0; f[1]=f[2]=-(1ll<<60);
	For(i,1,n+1){
		if (!(i&1)) f[1]=max(f[1],f[0]),f[2]=max(f[2],f[1]);
		if (i&1) f[0]+=a[i],f[2]+=a[i];
		else f[1]+=a[i];
	}
	cout<<max(ans,f[2])<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}