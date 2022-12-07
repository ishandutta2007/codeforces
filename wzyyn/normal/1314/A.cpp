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
int n;
pii a[200005];
priority_queue<int> Q;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i].fi);
	For(i,1,n) scanf("%d",&a[i].se);
	a[n+1].fi=1<<30;
	sort(a+1,a+n+2);
	ll S=0,ans=0;
	int t=0,p=0;
	for (;;){
		if (!S) t=a[p+1].fi;
		if (t==1<<30) break;
		for (;a[p+1].fi==t&&p<=n;++p)
			Q.push(a[p+1].se),S+=a[p+1].se;
		S-=Q.top(); Q.pop(); ans+=S; t++;
	} 
	printf("%lld\n",ans);
}