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
const int N=100005;
int n,a[N],x,f[N];
void solve(){
	scanf("%d%d",&n,&x);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,0,n+1) f[i]=0;
	For(i,1,n){
		f[i]=max(f[i],f[i-1]);
		int r=i+(x+a[i]-1)/a[i];
		if (r<=n+1) f[r]=max(f[r],f[i]+1);
	}
	cout<<f[n+1]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}