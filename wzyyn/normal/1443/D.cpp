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
int n,a[50005];
ll b[50005],c[50005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,0,n+1) b[i]=c[i]=0;
	For(i,1,n-1)
		if (a[i]<a[i+1]) c[i+1]+=a[i+1]-a[i];
		else b[i]+=a[i]-a[i+1];
	For(i,1,n) c[i]+=c[i-1];
	Rep(i,n,1) b[i]+=b[i+1];
	//cout<<a[1]<<' '<<b[1]<<' '<<c[1]<<endl;
	puts(a[1]>=b[1]+c[1]?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}