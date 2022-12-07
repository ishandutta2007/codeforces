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
int n,k,x[N],pr[N],su[N];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&x[i]);
	For(i,1,n) scanf("%*d");
	sort(x+1,x+n+1);
	int h=1;
	su[n+1]=0;
	For(i,1,n){
		for (;x[i]-x[h]>k;++h);
		pr[i]=max(pr[i-1],i-h+1);
	}
	h=n;
	int ans=0;
	Rep(i,n,1){
		for (;x[h]-x[i]>k;--h);
		su[i]=max(su[i+1],h-i+1);
		ans=max(ans,su[i]+pr[i-1]);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}