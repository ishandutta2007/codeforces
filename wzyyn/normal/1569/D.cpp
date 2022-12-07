#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=200005;
int n,m,k;
int a[N],sa[N];
int b[N],sb[N];
map<int,int> mpa[N],mpb[N];
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sa[i]=0,mpa[i].clear(),mpb[i].clear();
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),sb[i]=0;
	long long ans=0;
	for (int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int px=lower_bound(a+1,a+n+1,x)-a;
		int py=lower_bound(b+1,b+m+1,y)-b;
		if (a[px]!=x) ans+=sa[px]-mpa[px][py],++sa[px],++mpa[px][py];
		if (b[py]!=y) ans+=sb[py]-mpb[px][py],++sb[py],++mpb[px][py];
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}