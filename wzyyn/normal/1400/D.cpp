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
int n,a[5005],tab[5005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	ll ans=0;
	For(i,1,n){
		For(j,1,n) tab[j]=0;
		For(j,i+1,n) ++tab[a[j]];
		int sum=0;
		Rep(j,i-1,1){
			if (a[j]==a[i]) ans+=sum;
			sum+=tab[a[j]];
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}