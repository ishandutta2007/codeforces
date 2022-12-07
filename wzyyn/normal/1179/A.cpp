#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
int n,Q,a[N],ans1[N],ans2[N];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	int h=1,t=n;
	For(i,1,n){
		ans1[i]=a[h]; ans2[i]=a[h+1];
		a[++h]=max(ans1[i],ans2[i]);
		a[++t]=min(ans1[i],ans2[i]);
	}
	while (Q--){
		ll t;
		scanf("%lld",&t);
		if (t<=n) printf("%d %d\n",ans1[t],ans2[t]);
		else printf("%d %d\n",a[h],a[h+(t-n-1)%(n-1)+1]);
	}
}