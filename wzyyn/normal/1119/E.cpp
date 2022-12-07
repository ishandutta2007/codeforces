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
int n,a[N];
ll ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	ll sum=0;
	Rep(i,n,1){
		sum+=a[i]/2*2; a[i]&=1;
		if (a[i]&&sum>=2) sum-=2,ans++,a[i]=0;
	}
	ans+=sum/3;
	printf("%lld\n",ans);
}